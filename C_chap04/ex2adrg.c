#include <stdio.h>

main()
{
    char nom[11]="", prenom[11]="";//contiennent ce que disent leur nom
    printf("Tapez votre nom et votre prénom\n");
    scanf("%s %s", nom, prenom);
    printf("bonjour %s %s !\n", prenom, nom);
}
