/**
 * \file abo_mobile.h
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

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MOBIL_MODEL_MAXCHAR 10

#ifndef ABO_MOBILE_H
#define ABO_MOBILE_H

/**
 * \struct abo_mobile
 * \brief Stocke ce qui concerne l'abonnement mobile
 *
 * un abonnement pour téléphone mobile représentera : 
 * - un modele de mobile stocké dans char modele_mobile[10]
 * - un numéro de téléphone mobile (10 chiffres) stocké dans int num_mobile[10]
 * - ainsi que le montant mensuel de l’abonnement mobile stocké dans double prix_abo_mobile.
 */
typedef struct abo_mobile
{
	char modele_mobile[MOBIL_MODEL_MAXCHAR]; /*!< le modèle de mobile (ex: NOKIA3310) */
	int num_mobile[10];	/*!< le numéro de mobile */
	double prix_abo_mobile; /*!< le prix mensuel de l'abonnement mobile */
}t_abo_mobile;

/**
 * \fn void saisir_abo_mobile(t_abo_mobile *mobile);
 * \brief Fonction de saisie d'un abonnement mobile. Met à jour la variable t_abo_mobile mobile
 *
 * \param t_abomobile *mobile contient ce qui concerne l'abonnement mobile
 * \return void.
 */
void saisir_abo_mobile(t_abo_mobile *mobile);

#endif