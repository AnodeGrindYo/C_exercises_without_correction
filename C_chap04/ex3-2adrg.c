#include <stdio.h>

main()
{
    int jour, mois, an;

    printf("saisissez la date (jj/mm/aaaa) :\n");
    scanf("%d/%d/%d", &jour, &mois, &an);
    printf("vous avez saisi %02d/%02d/%04d\n", jour, mois, an);
}
