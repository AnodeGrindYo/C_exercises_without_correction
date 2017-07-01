/**
 * \file menu.c
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
#include "menu.h"

extern char save[]; // variable globale définie dans le main

/**
 * \fn void menu_gestionnaire();
 * \brief menu du programme
 *
 * \param aucun
 * \return void.
 */
void menu_gestionnaire()
{
	int choix;
	do
	{
		printf("\n1 - saisir les clients");
		printf("\n2 - afficher tous les clients");
		printf("\n0 - quitter\n");
		fscanf(stdin, "%d", &choix);
		getchar(); // pour la touche entrée
		if (choix != 0 &&
				choix != 1 &&
				choix != 2)
			printf("\nJe n'ai pas compris\n");
	} while (	choix != 0 &&
				choix != 1 &&
				choix != 2);
	switch (choix)
	{
		case 0:
		{
			printf ("\nAu revoir !\n");
			return;
		}
		case 1:
		{
			saisir_plusieurs_clients_export_csv(*save, strlen(save));
			menu_gestionnaire();
			break;
		}
		case 2:
		{
			lire_csv(*save, strlen(save));
			menu_gestionnaire();
			break;
		}
		default:
		{
			perror("\nmenu_gestionaire => ERROR");
			exit(1);
		}
	}
}
