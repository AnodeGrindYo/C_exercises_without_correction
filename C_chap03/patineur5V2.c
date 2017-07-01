#include <stdio.h>

// Exercice 4, question 4 (3.4.4.5)
main()
{
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //             //
    //  VARIABLES  //
    //             //
    /////////////////
    int notes[6][5]; // tableau de toutes les notes
    int i=0, j=0, k=0, min=6, max=0, comptJuges=0, numpatineur=0, podium1=0, podium2=0, podium3=0, jugeGenereux=0, bonneNote=0, mauvaiseNote=0, noteSuisse=0, singPlur=0; 
    double calculationnage=0.0, moypodium1=0.0, moypodium2=0.0, moypodium3=0.0; // variable multifonction pour les calculs de moyennes
    double moyenne[6]; // tableau des moyennes
    int hallofshame[3]; // ceux qui ne sont pas sur le podium
    int juryGenereux[5]={-1,-1,-1,-1,-1}, jurySuisse[5]={-1,-1,-1,-1,-1}, juryGenereux2[5]={0,0,0,0,0};
    char *score[6]; //c'est du bonus, voire tout en bas du code


    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //                     //
    //  DEBUT DU PROGRAMME //
    //                     //
    /////////////////////////
    // NB: pour des raisons évidentes d'hygiène, cette compétition est anonyme.

    do // Toute cette boucle concerne un patineur
    {
	// ces variables doivent être réinitialisée pour chaque patineur
	min=6;
	max=0;
	comptJuges=0;
	calculationnage = 0.0;

	printf(" ################################################################################################\n\n");

	// Identification du patineur
	printf("\t#################\n");
	printf("\t# patineur n°%d  #\n", numpatineur+1);
	printf("\t#################\n\n");

	// Saisie des notes
	for (i=0; i<5; i++)
	{
	    printf (" saisie de la note %d :\n", i+1);

	    scanf(" %d", &notes[numpatineur][i]);
	    //getchar(); // Visiblement, il ne sert à rien ici


	    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	    // VERIFICATION //
	    // DES NOTES    //
	    // SAISIES      //
	    //////////////////
	    // On vérifie que les notes sont comprises entre 1 et 6
	    if(notes[numpatineur][i]<1||notes[numpatineur][i]>6)
	    {
		i--;
		printf(" Erreur de saisie\nRE-");
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

	    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	    // CALCUL DES MOYENNES //
	    /////////////////////////

	    // Somme de toutes les notes saisies
	    calculationnage += notes[numpatineur][i];
	}
	calculationnage = calculationnage - min - max;
	// Calcul de la moyenne
	calculationnage = calculationnage/3.0;
	moyenne[numpatineur]=calculationnage;

	// Check du nombre de juges généreux pour ce patineur
	for(i=0; i<5; i++)
	{
	    if(notes[numpatineur][i]>calculationnage)
	    {
		comptJuges++;
	    }
	}

	printf(" Ce patineur a eu une moyenne de %.2lf.\n", moyenne[numpatineur]);
	printf(" La note la plus haute donnée est %d, et a été ignorée en vertu du nouveau règlement.\n",max);
	printf(" La note la plus basse donnée est %d, et a été ignorée en vertu du nouveau réglement.\n", min);
	printf(" %d juges on donné une note supérieur à %.2lf.\n\n", comptJuges, moyenne[numpatineur]);
	printf(" ################################################################################################\n\n");
	printf("\n\n\n");

	numpatineur++; //pour changer de patineur, par exemple dans notes[numpatineur][]

    } while (numpatineur<6);



    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //                                                 //
    //     CALCUL DE CEUX QUI SONT SUR LE PODIUM      //
    //                                               //
    //////////////////////////////////////////////////

    // Qui est sur la première marche du podium?
    for (i=0; i<6; i++)
    {
	if(moyenne[i]>moypodium1)
	{
	    moypodium1=moyenne[i];// calc meilleure moyenne
	    podium1=i+1;// n° patineur qui a cette moyenne
	}
    }

    // Qui est sur la deuxième marche du podium?
    for (i=0; i<6; i++)
    {
	if(moyenne[i]==moypodium1)
	{	
	    //i++;   // J'ai encore du mal avec le comportement de l'instruction "continue"
	    continue;
	}
	else if (moyenne[i]>moypodium2)
	{
	    moypodium2=moyenne[i];// calc deuxième meilleure moyenne
	    podium2=i+1;// n° patineur qui a cette moyenne
	}


    }

    // Qui est sur la troisième marche du podium?
    for (i=0; i<6; i++)
    {
	if(moyenne[i]==moypodium1||moyenne[i]==moypodium2)
	{
	    //i++;
	    continue;
	}
	else if (moyenne[i]>moypodium3)
	{
	    moypodium3=moyenne[i];// calc troisième meilleure moyenne
	    podium3=i+1;// n° patineur qui a cette moyenne
	}


    }

    // Ceux qui n'ont pas gagné
    for (i=0; i<6; i++)
    {
	if(moyenne[i]==moypodium1||moyenne[i]==moypodium2||moyenne[i]==podium3)
	{
	    //i++;
	    continue;
	}	

	hallofshame[j]=i+1;
	j++;
    }



    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //                                 //
    //  LES JUGES ET LEUR GENEROSITE  //
    //                               //
    //////////////////////////////////

    // Calcul des juges généreux sur l'ensemble
    for (i=0; i<5; i++)
    {
	for(j=0; j<6; j++)
	{
	    if(notes[j][i]>3)
	    {
		bonneNote++;			
	    }
	    else if (notes[j][i]==3)   // comment ça, c'est inutile?
	    {		         // peut-être q'un jour, le comité voudra savoir
		noteSuisse++;	// si certains juges ont fait le choix de la neutralité
	    }                      // 
	    else if (notes[j][i]<3)
	    {
		mauvaiseNote++;
	    }
	}
	if (bonneNote>(mauvaiseNote+noteSuisse))
	{
	    juryGenereux[k]=i+1;
	    k++;	
	}

    }

    // ici, on va juste chercher à déterminer si on va écrire une phrase au singulier ou au pluriel
    // (toujours cette histoire de juges)
    for(i=0; i<5; i++)             // basiquement, si la variable singPlur>0, on devra utiliser le pluriel
    {
	if(juryGenereux[i]>0)
	{
	    singPlur++;
	}
    }
    if(singPlur==0)
    {
	printf("\n Aucun des juges n'a été généreux, ou alors les candidats n'ont pas été éblouissants.\n\n");	
    }
    else if (singPlur==1)
    {
	printf(" Le juge ");
	for(i=0; i<5; i++)
	{
	    if(juryGenereux[i]>0)
	    {
		printf("n°%d ", juryGenereux[i]);
	    }
	}		
	printf(" a été particulièrement généreux.\n");
    }
    else if (singPlur>1)
    {
	printf(" Les juges ");
	for(i=0; i<5; i++)
	{
	    if(juryGenereux[i]>0)
	    {
		printf("n°%d, ", juryGenereux[i]);
	    }
	}		
	printf(" ont été particulièrement généreux sur les notes supérieures à 3.\n");

    }

    // jury génereux par rapport aux autres jurys (et on va faire plus simple que précédemment où je me suis compliqué la vie)
    for(i=0; i<5; i++)
    {
	for(j=0; j<6; j++)
	{
	    if(notes[j][i]>moyenne[i])
	    {	
		juryGenereux2[i]++;
	    }	
	}
    }
    for(i=0; i<5; i++)
    {
	if(juryGenereux[i]>3)
	{
	    printf(" Le juge %d à mis des notes plus généreuses que la moyenne du candidat plus de 3 fois\n", i);
	}
    }
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //                           //
    //  AFFICHAGE DES RESULTATS  //
    //                           //
    //////////////////////////////


    // blabla, les gagnants, les perdants, etc...
    printf("\n\n le patineur n°%d est sur la première marche du podium\n", podium1);
    printf(" le patineur n°%d est sur la seconde marche du podium\n", podium2);
    printf(" le patineur n°%d est sur la troisième marche du podium\n", podium3);
    printf(" en ce qui concerne les patineurs ");
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
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //  AFFICHAGE DU PODIUM, JE SAIS, C'EST UN PEU ILLISIBLE, printf OBLIGE // là, c'est du bonus
    //////////////////////////////////////////////////////////////////////////
    printf(" l'important est de participer.\n\n");
    printf(" Podium :\n-------\n\n\t\t           %d                      \n\t\t        #########                   \n\t\t        #       #    %d             \n\t\t   %d    #       #########          \n\t\t#########       #       #           \n\t\t#       #       #       #           \n\t\t#########################\n\n", podium1, podium2, podium3);

    for(i=0; i<6; i++)
    {
	if(moyenne[i]>5.5)
	{
	    score[i]="XXXXXXXXXXXX";
	}
	else if(moyenne[i]>5)
	{
	    score[i]="XXXXXXXXXXX ";
	}
	else if(moyenne[i]>4.5)
	{
	    score[i]="XXXXXXXXXX  ";
	}
	else if(moyenne[i]>4)
	{
	    score[i]="XXXXXXXXX   ";
	}
	else if(moyenne[i]>3.5)
	{
	    score[i]="XXXXXXXX    ";
	}
	else if(moyenne[i]>3)
	{
	    score[i]="XXXXXXX     ";
	}
	else if(moyenne[i]>2.5)
	{
	    score[i]="XXXXXX      ";
	}
	else if(moyenne[i]>2)
	{
	    score[i]="XXXXX       ";
	}
	else if(moyenne[i]>1.5)
	{
	    score[i]="XXXX        ";
	}
	else if(moyenne[i]>1)
	{
	    score[i]="XXX         ";
	}
	else if(moyenne[i]>0.5)
	{
	    score[i]="XX          ";
	}
	else if(moyenne[i]>0)
	{
	    score[i]="X           ";
	}
	else if(moyenne[i]=0)
	{
	    score[i]="            ";
	}
    }
    printf("\n\n\t\t--------------------------------------\n\t\t- patineur  -  Moyenne -   Score     -\n\t\t--------------------------------------\n\t\t-    1      -          - %s-\n\t\t--------------------------------------\n\t\t-    2      -          - %s-\n\t\t--------------------------------------\n\t\t-    3      -          - %s-\n\t\t--------------------------------------\n\t\t-    4      -          - %s-\n\t\t--------------------------------------\n\t\t-    5      -          - %s-\n\t\t--------------------------------------\n\t\t-    6      -          - %s -\n\t\t--------------------------------------\n\n\n", score[0], score[1], score[2], score[3], score[4], score[5]);
}

