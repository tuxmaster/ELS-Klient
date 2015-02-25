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

#ifndef FUNKKENNER_H
#define FUNKKENNER_H

#include "ui_Funkkenner.h"

class DlgFunkkenner : public QDialog, private Ui::DlgFunkkenner
{
		Q_OBJECT

	public:
		explicit		DlgFunkkenner(QWidget *eltern,const QString& funkkenner);
		const QString&	Funkkenner()const{return K_Funkkenner;}

	public Q_SLOTS:
		void			accept() Q_DECL_OVERRIDE;

	protected:
		void			changeEvent(QEvent *e) Q_DECL_OVERRIDE;

	private:
		QString			K_Funkkenner;
};

#endif // FUNKKENNER_H
