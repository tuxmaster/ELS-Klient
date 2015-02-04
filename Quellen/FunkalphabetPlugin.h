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

#include <QDesignerCustomWidgetInterface>

class FunkalphabetPlugin: public QObject, public QDesignerCustomWidgetInterface
{

	Q_OBJECT
	Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QDesignerCustomWidgetInterface" FILE "FunkalphabetDesigner.json")
	Q_INTERFACES(QDesignerCustomWidgetInterface)

	public:
		FunkalphabetPlugin(QObject* eltern=0);
		 void		initialize(QDesignerFormEditorInterface *kern);
		 bool		isInitialized()const{return K_geladen;}
		 bool		isContainer()const{return false;}
		 QString	name()const{return "Funkalphabet";}
		 QString	group()const{return "Display Widgets";}
		 QString	toolTip()const{return "Anzeige des Funkalphabetes";}
		 QString	whatsThis()const{return trUtf8("Zeigt es an oder übersetzt Text in dieses.");}
		 QString	domXml() const;
		 QString	includeFile() const{return "DlgFunkalphabet.h";}
		 QIcon		icon()const{return QIcon();}
		 QWidget*	createWidget(QWidget *eltern);

	private:
		bool		K_geladen;

};

#endif // FUNKALPHABETPLUGIN_H
