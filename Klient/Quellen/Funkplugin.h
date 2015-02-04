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

#ifndef FUNKPLUGIN_H
#define FUNKPLUGIN_H

#include <QtCore>
class Funkplugin
{
	public:
			virtual ~Funkplugin(){}
			virtual	const QString	Version() const =0;
			virtual const QString	Name()const =0;
			virtual const QString	Beschreibung() const =0;
};
Q_DECLARE_INTERFACE(Funkplugin, "de.terrortux.katlin.Funkplugin")
#endif // FUNKPLUGIN_H
