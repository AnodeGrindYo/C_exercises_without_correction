/**
 * \file abo_fixe.c
 * \brief concerne l'abonnement fixe.
 * \author Adrien Godoy
 * \version 0.1
 * \date 17 janvier 2017
 *
 * un abonnement pour téléphone fixe représentera : 
 * - un numéro de téléphone fixe (10 chiffres) stocké dans int num_fixe[10]
 * - si le client veut un abonnement internet sur une ligne (un booléen bool internet;)
 * - ainsi que le montant mensuel de l’abonnement fixe stocké dans double prix_abo_fixe.
 * 
 * on peut saisir l'abonnement fixe à l'aide de la fonction
 * void saisir_abo_fixe(t_abofixe *fixe);
 *
 */
#include "abo_fixe.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


/**
 * \fn void saisir_abo_fixe(t_abofixe *fixe);
 * \brief Fonction de saisie d'un abonnement fixe. Met à jour la variable t_abofixe_fixe
 *
 * \param t_abofixe *fixe Stocke ce qui concerne l'abonnement fixe
 * \return void.
 */
void saisir_abo_fixe(t_abo_fixe *fixe)
{
	int test;
	printf("\nNumero fixe : ");
	//fscanf(stdin, "%d", &fixe->num_fixe);
	fscanf(stdin, "%d", &test);
	fixe->num_fixe = test;
	getchar();
	printf("%d\n", test);
	printf("%s ==> %d\n", __FUNCTION__, fixe->num_fixe);
	printf("\nPrix mensuel (ttc) abonnement fixe : ");
	fscanf(stdin, "%lf", &fixe->prix_abo_fixe);
	getchar();
	// limite à deux chiffres après la virgule
	fixe->prix_abo_fixe = (floor(fixe->prix_abo_fixe*100))/100;
	printf("%s ==> %lf\n", __FUNCTION__, fixe->prix_abo_fixe);
}