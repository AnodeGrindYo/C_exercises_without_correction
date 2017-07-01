#include <stdio.h>

// Exercice 4, question 4 (3.4.4.5)
main()
{
	int notes[6][5]; // tableau de toutes les notes
	int i=0, j=0, min=6, max=0, comptJuges=0, numpatineur=0, podium1=0, podium2=0, podium3=0; 
	double calculationnage=0.0, moypodium1=0.0, moypodium2=0.0, moypodium3=0.0; // variable multifonction pour les calculs de moyennes
	double moyenne[6]; // tableau des moyennes
	int hallofshame[3]; // ceux qui ne sont pas sur le podium
	do
	{
	// ces variables doivent être réinitialisée pour chaque patineur
	min=6;
	max=0;
	comptJuges=0;
	calculationnage = 0.0;


		// Identification du patineur
		printf("#################\n");
		printf("# patineur n°%d  #\n", numpatineur);
		printf("#################\n\n");

		// Saisie des notes
		for (i=0; i<5; i++)
		{
			printf ("saisie de la note %d :\n", i+1);
			scanf("%d", &notes[numpatineur][i]);
			//getchar();

			// On vérifie que les notes sont comprises entre 1 et 6
			if(notes[numpatineur][i]<1||notes[numpatineur][i]>6)
			{
				i--;
				printf("Erreur de saisie\nRE-");
				continue;
			}

			// Ici, on va chercher les notes mini et maxi avec deux ifs, parce que nous ne sommes pas à deux cyprès
			if(notes[numpatineur][i]<min)
			{
				min = notes[numpatineur][i];
			}
			if(notes[numpatineur][i]>max)
			{
				max = notes[numpatineur][i];
			}		

			// Somme de toutes les notes saisies
			calculationnage += notes[numpatineur][i];




		}
		calculationnage = calculationnage - min - max;
		// Calcul de la moyenne
		calculationnage = calculationnage/3.0;
		moyenne[numpatineur]=calculationnage;

		// Check des juges généreux
		for(i=0; i<5; i++)
		{
			if(notes[numpatineur][i]>calculationnage)
			{
				comptJuges++;
			}
		}
		printf("Ce patineur a eu une moyenne de %.2lf.\n", moyenne[numpatineur]);
		printf("La note la plus haute donnée est %d, et a été ignorée en vertu du nouveau règlement.\n",max);
		printf("La note la plus basse donnée est %d, et a été ignorée en vertu du nouveau réglement.\n", min);
		printf("%d juges on donné une note supérieur à %.2lf.\n\n", comptJuges, moyenne[numpatineur]);
		printf("\n\n\n");

		numpatineur++;

	} while (numpatineur<6);



	// Qui est sur la première marche du podium?
	for (i=0; i<6; i++)
	{
		if(moyenne[i]>moypodium1)
		{
			moypodium1=moyenne[i];// calc meilleure moyenne
			podium1=i;// n° patineur qui a cette moyenne
		}
	}

	// Qui est sur la deuxième marche du podium?
	for (i=0; i<6; i++)
	{
		if(moyenne[i]==moypodium1)
		{	
			//i++;
			continue;
		}
		else if (moyenne[i]>moypodium2)
		{
			moypodium2=moyenne[i];// calc deuxième meilleure moyenne
			podium2=i;// n° patineur qui a cette moyenne
		}


	}

	// Qui est sur la troisième marche du podium?
	for (i=0; i<6; i++)
	{
		if(moyenne[i]==podium1||moyenne[i]==moypodium2)
		{
			//i++;
			continue;
		}
		else if (moyenne[i]>moypodium3)
		{
			moypodium3=moyenne[i];// calc troisième meilleure moyenne
			podium3=i;// n° patineur qui a cette moyenne
		}


	}

	// Ceux qui n'ont pas gagné
	for (i=0; i<6; i++)
	{
		if(moyenne[i]==moypodium1||moyenne[i]==moypodium2||moyenne[i]==moypodium3)
		{
			//i++;
			continue;
		}	

		hallofshame[j]=i;
		j++;
	}

	// blabla, les gagnants, les perdants, etc...
	printf("\n\n\nle patineur n°%d est sur la première marche du podium\n", podium1);
	printf("le patineur n°%d est sur la seconde marche du podium\n", podium2);
	printf("le patineur n°%d est sur la troisième marche du podium\n", podium3);
	printf("en ce qui concerne les patineurs ");
	for(i=0; i<3; i++)
	{
		if(i<3)
		{
			printf("n°%d, ", hallofshame[i]);
		}
		else if (i = 3)
		{
			printf("et n°%d, ", hallofshame[i]);
		}
	}	
	printf("l'important est de participer.\n\n");

}


