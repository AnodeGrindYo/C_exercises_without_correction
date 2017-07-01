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
#include "client.h"

extern char save[]; // variable globale définie dans le main

/**
 * \fn void saisir_plusieurs_clients(char *nomfichier, int longueur_nom_fichier);
 * \brief Fonction de saisie de plusieurs clients. boucle faisant appel à void saisir_client(t_client *client)
 *  et mettant à jour le fichier clients.csv.
 *
 * \param aucun
 * \return void.
 */
void saisir_plusieurs_clients_export_csv()
{
	t_client client;
	int choix;
	FILE *ptr_fichier;
	
	do
	{
		saisir_client(&client);
		// inscrit le client saisi dans le fichier
		ptr_fichier = fopen(save, "a");

		// gestion d'une erreur à l'ouverture du fichier en mode add
		if(ptr_fichier == NULL)
		{
			perror("\nERREUR : saisir_plusieurs_clients_export_csv => ptr_fichier is NULL\n");
			exit(-1);
		}
		// nom du client et adresse
		//fprintf(ptr_fichier, "%s ; %s ;", client.nom, client.adresse);
		// si le client a un abonnement fixe
		if (client.mobile == true) // si le client a un mobile
		{
			if (client.fixe == true) 
			{
				if (client.abofixe.internet == true) // mobile + fixe + internet
				{
					fprintf(ptr_fichier, "%s ; %s ; %d ; internet ; %f ; %s ; %d ; %f\n", 
														client.nom, 
														client.adresse, 
														&client.abofixe.num_fixe,  
														&client.abofixe.prix_abo_fixe,
														client.abomobile.modele_mobile,
														&client.abomobile.num_mobile, 
														&client.abomobile.prix_abo_mobile);
				}
				else // mobile + fixe
				{
					fprintf(ptr_fichier, "%s ; %s ; %d ; NEANT ; %f ; %s ; %d ; %f\n", 
														client.nom, 
														client.adresse, 
														&client.abofixe.num_fixe,  
														&client.abofixe.prix_abo_fixe,
														client.abomobile.modele_mobile,
														&client.abomobile.num_mobile, 
														&client.abomobile.prix_abo_mobile);
				}
			}
			else // mobile seul
			{
				fprintf(ptr_fichier, "%s ; %s ; 0 ; NEANT ; 0.0 ; %s ; %d ; %f", 
														client.nom, 
														client.adresse,   
														client.abomobile.modele_mobile,
														&client.abomobile.num_mobile, 
														&client.abomobile.prix_abo_mobile);
			}
		}
		else // pas de mobile
		{
			if (client.fixe == true) 
			{
				if (client.abofixe.internet == true) // fixe + internet
				{
					fprintf(ptr_fichier, "%s ; %s ; %d ; internet ; %f ; NEANT ; 0 ; 0.0\n", 
														client.nom, 
														client.adresse, 
														&client.abofixe.num_fixe,  
														&client.abofixe.prix_abo_fixe);
				}
				else // fixe seul
				{
					fprintf(ptr_fichier, "%s ; %s ; %d ; NEANT ; %f ; NEANT ; 0 ; 0.0\n", 
														client.nom, 
														client.adresse, 
														&client.abofixe.num_fixe,  
														&client.abofixe.prix_abo_fixe);
				}
			}
			else // ni mobile ni fixe
			{
				fprintf(ptr_fichier, "%s ; %s ; 0 ; NEANT ; 0.0 ; NEANT ; 0 ; 0.0\n", 
														client.nom, 
														client.adresse);
			}
		}
		
		fclose(ptr_fichier);
		printf("\n----------------------------------------------------------\n");
		printf("\n\n1 - nouvelle saisie");
		printf("\n0 - retour au menu principal\n");
		fscanf(stdin, "%d", &choix);
		getchar();
	} while (choix != 0 && choix != 1);
	switch (choix)
	{
		case 0:
		{
			return;
		}
		case 1:
		{
			saisir_plusieurs_clients_export_csv();
			break;
		}
		default:
		{
			perror("\nsaisir_plusieurs_clients_export_csv MENU => ERROR\n");
			exit(-1);
		}
	}
}

/**
 * \fn int lire_csv(char *nomfichier, int longueur_nom_fichier);
 * \brief Fonction de saisie de plusieurs clients. boucle faisant appel à void saisir_client(t_client *client)
 *  et mettant à jour le fichier clients.csv.
 *
 * \param *nomfichier est le nom du fichier, longueur_nom_fichier en est le nombre de caractères
 * \return void.
 */
int lire_csv(char *nomfichier, int longueur_nom_fichier)
{
	t_client client;
	FILE *ptr_fichier;
	char internaute[10];

	ptr_fichier = fopen(save, "r");

	// gestion des erreurs
	if(ptr_fichier == NULL)
	{
		perror("\nERREUR : lire_csv => ptr_fichier is NULL\n");
		exit(-1);
	}

	// lecture et impression des lignes une à une
	while(!feof(ptr_fichier))
	{
		fscanf(ptr_fichier, "%s ; %s ; %d ; %s ; %f ; %s ; %d ; %f\n",
													 	client.nom, 
														client.adresse, 
														&client.abofixe.num_fixe, 
														internaute, 
														&client.abofixe.prix_abo_fixe,
														client.abomobile.modele_mobile,
														&client.abomobile.num_mobile, 
														&client.abomobile.prix_abo_mobile);
		printf("\n----------------------------------------------------------\n");
		printf("\nnom 	: %26s\n", client.nom);
		printf("Adresse : %100s\n", client.adresse);
		// verifie si le client a un fixe
		// s'il n'en a pas, un 0 est stocké à cet emplacement dans le CSV
		if (client.abofixe.num_fixe != 0)
		{
			// impression du numéro de fixe
			printf("N° fixe : %0.10d\n", client.abofixe.num_fixe);
			if (strcmp(internaute, "NEANT") != 0)
			{
				// impression offre internet
				printf("Client internet\n");
			}
			// si le client n'a pas internet
			else
			{
				printf ("PROSPECT INTERNET\n");
			}
			// impression du prix mensuel du forfait
			printf("Forfait mensuel : %.2f€\n", client.abofixe.prix_abo_fixe);
		}
		// si le client n'a pas de fixe
		else
		{
			printf("PROSPECT FIXE ET INTERNET\n");
		}
		// si le client a un mobile
		if (strcmp(client.abomobile.modele_mobile, "NEANT") != 0)
		{
			printf("Modele mobile : %s\n", client.abomobile.modele_mobile);
			printf("Numero mobile : %0.10d\n", client.abomobile.num_mobile);
			printf("Forfait mobile : %.2f\n", client.abomobile.prix_abo_mobile);
		}
		// si le client n'a pas de mobile
		else
		{
			printf("PROSPECT MOBILE\n\n");
		}
	}
	fclose(ptr_fichier);
}
