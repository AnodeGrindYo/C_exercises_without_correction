# nom du compilateur
compilo=gcc

todo: telephonie
	bash erasecsv.sh 

telephonie: main.c abo_fixe.o abo_mobile.o client.o gestion_client.o menu.o
	echo "edition de liens"
	${compilo} main.c abo_fixe.o abo_mobile.o client.o gestion_client.o menu.o -o telephonie -lm

menu.o: menu.c abo_fixe.o abo_mobile.o client.o gestion_client.o
	${compilo} -c menu.c -lm

gestion_client.o: gestion_client.c abo_fixe.o abo_mobile.o client.o
	${compilo} -c gestion_client.c -lm

client.o: client.c abo_fixe.o abo_mobile.o
	${compilo} -c client.c -lm

abo_mobile.o: abo_mobile.c
	${compilo} -c abo_mobile.c -lm

abo_fixe.o: abo_fixe.c
	${compilo} -c abo_fixe.c -lm