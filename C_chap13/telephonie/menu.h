/**
 * \file menu.h
 * \brief menu principal du programme.
 *
 * \author Adrien Godoy
 * \version 0.1
 * \date 17 janvier 2017
 *
 * les 3  choix du menu sont:
 * - saisir un client (dans ce cas, appel de la fonction saisir_plusieurs_clients_export_csv 
 *   puis retour au menu)
 * - afficher tous les clients (dans ce cas, appel de la fonction lire_csv
 *   puis retour au menu)
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "abo_fixe.h"
#include "abo_mobile.h"
#include "client.h"
#include "gestion_client.h"

#ifndef MENU_H
#define MENU_H
/**
 * \fn void menu_gestionnaire();
 * \brief menu du programme
 *
 * \param aucun
 * \return void.
 */
void menu_gestionnaire();

#endif
