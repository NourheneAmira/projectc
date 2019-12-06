#include <stdlib.h>
#include <stdio.h>
#include "rese.h"

void ajout_resvol_txt(resvol p )
{
FILE* f;
f=fopen("utilisateur.txt","a");
  if(f!=NULL)
   {
   fprintf(f,"%s %s %s %s %s \n",p.id,p.vol.,p.prenom,p.date_naissence,p.adresse);
   }
fclose(f);
}
int verif di
