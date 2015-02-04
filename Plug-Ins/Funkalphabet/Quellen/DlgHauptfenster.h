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

#ifndef DLGHAUPTFENSTER_H
#define DLGHAUPTFENSTER_H

#include "ui_Hauptfenster.h"
#include "Vorgaben.h"

class Datenmodell;
class Uebersetzen;
class DlgHauptfenster : public QMainWindow, private Ui::DlgHauptfenster
{
		Q_OBJECT
	public:
		explicit	DlgHauptfenster(QWidget *eltern = 0);
	private:
		void		NormGeaendert(Norm norm);
		Datenmodell	*K_Datenmodell;
		Uebersetzen	*K_Uebersetzen;
	protected:
		void		changeEvent(QEvent *ereignis);
	private Q_SLOTS:
		void		Fehler(QString meldung);
		void		UebersetzungFertig(QStringList ergebnis);
		void		on_rkDIN_toggled(bool aktiv);
		void		on_rkITU_toggled(bool aktiv);
		void		on_txtEingabe_editingFinished();
};

#endif // DLGHAUPTFENSTER_H
