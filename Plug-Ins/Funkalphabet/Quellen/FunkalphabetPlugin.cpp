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

#include <QtPlugin>

#include "Funkalphabet.h"
#include "FunkalphabetPlugin.h"

FunkalphabetPlugin::FunkalphabetPlugin(QObject *eltern):QObject(eltern)
{
	K_geladen=false;
}
void FunkalphabetPlugin::initialize(QDesignerFormEditorInterface * /* kern */)
{
	if(K_geladen)
		return;
	K_geladen=true;
}
QWidget* FunkalphabetPlugin::createWidget(QWidget *eltern)
{
	return new Funkalphabet(eltern);
}
QString FunkalphabetPlugin::domXml() const
{
	return "<ui language=\"c++\">\n"
			   " <widget class=\"Funkalphabet\" name=\"Funkalphabet\">\n"
			   "  <property name=\"geometry\">\n"
			   "   <rect>\n"
			   "    <x>0</x>\n"
			   "    <y>0</y>\n"
			   "    <width>845</width>\n"
			   "    <height>548</height>\n"
			   "   </rect>\n"
			   "  </property>\n"
			   " </widget>\n"
			   "</ui>\n";
}
