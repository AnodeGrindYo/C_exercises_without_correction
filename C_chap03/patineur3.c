#include <stdio.h>

// Exercice 4, question 3 (3.4.4.4)
main()
{
	int notes[5];
	int i=0, min=6, max=0, comptJuges=0; 
	double calculationnage=0; // variable multifonction pour les calculs de moyennes


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// SAISIE
	// Saisie des notes
	for (i=0; i<5; i++)
	{
		printf("Saisie de la note\n");
		scanf("%d", &notes[i]);
		getchar();

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// VERIFICATION DE LA SAISIE
		// On vérifie que les notes sont comprises entre 1 et 6
		if(notes[i]<1||notes[i]>6)
		{
			i--;
			printf("Erreur de saisie\nRE-");
			continue;
		}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// NOTES AUX EXTREMES
		// Ici, on va chercher les notes mini et maxi avec deux ifs, parce que nous ne sommes pas à deux cyprès
		if(notes[i]<min)
		{
			min = notes[i];
		}
		if(notes[i]>max)
		{
			max = notes[i];
		}
		
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// MOYENNE DES NOTES
		// Somme de toutes les notes saisies
		calculationnage += notes[i];

	} // fin du for de la saisie de notes
	calculationnage = calculationnage - min - max;
	// Calcul de la moyenne
	calculationnage = calculationnage/3;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// JUGES GENEREUX PAR RAPPORT A LA MOYENNE DES NOTES
	// Check des juges généreux
	for(i=0; i<5; i++)
	{
		if(notes[i]>calculationnage)
		{
			comptJuges++;
		}
	}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// AFFICHAGE DES RESULTATS
	printf("Ce patineur a eu une moyenne de %.2lf\n.", calculationnage);
	printf("La note la plus haute donnée est %d, et a été ignorée en vertu du nouveau règlement.\n",max);
	printf("La note la plus basse donnée est %d, et a été ignorée en vertu du nouveau réglement.\n", min);
	printf("%d juges on donné une note supérieur à %.2lf.\n", comptJuges, calculationnage);
	printf("Type any key to continue.\n");
	getchar();
	printf("This is NOT 'any' key.\n");
	
} // fin main

