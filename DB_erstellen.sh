#!/bin/bash
Datei=Funkalphabet.dat
rm -f $Datei 2>/dev/null
sqlite3 $Datei < Funkalphabet.sql
