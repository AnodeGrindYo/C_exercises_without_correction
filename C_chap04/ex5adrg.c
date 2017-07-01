#include <stdio.h>

main()
{
	int nombre, x;// nombre est les nombre saisi, x le multiplicateur
	
	printf("entrez un nombre.\n");
	scanf("%d", &nombre);

	for(x=1; x<=10; x++)
	{
		printf("%d x %-2d = %-4d\n", nombre, x, (x*nombre));
	}
}
