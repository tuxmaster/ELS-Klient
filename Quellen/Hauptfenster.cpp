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
	Uhr= new QTimer(this);
	connect(Uhr,SIGNAL(timeout()),this,SLOT(UhrzeitSetzen()));
	Uhr->start(1000);
	UhrzeitSetzen();
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
