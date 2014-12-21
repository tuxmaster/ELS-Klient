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

#ifndef HAUPTFENSTER_H
#define HAUPTFENSTER_H

#include <QGeoPositionInfoSource>
#include <QtCore>

#include "ui_Hauptfenster.h"

class Funkalphabet;
class Hauptfenster : public QMainWindow, private Ui::Hauptfenster
{
		Q_OBJECT

	public:
		explicit Hauptfenster(QWidget *eltern = 0);

	protected:
		void changeEvent(QEvent *e);
		void		focusInEvent(QFocusEvent * ereignis);

	private Q_SLOTS:
		void UhrzeitSetzen();
		void NeuePosition(const QGeoPositionInfo &info);
		void Positionsfehler(QGeoPositionInfoSource::Error fehler);
		void on_action_Kenner_setzen_triggered();
		void on_action_Alphabet_triggered();
		void on_Stundenmodus_stateChanged(int status);
		void Fehler(const QString& meldung);

	private:
		QSettings*		K_Einstellungen;
		Funkalphabet*	K_Funkalphabet;
};

#endif // HAUPTFENSTER_H
