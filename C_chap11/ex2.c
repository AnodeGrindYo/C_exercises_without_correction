#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRMAX 26

typedef struct
{
	int jour;
	int mois;
	int an;
} date;

typedef struct
{
	char prenom[STRMAX];
	char nom[STRMAX];
	date ddn;
} individu;

// compte les lignes
int comptedonnees(char filenem[], int *nb_lignes); 
// récupère les données du fichier dans un tableau de structures de données
int lirefscanf(char filenem[], individu *gens, int nb_lignes);
/* écrit  les données contenues dans le tableau dans un fichier excel 
   (il s'agit d'un fichier dans lequel les données sont séparées par des ; 
   et les dates représentées au format jj/mm/aaaa) */
int ecrirefprintf(individu *gens, int nb_lignes);
// écrit les données au format binaire
int ecrirefwrite(individu *gens, int nb_lignes, char *nom_fichier_bin);
// lit les données au format binaire
int ecrirefread(char nom_fichier_bin[], int nb_lignes);
void verif_tab_individu(individu *gens, int nb_lignes);


int main(int argc, char *argv[])
{
	int appel;
	int nb_lignes;
	char nom_fichier_bin[128];
	
	//printf("\n%s\n", argv[1]);
	appel = comptedonnees(argv[1], &nb_lignes);
	// creation tableau de structures individu a la bonne taille
	individu gens[nb_lignes];
	printf("%d", nb_lignes);

	appel = lirefscanf(argv[1], gens, nb_lignes);
	verif_tab_individu(gens, nb_lignes);
	
	appel = ecrirefprintf(gens, nb_lignes);

	appel = ecrirefwrite(gens, nb_lignes, nom_fichier_bin);

	printf("%s", nom_fichier_bin);

	appel = ecrirefread(nom_fichier_bin, nb_lignes);
	return 0;
}

// version avec fscanf
// compte les lignes
int comptedonnees(char filenem[], int *nb_lignes)
{
	int lignes = 0;
	char caractere;
	individu temp;

	printf("\nFonction comptedonnees\n----------------------\n");

	FILE *ptr_fichier;
	ptr_fichier = fopen(filenem, "r");
	
	if (ptr_fichier == NULL)
	{
		perror("\n/!\\le fichier est vide\n");
		return(-1);
	}

	while(fscanf(ptr_fichier,"%s %s %d %d %d", temp.nom, temp.prenom, &temp.ddn.jour, &temp.ddn.mois, &temp.ddn.an)!=0)
	{
		printf("%s %s %d %d %d\n", temp.nom, temp.prenom, temp.ddn.jour, temp.ddn.mois, temp.ddn.an);
		lignes++;
		if (feof(ptr_fichier))
			break;
	}

	fclose (ptr_fichier);
	printf("\nNombre de lignes : %d\n", lignes);
	*nb_lignes = lignes;

	return 0;
}

// récupère les données du fichier dans un tableau de structures de données
int lirefscanf(char filenem[], individu *gens, int nb_lignes)
{
	int i;

	printf("\nFonction lirefscanf\n----------------------\n");

	FILE *ptr_fichier;
	ptr_fichier = fopen(filenem, "r");

	if (ptr_fichier == NULL)
	{
		perror("\n/!\\erreur lirefscanf\n");
		return(-1);
	}

	for (i = 0; i < nb_lignes; i++)
	{
		fscanf(ptr_fichier,"%s %s %d %d %d", 
			gens[i].nom, 
			gens[i].prenom, 
			&gens[i].ddn.jour, 
			&gens[i].ddn.mois, 
			&gens[i].ddn.an);
		// verification
		printf("\ninscrit a l'indice %d : %s %s %d %d %d\n", 
			i, 
			gens[i].nom, 
			gens[i].prenom, 
			gens[i].ddn.jour, 
			gens[i].ddn.mois, 
			gens[i].ddn.an);
	}
	fclose (ptr_fichier);
}

void verif_tab_individu(individu *gens, int nb_lignes)
{
	int i;

	printf("\nVerification tableau :\n----------------------\n");
	for (i = 0; i < nb_lignes; i++)
	{
		printf("\ninscrit a l'indice %d : %s %s %d %d %d\n", 
			i, 
			gens[i].nom, 
			gens[i].prenom, 
			gens[i].ddn.jour, 
			gens[i].ddn.mois, 
			gens[i].ddn.an);
	}
}

/* écrit  les données contenues dans le tableau dans un fichier excel 
   (il s'agit d'un fichier dans lequel les données sont séparées par des ; 
   et les dates représentées au format jj/mm/aaaa) */
int ecrirefprintf(individu *gens, int nb_lignes)
{
	char nomfichier[128];
	int i;

	printf("\nNom du fichier a creer (sans extension):\n");
	scanf("%s", nomfichier);
	strcat(nomfichier, ".xls");

	// creation/ouverture du fichier
	FILE *ptr_fichier;
	ptr_fichier = fopen(nomfichier, "w");

	if (ptr_fichier == NULL)
	{
		perror("\n/!\\erreur ecrirefprintf\n");
		return(-1);
	}

	// écriture
	for(i=0; i<nb_lignes; i++)
	{
		fprintf(ptr_fichier, "%s;%s;%d/%d/%d;\n", 
			gens[i].nom, 
			gens[i].prenom, 
			gens[i].ddn.jour, 
			gens[i].ddn.mois, 
			gens[i].ddn.an);
	}
	fclose (ptr_fichier);
}

int ecrirefwrite(individu *gens, int nb_lignes, char *nom_fichier_bin)
{
	char nomfichier[128];
	int i;

	printf("\nNom du fichier binaire a creer :\n");
	scanf("%s", nomfichier);
	//nom_fichier_bin = nomfichier;
	strcpy(nom_fichier_bin, nomfichier);
	// creation/ouverture du fichier
	FILE *ptr_fichier;
	ptr_fichier = fopen(nomfichier, "w");

	if (ptr_fichier == NULL)
	{
		perror("\n/!\\erreur ecrirefwrite\n");
		return(-1);
	}

	printf("test");
	// écriture
	/*for(i=0; i<nb_lignes; i++)
	{*/
		fwrite(gens, sizeof(individu), nb_lignes, ptr_fichier);
	//}
	fclose (ptr_fichier);
	return 0;
}

// lit les données au format binaire
int ecrirefread(char nom_fichier_bin[], int nb_lignes)
{
	int i;
	individu temp[nb_lignes];
	// ouverture du fichier
	FILE *ptr_fichier;
	ptr_fichier = fopen(nom_fichier_bin, "r");

	if (ptr_fichier == NULL)
	{
		perror("\n/!\\erreur ecrirefread\n");
		return(-1);
	}

	fread(temp, sizeof(individu), nb_lignes, ptr_fichier); // bug ici, incompatible type arg 1
	fclose (ptr_fichier);

	for (i = 0; i<nb_lignes; i++)
	{
		printf("%s %s %d/%d/%d", 
			temp[i].nom, 
			temp[i].prenom, 
			temp[i].ddn.jour, 
			temp[i].ddn.mois, 
			temp[i].ddn.an);
	}
}