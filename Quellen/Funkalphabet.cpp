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

#include <QtSql>
#include <QtGui>

#include "Datenmodell.h"
#include "Uebersetzen.h"
#include "Funkalphabet.h"

Funkalphabet::Funkalphabet(QWidget *eltern, Norm welche) :	QDialog(eltern)
{
	setupUi(this);
	K_Datenmodell= new Datenmodell(this);
	connect(K_Datenmodell,SIGNAL(Fehler(QString)),this,SIGNAL(Fehler(QString)));
	tbUebersicht->setModel(K_Datenmodell);
	K_Uebersetzen=new Uebersetzen(this,K_Datenmodell);
	connect(K_Uebersetzen,SIGNAL(Fertig(QStringList)),this,SLOT(UebersetzungFertig(QStringList)));
	K_Startnorm=welche;
	QPoint dialogCenter = mapToGlobal(rect().center());
	QPoint parentWindowCenter = eltern->window()->mapToGlobal(
		eltern->window()->rect().center());
	move(parentWindowCenter - dialogCenter);
	QTimer::singleShot(0,this,SLOT(Starten()));
}
void Funkalphabet::Starten()
{
	K_Datenmodell->DB_Laden();

	if(K_Startnorm==DIN)
	{
		NormGeaendert(DIN);
		rkDIN->setFocus();
	}
	else
	{
		rkITU->setChecked(true);
		rkITU->setFocus();
	}
}

void Funkalphabet::changeEvent(QEvent *e)
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
void Funkalphabet::on_rkDIN_toggled(bool aktiv)
{
	if(aktiv)
		NormGeaendert(DIN);
}
void Funkalphabet::on_rkITU_toggled(bool aktiv)
{
	if(aktiv)
		NormGeaendert(ITU);
}
void Funkalphabet::NormGeaendert(Norm norm)
{
	emit NormSpeichern(norm);
	K_Datenmodell->NormGeaendert(norm);
	on_txtEingabe_editingFinished();
}
void Funkalphabet::on_txtEingabe_editingFinished()
{
	if(txtEingabe->text().isEmpty())
		return;
	K_Uebersetzen->Loslegen(txtEingabe->text());
}
void Funkalphabet::UebersetzungFertig(QStringList ergebnis)
{
	txtAusgabe->setText(ergebnis.join("\r\n"));
}
