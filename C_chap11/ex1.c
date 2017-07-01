#include <stdio.h>
#include <stdlib.h>

int intmax;

int file_creationnage();
void nbmax();
int tab_creation(int tab_entiers[]);
int affichationnalisation();
int champ_par_ligne();

int main(int argc, char const *argv[])
{
	int appel;

	appel = file_creationnage();

	/* définition par l'utilisateur du nombre d'entiers */
	nbmax();
	/* creation du tableau a la bonne taille */
	int tab_entiers[intmax];
	/* remplissage du tableau */
	appel = tab_creation(tab_entiers);
	/* affichage du tableau */
	appel = affichationnalisation();
	/* affichage un champ par ligne */
	appel = champ_par_ligne();

	rename ("files_ex1.txt", "files_ex1.xls");

	return 0;
}

int file_creationnage()
{
	/* creation du fichier */
	FILE *ptr_fichier;
	ptr_fichier = fopen("files_ex1.txt", "w");

	// si ça ne marche pas
	if(ptr_fichier == NULL)
	{
		printf("\nl'ecriture dans le fichier marche pas, tu sais pourquoi, toi?\n");
		return (-1);
	}
	/* fermeture du fichier */
	fclose(ptr_fichier);
	return 0;
}


void nbmax()
{
	/* definition du nombre d'entiers a inclure dans le tableau */
	printf("\nEh, psst!");
	getchar();
	printf("\nJ'ai des entiers a refourguer. \nT'en veux combien (dans l'exercice, ils recommandent 97)? ");
	do
	{
		scanf("%d", &intmax);
		getchar();

		if (intmax < 0)
			printf("\nPas compris ...\nT'en veux combien ? ");
	} while (intmax < 0);

}

int tab_creation(int tab_entiers[])
{
	int i;
	FILE *ptr_fichier;

	ptr_fichier = fopen("files_ex1.txt", "w");

	printf("\n\nQuestion 1/\n");

	if(ptr_fichier == NULL)
	{
		printf("\nl'ecriture dans le fichier marche pas, tu sais pourquoi, toi?\n");
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

 int affichationnalisation()
{
	char tab[256];
	FILE *ptr_fichier;

	ptr_fichier = fopen("files_ex1.txt", "r");

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

int champ_par_ligne()
{
	char caractere;
	FILE *ptr_fichier;

	ptr_fichier = fopen("files_ex1.txt", "r");
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
}