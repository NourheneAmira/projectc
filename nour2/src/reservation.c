#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "reservation.h"

int tableau_salle_reserver(ReservationSalle tab[])
{
int n=0;
FILE* f=fopen("/home/nour/Projects/nour2/src/sallesReserve.txt","r");
 if(f!=NULL)
 {
  while(fscanf(f,"%s %c %d %d %d %d",tab[n].num,&tab[n].bloc,&tab[n].dt_resr.jour,&tab[n].dt_resr.mois,&tab[n].dt_resr.annee,&tab[n].hr_resr)!=EOF)
  {
   n++;
  }
 }
fclose(f);
return n;
}

int verifier_reserver(ReservationSalle sa)
{
ReservationSalle s;
int v=0;
FILE* f=fopen("/home/nour/Projects/nour2/src/sallesReserve.txt","r");
 if(f!=NULL)
  {
   while(v!=1 && fscanf(f,"%s %c %d %d %d %d",s.num,&s.bloc,&s.dt_resr.jour,&s.dt_resr.mois,&s.dt_resr.annee,&s.hr_resr)!=EOF)
     {
       if(strcmp(s.num,sa.num)==0)
          {
            if((s.dt_resr.jour==sa.dt_resr.jour) && (s.dt_resr.mois==sa.dt_resr.mois) && (s.dt_resr.annee==sa.dt_resr.annee) && (s.hr_resr==sa.hr_resr))
               {
                 v=1;
               }
          }
     }
   }
fclose(f);
return v;
}

int tableau_salle_disponible(char nom_salle[50][10],char bloc,Date dt_resr,int hr_resr)
{
int v=1,nS=0;
FILE* f=fopen("/home/nour/Projects/nour2/src/salle.txt","r");
ReservationSalle s;
s.bloc=bloc;
s.dt_resr=dt_resr;
s.hr_resr=hr_resr;
 if(f!=NULL)
  {
   while(fscanf(f,"%s",s.num)!=EOF)
    {
      if(s.num[0]==s.bloc)
       {
         v=verifier_reserver(s);
	  if(v==0)
            {
               strcpy(nom_salle[nS],s.num);
                nS=nS+1;
            }
       } 
    }
  }
fclose(f);
return nS;
}

void reserver_salle(ReservationSalle s)
{
FILE* f=fopen("/home/nour/Projects/nour2/src/sallesReserve.txt","a");
 if(f!=NULL)
  {
   fprintf(f,"%s %c %d %d %d %d\n",s.num,s.bloc,s.dt_resr.jour,s.dt_resr.mois,s.dt_resr.annee,s.hr_resr);
  }
fclose(f);
}
