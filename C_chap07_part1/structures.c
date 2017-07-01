#include <stdio.h>
#include <string.h>

// un élève se définit par son nom, son prenom et son âge //structeleve
struct st_eleve
{
	char nom[20];
	char prenom[20];
	unsigned int age;
};

// fonction qui permet d'afficher les caractéristiques de l'élève //protoaffichereleve
void f_afficher_eleve(struct st_eleve e);

// fonction qui permet d'entrer les données relatives à un élève
// à partir des données saisies au clavier
void f_affecter_eleve(struct st_eleve *eleve);

// fonction qui permet de trouver les clones d'un élève
void f_comparer_eleve(struct st_eleve e, struct st_eleve e2);

main()
{
	struct st_eleve e={"", "", 0};
	struct st_eleve moi={"Godoy", "Adrien", 28};
	struct st_eleve mon_jumeau={"Godoy", "Charles-Edouard", 28};
	struct st_eleve eleve_random={"Trump", "Donald", 70};
	struct st_eleve autre_moi = moi;
	f_afficher_eleve(e);
	f_afficher_eleve(moi);
	f_afficher_eleve(autre_moi);

	//test de la fonction f_affecter_eleve
	printf("\n-------------------------------------------------------------------------");
	printf("\nTest de l'affectation d'un élève :\n");
	f_affecter_eleve(&e);

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

//defaffichereleve
void f_afficher_eleve (struct st_eleve eleve)
{
	printf("\nL'élève %s %s a %u ans\n", eleve.nom, eleve.prenom, eleve.age); 
}

// fonction pour la saisie des données
void f_affecter_eleve(struct st_eleve *eleve)
{
	printf("\nEntrez le nom, le prénom et l'âge de l'élève sous la forme :");
	printf("\nNom Prenom age\n");
	scanf("%20s %20s %u", eleve->nom, eleve->prenom, &eleve->age); 
}

// fonction qui permet de trouver les clones d'un élève
void f_comparer_eleve(struct st_eleve e, struct st_eleve e2 )
{
	int comp_nom, comp_prenom, comp_age;

	// compare les noms
	comp_nom = strcmp(e.nom, e2.nom);
	if(comp_nom == 0)
		printf("\nMême nom\n");
	else
		printf("\nNom différent\n");

	// compare les prenoms
	comp_prenom = strcmp(e.prenom, e2.prenom);
	if(comp_prenom == 0)
		printf("\nMême prénom\n");
	else
		printf("\nPrénom différent\n");
	
	// compare les ages
	comp_age = e.age - e2.age;
	if(comp_age == 0)
		printf("\nMême âge\n");
	else
		printf("\nÂge différent\n");

	// si toutes les variables de comparaisons sont égales à 0, nous avons affaire à un
	// cas de clonage humain. Rappelons que c'est toujours interdit
	if(comp_nom == 0 && comp_prenom == 0 && comp_age == 0)
		printf("\nL'élève a été saisi deux fois ou a été cloné.\n");
	else if(comp_nom == 0)
		printf("\n%s %s et %s %s sont probablement de la même famille.\n", e.prenom, e.nom, e2.prenom, e2.nom);
	else
		printf("\n%s %s et %s %s sont deux personnes différentes.\n", e.prenom, e.nom, e2.prenom, e2.nom);
	
}
