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

#ifndef PLUGINVERSION_H
#define PLUGINVERSION_H

#include <QtCore>

class Pluginversion
{
	public:
		enum Type {Formular};
		Pluginversion();
		Pluginversion(Type type,const QString& name,const QString& beschreibung,const QString& version)
		{
			K_Type=type;K_Name=name;K_Beschreibung=beschreibung;K_Version=version;
		}
		const Type&		Art()const{return K_Type;}
		const QString&	Name() const {return K_Name;}
		const QString&	Version()const {return K_Version;}
		const QString&	Beschreibung() const {return K_Beschreibung;}

	private:
		Type			K_Type;
		QString			K_Name;
		QString			K_Version;
		QString			K_Beschreibung;
};

#endif // PLUGINVERSION_H