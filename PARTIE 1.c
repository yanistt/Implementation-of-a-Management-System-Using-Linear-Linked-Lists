#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include <windows.h>
void color(int couleurDuTexte,int couleurDeFond) // fonction d'affichage de couleurs
{
        HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(H,couleurDeFond*16+couleurDuTexte);
}


//****************************************** FONCTIONS NECESSAIRES ***************************************************************************//
typedef struct maillon

{
    struct maillon *prochain;
     char nom[13];

} maillon;
void  allouer(maillon **Neww)
{
    *Neww=(maillon*)malloc(sizeof(maillon));
}
void aff_adr(maillon *p ,maillon *q)
{
    p->prochain=q;
}
void aff_val(maillon *p, char valeur[])
{
   strcpy(p->nom , valeur);
}
maillon *suivant(maillon *p)
{
    return p->prochain;
}
char *valeur(maillon *p)
{
    return p->nom;
}

void liberer(maillon **Old)
{
    free(*Old);
    *Old=NULL;
}
void affiche(maillon *p)
{
    while(p!=NULL)
    {
        printf("%s | " , valeur(p));
        p=suivant(p);
    }
}
//**************************************************************************************************************************************************//
// * LES MODULES * //
//===========================//
maillon *creer_pop(int N)
//==========================//
{
    maillon *head, *p , *q ;
    int t, Nb_L , i ;
    char nomfam[14];
    const int A=65 , Z=90 , a=97 , z=122;


 allouer(&p);
 Nb_L=(rand()% (12-3 + 1))+3;
 nomfam[0]=rand()%(Z-A+1)+A;
    for(t=1 ; t<Nb_L ;t++)    // servira à generer un nom aleatoire //
    {
     nomfam[t]=rand()%(z-a+1)+a;
     }
     nomfam[Nb_L]='\0' ;
     aff_val(p,nomfam);        // affecter le nom aleatoire dans la case valeur du maillon //
     head=p;
for(i=1;i<N;i++)              // refaire ce qui a été fait précedemment pour N maillon //
{
    allouer(&q);
    Nb_L=(rand()% (12-3 + 1))+3;
    nomfam[0]=rand()%(Z-A+1)+A;
    for(t=1; t<Nb_L ;t++)
    {
     nomfam[t]=rand()%(z-a+1)+a;
     }
     nomfam[Nb_L]='\0' ;
     aff_val(q,nomfam);
     aff_adr(p,q);
     p=q;

}
aff_adr(p,NULL);
return head;
}
//=====================//
int trie_pop(maillon *tete)
//======================//
{	// permet de trier une liste chainée de caractére en utilisant le principe de tri par bulle //
    int flag,o,i;
	maillon *t,*p,*r;
	allouer(&r);
	do
	{  p=tete;
	    flag=0;
	    while(p!=NULL)     // servira à parcourir la liste chainée //
         {  t=suivant(p);
            if (t!=NULL)
              { o=strcmp((*p).nom,(*t).nom);
                if(o>0)
               { for(i=0;i<13;i++)    //  cette boucle permetera de permuter le contenu de deux maillons si le contenu est alphabétiquement supérieur//
                  {
                    r->nom[i] = p->nom[i];
                    p->nom[i] = t->nom[i];
                    t->nom[i] = r->nom[i];
                  }
                    flag=1;
               }

              }
            p=suivant(p);
	     }
     } while(flag!=0);
     return tete;
}
//====================//
int nbfamille(maillon *p,int d)
//===================//
{
    maillon *t;
    int k=d,o,i;
    while(p!=NULL)
         {  t=suivant(p);
            if (t!=NULL)

              { o=strcmp((*p).nom,(*t).nom);
                if(o==0)
        {
            k=k-1;
        }
     }
        p=suivant(p);

    }
    return k;
}
//=================================//
void present(maillon *tete, char *nomfam)
//=================================//
{
    maillon *p;
    int o;
    p=tete;
    while( p!=NULL && o!=0 )
    {   o=strcmp((*p).nom,nomfam);
        if (o==0)
         {
             printf ("l'adresse de la famille est : %d  ", p);
         }
         p=suivant(p);
    }
if(o!=0){printf("cette famille n'existe pas dans pop");}

}
//====================//
int supp(maillon *tete, char *nomfam)
//===================//
{
    maillon *pre,*p;
    allouer(&pre);
    int o;
    p=tete;
    while( p!=NULL && o!=0 )
    {   o=strcmp((*p).nom,nomfam);
        if (o!=0)
        {
        pre=p;
        p=suivant(p);
        }
    }
if (p==tete)    // si le maillon à supprimer se trouve au début //
{
    tete=suivant(p);
}
if (p==NULL)    // si le maillon à supprimer se trouve à la fin //
{
    pre=NULL;
    free(p);
}
else              // sinon s'elle se trouve au millieu  //
{
aff_adr(pre,suivant(p));
free(p);
}
return tete;
}
//====================//
int insrt(maillon *tete, char *name)
//===================//
{
    maillon *t,*p,*w;
    allouer(&w);
    aff_val(w,name);
    p=tete;
    t=suivant(p);
    while(t!=NULL)
    {
      if (strcmp(name,tete->nom)<0)    // Dans le cas ou on insere le nom au début de la liste //
        {
        aff_adr(w,tete);
        tete=w;
        }
      if((strcmp(name,(*p).nom)>0) && (strcmp(name,(*t).nom)<0)) // Dans le cas ou on l'insere au millieu de la liste//
       {
        aff_adr(p,w);
        aff_adr(w,t);
       }
     p=t;
     t=suivant(p);
    }
  if (strcmp(name,(*p).nom)>0) // dans le cas ou on insere a la fin de la liste //
   {
       aff_adr(p,w);
       aff_adr(w,NULL);
   }
  return tete;
}
//====================//
int main()
{                     // POUR QUE LE TRI ALPHABETIQUE SOIT PRIS EN CONSIDERATION IL FAUDRA COMMENCER LES NOMS PAR DES MAJUSCULES//
    //===============================//
    //  ESSAI DE LA PREMIERE PARTIE  //
    //===============================//
    srand(time(NULL));

    printf("======================================= \n");
    color(9,0);
    int N,n_b;
    char name[13],nom[13];
    maillon *head;
    Debut();
    printf("entrer le nombre de familles : \n");
    scanf( "%d", &N);
    head=creer_pop(N);
    affiche(head);
    head=trie_pop(head);
    printf("\n Apres le tri alphabetique : \n");
    affiche(head);
    n_b=nbfamille(head,N);
    printf("\n il ya %d famille!",n_b);
    printf("\n Entrer le nom de famille que vous cherchez : ");
    scanf("%s",&nom);
    present(head,nom);
    printf("\n Entrer le nom de famille que vous voulez supprimer : ");
    scanf("%s",&nom);
    head=supp(head,nom);
    affiche(head);
    printf("\n Entre le nom à inserer: ");
    scanf("%s",&name);
    head=insrt(head,name);
    affiche(head);



      return 0;
}
