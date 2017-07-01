#include <stdio.h>
#include <string.h>


// fonction qui permet la saisie de la séquence de nucléotides et qui
// vérifie que les lettres sont uniquement A, T, G ou C //protosaisir
int SaisirBrin(char *brinBleusaille, unsigned int nombreNucleotides, char debug);
// fonction qui imprime la séquence sous la forme A-G-C-T-T //protoimprimebleu
int ImprimerBrin(char *brinBleusaille, unsigned int nombreNucleotides);
// fonction qui déduit le brin rouge à partir du brin bleu //protoautrebrin
int AutreBrin(char *brinBleusaille, unsigned int nombreNucleotides, char *brinrouge);
// fonction qui imprime l'ADN en entier //protoimprimeradn
int ImprimerADN(char *brinBleusaille, unsigned int nombreNucleotides, char *brinrouge);
// fonction qui vérifie et modifie en conséquence les brin //protofinirbrin
int FinirBrin(char *brinBleu, unsigned int *nombreNucleotides, char *brinRouge, char  debug);
// fonction utilisée dans FinirBrin, quelques séquences de fin sont parfois ignorées//protocheck
int Check (char *brin, unsigned int *taille, char *autrebrin, char debug);
// fonction utilisée dans FinirBrin pour ajouter la séq de fin si besoin //protoseqfin
int SeqFin (char *brin, unsigned int *taille, char debug);




//////////////////////////////////////////////////////////////////////////
main()
{
	unsigned int nbnucleo;
	char debug, exo;

	// Activation des options spéciales?
	printf("\nBienvenue.\n");
	printf("\nVoulez-vous activer le mode debugage? (o/N)\n");
	scanf("%c", &debug);
	debug=toupper(debug);
	getchar();
	printf("\nVoulez-vous afficher le numéro des exercices? (o/N)\n");
	scanf("%c", &exo);
	exo=toupper(exo);
	getchar();

	// définition de la taille du tableau
	printf("\ncombien de nucléotides souhaitez-vous saisir?\n");
	scanf("%u", &nbnucleo);
	//getchar();

	// déclaration variables tableau qui contiendront les nucléotides

	char brinBleu[nbnucleo+1], brinRouge[nbnucleo+1];
	brinBleu[nbnucleo+1]='\0';
	brinRouge[nbnucleo+1]='\0';

	if(exo=='o')
		printf("\nExercice 1 :\n");
	// appel de la fonction de saisie et vérif des nucléotides //appelsaisie
	SaisirBrin(brinBleu, nbnucleo, debug);

	if(exo=='o')
		printf("\nExercice 2 :\n");
	// appel de la fonction qui affiche la séquence de nucléotides //appelimprimebleu
	ImprimerBrin(brinBleu, nbnucleo);

	if(exo=='o')
		printf("\nExercice 3 :\n");
	// appel fonction déduisant l'autre brin //appelautrebrin
	AutreBrin(brinBleu, nbnucleo, brinRouge);

	if(exo=='o')
		printf("\nExercice 4 :\n");
	// appel de la fonction qui imprimme l'ADN en entier //appelimprimeradn
	ImprimerADN(brinBleu, nbnucleo, brinRouge);

	if(exo=='o')
		printf("\nExercice 5 :\n");
	// appel de la fonction qui vérifie les brins et les modifie en conséquence //appelfinirbrin
	FinirBrin(brinBleu, &nbnucleo, brinRouge, debug);
}
/////////////////////////////////////////////////////////////////////////





