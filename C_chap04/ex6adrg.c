#include <stdio.h>

main()
{
	int nombre=0, i=0, j=0;
	do
	{
		printf ("saisissez un nombre entier entre 1 et 10\n");
		scanf("%d", &nombre);
	}while(nombre<1||nombre>10);

	printf("\n    |");
	
	// Cette boucle affiche la première ligne du tableau
	for(i=0; i<=nombre; i++)
	{
		printf("%4d", i);	
	}
	
	// Passe à la ligne suivante
	printf("\n");

	// Calcule  et affiche le bon nombre de - pour le trait horizontal
	for(i=0; i<=nombre+2; i++)
	{
	//	printf ("%d", i);
		printf("----");
	}
	
	printf("\n");

	// Affiche les lignes suivantes du tableau
	for(i=0; i<=nombre; i++)
	{
		printf("%-4d|", i);
		for(j=0; j<=nombre; j++)
		{
			printf("%4d", j*i);
		}
		printf("\n\n");
	}

	

}
