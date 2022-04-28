#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
// LES STRUCTURES //
typedef struct famille *pf ;
typedef struct personne *pp ;
typedef struct voiture *pv ;
typedef struct famille { char nom[21] ;pp parent ;pp enfant;pv voiture ; struct famille *next;} famille;
typedef struct personne { char prenom[21] ;char sexe[1];struct personne *next;} personne;
typedef struct voiture { char marque[21] ;char numero[21];struct voiture *next;} voiture;
int nb_alea_012()
{ int Nb_L;
    Nb_L=rand()% (2-(-1))-1;
return Nb_L;
}
int nb_alea_enf()
{ int Nb_L;
    Nb_L=rand()% (6-(-1))-1;
return Nb_L;
}

void cree_fam(pf *neww)
{ *neww=(famille*)malloc(sizeof(famille));}

void cree_persn(pp *neww)
{ *neww=(personne*)malloc(sizeof(personne));}

void cree_voit(pv *neww)
{ *neww=(voiture*)malloc(sizeof(voiture));}

void aff_adrfam(pf p,pf q) // l'adr de suivant famille
{p->next=q;}

void aff_adrper(pp p,pp q) // l'adr de suivant personne
{p->next=q;}

void aff_adrvoit(pv p,pv q) // l'adresse de suivant voiture
{p->next=q;}

void aff_nomfam(pf p, char name[]) // le nom de famille au maillon
{ strcpy(p->nom, name);}

void aff_prenom(pp p, char name[]) // le prenom de la personne au maillon
{ strcpy(p->prenom, name);}

void aff_sexe(pp p, char name[]) // le sexe de la personne
{ strcpy(p->sexe, name);}//

void aff_marque(pv p, char name[]) //la marque de la voiture au maillon
{ strcpy(p->marque, name);}

void aff_numero(pv p, char name[]) // le matricule de la voitureau maillon
{ strcpy(p->numero, name);}

pf next_fam(pf p) // next fam
{return p->next;}

pp next_person(pp p) //next pernonne
{return p->next;}

pv next_voit(pv p) // next voiture
{return p->next;}

char *name_nomfam(pf p) //le nom de la famille
{return p->nom;}

char *name_prenom(pp p) //le prenom de la personne
{return p->prenom;}

char *name_sexe(pp p) // le sexe de la personne
{return p->sexe;}

char* name_marque(pv p) // la marque de la voiture
{return p->marque;}

char* name_numero(pv p) // le numero de la voiture
{return p->numero;}

void aff_fam_parent(pf p,pp q) // l'adr du parent dans la case de la famille
{p->parent=q;}

void aff_fam_enf(pf p,pp q) // l'adresse du enfqnt dans la case de la famille
{p->enfant=q;}

