#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

////// MACROS //////
#define NB_YAOURT_MAX 100
#define STR_MAX 26


////// STRUCTURES //////

/* 	// t_yaourt : stocke le nom du yahourt, ainsi
	que sa date de péremption.

	// champs:
	char denomination[STR_MAX] : le nom du yaourt
	struct tm DLC : la date de péremption au format struct tm
*/
typedef struct 
{
	char denomination[STR_MAX];
	struct tm DLC;
}t_yaourt;


////// PROTOTYPES DE FONCTIONS //////

/* 	// void date_aujourdhui(time_t *aujourdhui)
	
	affiche la date courante au format jj/mm/aaa
	et met à jour cette date dans time_t *aujourdhui,
	qui est déclaré dans le main()
	
	// paramètres:
	time_t *aujourdhui : stocke la date au format time_t
*/
void date_aujourdhui(time_t *aujourdhui);

/*	// 	void saisir_yaourt(t_yaourt *yogurt)
	
	permet à l'utilisateur de saisir le nom du yahourt, d'une longueur maximale
	définie par #define NB_YAOURT_MAX, ainsi que sa date de péremption qui sera convertie
	pour correspondre au format struct tm. Ces informations sont déclarées dans la structure t_yaourt yogurt
	déclarée dans le main()

	// paramètres :
	t_yaourt *yogurt : voir la description de t_yaourt
*/
void saisir_yaourt(t_yaourt *yogurt);

/*	// void afficher_yaourt(t_yaourt yogurt)
	
	affiche le nom du yaourt et sa date de péremption dans un format intelligible (jj/mm/aaa)
	
	// paramètres :
	t_yaourt yogurt : voir la description de t_yaourt
*/
void afficher_yaourt(t_yaourt yogurt);

/* // void perime_aujourdhui(t_yaourt yogurt, time_t aujourdhui)

	convertit t_yaourt yogurt au format time_t à l'aide de mktime, puis compare cette valeur à
	time_t aujourdhui qui contient la date courante. trois cas sont taités: 
	- 	la date de péremption
		est dépassée depuis plus d'un jour, dans ce cas, la fonction affiche "le yaourt [nom du yaourt] est périmé"
	-	la date de péremption est dans moins de trois jours, la fonction affiche "le yaourt [nom du yaourt] périme 
		dans moins de trois jours"
	- 	la date de péremtion est dans plus de trois jours, la fonction affiche "le yaourt [nom du yaourt] est encore bon"
	enfin, cette fonction fait appel à la fonction nb_jours_avant_dlc (t_yaourt yogurt, time_t aujourdhui) pour déterminer 
	et afficher le nombre de jours avant la DLC ou le nombre de jours écoulés depuis

	// paramètres :
	t_yaourt yogurt 	: 	voir la description de t_yaourt
	time_t aujourdhui 	: 	date courante au format time_t
	*/
void perime_aujourdhui(t_yaourt yogurt, time_t aujourdhui);

/* 	// nb_jour_avant_dlc(t_yaourt yogurt, time_t aujourdhui)
	
	calcule et renvoie un entier correspondant au nombre de jours séparant la date courante de la DLC
	si cet entier est négatif, la DLC n'est pas encore passée
	si il est positif, la date est passée

	// paramètres :
	t_yaourt yogurt 	: 	voir la description de t_yaourt
	time_t aujourdhui 	: 	date courante au format time_t
*/
int nb_jour_avant_dlc(time_t peremption, time_t aujourdhui);


////// MAIN //////
int main(int argc, char *argv[])
{
	t_yaourt yogurt;
	time_t aujourdhui;

	// affiche la date
	date_aujourdhui(&aujourdhui);
	// demande à l'utilisateur de saisir les infos sur le yaourt
	saisir_yaourt(&yogurt);
	// affiche les infos saisie par l'utilisateur (contrôle)
	//afficher_yaourt(yogurt);
	// compare la date courante et la DLC. voir la description de la fonction
	perime_aujourdhui(yogurt, aujourdhui);
	return 0;
}


////// FONCTIONS //////

/* 	// void date_aujourdhui(time_t *aujourdhui)
	
	affiche la date courante au format jj/mm/aaa
	et met à jour cette date dans time_t *aujourdhui,
	qui est déclaré dans le main()
	
	// paramètres:
	time_t *aujourdhui : stocke la date au format time_t
*/
void date_aujourdhui(time_t *aujourdhui)
{
	// temps ecoule depuis 1/1/1970
	// time_t aujourdhui;

	// buffer qui contient la chaine finale
	char buffer[50];

	// on recupere le temps passé
	*aujourdhui  = time(NULL);

	strftime(buffer, 50, "Nous sommes le %d/%m/%Y\n",
	localtime(aujourdhui));

	printf (buffer);
}


