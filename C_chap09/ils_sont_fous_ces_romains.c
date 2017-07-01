#include <stdio.h>
#include <string.h>

#define ROM_LN 10

// prototypes //
// saisie du nombre romain
void saisir_rom(char *romain);
// convertit une seule lettre
int rom_to_dec(char c);
// convertit tout le nombre
unsigned long long int conversion(char *str);
// vérifie la validité du nombre romain
int verification (char *romain);
// version recursive
int conv2 (char *romain);

main()
{
    char romain[ROM_LN] = "";
    unsigned long long int convert;
    
    saisir_rom(romain);
    convert = conversion(romain);
    printf("\nNombre en chiffres arabes : %llu\n", convert);
    printf("\nVersion récursive : %d\n", conv2(romain));
    
}

// fonctions //

// saisie du nom et conversion des caractères en majuscule pour plus de praticité
// vérifie aussi si le nombre ne contient pas d'autres caractères que i,v ,x , l, c, d et m
void saisir_rom(char *romain)
{
    int i;
    int verif = 0;
    
    do
    {        
        printf("\nNombre romain : ");
        scanf("%s", romain);
        // conversion en majuscules
        for (i = 0; i < strlen(romain); i++)
        {
            romain[i] = toupper(romain[i]);
        }
        verif = verification(romain);
    } while ( verif == -1);
}

// valide hoc munus ducens ad numerus
int verification (char *romain)
{
    int i;
    // vérification des caractères
    for (i = 0; i < strlen(romain); i++)
    {
        switch (romain[i])
        {
            case 'I':
            case 'V':
            case 'X':
            case 'L':
            case 'C':
            case 'D':
            case 'M': break;
            default:
            {
                printf("\nhoc est numerus invalid\n");
                return -1;
            }
        }
    }
}

// convertit un chiffre romain en sa valeur en int
int rom_to_dec(char c)
{
    switch (c)
    {
        case 'I':
        {
            return 1;
        }
        case 'V':
        {
            return 5;
        }
        case 'X':
        {
            return 10;
        }
        case 'L':
        {
            return 50;
        }
        case 'C':
        {
            return 100;
        }
        case 'D':
        {
            return 500;
        }
        case 'M':
        {
            return 1000;
        }
        default: 
        {
            printf("\nUnknown value\n");
            return 0;
        }      
    }
}

// utilise la fonction rom_to_dec dans une boucle pour convertir 
// un nombre romain en nombre arabe
unsigned long long int conversion(char *str)
{
    int i;
    int soustraction = 0;
    unsigned long long int somme = 0;
    int longueur = strlen(str);
    
    for (i = 0; i < longueur-1; i++)
    {
        switch (rom_to_dec(str[i]))
            {
                case 1: // 1 ne peut se soustraire qu'à 5 et 10
                {
                    switch (rom_to_dec(str[i+1]))
                    {
                        case 1: break;
                        case 5:
                        case 10:
                        {
                            soustraction += 2;
                            break;
                        }
                        default :
                        {
                            printf ("\nIncorrect, %c ne peut pas preceder %c", str[i], str[i+1]);
                            break;
                        }

                    }
                }
                default: // si le nombre courrant est inférieur au nombre suivant,
                         // il faut soustraire le nombre courrant au nombre suivant.
                         // on le soustrait donc deux fois, puisqu'il sera ajouté à la somme
                         // de toutes façons
                {
                    if (rom_to_dec(str[i]) < rom_to_dec(str[i]))
                        soustraction += 2*(rom_to_dec(str[i]));
                    break;
                }
            }
        somme += rom_to_dec(str[i]);
    }
    // on ajoute le nombre représenté par la dernière lettre et on soustrait ce qu'il y a à soustraire
    // ça m'a pris presque 4h pour trouver qu'il fallait mettre longueur-1!!! (-_-')
    // ... je vais me pendre, et je reviens après
    somme += rom_to_dec(str[longueur-1]) - soustraction;
    return somme;
}

// version récursive
int conv2 (char *romain)
{
    int i = 0;
    int conversion;
    if (strlen(romain) == 1)
        return rom_to_dec(romain[0]);
    else
    {
        if (i<strlen(romain))
        {
            if (rom_to_dec(romain[i]) < rom_to_dec(romain[i+1]))
                return (conv2(&romain[i+1])-rom_to_dec(romain[i]));
            else
                return (conv2(&romain[i+1])+rom_to_dec(romain[i]));
        }
    }
}