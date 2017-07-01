/**
 * \file gestion_client.h
 * \brief permet d'inscrire plusieurs clients dans le fichier de sauvegarde
 *		  et de lire le fichier de sauvegarde.
 *
 * \author Adrien Godoy
 * \version 0.1
 * \date 17 janvier 2017
 *
 * gestion des clients et de leur sauvegarde dans le fichier save.csv
 * 
 * on peut saisir plusieurs clients dans un fichier client.csv à l'aide
 * de la fonction void saisir_plusieurs_clients_export_csv(char *nomfichier, int longueur_nom_fichier)
 * 
 * on peut lire le fichier client.csv à l'aide de la fonction
 * int lire_csv(char *nomfichier, int longueur_nom_fichier)
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include "abo_fixe.h"
#include "abo_mobile.h"
#include "client.h"

#ifndef GESTION_CLIENT_H
#define GESTION_CLIENT_H

/**
 * \fn void saisir_plusieurs_clients(char *nomfichier, int longueur_nom_fichier);
 * \brief Fonction de saisie de plusieurs clients. boucle faisant appel à void saisir_client(t_client *client)
 *  et mettant à jour le fichier clients.csv.
 *
 * \param aucun
 * \return void.
 */
void saisir_plusieurs_clients_export_csv();

/**
 * \fn int lire_csv(char *nomfichier, int longueur_nom_fichier);
 * \brief Fonction de saisie de plusieurs clients. boucle faisant appel à void saisir_client(t_client *client)
 *  et mettant à jour le fichier clients.csv.
 *
 * \param aucun
 * \return void.
 */
int lire_csv();

#endif
