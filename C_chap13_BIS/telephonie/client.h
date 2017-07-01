/**
 * \file client.h
 * \brief concerne un client.
 * \author Adrien Godoy
 * \version 0.1
 * \date 17 janvier 2017
 *
 * permet de gérer:
 * - nom du client
 * - l’adresse du client (sur 100 caractères avec des espaces),
 * - un booléen qui indique s’il a prit ou pas un abonnement de téléphone fixe
 * - un abonnement de téléphone fixe
 * - un booléen qui indique s’il a prit ou pas un abonnement de téléphone portable
 * - un abonnement de téléphone portable
 * 
 * on peut saisir le client à l'aide de la fonction
 * void saisir_client(t_client *client);
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include "abo_fixe.h"
#include "abo_mobile.h"

#define NOM_MAX 26
#define ADRESS_MAX 100

#ifndef CLIENT_H
#define CLIENT_H

/**
 * \struct abo_mobile
 * \brief Stocke ce qui concerne l'abonnement mobile
 * 
 * permet de stocker:
 * - nom du client
 * - l’adresse du client (sur 100 caractères avec des espaces),
 * - un booléen qui indique s’il a prit ou pas un abonnement de téléphone fixe
 * - un abonnement de téléphone fixe
 * - un booléen qui indique s’il a prit ou pas un abonnement de téléphone portable
 * - un abonnement de téléphone portable
 */
typedef struct client
{
	char nom[NOM_MAX]; /*!< nom du client */
	char adresse[100]; /*!< adresse du client */
	bool fixe; /*!< si le client a un abo fixe */
	t_abo_fixe abofixe;
	bool mobile; /*!< si le client a un abo mobile */
	t_abo_mobile abomobile;
}t_client;

/**
 * \fn void saisir_client(t_client *client);
 * \brief Fonction de saisie d'un client. met à jour la structure t_client client.
 *		  permet aussi d'appeler les fonctions :
 *		  - void saisir_abo_mobile(t_abo_mobile *mobile),
 *		  - void saisir_abo_fixe(t_abofixe *fixe),
 *   	  suivant l'offre qu'a le client 
 *
 * \param t_client *client contient toutes les infos d'un client.
 * \return void.
 */
void saisir_client(t_client *client);

#endif