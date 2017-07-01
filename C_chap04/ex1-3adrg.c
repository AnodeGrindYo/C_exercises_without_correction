#include  <stdio.h> 
 
 main()
 {
 char animal[20] ;
 char animal1[20] ;
 char animal2[20] ;
  
  printf( "  entrez un nom d animal \n  " ) ;         /*saisissez loup garou */
  scanf( "%s", animal) ;
  printf( " vous avez saisi : %s\n ", animal) ;
   
   printf( "  entrez un nom d animal \n  " ) ;
   scanf( "%s", animal) ;  
   printf( " vous avez saisi : %s\n ", animal) ;
    
    printf( "  entrez deux noms d'animaux ou un nom compose \n  " ) ;         /* essayez de saisir loup / garou */
    scanf( "%s / %s", animal1, animal2) ;
    printf( " vous avez saisi : %s %s\n ", animal1, animal2) ;
    }
