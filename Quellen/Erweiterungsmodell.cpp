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

#include "Erweiterungsmodell.h"

Erweiterungsmodell::Erweiterungsmodell(QObject *eltern, const QList<Pluginversion> *erweiterungen) : QAbstractItemModel(eltern)
{
}
Qt::ItemFlags Erweiterungsmodell::flags(const QModelIndex &index) const
{
	if (!index.isValid())
		return 0;
	return QAbstractItemModel::flags(index);
}
QVariant Erweiterungsmodell::headerData(int sektion, Qt::Orientation ausrichtung, int rolle) const
{
	return QVariant();
}
QVariant Erweiterungsmodell::data(const QModelIndex &index, int rolle) const
{
	return QVariant();
}
QModelIndex Erweiterungsmodell::index(int reihe, int spalte, const QModelIndex &eltern) const
{
	if (!hasIndex(reihe, spalte, eltern))
			return QModelIndex();
	//if(!eltern.isValid())
	return QModelIndex();
}
QModelIndex Erweiterungsmodell::parent(const QModelIndex &index) const
{
	return QModelIndex();
}
int Erweiterungsmodell::rowCount(const QModelIndex &eltern) const
{
	return 0;
}
int Erweiterungsmodell::columnCount(const QModelIndex &eltern) const
{
	return 0;
}
