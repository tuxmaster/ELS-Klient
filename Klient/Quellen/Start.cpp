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

#include <QApplication>
#include <QtCore>

#include "Hauptfenster.h"
#include "Vorgaben.h"

int main(int argc, char *argv[])
{
	QApplication Qt(argc, argv);
	QTranslator QtUebersetzung;
	QTranslator ProgrammUebersetzung;

	Qt.setApplicationVersion(VERSION);
	QtUebersetzung.load(QString("qt_%1").arg(QLocale::system().name()),QLibraryInfo::location(QLibraryInfo::TranslationsPath));
	ProgrammUebersetzung.load(QString("%1_%2").arg(PROGRAMM).arg(QLocale::system().name()),QLibraryInfo::location(QLibraryInfo::TranslationsPath));

	Qt.installTranslator(&QtUebersetzung);
	Qt.installTranslator(&ProgrammUebersetzung);

	Hauptfenster Fenster;
	Fenster.show();

	return Qt.exec();
}