// fonction pour la saisie et la vérification des nucléotides //defsaisie
int SaisirBrin(char *brinBleu, unsigned int nbreNucleotides, char debug)
{
	int i;
	printf("\nSaisissez la séquence.\n\n");

	for(i=0; i<nbreNucleotides; i++)
	{
		printf("\nNucléotide n°%d :\t", i+1);

		// mode de saisie 1:
		getchar();// récupère la touche entrée enregistrée par l'user dans le main
		scanf("%c", &brinBleu[i]);
		brinBleu[i]=toupper(brinBleu[i]);
		if (debug=='O')
		printf("vous avez saisi :\t%c\n", brinBleu[i]);
		switch(brinBleu[i])
		{
			case 'A': // si les lettres sont A, T, G ou C, ne rien faire
			case 'T':
			case 'G':
			case 'C': break;
					  //case '\n': break;
			default: {
						 --i; // si ce n'est pas les bonnes lettres, ne pas incrémenter
						 printf("\n\t/!\\\tERREUR! VEUILLEZ RECOMMENCER!\t/!\\\n\n");
						 break;
					 }
		}

	}
	printf("\n");
	return 0;
}

// Fonction qui imprime le brin bleu // defimprimebleu
int ImprimerBrin(char *brinBleu, unsigned int nbnuc)
{
	int i;
	printf("%c", brinBleu[0]);
	for(i=1; i<nbnuc; i++)
	{
		printf(" - %c", brinBleu[i]);
	}
	printf("\n");
	return 0;
}

// Fonction qui déduit l'autre brin //defautrebrin
int AutreBrin(char *brinBleu, unsigned int nbnuc, char *brinRouge)
{
	int i;
	for(i=0; i<nbnuc; i++)
	{
		switch(brinBleu[i])
		{
			case 'A':
				{
					brinRouge[i]='T';
					break;
				}
			case 'T':
				{
					brinRouge[i]='A';
					break;
				}
			case 'C':
				{
					brinRouge[i]='G';
					break;
				}
			case 'G':
				{
					brinRouge[i]='C';
					break;
				}
			default:
				{
					printf("\n\t/!\\\tERREUR\t/!\\\n");
				}
		}
	}
	brinRouge[nbnuc]='\0';

	printf("\nBrin rouge : \t%s\n", brinRouge);
	return 0;
}






// fonction qui imprime les deux brins d'adn //defimprimeradn
int ImprimerADN(char *brinBleu, unsigned int nbnuc, char *brinRouge)
{
	int i;
	// la première ligne est la même que la fonction ImprimerBrin()
	// et je suis fainéeant
	ImprimerBrin(brinBleu, nbnuc);
	for (i=0; i<nbnuc; i++)
	{
		printf("|   ");
	}
	printf("\n");
	// Idem que le dernier commentaire, il suffit de changer les paramètres
	ImprimerBrin(brinRouge, nbnuc);
	// and "voilà" !!
	return 0;
}






// Fonction qui contient des fonctions qui font ce qui est demandé dans l'exercice 5
// à savoir : un sous-programme FinirBrin qui vérifie que le brin saisit contient bien 
// un nombre entier de fois un multiple de 3 lettres sinon il supprime les lettres en trop.
//Si une des séquences de fin de brin est trouvée dans le brin elle est supprimée.
//Si une séquence de fin de brin n’est pas trouvée à la fin du brin, on rajoute la séquence « ATC »
int FinirBrin(char *brinBleu, unsigned int *nbnuc, char *brinRouge, char debug)
{
	int okBleu=1, okRouge=1, nbnucCopy=*nbnuc;

	// vérification et correction du nombre de nucléotides
	if(*nbnuc%3>0)
	{
		///////////////////debug
		if (debug=='O')
		{
			printf("\n\t/!\\\tNOMBRE DE NUCLEOTIDES ANORMAL !\t/!\\\n");
			printf("\t%d nucléotides ont été supprimées en fin de séquence.\n", *nbnuc%3);
		}
		brinBleu[*nbnuc-(*nbnuc%3)] = '\0';
		brinRouge[*nbnuc-(*nbnuc%3)] = '\0';
		*nbnuc -= (*nbnuc%3);
	}

	// vérification des séquences de fin qui se trouveraient en plein milieu
	do
	{
		do
		{
			// vérifie bleu et modif tant qu'il trouve une chaine de fin
			okBleu = Check(brinBleu, nbnuc, brinRouge, debug);
		}while (okBleu != 0);
		do
		{
			// vérifie rouge
			okRouge = Check(brinRouge, nbnuc, brinRouge, debug);
			// revérifie bleu au cas où une précédente modification aurait fait apparaitre
			// une séquence de fin
			okBleu = Check(brinBleu, nbnuc, brinRouge, debug);
		}while (okRouge != 0);
	}while(okRouge == 1 || okBleu == 1);


	// affiche la nouvelle version de l'ADN 
	printf("\nDes séquences de fin ont été supprimées :\n");
	nbnucCopy=*nbnuc;
	ImprimerADN(brinBleu, nbnucCopy, brinRouge);

	// vérifie et éventuellement modifie la séquence de fin
	SeqFin(brinBleu, nbnuc, debug);

	nbnucCopy=*nbnuc;
	// Réajustement de l'autre brin
	AutreBrin(brinBleu, nbnucCopy, brinRouge);

	printf("\n\nADN corrigé :\n\n");
	// réaffichage de l'ADN corrigé
	ImprimerADN(brinBleu, nbnucCopy, brinRouge);
		return 0;
}






