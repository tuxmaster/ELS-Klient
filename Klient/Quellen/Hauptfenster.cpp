/*
	Copyright (C) 2014 Frank Büttner frank-buettner@gmx.net

	This program is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with this program.  If not, see <http://www.gnu.org/licenses/>
*/

#include <QtGui>
#include <QtSql>
#include <QMessageBox>
#include "Hauptfenster.h"
#include "Erweiterungsuebersicht.h"
#include "Vorgaben.h"
#include "Hilfsfunktionen.h"
#include "Funkkenner.h"
#include "Funkpluginfabrik.h"
#include "Formularpluginfabrik.h"

Hauptfenster::Hauptfenster(QWidget *eltern) : QMainWindow(eltern)
{
	K_Pluginliste=new QList<Pluginversion>;
	K_Einstellungen=new QSettings(FIRMA,PROGRAMM,this);
	setupUi(this);

	if(!QSqlDatabase::isDriverAvailable("QSQLITE"))
	{
		Fehler(trUtf8("Das Qt SQLite Modul ist nicht verfügbar. Ohne dieses ist ein Start nicht möglich."));
		qApp->exit(1);
		return;
	}
	txtFunkkenner->setText(K_Einstellungen->value("Funk/Kenner",tr("unbekannt")).toString());
	Stundenmodus->setCheckState(static_cast<Qt::CheckState>(K_Einstellungen->value("Programm/24H",Qt::Checked).toInt()));

	Hilfsfunktionen::FensterZentrieren(this);

	QMainWindow::statusBar()->showMessage(tr("Version: %1").arg(VERSION));
	QTimer *Uhr;
	QGeoPositionInfoSource *GPS_Quelle;

	Uhr= new QTimer(this);
	GPS_Quelle = QGeoPositionInfoSource::createDefaultSource(this);

	connect(Uhr,SIGNAL(timeout()),this,SLOT(UhrzeitSetzen()));
	Uhr->start(1000);
	UhrzeitSetzen();
	ErweiterungenLaden();

#ifdef QT_DEBUG
	qDebug()<<"GPS Quellen:"<<QGeoPositionInfoSource::availableSources();
#endif
	if(GPS_Quelle)
	{
		/*Wenn eine API gefunden wurde, dann regelmäßig die Daten holen*/
		connect(GPS_Quelle,SIGNAL(positionUpdated(QGeoPositionInfo)),this,SLOT(NeuePosition(QGeoPositionInfo)));
		connect(GPS_Quelle,SIGNAL(error(QGeoPositionInfoSource::Error)),this,SLOT(Positionsfehler(QGeoPositionInfoSource::Error)));
		GPS_Quelle->startUpdates();
	}
	else
	{
		/* Keine GPS API gefunden*/
		PositionStapel->setCurrentIndex(1);
	}
}
Hauptfenster::~Hauptfenster()
{
	delete K_Pluginliste;
}

void Hauptfenster::changeEvent(QEvent *e)
{
	QMainWindow::changeEvent(e);
	switch (e->type())
	{
		case QEvent::LanguageChange:
				retranslateUi(this);
				break;
		default:
				break;
	}
}

void Hauptfenster::UhrzeitSetzen()
{
	QString UTC("dd.mm.yyyy hh:mm:ss");
	if(!Stundenmodus->checkState())
		UTC.append(" AP");
	txtZeitLokal->setText(QDateTime::currentDateTime().toString("dd.MM.yyyy hh:mm:ss t"));
	txtZeitUTC->setText(QDateTime::currentDateTimeUtc().toString(UTC));
}
void Hauptfenster::NeuePosition(const QGeoPositionInfo &info)
{
	qDebug()<<info;
}
void Hauptfenster::Positionsfehler(QGeoPositionInfoSource::Error fehler)
{
	QString Fehlertext;
	switch(fehler)
	{
		case QGeoPositionInfoSource::AccessError:
				Fehlertext=tr("Keine Zugrifsberechtigung auf die GPS Quelle.");
				break;
	}
	qDebug()<<Fehlertext;
}
void Hauptfenster::on_action_Kenner_setzen_triggered()
{
	DlgFunkkenner* kenner=new DlgFunkkenner(this,txtFunkkenner->text());
	if(kenner->exec()== QDialog::Accepted)
	{
		K_Einstellungen->setValue("Funk/Kenner",kenner->Funkkenner());
		txtFunkkenner->setText(kenner->Funkkenner());
	}
}
void Hauptfenster::on_Stundenmodus_stateChanged(int status)
{
	K_Einstellungen->setValue("Programm/24H",status);
}
void Hauptfenster::Fehler(const QString &meldung)
{
	QMessageBox::critical(this,tr("Fehler"),meldung);
	qApp->exit(1);
}

