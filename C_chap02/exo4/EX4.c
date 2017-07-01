#include <stdio.h>

main()
{
	// montant à convertir
	double montant=0.0, conv=0.0; // on aurait pu tout faire avec une seule variable, néanmoins, si le programme évolue, nous aurons directement deux valeurs exploitables.
	int choix=0;
	// menu pour la conversion
	printf("Veuillez saisir le montant, en euro (€), que vous souhaitez convertir :\n");
	scanf("%lf", &montant);
	getchar();
	printf("Vous avez saisi %.2lf\n€", montant); // ça peut être utile pour débuguer, on ne sait jamais

	printf("\t1) Euro -> Livres Sterling(GBP)\n\t2) Euro -> Dollar(USD)\n\t3) Euro -> Yen\n");
	scanf("%d", &choix);
	getchar();

	switch (choix)
	{
		case 1:// vers livres sterling
			{
				conv = montant*0.86;
				printf("%.2lf€ = %.2lf£\n", montant, conv);
				break;
			}
		case 2:// vers Dollar
			{
				conv = montant*1.077;
				printf("%.2lf€ = %.2lf$\n", montant, conv);
				break;
			}
		case 3:// vers le yen
			{
				conv = montant*116.021;
				printf("%.2lf€ = %.2lf¥\n", montant, conv);
				break;
			}
	}
}
