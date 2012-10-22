int coupValide(int joueur, plateau p, int NumLigne, int NumColonne)
{
   
   return(faitPrise(joueur,p,NumLigne,NumColonne)
            && (renvoieContenuCase(p,NumLigne,NumColonne)==0));
}


int faitPrise(int joueur,plateau p, int NumLigne, int NumColonne)
{
    int i,compte_tmp; 
    int compte=0;

    for(i=0;i<8;i++)
    {
		compte_tmp = faitPriseDansDirection(i,joueur,p,NumLigne,NumColonne);
		compte+=compte_tmp;
    }

    return (compte!=0);
   
}

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
