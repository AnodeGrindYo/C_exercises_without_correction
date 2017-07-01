#include <stdio.h>

long int facto(long int nbre);

main()
{
	long int nbre;
	printf("\nEntrez un entier pour avoir son factoriel :\n");
	scanf("%li", &nbre);
	printf("\nResultat : \n%li ! = %li\n", nbre, facto(nbre));
}

long int facto(long int nbre)
{
	int nbfact = nbre;
	if (nbre > 1)
	{
		nbfact *= facto(nbre - 1);
	}
	return nbfact;
}

