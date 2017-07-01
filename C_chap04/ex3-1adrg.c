#include <stdio.h>

main()
{
    int jour, mois, an;

    printf("saisissez la date (jj mm aaaa) :\n");
    scanf("%d %d %d", &jour, &mois, &an);
    printf("vous avez saisi %d %d %d\n", jour, mois, an);
}
