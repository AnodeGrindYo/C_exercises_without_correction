#include <stdio.h>
#include <string.h>

/* Note: Afin de mieux s'y retrouver, les structures ont le préfixe s_, les typedef le préfixe t_ et les fonctions le préfixe f_ et les tableaux le préfixe tab_*/


// un élève se définit par son nom, son prenom et son âge 
typedef s_eleve t_eleve;
struct s_eleve
{
	char nom[20];
	char prenom[20];
	unsigned int age;
};

// définition d'une classe
typedef struct s_classe t_classe;
struct s_classe
{
	char nom_classe[10];
	char nom_maitresse[20];
	t_eleve tab_classe[32];
	int nbre; //nombre d'élèves
};

// fonction qui permet d'afficher les caractéristiques de l'élève 
void f_afficher_eleve(t_eleve e);

// fonction qui permet d'entrer les données relatives à un élève
// à partir des données saisies au clavier
void f_affecter_eleve(t_eleve *eleve);

// fonction qui permet de trouver les clones d'un élève. Les trois derniers paramètres sont utilisées dans
// f_rechercher_classe
int f_comparer_eleve(t_eleve e, t_eleve e2);

// menu de la recherche permettant de choisir différents critères de recherche
void f_menu_recherche(t_eleve tab_classe[32], int *nbre, t_eleve *eleve);

// fonction qui sert à saisir les élèves d'une classe
void f_saisir_classe(t_eleve tab_classe[32], int *nbre);

// fonction qui permet de savoir si un élève existe dans la classe (demande nom, prenom et âge)
int f_rechercher_classe(t_eleve tab_classe[32], int nbre);

// recherche par le nom
int f_rechercher_nom(t_eleve tab_classe[32], int nbre);

// recherche par le prenom
int f_rechercher_prenom(t_eleve tab_classe[32], int nbre);

// appeler le directeur
void f_schmilblick();

// conversion string en majuscules
void f_convert_maj(char chaine_a_convertir[20]);

// tri alphabétique des élèves dans une classe
void f_tri_alpha(t_eleve tab_classe[32], int nbre, int affichage);

// permet d'enlever un élève (Enlever_Eleve)
void f_abduction(t_eleve tab_classe[32], int *nbre);

// permet d'ajouter un élève dans une classe
void f_ajouter_eleve(t_eleve tab_classe[32], int *nbre, t_eleve *eleve);

// Menu permettant de choisir une classe
int f_menu_choix_classe(t_classe tab_ecole[5]

main()
{
	t_eleve eleve={"", "", 0};
	t_eleve tab_classe[32];
	
	// déclaration d'une école contenant plusieurs classes
	t_ecole tab_ecole[5];

	
	// saisie d'une classe
	printf("\n-------------------------------------------------------------------------");
	f_saisir_classe(tab_classe, &nbre);

	// tri alphabétique des élèves
	f_tri_alpha(tab_classe, nbre, 1);

	// appel du menu pour faire des recherches et appeler le directeur
	f_menu_recherche(tab_classe, &nbre, &eleve);


}

//defaffichereleve
void f_afficher_eleve (t_eleve eleve)
{
	printf("\n%s %s,  %u ans\n", eleve.nom, eleve.prenom, eleve.age); 
}

// fonction pour la saisie des données
void f_affecter_eleve(t_eleve *eleve)
{
	printf("\nEntrez le nom, le prénom et l'âge de l'élève sous la forme :");
	printf("\nNom Prenom age\n");
	scanf("%20s %20s %u", eleve->nom, eleve->prenom, &eleve->age); 
	f_convert_maj(eleve->nom);
	f_convert_maj(eleve->prenom);
}

// fonction qui permet de trouver un élève
int f_comparer_eleve(t_eleve e, t_eleve e2)
{
	int comp_age, comp_nom, comp_prenom;

	// compare les noms
	comp_nom = strcmp(e.nom, e2.nom);
	/*if(comp_nom == 0)			// pour debug
	  printf("\nMême nom\n");
	  else
	  {
	  printf("\nNom différent\n");
	  comp_nom = 1;
	  }*/

	// compare les prenoms
	comp_prenom = strcmp(e.prenom, e2.prenom);
	/*if(comp_prenom == 0)		// pour debug
	  printf("\nMême prénom\n");
	  else
	  {
	  printf("\nPrénom différent\n");
	  comp_prenom = 1;
	  }*/

	// compare les ages
	comp_age = e.age - e2.age;
	/*if(comp_age == 0)			// pour debug
	  printf("\nMême âge\n");
	  else
	  printf("\nÂge différent\n");*/

	// si toutes les variables de comparaisons sont égales à 0, il s'agit probablement du même élève
	if(comp_nom == 0 && comp_prenom == 0 && comp_age == 0)
	{
		printf("\nL'élève est dans cette classe");
		return 0;
	}
	/*else if(comp_nom == 0)
	  {
	  printf("\n%s %s et %s %s sont probablement de la même famille.\n", e.prenom, e.nom, e2.prenom, e2.nom);
	  return 1;
	  }
	  else
	  {
	  printf("\n%s %s et %s %s sont deux personnes différentes.\n", e.prenom, e.nom, e2.prenom, e2.nom);
	  return 2;
	  }*/
	else
		return 1;

}


// fonction qui sert à saisir les élèves d'une classe
void f_saisir_classe(t_eleve tab_classe[32],int *nbre)
{
	int nombre, i; // nbre: nombre d'élèves de la classe

	printf("\n-------------------------------------------------------------------------");
	printf("\nSaisie des élèves de la classe\n");
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
		f_affecter_eleve(&tab_classe[i]);
	}

	// affichage de tous les élèves de la classe

	printf("\n\n-------------------------------------------------------------------------\n");
	printf("\nvous avez saisi :\n");
	for(i = 0; i<*nbre; i++)
	{
		f_afficher_eleve(tab_classe[i]);
	}
}

