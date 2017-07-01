/**
 * \file client.c
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
#include "client.h"

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
void saisir_client(t_client *client)
{
	int choix;
	int i;
	// saisie du nom
	printf("\nNom : ");
	fgets(client->nom, NOM_MAX, stdin);
	//getchar(); // récupère la touche entrée
	client->nom[strlen(client->nom)-1] = '\0';
	// suppression des espaces éventuels
	for (i = 0; i < strlen(client->nom)-1; i++)
	{
		if (client->nom[i] == ' ')
			client->nom[i] = '_';
	}
	// vérification de la saisie
	printf("%s ==> %s\n", __FUNCTION__, client->nom);
	// saisie de l'adresse
	printf("\nAdresse : ");
	fgets(client->adresse, ADRESS_MAX, stdin);
	//getchar(); // récupère la touche entrée
	client->adresse[strlen(client->adresse)-1] = '\0';
	// suppression des espaces éventuels
	for (i = 0; i < strlen(client->adresse)-1; i++)
	{
		if (client->adresse[i] == ' ')
			client->adresse[i] = '_';
	}
	//vérification de la saisie
	printf("%s ==> %s\n", __FUNCTION__, client->adresse);
	// sous-menu saisie client
	do
	{
		printf("\n1 - Ni fixe ni mobile");
		printf("\n2 - Client mobile seulement");
		printf("\n3 - Client fixe seulement");
		printf("\n4 - Client fixe et mobile sans internet");
		printf("\n5 - Client fixe, mobile et internet\n");
		fscanf(stdin, "%d", &choix);
		getchar();
		if (choix != 1 &&
			choix != 2 &&
			choix != 3 &&
			choix != 4 &&
			choix != 5)
		{
			printf("\nChoix invalide\n");
		}
	} while (choix != 1 &&
			 choix != 2 &&
			 choix != 3 &&
			 choix != 4 &&
			 choix != 5);

	switch (choix)
	{
		case 1: // n'a aucune offre
		{
			client->fixe = false;
			client->abofixe.internet = false;
			client->mobile = false;
			break;
		}
		case 2: // a seulement une offre mobile
		{
			client->fixe = false;
			client->abofixe.internet = false;
			client->mobile = true;
			saisir_abo_mobile (&client->abomobile);
			break;
		}
		case 3: // a seulement une offre fixe
		{
			client->fixe = true;
			client->abofixe.internet = false;
			client->mobile = false;
			saisir_abo_fixe(&client->abofixe);
			break;
		}
		case 4: // a une offre mobile et fixe SANS internet
		{
			client->fixe = true;
			client->abofixe.internet = false;
			client->mobile = true;
			saisir_abo_fixe(&client->abofixe);
			saisir_abo_mobile (&client->abomobile);
			// vérification de la saisie
			break;
		}
		case 5: // a une offre mobile et fixe AVEC internet
		{
			client->fixe = true;
			client->abofixe.internet = true;
			client->mobile = true;
			saisir_abo_fixe(&client->abofixe);
			saisir_abo_mobile (&client->abomobile);
			break;
		}
		default:
		{
			perror("\nsaisir_client => ERROR : choix invalide non intercepte\n");
			exit (-1);
		}
	}
	// vérification de la saisie mobile
	printf("\n%s ==> mobile : %s %d %lf\n", 	__FUNCTION__, 
									client->abomobile.modele_mobile, 
									client->abomobile.num_mobile, 
									client->abomobile.prix_abo_mobile);
	// vérification de la saisie fixe
	printf("\n%s ==> fixe : %d %lf\n", 	__FUNCTION__, 
									client->abofixe.num_fixe,
									client->abofixe.prix_abo_fixe);
	return;
}
