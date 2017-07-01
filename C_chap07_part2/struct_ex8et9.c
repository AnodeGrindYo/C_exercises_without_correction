#include <stdio.h>
#include <string.h>

/* Note: Afin de mieux s'y retrouver, les structures ont le préfixe st_, les fonctions le préfixe f_ et les tableaux le préfixe t_*/


// un élève se définit par son nom, son prenom et son âge 
struct st_eleve
{
	char nom[20];
	char prenom[20];
	unsigned int age;
};


// fonction qui permet d'afficher les caractéristiques de l'élève 
void f_afficher_eleve(struct st_eleve e);

// fonction qui permet d'entrer les données relatives à un élève
// à partir des données saisies au clavier
void f_affecter_eleve(struct st_eleve *eleve);

// fonction qui permet de trouver les clones d'un élève. Les trois derniers paramètres sont utilisées dans
// f_rechercher_classe
int f_comparer_eleve(struct st_eleve e, struct st_eleve e2);

// menu de la recherche permettant de choisir différents critères de recherche
void f_menu_recherche(struct st_eleve *a_trouver, struct st_eleve t_ma_classe[32], int nbre);

// fonction qui sert à saisir les élèves d'une classe
void f_saisir_classe(struct st_eleve t_ma_classe[32], int *nbre);

// fonction qui permet de savoir si un élève existe dans la classe (demande nom, prenom et âge)
void f_rechercher_classe(struct st_eleve *a_trouver, struct st_eleve t_ma_classe[32], int nbre);

// recherche par le nom
int f_rechercher_nom(struct st_eleve t_ma_classe[32], int nbre);

// recherche par le prenom
int f_rechercher_prenom(struct st_eleve t_ma_classe[32], int nbre);

// appeler le directeur
void f_schmilblick();

// conversion string en majuscules
void f_convert_maj(char chaine_a_convertir[20]);


	main()
{
	struct st_eleve e={"", "", 0};
	struct st_eleve moi={"Godoy", "Adrien", 28};
	struct st_eleve mon_jumeau={"Godoy", "Charles-Edouard", 28};
	struct st_eleve wanted = {"", "", 0};// sera utile pour rechecher dans une classe
	struct st_eleve eleve_random={"Trump", "Donald", 70};
	struct st_eleve autre_moi = moi;// test d'affectation
	int nbre = 0; // effectif de la classe
	char trucs_inutiles;// affichage des trucs inutiles (autres exercices que le 8);
	// définition d'un classe comportant 32 élèves max
	struct st_eleve t_ma_classe[32];

	printf("\nVoulez-vous afficher stdout lié aux exercices autres que Q8? (o/N)\n");
	scanf("%c", &trucs_inutiles);
	trucs_inutiles = toupper(trucs_inutiles);
	getchar();

	if(trucs_inutiles == 'O')
	{
		f_afficher_eleve(e);
		f_afficher_eleve(moi);
		f_afficher_eleve(autre_moi);

		//test de la fonction f_affecter_eleve
		printf("\n-------------------------------------------------------------------------");
		printf("\nTest de l'affectation d'un élève :\n");
		f_affecter_eleve(&e);
		f_afficher_eleve(e);

		//test de la fonction f_comparer-eleve
		printf("\n-------------------------------------------------------------------------");
		printf("\nTest de la comparaison de deux élèves de la même famille :\n");
		f_comparer_eleve(moi, mon_jumeau);
		printf("\n-------------------------------------------------------------------------");
		printf("\nTest de la comparaison entre un élève et lui-même :\n");
		f_comparer_eleve(moi, moi);
		printf("\n-------------------------------------------------------------------------");
		printf("\nTest de la comparaison entre deux élèves différents :\n");
		f_comparer_eleve(eleve_random, moi);
	}

	// saisie d'une classe
	printf("\n-------------------------------------------------------------------------");
	f_saisir_classe(t_ma_classe, &nbre);

	// appel du menu pour faire des recherches et appeler le directeur
	f_menu_recherche(&wanted, t_ma_classe, nbre);


}

