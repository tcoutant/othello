#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define DIM_MAX 8

typedef int plateau [DIM_MAX][DIM_MAX];

typedef struct _StrCoup {
                     
                           int ligne;
                           int colonne;
                           int joueur;   
 
                        }StrCoup;

typedef struct _Maillon { 
                        
                          StrCoup coup;
                          struct _Maillon * suivant;
 
                        }Maillon;


void dupliPlateau(plateau p, plateau * dupli)//OK
{  
	int i,j;
	
	for(i=0;i<DIM_MAX;i++)
		for(j=0;j<DIM_MAX;j++)
      (*dupli)[i][j]=p[i][j];  
} 


void free_Maillons(Maillon * teteMaillon)//OK
{
	Maillon * suivantMaillon;
	Maillon * courantMaillon;
	courantMaillon=teteMaillon;
   
	if(!courantMaillon) return;

	while(courantMaillon) 
	{ 
		printf("free maillon: %p\n",courantMaillon);

		suivantMaillon=courantMaillon->suivant;
		free(courantMaillon);
		courantMaillon=suivantMaillon;    
     
	}
}

int trouveCoupMaxPions(plateau p, StrCoup * Coup,int joueur)
{
	int equart_tmp,equart;
	int Ligne,Colonne;

	plateau tmp;//Plateau temporaire pour tester les differents coups

	Maillon * teteMaillon;//Maillon pour avoir les coupsValides
	Maillon * tmpMaillon;//Maillon pour parcourir les coupsValides
   
  
	eval=-70;
	Coup->joueur=joueur;

	teteMaillon=NULL; 

	donneTousLesCoupsValides(p,joueur,&teteMaillon);
	tmpMaillon=teteMaillon;

   /*   Parcours de la liste chainée*/
   
	/* Tant que le maillon a un suivant */
	while(tmpMaillon->suivant!=NULL) 
	{
       /* Duplication du Plateau*/
		dupliPlateau(p,&tmp);

		Ligne = tmpMaillon->coup.ligne;
		Colonne = tmpMaillon->coup.colonne;         
 
		printf("Maximise: evaluation de la position: (%c %d)\n",Colonne+'a',Ligne+1);
       
		tmp[Ligne][Colonne]=joueur;
		retournePions(joueur,(*tmpPlateau),Ligne,Colonne);
         
       // afficherPlateau(tmp);
       

		eval_tmp=evalue(tmp);

		printf("Maximise:\n\tresultat: eval:%d eval_tmp:%f\n",eval,eval_tmp);

		if(eval<eval_tmp)
		{
			printf("Maximise: Ce coup est meilleur\n");
			eval=eval_tmp;
			Coup->ligne=Ligne;
			Coup->colonne=Colonne;
			printf("\n");
		}
		else 
			printf("\n");

		/* Passage du maillon suivant */
		tmpMaillon = tmpMaillon->suivant;
	}; 

   free_Maillons(teteMaillon); //Liberation de tout les maillons
	
	return eval;   //renvoie le plus grand nombre d'equart de point possible entre les deux joueurs
}





void tourCPU(plateau p, int joueur)
{
	char c;
	StrCoup * Coup;   

	if(existeCoupPourJoueur(p, joueur) == 0) 
	{
		printf("Vous devez passer, joueur numero %d ! \nAppuyer sur une touche pour continuer\n",joueur);
   
		fgets(&c,1,stdin);
		videStdin();
	} 
	else
	{
		Coup=(StrCoup *) malloc(sizeof(StrCoup)); 

		if(Coup == NULL)
			printf("Allocation de memoire dans tourCPU impossible\n"); 

	/* Retient le meilleur coup possible dans la variable Coup */

	printf("Equart retenu apres coup: %d\n",trouveCoupMaxPions(p,Coup,joueur));

	joueLeCoup(p,(Coup->ligne),(Coup->colonne),joueur);

	free(Coup); //Liberation de la structure Coup
	}      
}



void CPUvsCPU()
{
	plateau p;
	int tour_joueur=2,Point1=0,Point2=0; 

	//demandeDIM_MAX();
   
	initialisePlateau(p);
	afficherPlateau(p); 

	do
	{ 
		if((tourJoueur%2)==0)
		{
			tourCPU(p,1);
		}
		else
		{
			tourCPU(p,2);
		}
		cpt_joueur++;

	}while(partieTerminee(p) != 0);

        printf("\n\n\n\n La Partie est terminee !\n");

        comptePions(p,&Point1,&Point2);
        printf("Le score est : CPU1 %d - CPU2 %d\n",Point1,Point2);
}

int main()
{
	return 0;
}