void Hauptfenster::on_action_Ueber_triggered()
{
	QMessageBox Meldung(this);
	Meldung.setTextFormat(Qt::RichText);
	Meldung.setWindowTitle(tr("Über den ELS Klient"));
	Meldung.setText(tr("Version %1 <br>"
					   "<a href='http://www.qt.io/'>Qt:</a> %2 <br>"
					   "Fehler bitte via <a href='https://katlin.terrortux.de/bugzilla'>Bugzilla</a> melden.")
					.arg(VERSION).arg(QT_VERSION_STR));
	Meldung.exec();
}
void Hauptfenster::on_action_Ueber_Erweiterungen_triggered()
{
	Erweiterungsuebersicht* Uebersicht=new Erweiterungsuebersicht(this,K_Pluginliste);
	Uebersicht->exec();
}
void Hauptfenster::ErweiterungenLaden()
{
	QDirIterator Verzeichis(PLUGINPFAD,QDirIterator::Subdirectories);
	QString Datei;
	while (Verzeichis.hasNext())
	{
		Datei=Verzeichis.next();
		if (Verzeichis.fileInfo().isFile())
		{
			QPluginLoader ErweiterungLesen(Datei);
			//qDebug()<<ErweiterungLesen.fileName();
			QObject *Erweiterung = ErweiterungLesen.instance();
			if(Erweiterung)
			{
				//qDebug()<<"geladen";
				Formularpluginfabrik* Formular=qobject_cast<Formularpluginfabrik*>(Erweiterung);
				if(Formular)
				{
					qDebug()<<"Formularplugin";

					QAction *Aktion=new QAction(Formular->formularplugin(this)->NameMenue(),this);
					menu_Vordrucke->addAction(Aktion);
				}
				else
				{
					Funkpluginfabrik* Funk=qobject_cast<Funkpluginfabrik*>(Erweiterung);

					if (Funk)
					{
						//qDebug()<<"Funkplugin";
						//Pluginversion(Type type,const QString& name,const QString& beschreibung,const QString& version,QObject* erweiterung);
						K_Pluginliste->append(Pluginversion(Pluginversion::Funk,Funk->funkplugin(this)->Name(),Funk->funkplugin(this)->Beschreibung(),
															Funk->funkplugin(this)->Version(),Funk->funkplugin(this)));
						QAction *Aktion=new QAction(Funk->funkplugin(this)->NameMenue(),this);
						connect(Aktion,SIGNAL(triggered()),Funk->funkplugin(this)->Dialog(this),SLOT(show()));
						menu_Funk->addAction(Aktion);
					}
					/*else
						qDebug()<<"Unbekannt";*/
				}
			}
		}

	}
	std::sort(K_Pluginliste->begin(),K_Pluginliste->end(),Hauptfenster::KleinerAls);
}
bool Hauptfenster::KleinerAls(const Pluginversion &a, const Pluginversion &b)
{
	//Typ Sortieren
	if(a.Art()<b.Art())
		return true;
	if (a.Art()>b.Art())
		return false;
	//Name Sortieren wenn gleiche Nummer
	if(a.Name()==b.Name())
		return false;
	QStringList tmp;
	tmp<<a.Name()<<b.Name();
	tmp.sort();
	if(tmp.at(0)==a.Name())
		return true;
	return false;
}
