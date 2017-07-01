#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>

// variables globales
int nombremax;

// prototypes
void selectNbre();
void nbPremiers();
void eratosthene();
void jumeaux(bool *tab, int nombremax);

// main
int main()
{
	selectNbre();
	printf("\nVersion algo de base :\n");
	nbPremiers();
	printf("\n\nVersion d'Eratosthene :");
	eratosthene();
	return 0;
}

// fonctions
void selectNbre()
{
	printf("\nJusqu'a quel nombre voulez-vous enumerer les nombres premiers ?\n");
	scanf("%d", &nombremax);
	getchar();
	printf("\nnombres premiers :\n");
}

void nbPremiers()
{
	int i;
	int j;
	bool divisible = false;

	// est nombre est dit premier s'il n'est divisible que par 1 et lui-memeement
	// autrement dit, si, si son modulo par un nombre different de 1 par tout autre
	// nombre inferieur est different de 0
	// d'abord, dans la premiere boucle for, on parcourt les entiers jusqu'au nombremax choisi
	for (i = 2; i <= nombremax; i++)
	{
		divisible = false;

		// on verifie le modulo de tous les nombres inferieurs
		for (j = 2; j < i; j++)
		{
			if (i%j == 0)
				divisible = true;
		}
		// si i n'est divisible par aucun nombre inferieur superieur a 1
		// et inferieur a lui-meme alors ce nombre est entier
		// on affiche ce nombre
		if (divisible == false)
			printf("%d\n", i);
	}
}

void eratosthene()
{
	int i;
	int j =2;
	bool tab[nombremax+1];

	// etape 0 : on passe toutes les valeurs du tableau a true
	for (i = 2; i <=nombremax; i++)
		tab[i] = true;

	// etape 1 : 0 et 1 ne sont pas des nombres premiers
	tab[0] = false;
	tab[1] = false;


	// etape 2 : parcourt les indices du tableau a partir de 2
	for (i = 2; i <= floor(sqrt(nombremax)); i++)
	{
		// si le nombre n'est pas deja un multiple d'un nombre inferieur,
		// on calcule tous ses multiples et on passe les indices correspondants a false
		
		for (j = 2; j <= nombremax; j++)
		{

			if (tab[i] == true && i*j <= nombremax)
			{
				tab[i*j] = false;
			}
		}
	}

	// etape 3 on affiche les indices don la valeur est restee true
	for (i = 2; i <= nombremax; i++)
	{
		if (tab[i] == true)
			printf("\n%d", i);
	}

	printf("\n");

	jumeaux(tab, nombremax);

}

void jumeaux(bool *tab, int nombremax)
{
	int i;
	for (i = 2; i <= nombremax - 2; i++)
	{
		if (tab[i] == true && tab[i+2])
			printf("\n%d et %d sont jumeaux", i, i+2);
	}
	printf("\n");
}