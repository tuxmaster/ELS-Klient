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

#include "Quellen/Funkkenner.h"

DlgFunkkenner::DlgFunkkenner(QWidget *eltern,const QString& funkkenner) :	QDialog(eltern)
{
	this->setWindowFlags(Qt::CustomizeWindowHint|Qt::WindowCloseButtonHint|Qt::WindowTitleHint|Qt::Window);
	K_Funkkenner=funkkenner;
	setupUi(this);
	txtFunkkenner->setText(K_Funkkenner);
}

void DlgFunkkenner::changeEvent(QEvent *e)
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
void DlgFunkkenner::accept()
{
	K_Funkkenner=txtFunkkenner->text();
	QDialog::accept();
}
