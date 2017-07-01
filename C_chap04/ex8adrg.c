#include <stdio.h>

main()
{
	int N=0,i=0, j=0;  // 

	// On demande à l'utilisateur la taille du tableau
	printf("Degré du polynome ?\n");
	scanf("%d", &N);
	//printf("Ni = %d\n", N); // Check OK
	// Création variable tableau aux bonnes dimensions
	int P[N+1][N+1];
	// parcours des lignes
	for(i=0; i<=N; i++)
	{
		//parcours des colonnes
		for(j=0; j<=N; j++)
		{
			if(j==0||i==j)
			{
				P[i][j]=1;
			}
			else if(j>i)
			{
				P[i][j]=0;
			}
			else if(i>0 && j<i)
			{
				P[i][j]=P[i-1][j-1]+P[i-1][j];
			}
			if(P[i][j]>0)
			{
			printf("%4d", P[i][j]);
			}
		}
		printf("\n\n");
	}
}

