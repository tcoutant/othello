int retournePions(int joueur, plateau p, int NumLigne, int NumColonne)
{
    int i; 
    int compte=0;
    int cpt_tmp;
    
    for(i=0;i<8;i++)
    {
      cpt_tmp=retournePionsDansDirection(i,camp,grille,NumLigne,NumColonne);
      cpt+=cpt_tmp;
    }
    return cpt;  
}


int retournePionsDansDirection(int direction, int joueur, plateau p, int NumLigne, int NumColonne)
{
   int compte=0;
   int dirLigne=0;
   int dirColonne=0;
   
	switch(dir)
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

    if( !faitPriseDansDirection(direction,joueur,p,NumLigne,NumColonne)) 
    	return 0;

       NumLigne+=dirLigne; 
       NumColonne+=dirColonne;

    while(renvoieContenuCase(p,NumLigne,NumColonne)!=joueur
           && renvoieContenuCase(p,NumLigne,NumColonne)!=0   
           && NumLigne<DIM_MAX
           && NumColonne<DIM_MAX           
           && NumLigne>=0   
           && NumColonne>=0)
	{
       p[NumLigne][NumColonne]=joueur;
       compte++;

       NumLigne+=dirLigne; 
       NumColonne+=dirColonne;
	}
    return compte--; 
}