//defaffichereleve
void f_afficher_eleve (struct st_eleve eleve)
{
	printf("\n%s %s,  %u ans\n", eleve.nom, eleve.prenom, eleve.age); 
}

// fonction pour la saisie des données
void f_affecter_eleve(struct st_eleve *eleve)
{
	printf("\nEntrez le nom, le prénom et l'âge de l'élève sous la forme :");
	printf("\nNom Prenom age\n");
	scanf("%20s %20s %u", eleve->nom, eleve->prenom, &eleve->age); 
	f_convert_maj(eleve->nom);
	f_convert_maj(eleve->prenom);
}

// fonction qui permet de trouver un élève
int f_comparer_eleve(struct st_eleve e, struct st_eleve e2)
{
	int comp_age, comp_nom, comp_prenom;

	// compare les noms
	comp_nom = strcmp(e.nom, e2.nom);
	if(comp_nom == 0)
		printf("\nMême nom\n");
	else
	{
		printf("\nNom différent\n");
		comp_nom = 1;
	}

	// compare les prenoms
	comp_prenom = strcmp(e.prenom, e2.prenom);
	if(comp_prenom == 0)
		printf("\nMême prénom\n");
	else
	{
		printf("\nPrénom différent\n");
		comp_prenom = 1;
	}

	// compare les ages
	comp_age = e.age - e2.age;
	if(comp_age == 0)
		printf("\nMême âge\n");
	else
		printf("\nÂge différent\n");

	// si toutes les variables de comparaisons sont égales à 0, il s'agit probablement du même élève
	if(comp_nom == 0 && comp_prenom == 0 && comp_age == 0)
	{
		printf("\nL'élève est dans cette classe");
		return 0;
	}
	else if(comp_nom == 0)
	{
		printf("\n%s %s et %s %s sont probablement de la même famille.\n", e.prenom, e.nom, e2.prenom, e2.nom);
		return 1;
	}
	else
	{
		printf("\n%s %s et %s %s sont deux personnes différentes.\n", e.prenom, e.nom, e2.prenom, e2.nom);
		return 2;
	}

}


// fonction qui sert à saisir les élèves d'une classe
void f_saisir_classe(struct st_eleve t_ma_classe[32],int *nbre)
{
	int nombre, i; // nbre: nombre d'élèves de la classe

	printf("\n-------------------------------------------------------------------------");
	do
	{
		printf("\ncombien d'élèves comporte la classe? (max 32)\n");
		scanf("%d", &nombre);// j'ai dû créer nombre parce que pour nbre, erreur de segmentation avec & ou *
		getchar();				// ou sans rien (pourquoi??)
	}while (*nbre < 0 || *nbre > 32);

	*nbre = nombre;

	//saisie des élèves
	for(i = 0; i<*nbre ; i++)
	{
		f_affecter_eleve(&t_ma_classe[i]);
	}

	for(i = 0; i<*nbre; i++)
	{
		f_afficher_eleve(t_ma_classe[i]);
	}
}

// fonction qui permet de savoir si un élève d'un nom donné existe dans la classe
void f_rechercher_classe(struct st_eleve *wanted, struct st_eleve t_ma_classe[32], int nbre)
{
	int i, comparaison;

	printf("\n-------------------------------------------------------------------------");


	// saisie de l'élève à chercher
	printf("\nEntrez le nom de l'élève recherché :\n");
	f_affecter_eleve(wanted); // pourquoi on ne met pas de & ici???
	//f_afficher_eleve(*wanted); //ok
	getchar();

	// comparaison avec les élèves de la classe
	for (i=0; i<nbre; i++)
	{
		comparaison = f_comparer_eleve(*wanted, t_ma_classe[i]);
		switch (comparaison)
		{
			case 0:
				{
					printf("\nCorrespondance trouvée :\n");
					f_afficher_eleve(t_ma_classe[i]);	
					break;
				}
			default: break;
		}

	}

}

