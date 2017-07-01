#include <stdio.h>

main()
{
	double temperature;
	int choix;
	printf ("\t88           88888888ba,    888b      88  88888888ba  * \n\t88           88        8b   8888b     88  88       8b  \n\t88           88         8b  88  8b    88  88      ,8P  \n\t88           88         88  88   8b   88  88aaaaaa8P   \n\t88           88         88  88    8b  88  88    88     \n\t88           88         8P  88     8b 88  88     8b    \n\t88           88      .a8P   88      8888  88      8b   \n\t88888888888  88888888Y      88       888  88       8b  \n\t* La Dindon Népalais Rigole                                                       		\n\n\n");



	// Voici notre superbe menu
	printf("\t1) celsius -> fahrenheit\n\t2)fahrenheit ->celsius\n\n");
	scanf("%d", &choix);

	switch (choix)
	{
		case 1:
			{
				printf("\nEntrez la température en Celsius\n");
				getchar();
				scanf("%lf", &temperature);
				//printf("%lf", temperature);
				temperature = (9/5)*temperature+32;
				printf("\nLa température est de %.2lf degrés Fahrenheit\n", temperature);
				break;
			}

		case 2:
			{
				printf("\nEntrez la température en Fahrenheit\n");
				getchar();
				scanf("%lf", &temperature);
				temperature = (5/9)*temperature-32;
				printf("\nLa température est de %.2lf degrés Celsius", temperature);
				break;
			}
		default:
			{
				printf("やめてください");

			}

			printf("\nvoulez-vous recommencer ?\n");
			getchar();
			printf("pas moi.\n");
			getchar();
			printf("au revoir.\n");
			getchar();
			printf("à une prochaine fois.\n");
			getchar();
			printf("peut-être\n");
			getchar();
			printf("ou pas\n");
			getchar();
			printf("j'aurai peut-être été désinstallé d'ici là\n");
			getchar();
			printf("Ou cet ordinateur aura peut-être rendu l'âme\n");
			getchar();
			printf("(à qui elle appartient)\n");
			getchar();
			printf("à cause d'un virus\n");
			getchar();
			printf("comme la grippe aviaire\n");
			getchar();
			while (1)
			{
				printf(".");
				getchar();
			}

	}
}

