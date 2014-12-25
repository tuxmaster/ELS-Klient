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

#ifndef ERWEITERUNGSMODELL_H
#define ERWEITERUNGSMODELL_H

#include <QtCore>
#include "Pluginversion.h"

class Erweiterungsmodell : public QAbstractItemModel
{
		Q_OBJECT
	public:
		explicit Erweiterungsmodell(QObject *eltern ,const QList<Pluginversion>* erweiterungen);
		Qt::ItemFlags				flags(const QModelIndex &index) const Q_DECL_OVERRIDE;
		QVariant					headerData(int sektion, Qt::Orientation ausrichtung,
											   int rolle=Qt::DisplayRole) const Q_DECL_OVERRIDE;
		QVariant					data(const QModelIndex &index, int rolle) const Q_DECL_OVERRIDE;
		QModelIndex					index(int reihe, int spalte,const QModelIndex &eltern = QModelIndex()) const Q_DECL_OVERRIDE;
		QModelIndex					parent(const QModelIndex &index) const Q_DECL_OVERRIDE;
		int							rowCount(const QModelIndex &eltern = QModelIndex()) const Q_DECL_OVERRIDE;
		int							columnCount(const QModelIndex &eltern = QModelIndex()) const Q_DECL_OVERRIDE;


	private:
		const QList<Pluginversion>*	K_Liste;
};

#endif // ERWEITERUNGSMODELL_H