void aff_fam_voit(pf p,pv q) // l'adresse du voiture dans la case de la famille
{p->voiture=q;}
//************************************ MODULES NECESSSAIRES POUR LE TP ***************************************************************************//
void affiche(famille *p)
{   personne *l,*o;
    voiture *w;
    while(p!=NULL)
    {     printf("\n_________________");
        printf("\n ||NOM DE FAMILLE || : \n ");

        printf("\n --> %s | " ,    name_nomfam(p));
                printf("  \n    *** Les Parents :\n");
          l=p->parent;
        while (l!=NULL)
               {
                   printf("* %s - %s | \n",name_prenom(l),name_sexe(l));
                   l=next_person(l);
               }
                printf("  \n   ***  les enfants : \n");
          o=p->enfant;
        while (o!=NULL)
               {
                   printf(" * %s - %s | \n ",name_prenom(o),name_sexe(o));
                   o=next_person(o);
               }
                printf("  \n  ***  les voitures :\n");
          w=p->voiture;
        while (w!=NULL)
               {
                   printf("\n Marque : %s ... -->  Matricule : %s | \n",name_marque(w),name_numero(w));
                   w=next_voit(w);
               }


        p=next_fam(p);

    }
}
//=====================//
int trie_personne(personne *x)
//======================//
{	// permet de trier une liste chainée de caractére en utilisant le principe de tri par bulle //
    int flag,o,i;
	personne *t,*p,*r;
	cree_persn(&r);
	do
	{  p=x;
	    flag=0;
	    while(p!=NULL)     // servira à parcourir la liste chainée //
         {  t=next_person(p);
            if (t!=NULL)
              { o=strcmp((*p).prenom,(*t).prenom);
                if(o>0)
               { for(i=0;i<13;i++)    //  cette boucle permetera de permuter le contenu de deux maillons si le contenu est alphabétiquement supérieur//
                  {
                    r->prenom[i] = p->prenom[i];
                    p->prenom[i] = t->prenom[i];
                    t->prenom[i] = r->prenom[i];
                  }
                    flag=1;
               }

              }
            p=next_person(p);
	     }
     } while(flag!=0);
     return x;
}
//==============================//
//=====================//
int trie_pop2(famille *tete)
//======================//
{	// permet de trier une liste chainée de caractére en utilisant le principe de tri par bulle //
    int flag,o,i;
	famille *t,*p,*r;
	cree_fam(&r);
	do
	{  p=tete;
	    flag=0;

	    while(p!=NULL)     // servira à parcourir la liste chainée //
         { trie_personne(p->enfant);
              t=next_fam(p);
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
            p=next_fam(p);
	     }
     } while(flag!=0);
     return tete;
}
//==============================//
int creer_pop2(int N)
//==============================//
{
    char sexe;
    famille *head, *p , *q ;
    personne *f1, *f2, *p1, *p2;
    voiture *v1, *v2;
    int t,k, Nb_L,n,g, i,m,d ;
    char nomfam[14],Nb_Lu[9];
    const int A=65 , Z=90 , a=97 , z=122;
cree_voit(&v1); cree_voit(&v2);
cree_persn(&f1); cree_persn(&f2);
 cree_fam(&p);
 cree_persn(&p1);
cree_persn(&p2);
 Nb_L=(rand()% (12-3 + 1))+3;
 nomfam[0]=rand()%(Z-A+1)+A;
    for(t=1 ; t<Nb_L ;t++)
    {
     nomfam[t]=rand()%(z-a+1)+a;
     }
     nomfam[Nb_L]='\0' ;
     aff_nomfam(p,nomfam);
     // 1 er enfant //
     k=nb_alea_enf();
     if(k<0) {f1=NULL; aff_fam_enf(p,f1); }
     if(k>=0)
         {
           aff_prenom(f1,"Kylie");aff_sexe(f1,"M");

           aff_fam_enf(p,f1);
               for(i=0;i<k;i++)
                     {  cree_persn(&f2);
                        Nb_L=(rand()% (12-3 + 1))+3;
                        nomfam[0]=rand()%(Z-A+1)+A;
                            for(t=1 ; t<Nb_L ;t++)
                                {
                                nomfam[t]=rand()%(z-a+1)+a;
                                }
                             nomfam[Nb_L]='\0' ;
                           aff_prenom(f2,nomfam);aff_sexe(f2,"M");

                           aff_adrper(f1,f2);
                            f1=f2;
                     }
                                          aff_adrper(f1,NULL);
         }
         //******************************************//


         // 1 er parent //
              k=nb_alea_012();
     if(k<0) {p1=NULL; aff_fam_parent(p,p1); }
     if(k>=0)
         {
           aff_prenom(p1,"Karim");aff_sexe(p1,"M");

           aff_fam_parent(p,p1);
               for(i=0;i<k;i++)
                     {  cree_persn(&p2);
                        Nb_L=(rand()% (12-3 + 1))+3;
                        nomfam[0]=rand()%(Z-A+1)+A;
                            for(t=1 ; t<Nb_L ;t++)
                                {
                                nomfam[t]=rand()%(z-a+1)+a;
                                }
                             nomfam[Nb_L]='\0' ;aff_sexe(p2,"M");
                           aff_prenom(p2,nomfam);

                           aff_adrper(p1,p2);
                            p1=p2;
                     }
                                          aff_adrper(p1,NULL);
         }

         //***************************//
                    //*******voiture*********//
                k=nb_alea_enf();
     if(k<0) {v1=NULL; aff_fam_voit(p,v1); }
     if(k>=0)
         {

           aff_marque(v1,"Jeep");


                           aff_numero(v1,"51985-118-16");

           aff_fam_voit(p,v1);
               for(i=0;i<k;i++)
                     {  cree_voit(&v2);
                        Nb_L=(rand()% (12-1 + 1))+1;
                        nomfam[0]=rand()%(Z-A+1)+A;
                            for(t=1 ; t<Nb_L ;t++)
                                {
                                nomfam[t]=rand()%(z-a+1)+a;
                                }
                             nomfam[Nb_L]='\0' ;
                           aff_marque(v2,nomfam);
    Nb_Lu[0]=rand()% (57-(49))+49;
    Nb_Lu[1]=rand()% (56-(49))+49;
    Nb_Lu[2]=rand()% (55-(49))+49;
    Nb_Lu[3]=rand()% (54-(49))+49;
    Nb_Lu[4]=rand()% (53-(49))+49;
    Nb_Lu[5]=45;
    Nb_Lu[6]=49;
    Nb_Lu[7]=rand()% (50-(49))+49;
    Nb_Lu[8]=rand()% (57-(48))+48;
    Nb_Lu[9]=45;
    Nb_Lu[10]=rand()% (52-(49))+49;
    Nb_Lu[11]=rand()% (57-(49))+49;
    Nb_Lu[12]='\0';

                           aff_numero(v2,Nb_Lu);

                           aff_adrvoit(v1,v2);
                            v1=v2;
                     }
                                          aff_adrvoit(v1,NULL);
         }

          //=======================//


     head=p;
for(i=1;i<N;i++)
{   cree_fam(&q);
    cree_persn(&p1);
    cree_persn(&f1);
    cree_voit(&v1);
    Nb_L=(rand()% (12-3 + 1))+3;
    nomfam[0]=rand()%(Z-A+1)+A;
    for(t=1; t<Nb_L ;t++)
     {
     nomfam[t]=rand()%(z-a+1)+a;
     }
     nomfam[Nb_L]='\0' ;
     aff_nomfam(q,nomfam);

   // **** parents *****//
           k=nb_alea_012();
     if(k<0) {p1=NULL; aff_fam_parent(q,p1); }
     if(k>=0)
         {
           Nb_L=(rand()% (12-3 + 1))+3;
           nomfam[0]=rand()%(Z-A+1)+A;
           for(t=1; t<Nb_L ;t++)
             {
              nomfam[t]=rand()%(z-a+1)+a;
             }
           nomfam[Nb_L]='\0' ;aff_sexe(p1,"F");
           aff_prenom(p1,nomfam);

           aff_fam_parent(q,p1);
               for(m=0;m<k;m++)
                     {  cree_persn(&p2);
                        Nb_L=(rand()% (12-3 + 1))+3;
                        nomfam[0]=rand()%(Z-A+1)+A;
                            for(t=1 ; t<Nb_L ;t++)
                                {
                                nomfam[t]=rand()%(z-a+1)+a;
                                }
                             nomfam[Nb_L]='\0' ; aff_sexe(p2,"M");
                           aff_prenom(p2,nomfam);

                           aff_adrper(p1,p2);
                            p1=p2;
                     }
                                          aff_adrper(p1,NULL);
         }
         //====================================//

//********enfants**********//
     k=nb_alea_enf();
     if(k<0) {f1=NULL; aff_fam_enf(q,f1); }
     if(k>=0)
         {
            Nb_L=(rand()% (12-3 + 1))+3;
           nomfam[0]=rand()%(Z-A+1)+A;
           for(t=1; t<Nb_L ;t++)
             {
              nomfam[t]=rand()%(z-a+1)+a;
             }
           nomfam[Nb_L]='\0' ;aff_sexe(f1,"F");
           aff_prenom(f1,nomfam);


           aff_fam_enf(q,f1);
               for(m=0;m<k;m++)
                     {  cree_persn(&f2);
                        Nb_L=(rand()% (12-3 + 1))+3;
                        nomfam[0]=rand()%(Z-A+1)+A;
                            for(t=1 ; t<Nb_L ;t++)
                                {
                                nomfam[t]=rand()%(z-a+1)+a;
                                }
                             nomfam[Nb_L]='\0';

                              d=(rand()%(3-0+1))+0;
                             if(d==1||d==0)
                             {aff_sexe(f2,"M");}
                             else {aff_sexe(f2,"F");}
                           aff_prenom(f2,nomfam);

                           aff_adrper(f1,f2);
                            f1=f2;
                     }
                                          aff_adrper(f1,NULL);
         }
           //*******voiture*********//
                k=nb_alea_enf();
     if(k<0) {v1=NULL; aff_fam_voit(q,v1); }
     if(k>=0)
         {
            Nb_L=(rand()% (12-0 + 1))+0;
           nomfam[0]=rand()%(Z-A+1)+A;
           for(t=1; t<Nb_L ;t++)
             {
              nomfam[t]=rand()%(z-a+1)+a;
             }
           nomfam[Nb_L]='\0' ;
           aff_marque(v1,nomfam);

    Nb_Lu[0]=rand()% (57-(49))+49;
    Nb_Lu[1]=rand()% (56-(49))+49;
    Nb_Lu[2]=rand()% (55-(49))+49;
    Nb_Lu[3]=rand()% (54-(49))+49;
    Nb_Lu[4]=rand()% (53-(49))+49;
    Nb_Lu[5]=45;
    Nb_Lu[6]=49;
    Nb_Lu[7]=rand()% (50-(49))+49;
    Nb_Lu[8]=rand()% (57-(48))+48;
    Nb_Lu[9]=45;
    Nb_Lu[10]=rand()% (52-(49))+49;
    Nb_Lu[11]=rand()% (57-(49))+49;
    Nb_Lu[12]='\0';

                           aff_numero(v1,Nb_Lu);

           aff_fam_voit(q,v1);
               for(m=0;m<k;m++)
                     {  cree_voit(&v2);
                        Nb_L=(rand()% (12-0 + 1))+0;
                        nomfam[0]=rand()%(Z-A+1)+A;
                            for(t=1 ; t<Nb_L ;t++)
                                {
                                nomfam[t]=rand()%(z-a+1)+a;
                                }
                             nomfam[Nb_L]='\0' ;
                           aff_marque(v2,nomfam);
    Nb_Lu[0]=rand()% (57-(49))+49;
    Nb_Lu[1]=rand()% (56-(49))+49;
    Nb_Lu[2]=rand()% (55-(49))+49;
    Nb_Lu[3]=rand()% (54-(49))+49;
    Nb_Lu[4]=rand()% (57-(49))+49;
    Nb_Lu[5]=45;
    Nb_Lu[6]=49;
    Nb_Lu[7]=rand()% (50-(49))+49;
    Nb_Lu[8]=rand()% (57-(48))+48;
    Nb_Lu[9]=45;
    Nb_Lu[10]=rand()% (52-(49))+49;
    Nb_Lu[11]=rand()% (57-(49))+49;
    Nb_Lu[12]='\0';


                           aff_numero(v2,Nb_Lu);

                           aff_adrvoit(v1,v2);
                            v1=v2;
                     }
                                          aff_adrvoit(v1,NULL);
         }

          //=======================//
     aff_adrfam(p,q);
     p=q;

}
aff_adrfam(p,NULL);
return head;
}
//**************************************************************************************************************************************************//
// MODULES DEMANDES //
//=======================//
int nbenfant(famille *pop)
//======================//
{   int cpt=0;
    personne *w;
    while(pop!=NULL)   //parcourir la liste
    {   w=pop->enfant;
        while(w!=NULL) // parcourir la liste des enfants dans chaque famille
          {   cpt++;       //s'il n'ya pas d'enfants on incrémente
              w=next_person(w);
          }
        pop=next_fam(pop);
    }
return cpt;
}
//============================//
int naissancetrie(famille *pop,char *nomfam,char *pre)
//=============================//
{   personne *nv,*c,*tete,*l;
    famille *p;
    char sexee;
    cree_persn(&nv);
    aff_prenom(nv,pre);
    printf("Entrer le sexe du nouveau ne : ");
    scanf("%s",&sexee);
    aff_sexe(nv,&sexee);
    cree_persn(&tete);
    p=pop;
    while (p!=NULL)       // parcourir les familles
    { if (strcmp(nomfam,p->nom)==0)   // si on trouve le nom de famille correspendant
           {  tete=(p->enfant);
              l=tete;
              c=next_person(l);
              while(c!=NULL)   // parcourir la liste des enfants
              {
                  if (strcmp(pre,tete->prenom)<0)     // si le nom a inserer doit etre inserer au debut
                   {
                       aff_adrper(nv,tete);
                       tete=nv;
                   }
                  if ((strcmp(pre,l->prenom))>0 && (strcmp(pre,c->prenom)<0))   // si on insere au millieu
                   {
                       aff_adrper(l,nv);
                       aff_adrper(nv,c);
                   }
                   l=c;
                   c=next_person(l);
              }
              if(strcmp(pre,l->prenom)>0) // si on insrer a la fin
                 {
                     aff_adrper(l,nv);
                     aff_adrper(nv,NULL);
                 }
              p->enfant=tete;
              }

    p=next_fam(p);}
return pop;}
//======================//
int nbfamillesansparent(famille *pop)
//======================//
{   int cpt=0,cptt=0;
    personne *s;
    while(pop!=NULL) // pour pqrcourir la chaine famille par famille
    {   s=pop->parent;
         if(s==NULL) // cette boucle : pour calcule le nombre des familles qui n'ont pas de parent c-a-d l'adr est null
         {
             cpt++;
         }
      pop=next_fam(pop);
    }
return cpt;


}
//=======================//
int nbenfnomfam(famille *pop, char *nomfam)
//======================//
{   int cpt=0;
    personne *w;
    while(pop!=NULL)// boucle : pour parcourir la chaine des familles

    {
         if(strcmp(nomfam,pop->nom)==0) // on verifie si le nom entree exist deja dans notre liste
         {
          w=pop->enfant;
        while(w!=NULL ) // boucle : pour calculer le nombre d'enfants de la famille saisie
          {

                cpt++;
              w=next_person(w);
          }
         }
        pop=next_fam(pop);
    }
return cpt;}
//=========================//
int Rechfamvoit_1(famille *pop, char *nomm)
//========================//
{
    voiture *w;
    cree_voit(&w);

    while( pop!=NULL ) // boucle pour parcourir la liste
    {
         w=pop->voiture;
    while(w!=NULL) // boucle pour parcourir les voiture d'une famille
    {
        if ( strcmp(nomm,w->numero)==0)  // verifie si on a le meme matricule en entree
         {
              return pop;  // on trouve de la famille qui a cette voiture
         }
         w=next_voit(w);
    }

    pop=next_fam(pop);
    }
return NULL;
}
//====================================//
int main()               // POUR QUE LE TRI ALPHABETIQUE SOIT PRIS EN CONSIDERATION IL FAUDRA COMMENCER LES NOMS PAR DES ** MAJUSCULES//
{   int n,nbenf,sans,enf,vt,adr;
    famille *pop;
    personne *nv;
    char nom[21],prenom[21],namee[21],numeroo[21];
    printf("Combien de familles ? ");
    scanf("%d",&n);
    pop=creer_pop2(n);
    pop=trie_pop2(pop);
    printf("\n Enfants et nom de familles tries : \n");
    affiche(pop);
    sans=nbfamillesansparent(pop);
    printf(" \n Le nombre de famille sans parents dans pop est : %d \n",sans);
    nbenf=nbenfant(pop);
    printf(" \n Le nombre d'enfants de pop est : %d",nbenf);
    printf(" \n Quel est le nom de la famille dont vous cherchez son nombre d'enfants? ");
    scanf("%s",&namee);
    enf=nbenfnomfam(pop,namee);
    printf("\n Le nombre d'enfants Dans la famille %s est : %d \n",namee,enf);
    printf("\n Entrer le nom de famille et le prenom du nouveau ne : ");
    scanf("%s %s",&nom,&prenom);
    pop=naissancetrie(pop,nom,prenom);
    affiche(pop);
    printf("entre nnumero : \n");
    scanf("%s",&numeroo);
    adr=Rechfamvoit_1(pop,numeroo);
    printf("L'adreese de la famille victime du vol de voiture est : %d",adr);
    // pour trouver la famille victime du vole d'une façon plus rapide il st preferable d'utiliser les rabre pour limiter les acces memoires et les iterations non-nécessaires.
}

