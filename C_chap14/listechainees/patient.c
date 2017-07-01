#include "patient.h"

// affiche la liste de tous les patients
void afficher_liste(t_file_attente *debut)
{
	int i = 1;
	// position est le patient que l'on va afficher
	// on se positionne au premier patient
	t_file_attente *position = debut;

	while( position != NULL)
	{
		printf("\n#ticket %d : %.20s %.20s %.10d", i,
											position->patient.nom, 
											position->patient.prenom, 
											position->patient.num_secu);
		i++;
		position = position->suivant;
	}
	printf("\n");
}


// ajoute un patient à la fin de la liste
void ajout_queue(t_file_attente **debut)
{
	// on positionne le pointeur au début de la liste
	t_file_attente *position = *debut;

	t_file_attente *nouveau; // espace mémoire où sera stocké le nouveau patient

	int nbre_patients = 0;
	int i;

	// reservation de l'espace mémoire pour un nouveau wagon
	nouveau = (t_file_attente *)malloc(sizeof(t_file_attente));

	if (nouveau == NULL)
	{
		printf ("\nImpossible d'ajouter un nouveau patient\n");
		return;
	}
	else
	{
		// saisie des donnes
		printf ("\nNom : ");
		scanf("%s", nouveau->patient.nom);
		getchar();
		printf("\nPrenom : ");
		scanf("%s", nouveau->patient.prenom);
		getchar();
		printf("\nNumero de securite sociale : ");
		scanf("%d", &nouveau->patient.num_secu);
		// conversion des noms en majuscule :
		// nom du patient
		for (i = 0; i<strlen(nouveau->patient.nom); i++)
		{
			nouveau->patient.nom[i] = toupper(nouveau->patient.nom[i]);
		}
		// prenom du patient
		for (i = 0; i<strlen(nouveau->patient.prenom); i++)
		{
			nouveau->patient.nom[i] = toupper(nouveau->patient.prenom[i]);
		}
		// le nouveau patient devient le dernier
		nouveau->suivant = NULL;
		// cas particulier où la file d'atente est vide
		if (position == NULL)
		{
			*debut = nouveau;
			return;
		}
		// si au moins un patient est dans la file d'attente
		else
		{
			nbre_patients = 1;

			while (position->suivant != NULL)
			{
				// on compte les patients juste qu'au dernier
				nbre_patients++;
				position = position->suivant;
			}
		
			// celui qui était précédemment le dernier patient pointe vers le nouveau
			position->suivant = nouveau; // SEGMENTATION FAULT ICI
		}
	}
}


// supprime un patient de la tête de file
void suppr_tete(t_file_attente **debut)
{
	t_file_attente *tete = *debut;
	t_file_attente *patient_suppr = *debut;
	
	// suppression du patient en tête

	// cas où il n'y a pas de patient à supprimer
	if (tete->suivant == NULL)
	{
		printf("\nLa liste d'attente est vide\n");
		return;
	}
	// cas où il y a au moins un patient
	else
	{
		// le patient à supprimer est le premier
		patient_suppr = *debut;
		// sle second patient devient le premier de la ligne
		*debut = tete->suivant;
		printf("\nsuppresion de %s %s\n", patient_suppr->patient.nom, patient_suppr->patient.prenom);
		free(patient_suppr);
	}
}
// compte les patients dans la file d'attente
// retourne le nombre de patients dans la file d'attente
int compter_patient(t_file_attente *debut)
{
	t_file_attente *position = debut;
	int i = 0;

	while(position != NULL)
	{
		i++;
		position = position->suivant;
	}
	printf("\nNombre de passant : %d\n", i);
	return i;
	
}
// supprime un patient de la liste
int suppr_patient(t_file_attente **debut)
{
	t_file_attente *position = *debut;
	t_file_attente *suppr = position->suivant;
	char wanted[26];
	char reponse;

	int i;
	// l'utilisateur entre le nom de la personne recherchée
	printf("\nNom du patient a retirer de la file d'attente :\n");
	scanf("%s", wanted);
	// conversion du nom entré en majuscule
	for (i = 0; i < strlen(wanted); i++)
	{
		wanted[i] = toupper(wanted[i]);
	}
	// comparaison avec les noms des patients
	// cas où il n'y a aucun patient dans la file d'attente
	if (position == NULL)
	{
		printf("\nFile d'attente vide\n");
	}
	else
	{
		while (suppr != NULL)
		{
			if (strcmp(suppr->patient.nom, wanted) == 0)
			{
				printf("\n ==> %s %s\n", suppr->patient.nom, suppr->patient.prenom);
				printf("Supprimer ? (y/N)\n");
				scanf("%c", &reponse);
				reponse = toupper(reponse);
				if (reponse == 'Y')
				{
					// suppression du patient
					if (position->suivant->suivant != 0)
					{
						position = position->suivant->suivant;
					}
					free(suppr);
					printf("\nPatient supprime\n");
				}

			}
			else
			{
				position = position->suivant;
				suppr = position->suivant;
			}
		}
	}
}