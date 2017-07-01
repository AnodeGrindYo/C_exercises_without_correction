#include <stdio.h>
#include <string.h>

main()
{
	char verbe[26]="";
	char retry;
	do
	{
		do
		{
			printf("Ecrivez un verbe du premier groupe (terminaison en -er)\n");
			scanf("%26s", verbe);
			//dans la condition du while, le vérifie la terminaison du verbe
		}while(verbe[strlen(verbe)-2]!='e' ||  verbe[strlen(verbe)-1]!='r');
		// printf("longueur : %d", strlen(verbe));// juste pour debug

		printf("\nje %.*se\n", (strlen(verbe)-2),verbe); 
		printf("tu %.*ses\n", (strlen(verbe)-2),verbe); 
		printf("il %.*se\n", (strlen(verbe)-2),verbe); 
		printf("nous %.*sons\n", (strlen(verbe)-2),verbe); 
		printf("vous %.*sez\n", (strlen(verbe)-2),verbe); 
		printf("ils %.*sent\n", (strlen(verbe)-2),verbe); 
		
		do// voulez-vous recommencer?
		{
			printf("voulez-vous recommencer ?");
			getchar();
			scanf("%c", &retry);
			retry=toupper(retry);
		}while (retry!='O'&&retry!='N');

	}while (retry=='O');
}
