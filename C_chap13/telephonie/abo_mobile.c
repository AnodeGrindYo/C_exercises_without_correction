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
	printf("\nNumero mobile : ");
	fscanf(stdin, "%d", &mobile->num_mobile);

	printf("\nPrix mensuel (ttc) forfait mobile : ");
	fscanf(stdin, "%f", &mobile->prix_abo_mobile);
	return;
}