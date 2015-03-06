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

Erweiterungsmodell::Erweiterungsmodell(QObject *eltern, const QList<Pluginversion> *erweiterungen) : QAbstractTableModel(eltern)
{
	K_Liste=erweiterungen;
}
QVariant Erweiterungsmodell::headerData(int sektion, Qt::Orientation ausrichtung, int rolle) const
{
	if((ausrichtung==Qt::Horizontal)&& (rolle==Qt::DisplayRole))
	{
		switch (sektion)
		{
			case 0:
					return tr("Type");
					break;
			case 1:
					return tr("Name");
					break;
			case 2:
					return tr("Version");
					break;
			case 3:
					return tr("Beschreibung");
					break;
			default:
					return QVariant();
					break;
		}
	}
	return QVariant();
}
QVariant Erweiterungsmodell::data(const QModelIndex &index, int rolle) const
{
	if((rolle!= Qt::DisplayRole) || (index.row()>K_Liste->size()) )
		return QVariant();
	switch (index.column())
	{
		case 0:
			return K_Liste->at(index.row()).Artname();
			break;
		case 1:
			return K_Liste->at(index.row()).Name();
			break;
		case 2:
			return K_Liste->at(index.row()).Version();
		case 3:
			return K_Liste->at(index.row()).Beschreibung();
			break;
		default:
			break;
	}
	return QVariant();
}