// menu de la recherche
void f_menu_recherche (struct st_eleve *wanted, struct st_eleve t_ma_classe[32], int nbre)
{
	int choix;
	char try_again;
	do
	{
		do
		{
			printf("\n-------------------------------------------------------------------------\n");
			printf("-------------------------------------------------------------------------\n");
			printf("-\t1)\tRecherche par nom                                       -\n");
			printf("-\t2)\tRecherche par prénom                                    -\n");
			printf("-\t3)\tRecherche par nom ET prenom ET âge                      -\n");
			printf("-\t9)\tAppeler le Directeur                                    -\n");
			printf("-------------------------------------------------------------------------\n");
			scanf("%d", &choix);
			getchar();
		}while (choix!=1 && choix !=2 && choix !=3 && choix!=9);

		switch(choix)
		{
			case 1: 
				{
					f_rechercher_nom(t_ma_classe, nbre);
					break;
				}
			case 2:
				{
					f_rechercher_prenom(t_ma_classe, nbre);
					break;
				}
			case 3:
				{
					f_rechercher_classe(wanted, t_ma_classe, nbre);
					break;
				}
			case 9:
				{
					f_schmilblick();
					break;
				}
			default:
				{
					printf("Something impossible happened !");
					break;
				}
		}
		printf("\nVoulez-vous effectuer une autre recherche ?\n");
		scanf("%c", &try_again);
		getchar();
	}while(toupper(try_again) == 'O');
}

// fonction de recherche par le nom
int f_rechercher_nom(struct st_eleve t_ma_classe[32], int nbre)
{
	int comp_nom, i;
	char nom_wanted[20]="";

	// saisie du nom à chercher
	printf("\nNom?\t");
	scanf("%s", &nom_wanted);
	getchar();

	// conversion de la saisie en majuscule
	f_convert_maj(nom_wanted);

	// compare les noms
	for(i=0; i<nbre; i++)
	{
		comp_nom = strcmp(t_ma_classe[i].nom, nom_wanted);
		if(comp_nom == 0)
		{
			printf("\nCorrespondance trouvée :\n");
			f_afficher_eleve(t_ma_classe[i]);
			return 1;// en prévision d'usages futurs
		}
	}
	return 0;
}

// fonction de recherche par le prénom
int f_rechercher_prenom(struct st_eleve t_ma_classe[32], int nbre)
{
	int comp_prenom, i;
	char prenom_wanted[20]="";

	// saisie du prenom à chercher
	printf("\nPrénom?\t");
	scanf("%s", &prenom_wanted);
	getchar();
	
	// conversion de la saisie en majuscule
	f_convert_maj(prenom_wanted);

	// compare les noms
	for(i=0; i<nbre; i++)
	{
		comp_prenom = strcmp(t_ma_classe[i].prenom, prenom_wanted);
		if(comp_prenom == 0)
		{
			printf("\nCorrespondance trouvée :\n");
			f_afficher_eleve(t_ma_classe[i]);
			return 1;
		}
	}
	return 0;
}