// fonction qui permet de savoir si un élève d'un nom donné existe dans la classe
int f_rechercher_classe(t_eleve tab_classe[32], int nbre)
{
	int i, comparaison;
	int a_renvoyer = -1;
	struct s_eleve wanted = {"", "", 0};

	printf("\n-------------------------------------------------------------------------");
	;

	// saisie de l'élève à chercher
	f_affecter_eleve(&wanted); 	
	getchar();

	// comparaison avec les élèves de la classe
	for (i=0; i<nbre; i++)
	{
		comparaison = f_comparer_eleve(wanted, tab_classe[i]); // renvoie 0 si correspondance trouvée
		switch (comparaison)
		{
			case 0:
				{
					printf("\nCorrespondance trouvée \n");
					f_afficher_eleve(tab_classe[i]);	
					a_renvoyer = i;
					break;
				}
			default: 
				{
					break;
				}
		}

	}
	return a_renvoyer;
}

// menu de la recherche
void f_menu_recherche (t_eleve tab_classe[32], int *nbre, t_eleve *eleve)
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
			printf("-\t4)\tSupprimer un élève                                      -\n");
			printf("-\t5)\tAjouter un élève                                        -\n");
			printf("-\t9)\tAppeler le Directeur                                    -\n");
			printf("-------------------------------------------------------------------------\n");
			scanf("%d", &choix);
			getchar();
		}while (choix!=1 && choix !=2 && choix !=3 && choix!=4 &&choix !=5 && choix!=9);

		switch(choix)
		{
			case 1: 
				{
					f_rechercher_nom(tab_classe, *nbre);
					break;
				}
			case 2:
				{
					f_rechercher_prenom(tab_classe, *nbre);
					break;
				}
			case 3:
				{
					f_rechercher_classe(tab_classe, *nbre);
					break;
				}
			case 4:
				{
					f_abduction(tab_classe, nbre);
					break;
				}
			case 5:
				{
					f_ajouter_eleve(tab_classe, nbre, eleve);
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
		getchar();
		printf("\nVoulez-vous effectuer une autre opération ?\n");
		scanf("%c", &try_again);
		getchar();
	}while(toupper(try_again) == 'O');
}


// fonction de recherche par le nom
int f_rechercher_nom(t_eleve tab_classe[32], int nbre)
{
	int comp_nom, i;
	int compt_meme = 0;
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
		comp_nom = strcmp(tab_classe[i].nom, nom_wanted);
		if(comp_nom == 0)
		{
			printf("\nCorrespondance trouvée :\n");
			f_afficher_eleve(tab_classe[i]);
			compt_meme += 1;
		}
	}
	return compt_meme;
}

// fonction de recherche par le prénom
int f_rechercher_prenom(t_eleve tab_classe[32], int nbre)

