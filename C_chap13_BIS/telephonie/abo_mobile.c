/**
 * \file abo_mobile.c
 * \brief concerne l'abonnement mobile.
 * \author Adrien Godoy
 * \version 0.1
 * \date 17 janvier 2017
 *
 * un abonnement pour téléphone mobile représentera : 
 * - un modele de mobile stocké dans char modele_mobile[10]
 * - un numéro de téléphone mobile (10 chiffres) stocké dans int num_mobile[10]
 * - ainsi que le montant mensuel de l’abonnement mobile stocké dans double prix_abo_mobile.
 * 
 * on peut saisir l'abonnement mobile à l'aide de la fonction
 * saisir_abo_mobile(t_abo_mobile *mobile);
 *
 */
#include "abo_mobile.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/**
 * \fn void saisir_abo_mobile(t_abo_mobile *mobile);
 * \brief Fonction de saisie d'un abonnement mobile. Met à jour la variable t_abo_mobile mobile
 *
 * \param t_abomobile *mobile contient ce qui concerne l'abonnement mobile
 * \return void.
 */
void saisir_abo_mobile(t_abo_mobile *mobile)
{
	printf("\nModele mobile (ex: NOKIA3310) : ");
	fgets(mobile->modele_mobile, MOBIL_MODEL_MAXCHAR, stdin);
	mobile->modele_mobile[strlen(mobile->modele_mobile)-1] = '\0';
	printf("\nNumero mobile : ");
	fscanf(stdin, "%d", &mobile->num_mobile);
	// vérification de la saisie
	printf("%s ==> %d\n", __FUNCTION__, mobile->num_mobile);

	printf("\nPrix mensuel (ttc) forfait mobile : ");
	fscanf(stdin, "%lf", &mobile->prix_abo_mobile);
	// limite à deux chiffres après la virgule
	mobile->prix_abo_mobile = (floor(mobile->prix_abo_mobile*100))/100;
	// vérification de la saisie
	printf("%s ==> %lf\n", __FUNCTION__, mobile->prix_abo_mobile);
	return;
}