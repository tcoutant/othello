int faitPriseDansDirection(int direction, int joueur, plateau p, int NumLigne, int NumColonne)
{
   int dirLigne=0;
   int dirColonne=0;
   
	switch(direction) 
	{
		case 0:			//Case au Nord
			dirLigne=-1;
		break;
	
		case 1:			//Case Nord-Est
			dirLigne=-1;
			dirColonne=1;
		break;

		case 2:			//Case Est
			dirColonne=1;
		break;

		case 3:			//Case Sud-Est
			dirLigne=1;
			dirColonne=1;
		break;
	  
		case 4:			//Case Sud
			dirLigne=1;
		break;

		case 5:			//Case Sud-Ouest
			dirLigne=1;
			dirColonne=-1; 
		break;

		case 6:			//Case Ouest
			dirColonne=-1;
		break;

		case 7:			//Case Nord-Ouest
			dirLigne=-1;
			dirColonne=-1;
		break;
	}
       NumLigne+=dirLigne;
       NumColonne+=dirColonne;

    if(NumLigne>=DIM_MAX 
		|| NumColonne>=DIM_MAX          
		|| NumLigne<0 
		|| NumColonne<0
		|| renvoieContenuCase(p,NumLigne,NumColonne)==joueur
		|| renvoieContenuCase(p,NumLigne,NumColonne)==0)
	{
		return 0;  
	}
	else
	{
		while(NumLigne<DIM_MAX 
              && NumColonne<DIM_MAX 
              && NumLigne>=0 
              && NumColonne>=0 
              && renvoieContenuCase(p,NumLigne,NumColonne)!=joueur 
              && renvoieContenuCase(p,NumLigne,NumColonne)!=0)
		{
			NumLigne+=dirLigne; 
			NumColonne+=dirColonne;
		}
		if(NumLigne>=DIM_MAX
			|| NumColonne>=DIM_MAX  
			|| NumLigne<0 
			|| NumColonne<0)
		{ 
			return 0;
		}
		else  
		{              
			return (renvoieContenuCase(p,NumLigne,NumColonne)==joueur);
		}
   }
}
