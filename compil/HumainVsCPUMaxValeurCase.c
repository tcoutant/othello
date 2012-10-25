#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "definitions.h"
#include "fmenu.h"
#include "fprise.h"
#include "ftour.h"
#include "modeDeJeu.h"
#include "HumainVsCPURandom.h"
#include "HumainVsCPUMaxPions.h"
#include "HumainVsCPUMinOptions.h"
#include "HumainVsCPUMaxValeurCase.h"

void tourCPUMaxValeurCase(plateau p, int joueur)
{
	/* initialisation du tableau des valeurs des cases */
	plateau plateauValeur;
	initialiserPlateauCoef(plateauValeur);


	int nbCoupsPossibles;
	int ligne,colonne;
	int LvalMax=0;
	int CvalMax=0;
	int valeurMax= -1000;

	Maillon *teteMaillon;  //Il sera alloué dans donneTousLesCoupsValides
	Maillon *courantMaillon;//Sert a parcourir teteMaillon, pas besoin d'etre alloué
	
		if(!existeCoupPourJoueur(p, joueur)) 
		printf(" Le joueur numero %d doit passer son tour !  \n",joueur); 
	else
	{
        /*remplit la liste des coups jouables et retourne le nb de coups possibles*/

	nbCoupsPossibles=donneTousLesCoupsValides(p,joueur,&teteMaillon);
	printf("nb de Cases Possibles = %d\n",nbCoupsPossibles);

	courantMaillon = teteMaillon;   //Pour parcourir teteMaillon

	

	/* parcours la liste chainée pour touver la case la plus valorisée */

	while (courantMaillon!=NULL) // on parcourt tous les coups jouables
	{
		//courantMaillon = courantMaillon->suivant;
		ligne=courantMaillon->coup.ligne;
		colonne=courantMaillon->coup.colonne;

		printf("Test de la position: (%c %d)\n",colonne+'a',ligne+1);

		/* on regarde la valeur de la case dans le tableau de coef */
		/* et on la comapre à la valeurMax                         */
		if (plateauValeur[colonne][ligne]>valeurMax)
		{
			valeurMax=plateauValeur[colonne][ligne];
			LvalMax=ligne;
			CvalMax=colonne;
			printf("Ce coup est joué sur une case mieux valorisée : %d points\n",valeurMax);
		}
		else
			printf("Ce coup est joué sur une case qui n'est pas plus valorisée.\n");

		//passage au maillon suivant
		courantMaillon=courantMaillon->suivant;	
	}
	
	free_Maillons(teteMaillon); //Liberation de tout les maillons
	
	/* joue la case la plus valorisée */
	joueLeCoup(p,LvalMax,CvalMax,joueur);
	printf("Coup le plus valorisé joué par l'ordi : (%c %d)\n", 'a'+CvalMax, LvalMax+1);
	    
	}    
}


