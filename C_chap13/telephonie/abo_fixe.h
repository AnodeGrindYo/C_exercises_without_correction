/**
 * \file abo_fixe.h
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

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#ifndef ABO_FIXE_H
#define ABO_FIXE_H

/**
 * \struct abo_fixe
 * \brief Stocke ce qui concerne l'abonnement fixe
 *
 * un abonnement pour téléphone fixe représentera : 
 * - un numéro de téléphone fixe (10 chiffres) stocké dans int num_fixe[10]
 * - si le client veut un abonnement internet sur une ligne (un booléen bool internet;)
 * - ainsi que le montant mensuel de l’abonnement fixe stocké dans double prix_abo_fixe.
 */
typedef struct abo_fixe
{
	int num_fixe[10]; /*!< numéro de téléphone fixe */
	bool internet;	/*!< si le client a un abonnement internet, prend true, sinon prend false */
	double prix_abo_fixe; /*! prix mensuel en euro de l'abonnement fixe */
}t_abo_fixe;

/**
 * \fn void saisir_abo_fixe(t_abofixe *fixe);
 * \brief Fonction de saisie d'un abonnement fixe. Met à jour la variable t_abofixe_fixe
 *
 * \param t_abofixe *fixe Stocke ce qui concerne l'abonnement fixe
 * \return void.
 */
void saisir_abo_fixe(t_abo_fixe *fixe);

#endif