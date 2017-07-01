#include <stdio.h>

int PyramideBas(int base, int space);

main()
{
	int base, space;

	printf("\nTaille de la base ?\n");
	scanf("%d", &base);
	getchar();
	printf("Nombre d'espaces avant?\n");
	scanf("%d", &space);
	getchar();
	PyramideBas(base, space);
}

int PyramideBas(int base, int space)
{
	int i;

		if (base <= 0)
		{
			return 0;
		}
		else
		{
			for(i=0; i<=space; i++)
				printf(" ");

			for (i=base; i>0; i--)
				printf("*");
		}
		printf("\n");
		PyramideBas(base-2, space+1);
}

