#include  <stdio.h> 

main()
{
    int nbre ;
    printf( "  entrez le nombre d’eleves dans la salle\n  " ) ;
    scanf( "%d",  & nbre) ;
    if (nbre  < = 0)
	printf( " il y a %s eleve dans la salle ", nbre==0 ?  " aucun "  :  " " ) ;
    else
	printf( " il y a %d eleve%s dans la salle ", nbre, nbre==1 ?  " "  :  " s " )  ;
}
