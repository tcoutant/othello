#include <stdio.h>
#include <stdlib.h>

#include "HumainVsHumain.h"
#include "definitions.h"
#include "fmenu.h"
#include "fprise.h"
#include "ftour.h"





/*/////////////////////////////////
 /                                              
 /    Programme Principal
 /        
 /////////////////////////////////*/


int main()
{
	   
   int menu;
   int c;

   menu=proposeEtChoixMenu();   
     
    switch(menu) {

       case 1: // Le menu jouer a été choisi
         
           menu=proposeEtChoixModeDeJeu();
           
              switch(menu) 
              { 
		 
                  case 1: // Le mode à 2 joueurs a été choisi
                     	HumainVsHumain();
                  break;

                  case 2: // mode 1 joueur contre l'ordi a été choisi
                     	menu=proposeEtChoixNiveauDeJeu();

			switch(menu)
			{
			   case 1: // niveau debutant, ordi random

			   break;

			   case 2: // niveau moyen
			   break;

			   case 3: // niveau experimenté
			   break;

			   case 4: // niveau expert
			   break;
			}
		   main();
                  break;
  
                  case 3: // retour au menu principal
			main();
		  
                  break;

               }

           main();
           
           break;
  
       case 2: // menu affichage des regles a été choisi
	   printf("\n\n\n");
	   printf("     bientot ou plus tard les regles seront écrites\n");
           printf("\n\n\n");
	   printf("tapez 1 puis Entrée pour revenir au menu...\n");

           scanf("%d",&c);
	   while(c!=1)
	   	scanf("%d",&c);
           main();
           break;

       case 3: // menu affichage des auteurs a été choisi

           printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
           printf("______________________________________________________\n"); 
     	   printf("|     stage tutoré dans le cadre de la licence pro    |\n");
     	   printf("______________________________________________________\n");
           printf("\n\n\n");
           printf("                   Jeu d'othello\n\n");
	   printf("   Origines Sources: Vincent Spiewak et Allaedine Elbanna\n");
	   printf("\n");
           printf("   reprit par: Thomas Fraquet, Florent Guibert, Thierry Coutant\n");
           printf("\n\n\n\n\n\n\n");
           printf("tapez 1 puis Entrée pour revenir au menu...\n");
	   
	   scanf("%d",&c);
	   while(c!=1)
	   	scanf("%d",&c);
           main();

           break;

       case 4: //menu quitter le jeu a été choisi
	   
printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
           printf("Au revoir ...\n");
	   printf("\n\n\n");
           break;
 
      
   }

	return 0;
}