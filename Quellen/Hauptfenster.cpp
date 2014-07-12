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
#include "Hauptfenster.h"
#include "Vorgaben.h"
#include "Hilfsfunktionen.h"

Hauptfenster::Hauptfenster(QWidget *eltern) : QMainWindow(eltern)
{
	setupUi(this);
	Hilfsfunktionen::FensterZentrieren(this);
	QMainWindow::statusBar()->showMessage(tr("Version: %1").arg(VERSION));
	QTimer *Uhr;
	QGeoPositionInfoSource *GPS_Quelle;

	Uhr= new QTimer(this);
	GPS_Quelle = QGeoPositionInfoSource::createDefaultSource(this);

	connect(Uhr,SIGNAL(timeout()),this,SLOT(UhrzeitSetzen()));
	Uhr->start(1000);
	UhrzeitSetzen();

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