void f_schmilblick()
{
	printf("\n");
	printf("\t\t________________1¶¶¶¶¶¶¶¶¶¶¶1________________\n");
	printf("\t\t_____________¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶1____________\n");
	printf("\t\t__________¶¶¶¶118¶¶8¶¶¶¶¶¶¶¶¶¶¶¶¶¶___________\n");
	printf("\t\t_______8¶¶¶¶888¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶8________\n");
	printf("\t\t______¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶______\n");
	printf("\t\t____8¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶____\n");
	printf("\t\t___¶¶¶¶¶¶¶¶¶¶¶8¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶8¶¶¶___\n");
	printf("\t\t__8¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶8¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶8¶¶¶¶__\n");
	printf("\t\t__¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶88881__¶¶¶¶¶¶¶__\n");
	printf("\t\t_¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶81___________¶¶¶¶¶¶__\n");
	printf("\t\t1¶¶¶¶¶111____________________________8¶¶¶¶¶¶_\n");
	printf("\t\t¶¶¶¶¶1___________________________1___1¶¶¶¶¶¶_\n");
	printf("\t\t¶¶¶¶¶8111___________________________11¶¶¶¶¶¶_\n");
	printf("\t\t1¶¶¶¶88111__________________________111¶¶¶¶¶_\n");
	printf("\t\t_¶¶¶¶1881________________________11111_¶¶¶¶¶_\n");
	printf("\t\t_¶¶¶¶18811_____________________¶¶¶¶¶¶8_1¶¶¶¶1\n");
	printf("\t\t_¶¶¶¶118¶¶¶¶81______________8¶¶¶¶¶¶¶¶¶_1¶¶¶8¶\n");
	printf("\t\t_8¶¶881¶¶¶¶¶¶¶¶¶1_________1¶¶¶¶811__1¶811¶¶1¶\n");
	printf("\t\t¶¶¶¶118¶1__18¶¶¶¶¶8118818¶¶¶88¶111¶888¶11¶¶18\n");
	printf("\t\t¶8¶¶11¶¶11¶¶111¶¶¶¶¶1___1¶¶¶¶1_1¶__¶¶8888¶¶8_\n");
	printf("\t\t_1¶¶11¶¶¶¶¶_8¶8_8¶8¶¶____8188__¶¶__¶1__18881_\n");
	printf("\t\t__8¶88111¶¶_8¶8__1__11___1___111_181___18811_\n");
	printf("\t\t__11881___181111____11_________________1881__\n");
	printf("\t\t__118¶81_____________8_________________1881__\n");
	printf("\t\t___18¶¶1__________1111_____1_11______1_188___\n");
	printf("\t\t___88¶¶8________88____________8¶81____188____\n");
	printf("\t\t______1¶1_____8¶888_11____18¶¶118¶8888888____\n");
	printf("\t\t_______¶¶8881¶¶818¶¶¶¶¶8_1¶¶¶8118¶¶¶¶8888____\n");
	printf("\t\t_______¶¶¶¶¶¶¶¶881188¶¶¶¶¶¶818¶¶¶¶¶__1888____\n");
	printf("\t\t_______¶888¶18¶¶¶¶¶8888¶¶¶8¶¶¶¶8_11__88¶_____\n");
	printf("\t\t______1¶¶8181_118¶¶¶¶¶¶¶¶¶¶¶¶8111___8¶¶______\n");
	printf("\t\t¶¶¶¶¶¶¶¶¶¶88¶8_1_18¶¶¶¶¶¶¶8881_____1¶8_______\n");
	printf("\t\t88888¶¶¶¶¶¶¶¶¶8_11118881111_______8¶¶________\n");
	printf("\t\t88118¶__¶¶8¶8888_1_____________18¶¶_¶¶_______\n");
	printf("\t\t88888¶___¶¶8818¶¶11_1_______11¶¶¶8__¶¶¶______\n");
	printf("\t\t¶81¶¶¶____1¶¶¶88¶¶¶88888188¶¶¶¶81__¶¶¶¶¶_____\n");
	printf("\t\t88¶¶¶8______¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶811__1¶¶¶¶¶¶1____\n");
	printf("\t\t8¶¶8_________11_1¶¶¶¶¶¶¶888811__¶¶¶¶8¶¶¶¶1___\n");
	printf("\t\t¶¶8_______¶¶¶¶¶_____11118881__1¶¶¶¶¶¶¶¶¶¶¶___\n");
	printf("\t\t¶1_______¶¶¶¶¶¶______________¶¶¶¶¶¶¶¶¶8¶¶¶8__\n");
	printf("\t\t¶_______¶¶¶¶¶¶¶____________1¶¶¶¶¶¶¶8¶¶¶88¶¶8_\n\n");
}

void f_convert_maj(char raw_txt[20])
{
	int i;
	for (i=0; i<strlen(raw_txt); i++)
		raw_txt[i] = toupper(raw_txt[i]);
}