{
	int comp_prenom, i;
	int compt_meme = 0;
	char prenom_wanted[20]="";

	// saisie du prenom à chercher
	printf("\nPrénom?\t");
	scanf("%s", &prenom_wanted);
	getchar();

	// conversion de la saisie en majuscule
	f_convert_maj(prenom_wanted);

	// compare les prenoms
	for(i=0; i<nbre; i++)
	{
		comp_prenom = strcmp(tab_classe[i].prenom, prenom_wanted);
		if(comp_prenom == 0)
		{
			printf("\nCorrespondance trouvée :\n");
			f_afficher_eleve(tab_classe[i]);
			compt_meme += 1;
		}
	}
	return compt_meme;
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
	printf("\t\t______¶¶8881¶¶818¶¶¶¶¶8_1¶¶¶8118¶¶i¶¶8888____\n");
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

// Fonction qui convertit une chaine en majuscule
void f_convert_maj(char raw_txt[20])
{
	int i;
	for (i=0; i<strlen(raw_txt); i++)
		raw_txt[i] = toupper(raw_txt[i]);
}

//fonction qui effectue le tri par nom des élèves (tri par insertion)
void f_tri_alpha(t_eleve tab_classe[32], int nbre, int affichage)
{
	int i, j;
	t_eleve en_cours ={"","",0};
	char afficher;

	for (i = 1; i < nbre; i++) 
	{
		en_cours = tab_classe[i];
		//printf("en_cours :%s\ttab_ma_classe[i] :%s\n", en_cours.nom, tab_ma_classe[i].nom);// OK
		for (j = i; j > 0 && strcmp(tab_classe[j - 1].nom, en_cours.nom) >0; j--) 
		{
			tab_classe[j] = tab_classe[j - 1];
		}
		tab_classe[j] = en_cours;
	}
	// vérification du bon déroulement de la fonction de tri
	getchar();
	printf("\n\n-------------------------------------------------------------------------\n");
	if (affichage == 1)
	{
		printf("Voulez-vous afficher la liste triée? (o/N)\n");
		scanf("%c", &afficher);
		getchar();
		afficher = toupper(afficher);
		if(afficher == 'O')
		{
			printf("LISTE TRIEE :\n\n");
			for(i=0; i<nbre; i++)
			{
				f_afficher_eleve(tab_classe[i]);
			}
		}
	}
}

void f_abduction(t_eleve tab_classe[32], int *nbre)
{
	int indice_corresp = 0;
	char suppr;

	printf("\nRecherche de l'élève à supprimer :\n");
	// la fonction f_rechercher_classe renvoie l'indice d'une correspondance exacte
	indice_corresp = f_rechercher_classe(tab_classe, *nbre);

	if(indice_corresp >= 0)
	{
		printf("\n/!\\\tVoulez-vous supprimer cet élève ? (o/N)\t/!\\\n");
		scanf("%c", &suppr);
		getchar();
		suppr = toupper(suppr);

		switch(suppr)
		{
			case 'O':
				{
					// fait passer la case de l'élève en fin de tableau
					strcpy (tab_classe[indice_corresp].nom, "ZZZZZZZZZZZZZZZZZZZZ");
					strcpy (tab_classe[indice_corresp].prenom, "ZZZZZZZZZZZZZZZZZZZZ");
					tab_classe[indice_corresp].age = 9999;
					f_tri_alpha(tab_classe, *nbre, 0);

					// puis la supprime
					strcpy (tab_classe[indice_corresp].nom, "");
					strcpy (tab_classe[indice_corresp].prenom, "");
					tab_classe[indice_corresp].age = 0;
					*nbre -= 1;
					printf("L'élève a été supprimé\n");
					break;
				}
			default:
				{
					printf("L'élève n'a pas été supprimé\n");
					break;
				}

		}
	}
}

// permet d'ajouter un élève dans une classe
void f_ajouter_eleve(t_eleve tab_classe[32], int *nbre, t_eleve *eleve)
{
	printf("\n\n-------------------------------------------------------------------------\n");
	printf("\nAjout d'un élève\n");
	*nbre += 1;
	f_affecter_eleve(eleve);
	tab_ma_classe[*nbre-1]= *eleve;
	printf("\nBienvenue à %s %s !\n", tab_classe[*nbre-1].prenom, tab_classe[*nbre-1].nom);
}


