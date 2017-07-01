#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_patient
{
	char nom[26];
	char prenom[26];
	int num_secu;
}t_patient;

typedef struct s_file_attente
{
	t_patient patient;
	struct s_file_attente *suivant;
}t_file_attente;

// affiche la liste de tous les patients
void afficher_liste(t_file_attente *debut);
// ajoute un patient à la fin de la liste
void ajout_queue(t_file_attente **debut);
// supprime un patient de la tête de file
void suppr_tete(t_file_attente **debut);
// compte les patients dans la file d'attente
int compter_patient(t_file_attente *debut);
// supprime un patient de la liste
int suppr_patient(t_file_attente **debut);