#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAXSTR 64

typedef struct
{
	char nom[MAXSTR];
	int duree;
	struct tm date;
	
}EmissionTV;

void SaisirEmission(EmissionTV *emission);
void AfficherEmission(EmissionTV emission);
int NombreEmission();
void SaisirTableauEmission(EmissionTV *programme, int nb_saisies);
void AfficherTableauEmission(EmissionTV *programme, int nb_saisies);
int ExportCSV(EmissionTV *programme, int nb_saisies);
int LireCSV(char *fichier_csv, int taille_nom_fichier);

int main(int argc, char *argv[])
{
	int appelfonction;
	EmissionTV emission;
	EmissionTV *programme = NULL;
	int nb_saisies;
	char *fichier_csv = "save.csv";
	//SaisirEmission(&emission);
	//AfficherEmission(emission);
	nb_saisies = NombreEmission();
	programme = malloc(nb_saisies*sizeof(EmissionTV));
	SaisirTableauEmission(programme, nb_saisies);
	AfficherTableauEmission(programme, nb_saisies);
	appelfonction = ExportCSV(programme, nb_saisies);
	if (appelfonction == -1)
		perror("\nERREUR EXPORTATION CSV");
	appelfonction = LireCSV(fichier_csv, strlen(fichier_csv));
	if (appelfonction == -1)
		perror("\nERREUR LECTURE CSV");
	return 0;
}

void SaisirEmission(EmissionTV *emission)
{
	int jour;
	int mois;
	int an;
	int heure;
	int min;

	// saisie du nom de l'emission
	printf("\nNom de l'emission (sans espace) : \n");
	scanf("%s", emission->nom);
	getchar();
	// saisie de la durée
	printf("Duree en minutes : \n");
	scanf("%d", &emission->duree);
	getchar();
	// saisie de la date
	printf("Date de diffusion (jj/mm/aaaa) :\n");
	scanf("%d/%d/%d", &jour, &mois, &an);
	getchar();
	// ajustement de la date au format struct tm et assignation
	mois--;
	an-=1900;
	emission->date.tm_mday = jour;
	emission->date.tm_mon = mois;
	emission->date.tm_year = an;
	// saisie de l'heure de diffusion
	printf("Horaire de diffusion au format 24h (hh:mm) :\n");
	scanf("%d:%d", &emission->date.tm_hour, &emission->date.tm_min);
	getchar();
}

void AfficherEmission(EmissionTV emission)
{
	printf("%*s  %.3d min. %.2d/%.2d/%.4d        %.2d:%.2d\n", MAXSTR, emission.nom,
										 						     emission.duree, 
										 						     emission.date.tm_mday,
										 						     emission.date.tm_mon+1,
										 						     emission.date.tm_year+1900,
										 						     emission.date.tm_hour,
										 						     emission.date.tm_min);
}

int NombreEmission()
{
	int nb_emissions;
	do
	{
		printf("\nNombre d'emissions a saisir : ");
		scanf("%d", &nb_emissions);
		if (nb_emissions > 0)
			return nb_emissions;
	} while (nb_emissions <= 0);
}

void SaisirTableauEmission(EmissionTV *programme, int nb_saisies)
{
	int i;
	for (i = 0; i < nb_saisies; i++)
	{
		SaisirEmission(&programme[i]);
	}
}

void AfficherTableauEmission(EmissionTV *programme, int nb_saisies)
{
	int i;
	char nom_emission[] = "Nom de l'emission";
	int nb_espaces = MAXSTR - strlen(nom_emission);

	// en-têtes du tableau
	// affichage du bon nombre d'espaces pour la colonne nom de l'emission
	for(i = 0; i < nb_espaces; i++)
	{
		printf(" ");
	}
	printf("%s ", nom_emission);
	printf("    Duree Date de diffusion Heure\n");
	for (i = 0; i <= MAXSTR; i++)
	{
		printf("-");
	}
	printf("---------------------------------\n");

	// affichage du tableau d'emission
	for (i = 0; i < nb_saisies; i++)
	{
		AfficherEmission(programme[i]);
		printf("\n");
	}
}

int ExportCSV(EmissionTV *programme, int nb_saisies)
{
	char nomfichier[] = "save.csv";
	int i;

	/* creation du fichier */
	FILE *ptr_fichier;
	ptr_fichier = fopen(nomfichier, "a");

	// gestion erreur
	if(ptr_fichier == NULL)
	{
		perror("\nERREUR : ExportCSV => ptr_fichier is NULL\n");
		return (-1);
	}
	printf("\nExportation dans save.csv");
	for (i = 0; i < nb_saisies; i++)
	{
		/* une ligne se compose de : 	nom du programme (string), 
										duree (int),
										jour (int),
										mois (int),
										année (int),
										heure (int),
										minute (int).
		*/
		fprintf(ptr_fichier, "%s ; %d ; %d ; %d ; %d ; %d ; %d\n", 	programme[i].nom, 
														programme[i].duree, 
														programme[i].date.tm_mday, 
														programme[i].date.tm_mon,
														programme[i].date.tm_year,
														programme[i].date.tm_hour,
														programme[i].date.tm_min);
	}
	fclose(ptr_fichier);
	printf("\nFin de l'exportation\n");
	return 0;
}