// verifie si une séquence de fin est présente avant la fin et la supprime s'il faut
int Check (char *brinBleu, unsigned int *nbnuc, char *brinRouge, char debug)
{
	int i, j, k, compteurModif=0;

	///////////////////////////////////debug
	if(debug=='O')
		printf("\n\tappel fonction \"Check\" OK\n");
	char verif[4]="";
	// parcours du tableau pour vérif qu'il n'y a pas de séquences de fin
	for (i=0; i<*nbnuc-3; i++)
	{
		// copie séquence trois lettres dans variable de vérification
		for(j=0; j<3; j++)
		{
			verif[j] = brinBleu[i+j];
		}
		// vérification si la variable verif contient un séquence de fin
		///////////////////////////////////////////////debug
		if(debug=='O')
			printf("\nVERIF = %s\n", verif);

		if(strcmp(verif, "ATT")==0  || strcmp(verif, "ATC")==0 || strcmp(verif,"ACT")==0)
		{
			//////////////////////////////debug
			if(debug=='O')
			printf("\n\tSéquence de fin trouvée à l'indice %d\n", i);
			for(k=i; k<(*nbnuc-3); k++)
			{
				///////////////////////////debug
				if(debug=='O')
					printf("\n\t\t ORIG :  brinBleu[%d] = '%c'\n", k, brinBleu[k]);

				//décalage des nucléotides vers la gauche pour écraser la séquence de fin
				brinBleu[k] = brinBleu[k+3];
				brinRouge[k] = brinRouge[k+3];
				///////////////////////////debug
				if(debug=='O')
					printf("\n\t\t MODIF  :  brinBleu[%d] = '%c'\n", k, brinBleu[k]);
				compteurModif++;
				///////////////////////////debug
				if(debug=='O')
					printf("\n\tNombre de modifications :\t%d\n", compteurModif);
			}
			brinBleu[strlen(brinBleu)-3]='\0';
			brinRouge[strlen(brinRouge)-3]='\0';
			*nbnuc -=3;
			return 1;
		}
	}
	
	if (debug=='O')
	printf("\n\tPas de sequence de fin trouvée\n");
	return 0;
}



// fonction utilisée dans FinirBrin //defseqfin
// rajoute "ATC" à la fin si la séquence ne se termine pas par une séquence de fin
int SeqFin (char *brinBleu, unsigned int *nbnuc, char debug)
{
	char verifFin[4]="";
	int i;

	for(i=0; i<3; i++)
	{
		verifFin[i]=brinBleu[strlen(brinBleu)-i-3];
	}

	//////////////debug
	printf("\nLes trois dernières nucléotides sont : %s\n", verifFin);

	if(strcmp(verifFin, "ATT")==0  || strcmp(verifFin, "ATC")==0 || strcmp(verifFin,"ACT")==0)
	{
		printf("\nC'est une séquence de fin correcte.\n");
	}
	else
	{
		printf("\nCe n'est pas une séquence de fin correcte\n");
		strcat(brinBleu, "ATC");
		printf("\nLa nouvelle séquence est : %s\n", brinBleu);
		*nbnuc+=3;
	}
	return 0;

}

