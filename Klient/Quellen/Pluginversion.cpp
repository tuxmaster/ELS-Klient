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
#include "Pluginversion.h"
Pluginversion::Pluginversion(Type type, const QString &name, const QString &beschreibung, const QString &version, QObject *erweiterung)
{
	K_Type=type;K_Name=name;K_Beschreibung=beschreibung;K_Version=version;K_Erweiterung=erweiterung;
}
const QString Pluginversion::Artname() const
{
	QString nix=QObject::tr("unbekannt");
	switch (K_Type)
	{
		case Type::Formular:
			return QObject::tr("Formular");
			break;
		default:
			return nix;
			break;
	}
	return nix;
}

QDebug operator<<(QDebug debug, const Pluginversion& p)
{
	QDebugStateSaver sichern(debug);
	debug.nospace()<<"("<<p.Art()<<", "<<p.Artname()<<", "<<p.Name()<<", "<<p.Version()<<", "<<p.Beschreibung()<<")";
	return debug;
}
