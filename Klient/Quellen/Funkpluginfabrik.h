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

#ifndef FUNKPLUGINFABRIK_H
#define FUNKPLUGINFABRIK_H

#include <QtCore>

#include "Funkplugin.h"

class Funkpluginfabrik
{
	public:
				virtual ~Funkpluginfabrik(){}
				virtual Funkplugin	*funkplugin(QObject *eltern)=0;
};
#define Funkpluginfabrik_iid "de.terrortux.katlin.Funkpluginfabrik"
Q_DECLARE_INTERFACE(Funkpluginfabrik, Funkpluginfabrik_iid)
#endif // FUNKPLUGINFABRIK_H