int LireCSV(char *fichier_csv, int taille_nom_fichier)
{
	EmissionTV *TV = NULL;
	int i = 0;
	int ligne = 0;
	char tamp[512];

	FILE *ptr_fichier;

	ptr_fichier = fopen(fichier_csv, "r");

	// compte le nombre de lignes
	while(!feof(ptr_fichier))
	{
		fgets(tamp, 512, ptr_fichier);
		ligne++;
	}
	fclose (ptr_fichier);
	ligne--;

	ptr_fichier = fopen(fichier_csv, "r");
	printf("\nNombre de lignes : %d\n", ligne);
	TV = malloc((ligne-1)*sizeof(EmissionTV));

	if(ptr_fichier == NULL)
	{
		perror("\nERREUR : LireCSV => ptr_fichier is NULL\n");
		return (-1);
	}

	printf("\nRecuperation du fichier %s ...\n", fichier_csv);
	while (!feof(ptr_fichier))
	{
		fscanf(ptr_fichier, "%s ; %d ; %d ; %d ; %d ; %d ; %d\n",
			TV[i].nom,
			&TV[i].duree,
			&TV[i].date.tm_mday,
			&TV[i].date.tm_mon,
			&TV[i].date.tm_year,
			&TV[i].date.tm_hour,
			&TV[i].date.tm_min);
		i++;
	}
	fclose(ptr_fichier);
	printf("\nRecuperation du fichier terminée\n");
	printf("\n%s\n", TV[0].nom); // 
	AfficherTableauEmission(TV, ligne);
	return 0;
}
/*int LireCSV(char *fichier_csv) // PROBLEME UTILISATION FGETC
{
	char buffer[128];
	EmissionTV *TV;
	int ligne = 1;
	char c;
	char charNombre[10] = "";
	int i;
	FILE *ptr_fichier;

	ptr_fichier = fopen(fichier_csv, "r");

	if(ptr_fichier == NULL)
	{
		perror("\nERREUR : LireCSV => ptr_fichier is NULL\n");
		return (-1);
	}

	printf("\nRecuperation du fichier ...\n");
	while (!feof(ptr_fichier))
	{
		TV = malloc(ligne*sizeof(EmissionTV));
		// récupération du nom de l'émission
		for (i = 0; i < MAXSTR; i++)
		{
			c = fgetc(ptr_fichier);
			if (c == ';')
				break;
			else
				TV[ligne-1].nom[i] = c;
		}

		// récupération de la durée
		for (i = 0; i < 5; i++)
		{
			c = fgetc(ptr_fichier);
			if (c == ';')
				break;
			else
				charNombre[i] = c;
		}
		TV[ligne-1].duree = (int) strtol(charNombre, (char **)NULL, 10);

		// récupération du jour
		for (i = 0; i < 5; i++)
		{
			c = fgetc(ptr_fichier);
			if (c == ';')
				break;
			else
				charNombre[i] = c;
		}
		TV[ligne-1].date.tm_mday = (int) strtol(charNombre, (char **)NULL, 10);

		// récupération du mois
		for (i = 0; i < 5; i++)
		{
			c = fgetc(ptr_fichier);
			if (c == ';')
				break;
			else
				charNombre[i] = c;
		}
		TV[ligne-1].date.tm_mon = (int) strtol(charNombre, (char **)NULL, 10);

		// récupération de l'année
		for (i = 0; i < 5; i++)
		{
			c = fgetc(ptr_fichier);
			if (c == ';')
				break;
			else
				charNombre[i] = c;
		}
		TV[ligne-1].date.tm_year = (int) strtol(charNombre, (char **)NULL, 10);

		// récupération de l'heure
		for (i = 0; i < 5; i++)
		{
			c = fgetc(ptr_fichier);
			if (c == ';')
				break;
			else
				charNombre[i] = c;
		}
		TV[ligne-1].date.tm_hour = (int) strtol(charNombre, (char **)NULL, 10);

		// récupération des minutes
		for (i = 0; i < 5; i++)
		{
			c = fgetc(ptr_fichier);
			if (c == ';')
				break;
			else
				charNombre[i] = c;
		}
		TV[ligne-1].date.tm_min = (int) strtol(charNombre, (char **)NULL, 10);
		ligne++;
	}
	fclose(ptr_fichier);
	printf("\nRecuperation du fichier terminée\n");
	AfficherTableauEmission(TV, ligne);
	return 0;
}
*/