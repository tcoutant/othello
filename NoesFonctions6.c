extern char adversaire(int joueur);

extern char renvoieContenuCase(plateau p, int NumLigne, int NumColonne);



typedef struct _StrCoup {
                     
                           int ligne;
                           int colonne;
                           int joueur;   
 
                        } StrCoup;

typedef struct _Maillon { 
                        
                          StrCoup coup;
                          struct _Maillon * suivant;
 
                        } Maillon;

extern void free_Maillons(Maillon * teteMaillon);
extern void videStdin(); 









//proc��dure qui demande la taille du tableau d��ris��e et la stocke dans la variable globale DIM_MAX
void demandeDIM_MAX()
{
   DIM_MAX=0;

   do
   {
      printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
      printf("Entrez la dimension de l'othellier (4,6 ou 8)\n");
      scanf("%i",&DIM_MAX);
      videStdin();

   } while(DIM_MAX!=4 && DIM_MAX!=6 && DIM_MAX!=8);
     printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
}

//__________________________________________________________________________________________________\\

void moteur(plateau p, int joueur)
{
   int testL;
   int testC;
   char c;
   
   

   if(!existeCoupPourJoueur(p,joueur)) 
   {
      printf("Vous devez passer, joueur num��ro %d ! :( \nAppuyez sur une touche pour continuer\n",joueur);
      
      fgets(&c,1,stdin);
      

      videStdin();
 
   } 
   else
   {
      

      do 
      {  
         testL=DIM_MAX;
         testC=DIM_MAX;
   
         printf("CoupsValides: %s\n",donneStringCoupsValides(p, joueur)); 
         
         saisiUnCoup(joueur,&testL,&testC);
            

      } while( 
                (   ( testL >= DIM_MAX )
                 || ( testC >= DIM_MAX )            
                 || ( testL < 0 )   
                 || ( testC < 0 ) 
                ) 
              || ( !coupValide(joueur, p,testL,testC) ) 
             );
         
        joueLeCoup(p,testL,testC,joueur);    

   }      
}


//____________________________________________________________________________________________________________________________

void moteurCPU(plateau p, int joueur)
{

   char c;
   StrCoup * Coup;   


   if(!existeCoupPourJoueur(p, joueur)) 
   {
      printf("Vous devez passer, joueur num��ro %d ! :( \nAppuyer sur une touche pour continuer\n",joueur);
      
      fgets(&c,1,stdin);
      videStdin();
     
   } 
   else
   {


        Coup=(StrCoup *) malloc(sizeof(StrCoup)); 
  
        if(Coup==NULL)
           printf("Allocation dans moteurCPU impossible\n"); 

        printf("Evaluation Retenue(max): %f\n",trouveCoupMinimax(p,joueur,3,Coup));

        joueLeCoup(p,Coup->ligne,Coup->colonne,joueur);

        free(Coup);
        
   }      
}




//________________________________________________________________________________________________________________________________

void joueHumainHumain()
{
   plateau p;  
   int cpt_joueur=2,Px=0,Po=0; 
   
        demandeDIM_MAX();

   initialisePlateau(p);
   affichePlateau(p); 
 

                  
       do
       { 
          if( (cpt_joueur%2)==0 )
          moteur(p,'x');    
          else moteur(p,'o');
          cpt_joueur++;      

       } 
        while(!partieTerminee(p));
     


        printf("\n\n\n\n La Partie est termin��e !\n");
        comptePions(p,&Px,&Po);
        printf("Le score est (o - x):  %i - %i\n",Po,Px);
}

//_________________________________________________________________________________________________________________________________________

