#include <stdio.h>



main()
{
	double temperature=0.0; // variable température
	char reponse='\0'; //pour savoir si l'utilisateur veut recommencer
	int i=0; // variables pour les utilisateurs qui ne font pas ce que l'on attend d'eux
	printf ("\t88           88888888ba,    888b      88  88888888ba  * \n\t88           88        8b   8888b     88  88       8b  \n\t88           88         8b  88  8b    88  88      ,8P  \n\t88           88         88  88   8b   88  88aaaaaa8P   \n\t88           88         88  88    8b  88  88    88     \n\t88           88         8P  88     8b 88  88     8b    \n\t88           88      .a8P   88      8888  88      8b   \n\t88888888888  88888888Y      88       888  88       8b  \n\t* La Dame Nous Regarde                                                       		\n\n\n");


	do
	{
		printf("Entrez la température :\n");
		scanf( "%lf", &temperature);
		printf ("Vous avez saisi %.2lf, à quelques bananes près\n\n", temperature); //utile pour débug

		// ici, on aurait très bien pu utiliser un switch. ça aurait été mieux, c'est fait pour ce genre de situation. Je suis certain que j'avais une bonne raison d'utiliser un if à la place... la flemme de changer, très certainement

		// Cas n°1 : il faut migrer vers le sud.
		if(temperature<=10.0)
		{
			printf("brrr! Il fait frisquet, vous feriez mieux de mettre un manteau si vous ne voulez pas attraper froid. Enfin, c'est vous qui voyez.\n");
		}

		// Cas n°2 : il fait encore un peu froid (sauf s'il faut entre 16 et 20, ce qui est, paraît-il, une température idéale pour dormir) 
		else if(temperature<=20.0)
		{
			printf("Je vous conseille de mettre un pull\n");
		}

		// Cas n°3 : Notez que l'on préconnise un T-shirt, mais nous n'avons rien contre les marcels, les tops, ou des choses plus absurdes si vous êtes adeptes de la haute couture.
		else if(temperature<=30.0)
		{
			printf("Un T-shirt suffit\n");
		}

		// Cas n°4 : Il fait trop chaud pour commenter cette partie, je vais faire une sieste.
		else if(temperature>30.0)
		{
			printf("Il fait chaud, on reste à la maison\n");
		}



		// Ici, on va poser une question: "retry Y/n",  et harceler l'utilisateur jusqu'à ce qu'il émette une réponse attendue, qu'il ferme le programme ou que des infirmiers viennent le chercher
		i=0;
		do{
			if (i<1)
			{
				printf("voulez-vous réessayer? La température peut parfois changer si vite... Il n'y a plus de saison! (o/n)\n");
			}
			else if (i>=1)
			{
				printf ("Alors, vous voulez réessayer ou pas?\n");
			}
			else if (i=3)
			{
				printf ("Vous êtes désespérant !");
			}


			getchar();
			scanf("%c", &reponse);
			if (reponse != 'o' && reponse != 'O' && reponse != 'y' && reponse != 'Y' && reponse != 'n' && reponse != 'N')
			{
				printf ("Nous vous rappelons que seuls les caractères o, O, y, Y, n, N,\net éventuellement  私の小さなポニー \n(seulement les soirs de pleine lune)\nsont acceptés.\n");
				putchar('\a');
				i++;
			}
		} while (reponse != 'o' && reponse != 'O' && reponse != 'y' && reponse != 'Y' && reponse != 'n' && reponse != 'N');

	} while (reponse=='o'||reponse=='O');
	printf ("Au revoir. Sollicitez-moi à nouveau si vous voulez savoir si vous avez chaud ou froid.");
}


