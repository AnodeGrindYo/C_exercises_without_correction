#include <stdio.h>
#include <math.h>

main()
{
    int sexe;
    int jour;
    int mois;
    int annee;
    int departement;
    int insee;
    int nir;
    unsigned long long int num_secu;
    unsigned long long int clef;
    char reponse;

    do
    {
        printf("\nconnaissez-vous votre numero de securite sociale ? (o/N)\n");
        scanf("%c", &reponse);
        reponse = toupper(reponse);
    } while (reponse != 'O' && reponse != 'N');
    
    switch (reponse)
    {
        case 'O' : // l'utilisateur connait son numero de secu
        {
            printf("veuillez saisir votre numero de securite sociale");
            scanf("%llu", &num_secu);
            break;
        }
        case 'N' : // l'utilisateur ne le connait pas
        {
            // saisie du sexe de l'utilisateur
            do
            {
                printf("\ntappez 1 si vous êtes un homme, 2 si vous êtes une femme, 3 pour autre : ");
                scanf("%d", &sexe);
            } while (sexe != 1 && sexe != 2 && sexe != 3);

            // saisie de la date de naissance
            do
            {
                printf("\nveuillez saisir votre date de naissance (jj/mm/aa) : ");
                scanf("%d/%d/%d", &jour, &mois, &annee);
            } while (jour < 1 || 
                    jour > 31 || 
                    mois < 1 ||
                    mois >12); 

            // saisie du lieu de naissance
            printf("\nveuillez saisir votre département de naissance (99 pour l'étranger) : ");
            scanf("%d", &departement);

            // saisie du code insee de la commune ou du departement si né à l'étranger
            printf("\nveuillez saisir le code INSEE de votre commune de naissance, ou le numero du departement si vous etes né à l'etranger : ");
            scanf("%d", &insee);

            // saisie du numéro d'inscription au répertoire
            printf("\nsaisissez votre numero d'inscription au repertoire (NIR) : ");
            scanf("%d", &nir);

            //calcul du numero sans la clé
            num_secu = sexe*1000000000000
                    + annee*10000000000
                    + mois*100000000
                    + departement*1000000
                    + insee*1000
                    + nir;

            // calcul de la clé 
            clef = num_secu % 97;

            // calcul du numero de secu entier
            num_secu = num_secu*100 + clef;
            break;
        }
        default:
        {
            printf("\nerror\n");
            break;
        }
    } // fin switch
    
    // affichage du numero de secu
    printf("\nVotre numero de securite sociale : \n%llu", num_secu);
}