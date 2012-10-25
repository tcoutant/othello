#include <stdio.h>
#include <stdlib.h>

#include "definitions.h"
#include "fmenu.h"
#include "fprise.h"
#include "ftour.h"
<<<<<<< HEAD
#include "HumainVsHumain.h"
#include "HumainVsCPURandom.h"
#include "HumainVsCPUMaxPions.h"
#include "HumainVsCPUMinOptions.h"
=======
#include<time.h>
>>>>>>> f568341fc38d57ba1e0a6032acf84599ca711822


/*/////////////////////////////////
 /                                              
 /    Nom : int proposeEtChoixMenu()
 /                           
 /    retourne le choix du menu principal
 /        
 /////////////////////////////////*/

int proposeEtChoixMenu()
{
   int choix;
   choix=-1;
   do
   {
      printf("\n\n\n");
      printf("______________________________________________________\n"); 
      printf("|                                                     |\n");
      printf("|            Menu Principal du jeu othello            |\n");
      printf("______________________________________________________\n");
      printf("\n");
      printf("         1 - Jouer\n");
      printf("\n");
      printf("         2 - Règles\n");
      printf("\n");
      printf("         3 - Auteurs\n");
      printf("\n");
      printf("         4 - Quitter\n");
      printf("\n\n\n"); 
      printf("   Faites votre choix puis appuyez sur Entrée...\n");
      scanf(" %i",&choix);
   }      while(choix<1 || choix>4);
   
   return choix;
}



/*/////////////////////////////////
 /                                              
 /    Nom : int proposeEtChoixModeDeJeu()
 /                           
 /    retourne le choix du mode de jeux
 /        
 /////////////////////////////////*/

int proposeEtChoixModeDeJeu()
{
   int mode;
   mode=-1;
   do
   {
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
		printf("______________________________________________________\n"); 
		printf("|                                                     |\n");
	 	printf("|              Menu choix du type de jeu             |\n");
		printf("______________________________________________________\n");
		printf("\n");
		printf("         1 - à 2 joueurs \n");
	 	printf("\n");
		printf("         2 - un joueur contre l'ordinateur \n");
		printf("\n");
		printf("         3 - Ordinateur contre Ordinateur\n");
		printf("\n");
		printf("         4 - Retour au Menu Principal \n");
		printf("\n");	
		printf("\n\n\n\n\n\n"); 
		printf("   Faites votre choix puis appuyez sur Entrée...\n");
		scanf("%i",&mode);
    }while(mode<1 || mode>3);
   
   return mode;
}


/*/////////////////////////////////
 /                                              
 /    Nom : int proposeEtChoixNiveauDeJeu()                          
 / 
 /    retourne le niveau de jeux choisi
 /        
 /////////////////////////////////*/

int proposeEtChoixNiveauDeJeu()
{
   int niveau;
   niveau=-1;
   do
   {
      printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
      printf("______________________________________________________\n"); 
      printf("|                                                     |\n");
<<<<<<< HEAD
      printf("|             Menu choix du niveau de jeu             |\n");
      printf("______________________________________________________\n");
      printf("\n");
      printf(" 1 - Niveau 'Random', réponse aléatoire de l'ordinateur \n");
      printf("\n");
      printf(" 2 - Niveau 'MaxPions', l'ordinateur joue le coup qui maximise le nombre de pièces prises à l'adversaire\n");
      printf("\n");
      printf(" 3 - Niveau 'MinOptions, l'ordinateur joue le coup qui minimise le nombre de possibilités de l'adversaire\n");
      printf("\n");
      printf(" 4 - Niveau expert, l'ordi utilise minimax\n");
      printf("\n\n\n\n\n\n"); 
      printf("   Faites votre choix puis appuyez sur Entrée...\n");
      scanf("%i",&niveau);
    } 	  while(niveau<1 || niveau>4);
=======
      printf("|              Menu choix du type de jeu             |\n");
      printf("______________________________________________________\n");
      printf("\n");
      printf("         1 - à 2 joueurs \n");
      printf("\n");
      printf("         2 - un joueur contre l'ordinateur \n");
      printf("\n");
      printf("         3 - Retour au Menu Principal\n");
      printf("\n\n\n\n\n\n"); 
      printf("   Faite votre choix puis appuyer sur Entrée...\n");
      scanf("%i",&mode);
    }     while(mode<1 || mode>3);
>>>>>>> f568341fc38d57ba1e0a6032acf84599ca711822
   
   return niveau;
}




/*/////////////////////////////////
 /                                              
 /    Nom : int proposeEtChoixNiveauDeJeu()                          
 / 
 /    retourne le niveau de jeux choisi
 /        
 /////////////////////////////////*/

int proposeEtChoixNiveauDeJeuCPUVsCPU(int num)
{
   int niveau;
   niveau=-1;
   do
   {
      printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
      printf("______________________________________________________\n"); 
      printf("|                                                     |\n");
<<<<<<< HEAD
      printf("|             choix du niveau de l'Ordinateur %d       |\n", num);
=======
      printf("|             Menu choix du niveau de jeu             |\n");
>>>>>>> f568341fc38d57ba1e0a6032acf84599ca711822
      printf("______________________________________________________\n");
      printf("\n");
      printf(" 1 - Niveau 'Random', réponse aléatoire de l'ordinateur \n");
      printf("\n");
      printf(" 2 - Niveau 'MaxPions', l'ordinateur joue le coup qui maximise le nombre de pièces prises à l'adversaire\n");
      printf("\n");
      printf(" 3 - Niveau 'MinOptions, l'ordinateur joue le coup qui minimise le nombre de possibilités de l'adversaire\n");
      printf("\n");
      printf(" 4 - Niveau expert, l'ordi utilise minimax\n");
      printf("\n\n\n\n\n\n"); 
      printf("   Faites votre choix puis appuyez sur Entrée...\n");
      scanf("%i",&niveau);
    } 	  while(niveau<1 || niveau>4);
   
   return niveau;
}

