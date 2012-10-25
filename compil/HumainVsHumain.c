#include <stdio.h>
#include <stdlib.h>

#include "definitions.h"
#include "fmenu.h"
#include "fprise.h"
#include "ftour.h"
#include "HumainVsHumain.h"
#include "HumainVsCPURandom.h"
#include "HumainVsCPUMaxPions.h"
#include "HumainVsCPUMinOptions.h"




void HumainVsHumain()
{
	plateau p;  
	int tour=2,Point1=0,Point2=0; 
   
	//demandeDIM_MAX(&DIM_MAX);

	initialiserPlateau(p);
	afficherPlateau(p);

	do
	{ 
		if((tour%2)==0)
			tourJoueur(p,1);    
		else 
			tourJoueur(p,2);
		tour++;
	}while(!partieTerminee(p));

        printf("\n\n\n\n La Partie est terminée !\n");
        comptePions(p,&Point1,&Point2);
        printf("Le score final est :\nJoueur 1 : %d\nJoueur 2 : %i\n",Point1,Point2);
		videStdin();
}
/*_________________________________________________________________________________*/
void HumainVsCPUMaxPions()
{
	plateau p;
	int tour=2,Point1=0,Point2=0; 

	//demandeDIM_MAX();
   
	initialiserPlateau(p);
	afficherPlateau(p); 

	do
	{ 
		if((tour%2)==0)
			tourJoueur(p,1);
		else
			tourCPUMaxPions(p,2);
		tour++;
	}while(!partieTerminee(p));

        printf("\n\n\n\n La Partie est terminee !\n");
        comptePions(p,&Point1,&Point2);
        printf("Le score est : Joueur %d - Ordi %d\n",Point1,Point2);
		videStdin();
}
/*_________________________________________________________________________*/
void HumainVsCPUMinOptions()
{
	plateau p;
	int tour=2,Point1=0,Point2=0; 
  
	initialiserPlateau(p);
	afficherPlateau(p); 

	do
	{ 
		if((tour%2)==0)
			tourJoueur(p,1);
		else
			tourCPUMinOptions(p,2);
		tour++;
	}while(!partieTerminee(p));

        printf("\n\n\n\n La Partie est terminee !\n");
        comptePions(p,&Point1,&Point2);
        printf("Le score est :\nJoueur : %d\nOrdinateur : %d\n",Point1,Point2);
		videStdin();
}
/*_________________________________________________________________________*/
void HumainVsCPURandom()
{
   plateau p;  
   int tour=2,Point1=0,Point2=0; 

   initialiserPlateau(p);
   afficherPlateau(p); 
         
	do
	{ 
		if( (tour%2)==0 )
			tourJoueur(p,1);
		else
			tourCPURandom(p,2);
		tour++;
      
	}while(!partieTerminee(p));

        printf("\n\n\n\n La Partie est terminee !\n");
        comptePions(p,&Point1,&Point2);
        printf("Le score est :\nJoueur : %d\nOrdinateur : %d\n",Point1,Point2);

}
/*____________________________________________________________________________*/
void CPUVsCPU(int niveauOrdi1, int niveauOrdi2)
{
   plateau p;  
   int tour=2,Point1=0,Point2=0; 

   initialiserPlateau(p);
   afficherPlateau(p); 
         
	do
	{ 
		if( (tour%2)==0 )
			switch(niveauOrdi1)
			{
				case 1:
					tourCPURandom(p, 1);
				case 2:
					tourCPUMaxPions(p, 1);
				case 3:
					tourCPUMinOptions(p, 1);
			}
		else
			switch(niveauOrdi2)
			{
				case 1:
					tourCPURandom(p, 2);
				case 2:
					tourCPUMaxPions(p, 2);
				case 3:
					tourCPUMinOptions(p, 2);
			}
		tour++;
      
	}while(!partieTerminee(p));

        printf("\n\n\n\n La Partie est terminee !\n");
        comptePions(p,&Point1,&Point2);
        printf("Le score est :\nOrdinateur 1 : %d\nOrdinateur 2 :  %d\n",Point1,Point2);

}
