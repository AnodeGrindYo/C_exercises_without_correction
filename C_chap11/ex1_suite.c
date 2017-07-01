#include <stdio.h>
#include <stdlib.h>

int intmax;

int file_creationnage(char nomfichier[]);
int tab_creation(int tab_entiers[], char nomfichier[]);
int affichationnalisation(char nomfichier[]);
int champ_par_ligne(char nomfichier[]);

int main(int argc, char *argv[])
{
	int appel;

	intmax = (int) strtol(argv[2], (char **)NULL, 10);

	appel = file_creationnage(argv[1]);

	/* creation du tableau a la bonne taille */
	int tab_entiers[intmax];
	/* remplissage du tableau */
	appel = tab_creation(tab_entiers, argv[1]);
	/* affichage du tableau */
	appel = affichationnalisation(argv[1]);
	/* affichage un champ par ligne */
	appel = champ_par_ligne(argv[1]);

	return 0;
}

int file_creationnage(char nomfichier[])
{
	/* creation du fichier */
	FILE *ptr_fichier;
	ptr_fichier = fopen(nomfichier, "w");

	// si ça ne marche pas
	if(ptr_fichier == NULL)
	{
		perror("\nl'ecriture dans le fichier marche pas, tu sais pourquoi, toi?\n");
		return (-1);
	}
	/* fermeture du fichier */
	fclose(ptr_fichier);
	return 0;
}

int tab_creation(int tab_entiers[], char nomfichier[])
{
	int i;
	FILE *ptr_fichier;

	ptr_fichier = fopen(nomfichier, "w");

	printf("\n\nQuestion 1/\n");

	if(ptr_fichier == NULL)
	{
		perror("\nl'ecriture dans le fichier marche pas, tu sais pourquoi, toi?\n");
		return (-1);
	}

	for (i = 0; i < intmax; i++)
	{
		tab_entiers[i] = i+1;
		printf("\n%d a ete ajoute au tableau a l'indice %d", i+1, i);
		fprintf(ptr_fichier, "%d; ", tab_entiers[i]);
		if(tab_entiers[i]%10 == 0)
			fprintf(ptr_fichier, "\n");
	}
	fclose(ptr_fichier);
	return 0;
}

 int affichationnalisation(char nomfichier[])
{
	char tab[256];
	FILE *ptr_fichier;

	ptr_fichier = fopen(nomfichier, "r");

	printf("\n\nQuestion 2/\n");

	if(ptr_fichier == NULL) 
   {
      perror("\nZ'y va, l'affichage marche pas! T'es sur que tu sais coder ?\n");
      return(-1);
   }

	while (!feof(ptr_fichier))
	{
		fgets(tab, 256, ptr_fichier);
		printf("%s", tab);
	}

	fclose(ptr_fichier);
	return 0;
}

int champ_par_ligne(char nomfichier[])
{
	char caractere;
	FILE *ptr_fichier;

	ptr_fichier = fopen(nomfichier, "r");
	if(ptr_fichier == NULL) 
   {
      perror("\nErreur: la fonction champ_par_ligne est mal fichue !\n");
      return(-1);
   }

   while(!feof(ptr_fichier))
   {
   		caractere = fgetc(ptr_fichier);

   		if(caractere == ';')
   		{
   			printf("\n");
   		}
   		else if (caractere == ' ' || 
   				caractere == '\n')
   		{
   			continue;
   		}
   		else
   		{
   			printf("%c", caractere);
   		}
   }
   printf("\nfin\n");
   return 0;
}