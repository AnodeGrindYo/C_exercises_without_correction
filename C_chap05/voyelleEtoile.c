#include <stdio.h>
#include <string.h>

int Transformation(char *mot, unsigned int nombre_de_caracteres);

main()
{
	char mot[100]="";
	int nbchar;
	//saisie de l'utilisateur
	printf("wesh, c'est quoi ton mot ? \n");
	scanf("%s", mot);
	nbchar = strlen(mot);
	Transformation(mot, nbchar);
}

int Transformation(char * mot, unsigned int nchar)
{
	int i;

	for(i=0; i<nchar; i++)
	{
		switch(mot[i])
		{
			case 'a':
			case 'e':
			case 'i':
			case 'o':
			case 'u':
			case 'y': mot[i]='*';
					  break;
			default: break;
		}
	printf("%c", mot[i]);
	}
	//printf("%s\n", mot);
	return 0;
}

