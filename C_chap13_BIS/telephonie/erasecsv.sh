#!/bin/bash
echo "cherche si le fichier save.csv existe"
if [ -f save.csv ] 
then 
   rm -r save.csv
   echo "Fichier save.csv efface"
else
	echo "Fichier save.csv non trouve"
fi