/*	// 	void saisir_yaourt(t_yaourt *yogurt)
	
	permet à l'utilisateur de saisir le nom du yahourt, d'une longueur maximale
	définie par #define NB_YAOURT_MAX, ainsi que sa date de péremption qui sera convertie
	pour correspondre au format struct tm. Ces informations sont déclarées dans la structure t_yaourt yogurt
	déclarée dans le main()

	// paramètres :
	t_yaourt *yogurt : voir la description de t_yaourt
*/
void saisir_yaourt(t_yaourt *yogurt)
{
	int day;
	int month;
	int year;

	// saisie par l'utilisateur du nom du yaourt
	printf("\nDenomination du yaourt : ");
	scanf("%s", yogurt->denomination);

	// initialisation de la structure
	memset(&yogurt->DLC, 0, sizeof(yogurt->DLC));

	// saisie par l'utilisateur de la DLC
	printf("Date Limite de Consommation au format jj/mm/aaaa :\n");
	scanf("%d/%d/%d", &day, &month ,&year);


	// ajustement des dates
	// (tm_mon va de 0 à 11, il faut donc décrémenter 
	// la valeur du mois saisie par l'utilisateur de 1)
	month--;
	yogurt->DLC.tm_mon = month;
	// (tm_year stocke le nombre d'années écoulées depuis 1900
	// il faut donc soustraire 1900 à la valeur saisie par l'utilisateur)
	year-=1900;
	yogurt->DLC.tm_year = year;
	// (pour tm_day, pas de problème: stocke le jour du mois de 1 à 31)
	yogurt->DLC.tm_mday = day;
	
	// décomenter pour vérifier la saisie au sein de la fonction
	//printf("\n%s %0.2d/%0.2d/%d\n",yogurt->denomination, yogurt->DLC.tm_mday, yogurt->DLC.tm_mon+1, yogurt->DLC.tm_year+1900/*, yogurt->DLC.tm_mon ,yogurt->DLC.tm_year*/);
}


/*	// void afficher_yaourt(t_yaourt yogurt)
	
	affiche le nom du yaourt et sa date de péremption dans un format intelligible (jj/mm/aaa)
	
	// paramètres :
	t_yaourt yogurt : voir la description de t_yaourt
*/
void afficher_yaourt(t_yaourt yogurt)
{
	// buffer qui contient la chaine finale
	char buffer[50];

	// affichage du nom du yaourt
	printf("\n%s : ", yogurt.denomination);

	strftime(buffer, 50, "Ce yaourt perime le %d/%m/%Y\n",
	&yogurt.DLC);

	printf (buffer);
}


/* // void perime_aujourdhui(t_yaourt yogurt, time_t aujourdhui)

	convertit t_yaourt yogurt au format time_t à l'aide de mktime, puis compare cette valeur à
	time_t aujourdhui qui contient la date courante. trois cas sont taités: 
	- 	la date de péremption
		est dépassée depuis plus d'un jour, dans ce cas, la fonction affiche "le yaourt [nom du yaourt] est périmé"
	-	la date de péremption est dans moins de trois jours, la fonction affiche "le yaourt [nom du yaourt] périme 
		dans moins de trois jours"
	- 	la date de péremtion est dans plus de trois jours, la fonction affiche "le yaourt [nom du yaourt] est encore bon"
	enfin, cette fonction fait appel à la fonction nb_jours_avant_dlc (t_yaourt yogurt, time_t aujourdhui) pour déterminer 
	et afficher le nombre de jours avant la DLC ou le nombre de jours écoulés depuis. Cette durée ne s'affiche pas si
	la date courant tombe le même jour que la DLC

	// paramètres :
	t_yaourt yogurt 	: 	voir la description de t_yaourt
	time_t aujourdhui 	: 	date courante au format time_t
	*/
void perime_aujourdhui(t_yaourt yogurt, time_t aujourdhui)
{
	time_t peremption;
	int jours_restants;

	peremption = mktime(&yogurt.DLC);

	//printf("%d'%d\"%d", yogurt.DLC.tm_hour, yogurt.DLC.tm_min, yogurt.DLC.tm_sec);

	// vérifie si le yaourt est périmé
	if ((peremption+(60*60*24)) < aujourdhui)
		printf("\nle yaourt %s est perime.\n", yogurt.denomination);
	// vérifie si le yaourt périme aujourd'hui
	else if ((peremption - aujourdhui) < (60*60*24))
	{
		printf("\nle yaourt %s perime aujourd'hui.\n", yogurt.denomination);
	}
	// vérifie si le yaourt périme dans moins de 3 jours
	else if ((peremption - aujourdhui) < (3*60*60*24))
	{
		printf("\nle yaourt %s perime dans moins de 3 jours.\n", yogurt.denomination);
	}
	else
		printf("\nle yaourt %s est encore bon.\n", yogurt.denomination);

	// détermination du nombre de jours
	peremption = nb_jour_avant_dlc(peremption, aujourdhui);
	if (peremption < 0)
		printf("nombre de jours avant DLC : %d\n", fabs(peremption));
	else if (peremption > 0)
		printf("il s'est ecoule %d jours depuis la DLC\n", peremption);
}


/* 	// nb_jour_avant_dlc(t_yaourt yogurt, time_t aujourdhui)
	
	calcule et renvoie un entier correspondant au nombre de jours séparant la date courante de la DLC
	si cet entier est négatif, la DLC n'est pas encore passée
	si il est positif, la date est passée

	// paramètres :
	t_yaourt yogurt 	: 	voir la description de t_yaourt
	time_t aujourdhui 	: 	date courante au format time_t
*/
int nb_jour_avant_dlc(time_t peremption, time_t aujourdhui)
{
	int nb_jours;

	// calcul du nombre de jours
	nb_jours = floor((aujourdhui - peremption)/(60*60*24));
	return nb_jours;
}