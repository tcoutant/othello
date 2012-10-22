#include<stdio.h>
#define N 8


void initialiserPlateau(plateau p)
{
	int i, j;

	for(i=0;i<N; i++)
		for(j=0;j<N;j++)
			p[i][j]=0;

	p[(N/2)-1][(N/2)-1]	= 1;
	p[(N/2)-1][(N/2)]	= 2;
	p[(N/2)][(N/2)-1]	= 2;
	p[(N/2)][(N/2)]		= 1;
}



void afficherPlateau(plateau p)
{
	int i,j,k;

	printf("\v");
	
	for(i=0;i<N;i++)
	{
		printf("\t");
		for(k=0;k<N;k++)
		{
			printf("+---");
		}
		
		printf("+\n\t|");
		
		for(j=0;j<N;j++)
		{
			if(p[i][j]==0)
				printf("   |");
			else if (p[i][j]==1)
					printf(" @ |");
				else
					printf(" O |");
		}
		printf("\n");
	}
	printf("\t");

	for(k=0;k<N;k++)
	{
		printf("+---");
	}
	printf("+\n\n\n");
}


int main()
{
	plateau p;

	initialiserPlateau(p);

	afficherPlateau(p);

	return 0;
}
