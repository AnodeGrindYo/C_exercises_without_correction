#include <stdio.h>
#include <time.h>
#include <stdlib.h>


/* fonction qui génère un nombre entier aléatoire compris entre a et b */
// renvoie une valeur aléatoire comprise entre a et b
int Frand_a_b(double a, double b);
// Fonction qui calcule la puissance d'un entier
int Puissance(int nbre, int exposant);
// Fonction qui permet à l'utilisateur de saisir des nombres et qui affiche
// des messages en conséquence
void ChaudFroid(int nombre); 



main()
{
	int nombre,i=0;
	char next;
	do
	{
		// début de la partie
		printf("Niveau %d, nombre de chiffre max: %d\n", i+1, i+2);

		// initialisation du nombre à trouver
		nombre = Frand_a_b(1, Puissance(10, i+2));

		printf("\nJe pense à un nombre...%0.*d\n", i+2, nombre);
		// interraction avec l'utilisateur
		ChaudFroid(nombre);
		
		//ici, exceptionnellement, je n'harcèle pas l'utilisateur pour que sa réponse corresponde à mes critères
		printf("voulez-vous continuer ? (o/N)\n");
		scanf("%c", &next);
		i++;
	}while(toupper(next)=='O');
}


/* fonction qui génère un nombre entier aléatoire compris entre a et b */
// renvoie une valeur aléatoire comprise entre a et b
int Frand_a_b(double a, double b)
{
	int nbrand;
	srand(time(NULL));
	return ( rand()/(double)RAND_MAX ) * (b-a) + a;
}

// Calcule nombre nbre à l'esposant exp
int Puissance(int nbre, int exp)
{
	int i, resultat=1;
	for (i=exp; i>0; i--)
	{
		resultat *= nbre;
	}
	return resultat;
}




void ChaudFroid(int nombre)
 {
	int nbuser, nbEssais=0;
	do
	{
		scanf("%d", &nbuser);
		nbEssais++;// on ajoute 1 au compteur d'essais

		// verification du nombre de l'utilisateur
		if(nbuser<nombre)
		{
			printf("mon nombre est plus grand !\n");
		}
		else if (nbuser>nombre)
		{
			printf("mon nombre est plus petit !\n");
		}
		getchar();

	}while (nbuser != nombre);

	// Affichage du nombre d'essais
	printf("\nBravo! Vous avez trouvé en %d essai(s)\nVous êtes un dichotomiste professionnel!\n\n", nbEssais);
return;
}

