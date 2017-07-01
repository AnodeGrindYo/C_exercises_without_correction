#include <stdio.h>
#include <string.h>

main()
{
	char mot[100]="";
	char alphabet[]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char retry;
	int i, j, occurence=0;

	do
	{
		printf("Entrez votre mot (peu importe la casse):\n");
		scanf("%s", mot);

		// si le mot entré comprend plus de 100 lettres, 
		// on affiche un message
		if (strlen(mot) > 100)
		{
			printf("\nLes mots de plus de 100 lettres ne sont pas autorisés car ce programme est\nhippopotomonstrosesquippedialophobe.\n"); 
		}
	}while (strlen(mot)>100); // try again si mot entré > 100 lettres

	for(i=0; i<=strlen(mot); i++)
	{
		mot[i]=toupper(mot[i]);
	}

	printf("\nLe mot %s contient\n", mot);

	// On vérifie pour chaque lettre de l'alphabet son nombre d'occurences dans le mot
	// Le premier for parcourt l'alphabet
	for(i = 0; i < (strlen(alphabet)); i++)
	{
		// Le for qui suit parcourt le mot
		for(j = 0; j < (strlen(mot)); j++)
		{
			// si le caractère contenu dans le tableau mot à l'indice j correspond au caractère 
			// contenu dans le tableau alphabet à l'indice i, on incrémente occurence
			if(mot[j] == alphabet[i])
			{
				occurence++;
			}
		}

		if(occurence >= 1)
		{
			printf("%d fois la lettre '%c'\n", occurence, alphabet[i]);
		}

		occurence = 0; // remise à 0 du compteur d'occurence
	}

}
