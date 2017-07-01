#include <stdio.h>

int Facto(int a);

main()
{
	int nbre;
	int resultat;
	printf("Entrez un nombre pour avoir son factoriel :\n");
	scanf("%d", &nbre);
	resultat =  Facto(nbre);

}

int Facto(int a)
{
	int i, b=1; //

    printf("%d ! = ", a);
	for(i=a; i>1; i--)
	{
		b*= i;
		printf(" %d x", i);
	}
	printf("1\n%d != %d\n",a, b); 

	return 0;
}

