/*
	Regarde si le joueur a la possibilité de jouer, en appelant la fonction "coupValide"
*/
int existeCoupPourJoueur(plateau p,int joueur);




/*
	Regarde si l'un des deux joueurs peut jouer. Si aucun ne peut jouer, la partie est finie
	Utilise existeCoupPourJoueur
*/
int partieTerminee(plateau p);



/*
	Une fois le plateau rempli de pions, on le parcourt et incrémente le "NbPions" du bon joueur en fonction de la couleur de chaque case
*/
void comptePions(plateau p, int *NbPions1, int *NbPions2);



/*
	On pose la pièce sur le plateau (la case passe de vide à couleur).
	On appelle ensuite la fonction retournePions, qui retourne les pion qui sont prit lors du coup
	On affiche le nouveau plateau de jeu, avec les modifications
*/
void joueLeCoup(plateau p, int NumLigne, int NumColonne, int joueur);



/*
	On regarde si le pion est posé sur une case vide ou non, et si oui, si la pose fait une prise.
	Si les deux conditions son OK, on retourne 1
	Sinon, on retourne 2
*/
int coupValide(int joueur, plateau p, int NumLigne, int NumColonne);



/*
	On teste toutes les cases du tableau, et si un coup est valide, il crée un nouveau maillon dans une liste chainée, qui contient toutes les cases où l'on peut jouer
*/
int donneTousLesCoupsValides(plateau p, int joueur, Maillon ** teteMaillon);



/*
	On demande à l'utilisateur de rentrer un coup, que l'on stocke dans les deux entiers passés en paramètre
*/
void saisiUnCoup(int joueur, int * NumLigne, int * NumColonne);



/*
	Déroulement du tour d'un joueur
	On regarde si le joueur peut jouer, avec la fonction existeCoupPourJoueur
	Si oui, on liste tous les coups qu'il peut jouer
	On lui demande de saisir des coordonées
	On teste si les valeurs données sont correctes et si le coup est valide
	On joue le coup (retourne les pions qu'il faut....)
*/
void tourJoueur(plateau p, int joueur);


////////////////Tomas -> maxPions

void free_Maillons(Maillon * teteMaillon);

int ecartPions(plateau p);

void dupliPlateau(plateau p, plateau * dupli);

int trouveCoupMaxPions(plateau p, StrCoup * Coup,int joueur);

void tourCPUMaxPions(plateau p, int joueur);


//////// thierry -> fonction qui repond aleatoirement

void moteurOrdiAleatoire(plateau p, int joueur);

//////// Florent : MinOptions

int nbCoupsValides(plateau p, int joueur);

void tourCPUMinOptions(plateau p, int joueur);

int trouveCoupMinOptions(plateau p, StrCoup * Coup,int joueur);



