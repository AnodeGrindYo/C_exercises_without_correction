#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "patient.h"

int main(int argc, char *argv[])
{
	int choix;
	t_file_attente *debut = NULL;
	

	// menu
	while (1)
	{
		do
		{
			printf ("\n1 - Ajouter dans la file");
			printf ("\n2 - Afficher la file");
			printf ("\n3 - Patient en consultation");
			printf ("\n4 - Supprimer un patient de la file d'attente");
			printf ("\n0 - Sortir\n");
			scanf("%d", &choix);
		} while (	choix != 0 &&
					choix != 1 &&
					choix != 2 &&
					choix != 3 &&
					choix != 4);
			switch (choix)
			{
				case 0: 
				{
					return (0);
				}
				case 1:
				{
					ajout_queue(&debut);
					break;
				}
				case 2:
				{
					afficher_liste(debut);
					break;
				}
				case 3:
				{
					suppr_tete(&debut);
					break;
				}
				case 4:
				{
					suppr_patient(&debut);
				}
				default:
				{
					printf("\nLe truc, pour voler, c'est de se jeter au sol et de rater son coup.\n");
					break;
				}
			}
			compter_patient(debut);
			getchar();
		}
		return 0;

}