#include <stdio.h>

main()
{
    int jour, an;
	char mois[8];
	
    printf("saisissez la date (jj mois_en_toutes_lettres aaaa) :\n");
    scanf("%d %s %d", &jour, mois, &an);
    printf("vous avez saisi %02d %.8s %04d\n", jour, mois, an);
}
