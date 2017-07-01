#include <stdio.h>

// Exercice 4, question 1 (3.4.4.2)
main()
{
	int notes[5];
	int i=0;
	double calculationnage=0;

	// Saisie des notes
	for (i=0; i<5; i++)
	{
		printf("Saisie de la note\n");
		scanf("%d", &notes[i]);
		getchar();

	// On vérifie que les notes sont comprises entre 1 et 6
		if(notes[i]<1||notes[i]>6)
		{
			i--;
			printf("Erreur de saisie !\nRE-");
			continue;
		}
	// Somme de toutes les notes saisies
		calculationnage += notes[i];
	}
	// Calcul de la moyenne
	calculationnage = calculationnage/5;
	printf("Ce patineur a eu une moyenne de %.2lf\n", calculationnage);

}
