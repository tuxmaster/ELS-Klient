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

#ifndef UEBERSETZEN_H
#define UEBERSETZEN_H

#include <QObject>
#include <QtCore>

class Uebersetzen : public QObject
{
		Q_OBJECT
	public:
		explicit					Uebersetzen(QObject *eltern,const QAbstractTableModel *tabelle);
									~Uebersetzen();

	public Q_SLOTS:
		void						Loslegen(const QString &text);
	Q_SIGNALS:
		void						Fertig(QStringList ergebnis);
	private Q_SLOTS:
		void						DatenGeaendert();
	private:
		QStringList					K_Wortliste;
		QHash<QChar,QString>		*K_Hashtabelle;
		const QAbstractTableModel	*K_Datenmodell;

};

#endif // UEBERSETZEN_H
