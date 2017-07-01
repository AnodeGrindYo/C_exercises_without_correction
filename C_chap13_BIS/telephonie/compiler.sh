#!/bin/bash
gcc -c abo_fixe.c
gcc -c abo_mobile.c
gcc -c client.c
gcc -c gestion_client.c
gcc -c menu.c
gcc -c main.c
gcc abo_fixe.o abo_mobile.o client.o gestion_client.o menu.o main.o -o telephonie
if [ -f save.csv ] 
then 
   rm -r save.csv 
fi
echo 'compilation terminee'