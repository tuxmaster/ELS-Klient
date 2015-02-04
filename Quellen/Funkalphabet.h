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

#ifndef DLGFUNKALPHABET_H
#define DLGFUNKALPHABET_H

#include <QtDesigner/QDesignerExportWidget>
#include "ui_Funkalphabet.h"
#include "Vorgaben.h"

class Datenmodell;
class Uebersetzen;
class QDESIGNER_WIDGET_EXPORT Funkalphabet : public QDialog, private Ui::DlgFunkalphabet
{
		Q_OBJECT

	public:
		explicit	Funkalphabet(QWidget *eltern,Norm welche=DIN);

	Q_SIGNALS:
		void		Fehler(QString meldung);
		void		NormSpeichern(Norm die);

	protected:
		void		changeEvent(QEvent *e);

	private Q_SLOTS:
		void		UebersetzungFertig(QStringList ergebnis);
		void		on_rkDIN_toggled(bool aktiv);
		void		on_rkITU_toggled(bool aktiv);
		void		on_txtEingabe_editingFinished();
		void		Starten();

	private:
		void		NormGeaendert(Norm norm);
		Norm		K_Startnorm;
		Datenmodell	*K_Datenmodell;
		Uebersetzen	*K_Uebersetzen;
};

#endif // DLGFUNKALPHABET_H
