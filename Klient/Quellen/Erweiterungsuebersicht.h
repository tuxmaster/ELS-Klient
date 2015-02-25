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

#ifndef ERWEITERUNGSUEBERSICHT_H
#define ERWEITERUNGSUEBERSICHT_H

#include "ui_Erweiterungsuebersicht.h"
#include "Pluginversion.h"

class Erweiterungsmodell;
class Erweiterungsuebersicht : public QDialog, private Ui::Erweiterungsuebersicht
{
		Q_OBJECT

	public:
		explicit Erweiterungsuebersicht(QWidget *eltern,const QList<Pluginversion>* erweiterungen);

	protected:
		void				changeEvent(QEvent *e) Q_DECL_OVERRIDE ;

	private:
		Erweiterungsmodell*	K_Datenmodell;
};

#endif // ERWEITERUNGSUEBERSICHT_H
