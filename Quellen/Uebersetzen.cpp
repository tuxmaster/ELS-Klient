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

#include "Uebersetzen.h"

Uebersetzen::Uebersetzen(QObject *eltern, const QAbstractTableModel *tabelle ) :	QObject(eltern)
{
	K_Hashtabelle=new QHash<QChar,QString>;
	K_Datenmodell=tabelle;
	connect(tabelle,SIGNAL(modelReset()),this,SLOT(DatenGeaendert()));
}
Uebersetzen::~Uebersetzen()
{
	delete K_Hashtabelle;
}
void Uebersetzen::Loslegen(const QString &text)
{
	K_Wortliste.clear();
	QChar Buchstabe;
	for(int Zeichen=0;Zeichen<text.size();Zeichen++)
	{
		Buchstabe=text.at(Zeichen);
		if(!Buchstabe.isLetter())
			K_Wortliste.append(Buchstabe);
		else
		{
			K_Wortliste.append(K_Hashtabelle->operator [](Buchstabe.toUpper()));
		}
	}
	Q_EMIT Fertig(K_Wortliste);
}
void Uebersetzen::DatenGeaendert()
{
	QChar Schluessel;
	QString Wert;
	for(int Eintrag=0;Eintrag<K_Datenmodell->rowCount();Eintrag++)
	{
		if(K_Datenmodell->data(K_Datenmodell->index(Eintrag,0)).toString().size()==1)
		{
			Schluessel=K_Datenmodell->data(K_Datenmodell->index(Eintrag,0)).toString().at(0);
			Wert=K_Datenmodell->data(K_Datenmodell->index(Eintrag,1)).toString();
			//Für einige gibt es keine Entsprchung.
			if(!Wert.isEmpty())
				K_Hashtabelle->insert(Schluessel,Wert);
		}
	}
}
