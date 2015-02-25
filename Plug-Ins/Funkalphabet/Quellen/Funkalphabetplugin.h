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

#ifndef FUNKALPHABETPLUGIN_H
#define FUNKALPHABETPLUGIN_H

#include <QObject>
#include <QtPlugin>

#include "Funkalphabet.h"
#include "../../Klient/Quellen/Funkpluginfabrik.h"

class Funktafel : public Funkplugin
{
	public:
			QWidget* Dialog(QWidget* eltern) Q_DECL_OVERRIDE {return new Funkalphabet(eltern);}
			const QString	Version() const Q_DECL_OVERRIDE {return QString(FUNKALPHABET_VERSION);}
			const QString	Name() const Q_DECL_OVERRIDE {return QObject::tr("Funkalphabet");}
			const QString	Beschreibung() const Q_DECL_OVERRIDE {return QObject::tr("Das Funkalphabet.");}
};

class Funkalphabetplugin :public QObject, Funkpluginfabrik
{
	Q_OBJECT
	Q_PLUGIN_METADATA(IID "de.terrortux.katlin.Funkpluginfabrik")
	Q_INTERFACES(Funkpluginfabrik)

	public:
			Funkplugin	*funkplugin(QObject *) Q_DECL_OVERRIDE {return new Funktafel();}
};

#endif // FUNKALPHABETPLUGIN_H