void joueHumainVsCPU(int joueur)
{
   plateau p;  
   int cpt_joueur=2,Px=0,Po=0; 

   demandeDIM_MAX();   

   initialisePlateau(p);
   affichePlateau(p); 
 

                  
       do
       { 
          if( (cpt_joueur%2)==0 )
          {
             if(joueur==1)
             moteurCPU(p,1);    
             else moteur(p,1);
          }
          else
          {
             if(joueur==2)
             moteurCPU(p,2);    
             else moteur(p,2);
          }
          
          cpt_joueur++;      

       } 
        while(!partieTerminee(p));
     


        printf("\n\n\n\n La Partie est termin��e !\n");
        comptePions(p,&Px,&Po);
        printf("Le score est (o - x):  %i - %i\n",Po,Px);

}

//_______________________________________________________________________________________________________________________________________________

void joueCPUVsCPU()
{
   plateau p;
   int cpt_joueur=2,Px=0,Po=0; 

   demandeDIM_MAX();
   
   initialisePlateau(p);
   afficheOthellier(p); 
 

                  
       do
       { 
          if( (cpt_joueur%2)==0 )
          {
             
             moteurCPU(p,1);    
         
          }
          else
          {
         
             moteurCPU(p,2);    
         
          }
          
          cpt_joueur++;      

       } 
        while(!partieTerminee(p));
     


        printf("\n\n\n\n La Partie est termin��e !\n");
        comptePions(p,&Px,&Po);
        printf("Le score est (o - x):  %i - %i\n",Po,Px);

}





/
void free_Maillons(Maillon * teteMaillon)
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


void videStdin()
{

     char c;
     c = getchar();

     if (c != '\n')
       while ( (getchar()) != '\n'); 
 
}







void saisiUnCoup(int joueur, int * NumLigne, int * NumColonne)
{

      char tmp[4];

      printf("Veuillez entrez un coup joueur num��ro %d (format: a 1,...,h 8)\npuis appuyer sur Entr��e\n",joueur);

      fgets(tmp, sizeof tmp, stdin);

      *NumLigne=tmp[2]-'0'-1;
      *NumColonne=tmp[0]-'a';
      
      videStdin();

}









int donneTousLesCoupsValides(plateau p, int joueur, Maillon ** teteMaillon)
{
   int i,j,cpt;
   Maillon * courantMaillon;
   Maillon * newMaillon;

   courantMaillon=NULL;
   cpt=0;


   for(i=0;i<DIMENSION_MAX;i++)
       for(j=0;j<DIMENSION_MAX;j++)
              if(coupValide(joueur,p,i,j))
              {                   

                 newMaillon=(Maillon *)malloc(sizeof(Maillon));
                 
                 if(!newMaillon)
                 { 
                    printf("malloc null: newMaillon,donneTousLesCoupsValides \n");
                    exit(1);              
                 }
                 
                 newMaillon->coup.ligne=i;
                 newMaillon->coup.colonne=j;
                 newMaillon->coup.joueur=joueur;

                 newMaillon->suivant=courantMaillon;             
                 courantMaillon=newMaillon;
                  
                 cpt++;

              }       

         *teteMaillon=courantMaillon;

   return cpt;
}
 
 

char * donneStringCoupsValides(plateau p, int joueur)
{
   
   Maillon * teteMaillon;
   Maillon * courantMaillon;
   char * coups;
   int index;


   teteMaillon=NULL;

   coups=(char *)malloc(sizeof(char)*1000);
   if(!coups)
   {
      printf("Alloc:null coups donneStringCoupsValides\n"); 
      exit(1);
   }
   
   index=0;
   
   
   printf("Il y a %i ",
   donneTousLesCoupsValides(p,joueur,&teteMaillon));
   
   courantMaillon=teteMaillon;

      
   while(courantMaillon) 
   { 
                     
      *(coups+index)='(';   index++;
      *(coups+index)=courantMaillon->coup.colonne+'a'; index++;  
      *(coups+index)=' ';   index++; 
      *(coups+index)=(courantMaillon->coup.ligne)+'1'; index++;
      *(coups+index)=')';   index++;  
      *(coups+index)=' ';   index++;

      courantMaillon=courantMaillon->suivant;

   } 

   *(coups+index)='\0';

   return coups; 
  
}

