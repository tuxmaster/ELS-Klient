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

#include "Erweiterungsuebersicht.h"

Erweiterungsuebersicht::Erweiterungsuebersicht(QWidget *eltern, const QList<Pluginversion> *erweiterungen) : QDialog(eltern)
{
	setupUi(this);
	QList<QTreeWidgetItem *> Gruppen;
	QHash<QString,QTreeWidgetItem*> Tabelle;
	//C++11 mit Qt
	for ( auto Plugin : *erweiterungen)
	{
		if (!Tabelle.contains(Plugin.Artname()))
		{
			Tabelle[Plugin.Artname()]=new QTreeWidgetItem(Erweiterungsbaum,QStringList(tr("%1").arg(Plugin.Artname())));
			Gruppen.append(Tabelle[Plugin.Artname()]);
		}
		QStringList Daten;
		Daten <<Plugin.Name()<<Plugin.Version()<<Plugin.Beschreibung();
		Tabelle[Plugin.Artname()]->addChild(new QTreeWidgetItem(Tabelle[Plugin.Artname()],Daten));

	}
	Erweiterungsbaum->insertTopLevelItems(0,Gruppen);
}

void Erweiterungsuebersicht::changeEvent(QEvent *e)
{
	QDialog::changeEvent(e);
	switch (e->type())
	{
		case QEvent::LanguageChange:
			retranslateUi(this);
			break;
		default:
			break;
	}
}
