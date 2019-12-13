#include <stdlib.h>
#include <stdio.h>
#include "nour.h"
#include "string.h"
#include <gtk/gtk.h>



////////////////vol//////////////
vol rechercheduvol(char d[])
{vol v;
FILE* f;
f=fopen("vol.txt","r");
if(f!=NULL)
{ 
while(fscanf(f,"%s %s %s %d %d %d %s %s %d %d",v.id,v.dep,v.arr,&v.jv,&v.mv,&v.av,v.heure,v.type,&v.prixv,&v.pl))
			{ 
				if (strcmp(d,v.id)==0)	
                               return(v);		
}
}

}


void ajout_resvol_txt( resvol p )
{
FILE* f;
f=fopen("resvol.txt","a");
  if(f!=NULL)
   {
   fprintf(f,"%d %s %s %s %s %d %d %d %s %s %d %d\n",p.id,p.r.id,p.login,p.r.dep,p.r.arr,p.r.jv,p.r.mv,p.r.av,p.r.heure,p.r.type,p.r.prixv,p.nbrp);
   }
fclose(f);
}

int iddd ()
{FILE* f =fopen("resvol.txt","r");
char s[1500];
int nb=1;
while (fgets(s,1500,f)!=NULL) nb++;
fclose(f);
return nb ;
}

int disponiblevol (vol v, int a)
{
 if (v.pl >= a) 
return 1 ;
else 
return 0;
}


 ///////////////hotel///////////
hotel rechercheduhotel(char d[])
{hotel v;
FILE* f;
f=fopen("hot.txt","r");
if(f!=NULL)
{ 
while(fscanf(f,"%s %s %s %d %s %d %d",v.id,v.lieu,v.nom,&v.e,v.chambre,&v.prix,&v.p))
			{ 
				if (strcmp(d,v.id)==0)	
                               return(v);
}
}

}

void ajout_reshot_txt( reshot p )
{
FILE* f;
f=fopen("reshot.txt","a");
  if(f!=NULL)
   {
   fprintf(f,"%d %s %s %s %s %d %s %d %d %d %d %d %d\n",p.id,p.r.id,p.login,p.r.lieu,p.r.nom,p.r.e,p.r.chambre,p.r.prix,p.j,p.m,p.a,p.nn,p.nbrp);
   }
fclose(f);
}

int idddh ()
{FILE* f =fopen("reshot.txt","r");
char s[1500];
int nb=1;
while (fgets(s,1500,f)!=NULL) nb++;
fclose(f);
return nb ;
}

int disponiblehot (hotel v, int a)
{
 if (v.p>= a) 
return (1);
else 
return (0);
}
  
int bissextile(int an)
{
   if (an%400==0) return 1;
   if (an%100==0) return 0;
   if (an%4==0) return 1;
   return 0;
}

// retourne la longueur du mois selon le mois et l'année
int longueur_mois(int m,int a)
{
    switch(m)
    {
    case 1: return 31;
    case 2:
         if (bissextile(a))
         return 29;
         else
         return 28;
    case 3: return 31;
    case 4: return 30;
    case 5: return 31;
    case 6: return 30;
    case 7: return 31;
    case 8: return 31;
    case 9: return 30;
    case 10: return 31;
    case 11: return 30;
    case 12: return 31;
    default: return 0;
    }
}

// retourne 0 si la date n'est pas valide et 1 dans le cas contraire
int est_valide(int j, int m, int a)
{
    if (((j > 0) && (j <= longueur_mois(m,a)) && ((m > 0) && (m < 13))))
    return 1;
    else
    return 0;
}

 
/////////////////excursion/////////
excursion rechercheduexc(char d[])
{excursion v;
FILE* f;
f=fopen("exc.txt","r");
if(f!=NULL)
{ 
while(fscanf(f,"%s %s %d %d %d %s %d %d",v.id,v.des,&v.j,&v.m,&v.a,v.prog,&v.prix,&v.p))
			{ 
				if (strcmp(d,v.id)==0)	
                               return(v);
				
			}
}

}

void ajout_resexc_txt( resexc p )
{
FILE* f;
f=fopen("resexc.txt","a");
  if(f!=NULL)
   {
   fprintf(f,"%d %s %s %d %d %d %d %s %d %d\n",p.id,p.r.id,p.login,p.r.des,p.r.j,p.r.m,p.r.a,p.r.prog,p.r.prix,p.nbrp);
   }
fclose(f);
}

int iddde ()
{FILE* f =fopen("resexc.txt","r");
char s[1500];
int nb=1;
while (fgets(s,1500,f)!=NULL) nb++;
fclose(f);
return nb ;
}
   
int disponibleexc (excursion v, int a)
{
 if (v.p>= a) 
return (1);
else 
return (0);
}
///////////////////////////reservation/////////////////////////////////
void ajout_res_txt( res z)
{
FILE* f;
f=fopen("reservations.txt","a");
  if(f!=NULL)
   {
   fprintf(f,"%d %s %s %d\n",z.id,z.type,z.login,z.nbrp);
   }
fclose(f);
}
enum   
{       
 
 ID,
 TYPE,
 LOGIN,
 NBRP,
COLUMNS
 
};


void afficher_reservation(GtkWidget *liste)
{
 GtkCellRenderer *renderer;
 GtkTreeViewColumn *column;
 GtkTreeIter    iter;
 GtkListStore *store;


res z;
 store=NULL;
FILE* g;
 FILE *f;
char d[10];
  store=gtk_tree_view_get_model(liste);	
 if (store==NULL)
	{
	 renderer = gtk_cell_renderer_text_new ();
	 column = gtk_tree_view_column_new_with_attributes("identifiant", renderer,"text",ID, NULL);
	 gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

       

	 renderer = gtk_cell_renderer_text_new ();
	 column = gtk_tree_view_column_new_with_attributes("type", renderer, "text",TYPE, NULL);
	 gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);


         renderer = gtk_cell_renderer_text_new ();
	 column = gtk_tree_view_column_new_with_attributes("username", renderer, "text",LOGIN, NULL);
	 gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	 renderer = gtk_cell_renderer_text_new ();
	 column = gtk_tree_view_column_new_with_attributes("nombre de place", renderer, "text",NBRP, NULL);
	 gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
 }


 store=gtk_list_store_new (COLUMNS,G_TYPE_INT,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_INT);
g=fopen("util.txt","r");
			fscanf(g,"%s",d);
			fclose(g);

f = fopen("reservations.txt", "r");

 if(f==NULL)
	{
	 return;
	}		
 else 
	{
 	 f = fopen("reservations.txt", "a+");
	 while(fscanf(f," %d %s %s %d\n",&z.id,z.type,z.login,&z.nbrp)!=EOF)
		{if (strcmp(d,z.login)==0)
		 {gtk_list_store_append (store, &iter);
		 gtk_list_store_set (store,&iter,ID,z.id,TYPE,z.type,LOGIN,z.login,NBRP,z.nbrp,-1); }
		}
	 fclose(f);
	 gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
	 g_object_unref (store);
	}
}

resvol recherche_res_vol_id (int d)
{ 
resvol p;
FILE* f;
f=fopen("resvol.txt","r");
if(f!=NULL)
{ 
while( fscanf(f,"%d %s %s %s %s %d %d %d %s %s %d %d\n",&p.id,p.r.id,p.login,p.r.dep,p.r.arr,&p.r.jv,&p.r.mv,&p.r.av,p.r.heure,p.r.type,&p.r.prixv,&p.nbrp)!=EOF)
			{ 
				if (d==p.id)	
                               return p ;}
                          }

} 
enum   
{       
 
 IDV,
 IDDV,
 LOGINV,
 DEPV,
 ARRV,
 JV,
 MV,
 AV,
 HEUREV,
 TYPEV,
 PRIXVV,
 NBRPV,
COLUMNSV
 
};
void affiche_mon_res_vol (GtkWidget *liste )
{
  GtkCellRenderer *renderer;
 GtkTreeViewColumn *column;
 GtkTreeIter    iter;
 GtkListStore *store;

FILE* f;
resvol p ;
/*p=recherche_res_vol_id (d);*/
 store=NULL;
store=gtk_tree_view_get_model(liste);	
 if (store==NULL)
	{
	 renderer = gtk_cell_renderer_text_new ();
	 column = gtk_tree_view_column_new_with_attributes("id du res", renderer,"text",IDV, NULL);
	 gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

       

	 renderer = gtk_cell_renderer_text_new ();
	 column = gtk_tree_view_column_new_with_attributes("id du vol", renderer, "text",IDDV, NULL);
	 gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);


         renderer = gtk_cell_renderer_text_new ();
	 column = gtk_tree_view_column_new_with_attributes("username", renderer, "text",LOGINV, NULL);
	 gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	 renderer = gtk_cell_renderer_text_new ();
	 column = gtk_tree_view_column_new_with_attributes("depart", renderer, "text",DEPV, NULL);
	 gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	 renderer = gtk_cell_renderer_text_new ();
	 column = gtk_tree_view_column_new_with_attributes("arrivée", renderer,"text",ARRV, NULL);
	 gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

       

	 renderer = gtk_cell_renderer_text_new ();
	 column = gtk_tree_view_column_new_with_attributes("jour", renderer, "text",JV, NULL);
	 gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);


         renderer = gtk_cell_renderer_text_new ();
	 column = gtk_tree_view_column_new_with_attributes("mois", renderer, "text",MV, NULL);
	 gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	 renderer = gtk_cell_renderer_text_new ();
	 column = gtk_tree_view_column_new_with_attributes("année", renderer, "text",AV, NULL);
	 gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	 renderer = gtk_cell_renderer_text_new ();
	 column = gtk_tree_view_column_new_with_attributes("heure", renderer,"text",HEUREV, NULL);
	 gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

       

	 renderer = gtk_cell_renderer_text_new ();
	 column = gtk_tree_view_column_new_with_attributes("type", renderer, "text",TYPEV, NULL);
	 gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);


         renderer = gtk_cell_renderer_text_new ();
	 column = gtk_tree_view_column_new_with_attributes("prix", renderer, "text",PRIXVV, NULL);
	 gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	 renderer = gtk_cell_renderer_text_new ();
	 column = gtk_tree_view_column_new_with_attributes("nombre de place", renderer, "text",NBRPV, NULL);
	 gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
	}
 store=gtk_list_store_new (COLUMNSV,G_TYPE_INT,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_INT,G_TYPE_INT);
f = fopen("resvol.txt", "r");

 if(f==NULL)
	{
	 return;
	}		
 else 
	{
 	 f = fopen("resvol.txt", "r");
	 while(fscanf(f,"%d %s %s %s %s %d %d %d %s %s %d %d\n",&p.id,p.r.id,p.login,p.r.dep,p.r.arr,&p.r.jv,&p.r.mv,&p.r.av,p.r.heure,p.r.type,&p.r.prixv,&p.nbrp)!=EOF)
		 {
		 gtk_list_store_append (store, &iter);
		 gtk_list_store_set (store,&iter,IDV,p.id,IDDV,p.r.id,LOGINV,p.login,DEPV,p.r.dep,ARRV,p.r.arr,JV,p.r.jv,MV,p.r.mv,AV,p.r.av,HEUREV,p.r.heure,TYPEV,p.r.type,PRIXVV,p.r.prixv,NBRPV,p.nbrp,-1); }
		}
 fclose(f);
	 gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
	 g_object_unref (store);
	
}


				
void supprimer_resvol(resvol p)
{
char iddn[20],loginn[20],depn[20], arrn[20],heuren[20],typen[20];
int idn,jvn,mvn,avn,nbrpn,prixvn;
	FILE *f , *tmp;
	f=fopen("resvol.txt","r");
	tmp=fopen("resvol.tmp","a+");
	while(fscanf(f,"%d %s %s %s %s %d %d %d %s %s %d %d\n",&idn,iddn,loginn,depn,arrn,&jvn,&mvn,&avn,heuren,typen,&prixvn,&nbrpn)!=EOF){
		if(p.id==idn ){continue;}
else fprintf(tmp,"%d %s %s %s %s %d %d %d %s %s %d %d\n",idn,iddn,loginn,depn,arrn,jvn,mvn,avn,heuren,typen,prixvn,nbrpn);
}
fclose(f);
fclose(tmp);
rename("resvol.tmp","resvol.txt");
}




void modif_resvol(resvol p)
{
char iddn[20],loginn[20],depn[20], arrn[20],heuren[20],typen[20];
int idn,jvn,mvn,avn,nbrpn,prixvn;
	FILE *f , *tmp;
	f=fopen("resvol.txt","r");
	tmp=fopen("resvol.tmp","a+");
	while(fscanf(f,"%d %s %s %s %s %d %d %d %s %s %d %d\n",&idn,iddn,loginn,depn,arrn,&jvn,&mvn,&avn,heuren,typen,&prixvn,&nbrpn)!=EOF){
		if(p.id==idn ){fprintf(tmp,"%d %s %s %s %s %d %d %d %s %s %d %d\n",p.id,p.r.id,p.login,p.r.dep,p.r.arr,p.r.jv,p.r.mv,p.r.av,p.r.heure,p.r.type,p.r.prixv,p.nbrp);}
else fprintf(tmp,"%d %s %s %s %s %d %d %d %s %s %d %d\n",idn,iddn,loginn,depn,arrn,jvn,mvn,avn,heuren,typen,prixvn,nbrpn);
}
fclose(f);
fclose(tmp);
rename("resvol.tmp","resvol.txt");
}



void supprimer_res(res p)
{
char typen[20],loginn[20];
int idn,nbrpn;
	FILE *f , *tmp;
	f=fopen("reservations.txt","r");
	tmp=fopen("reservations.tmp","a+");
	while(fscanf(f,"%d %s %s %d\n",&idn,typen,loginn,&nbrpn)!=EOF){
		if(p.id==idn ){continue;}
else fprintf(tmp,"%d %s %s %d\n",idn,typen,loginn,nbrpn);
}
fclose(f);
fclose(tmp);
rename("reservations.tmp","reservations.txt");
}

void modif_res(res p)
{
char typen[20],loginn[20];
int idn,nbrpn;
	FILE *f , *tmp;
	f=fopen("reservations.txt","r");
	tmp=fopen("reservations.tmp","a+");
	while(fscanf(f,"%d %s %s %d\n",&idn,typen,loginn,&nbrpn)!=EOF){
		if(p.id==idn ){fprintf(tmp,"%d %s %s %d\n",p.id,p.type,p.login,p.nbrp);}
else fprintf(tmp,"%d %s %s %d\n",idn,typen,loginn,nbrpn);
}
fclose(f);
fclose(tmp);
rename("reservations.tmp","reservations.txt");
}
/////////////modreshotel/////////

reshot recherche_res_hot_id (int d)
{ 
reshot p;
FILE* f;
f=fopen("reshot.txt","r");
if(f!=NULL)
{ 
while(fscanf(f,"%d %s %s %s %s %d %s %d %d %d %d %d %d\n",&p.id,p.r.id,p.login,p.r.lieu,p.r.nom,&p.r.e,p.r.chambre,&p.r.prix,&p.j,&p.m,&p.a,&p.nn,&p.nbrp))
			{ 
				if (d==p.id)	
                               return p ;}
                          }

} 


enum   
{       
 
 IDH,
 IDDH,
 LOGINH,
 LIEUX,
 NOM,
 ETOILE,
 CHAMBRE,
 AH,
JH,
MH,
 PRIXH,
NN,
 NBRPH,
COLUMNSH
 
};
void affiche_mon_res_hotel (GtkWidget *liste )
{
  GtkCellRenderer *renderer;
 GtkTreeViewColumn *column;
 GtkTreeIter    iter;
 GtkListStore *store;

FILE* f;
reshot p ;
/*p=recherche_res_vol_id (d);*/
 store=NULL;
store=gtk_tree_view_get_model(liste);	
 if (store==NULL)
	{
	 renderer = gtk_cell_renderer_text_new ();
	 column = gtk_tree_view_column_new_with_attributes("id du res", renderer,"text",IDH, NULL);
	 gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

       

	 renderer = gtk_cell_renderer_text_new ();
	 column = gtk_tree_view_column_new_with_attributes("id du hotel", renderer, "text",IDDH, NULL);
	 gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);


         renderer = gtk_cell_renderer_text_new ();
	 column = gtk_tree_view_column_new_with_attributes("username", renderer, "text",LOGINH, NULL);
	 gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	 renderer = gtk_cell_renderer_text_new ();
	 column = gtk_tree_view_column_new_with_attributes("lieux", renderer, "text",LIEUX, NULL);
	 gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	 renderer = gtk_cell_renderer_text_new ();
	 column = gtk_tree_view_column_new_with_attributes("nom", renderer,"text",NOM, NULL);
	 gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

       

	 renderer = gtk_cell_renderer_text_new ();
	 column = gtk_tree_view_column_new_with_attributes("etoile", renderer, "text",ETOILE, NULL);
	 gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);


         renderer = gtk_cell_renderer_text_new ();
	 column = gtk_tree_view_column_new_with_attributes("chambre", renderer, "text",CHAMBRE, NULL);
	 gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	 renderer = gtk_cell_renderer_text_new ();
	 column = gtk_tree_view_column_new_with_attributes("prix", renderer, "text",PRIXH, NULL);
	 gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	 renderer = gtk_cell_renderer_text_new ();
	 column = gtk_tree_view_column_new_with_attributes("jour", renderer,"text",JH, NULL);
	 gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

       

	 renderer = gtk_cell_renderer_text_new ();
	 column = gtk_tree_view_column_new_with_attributes("mois", renderer, "text",MH, NULL);
	 gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);


         renderer = gtk_cell_renderer_text_new ();
	 column = gtk_tree_view_column_new_with_attributes("année", renderer, "text",AH, NULL);
	 gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	 renderer = gtk_cell_renderer_text_new ();
	 column = gtk_tree_view_column_new_with_attributes("nombre de nuit", renderer, "text",NN, NULL);
	 gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	 renderer = gtk_cell_renderer_text_new ();
	 column = gtk_tree_view_column_new_with_attributes("nombre de place", renderer, "text",NBRPH, NULL);
	 gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
	}
 store=gtk_list_store_new (COLUMNSH,G_TYPE_INT,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_INT,G_TYPE_STRING,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT);
f = fopen("reshot.txt", "r");

 if(f==NULL)
	{
	 return;
	}		
 else 
	{
 	 f = fopen("reshot.txt", "r");
	 while(fscanf(f,"%d %s %s %s %s %d %s %d %d %d %d %d %d\n",&p.id,p.r.id,p.login,p.r.lieu,p.r.nom,&p.r.e,p.r.chambre,&p.r.prix,&p.j,&p.m,&p.a,&p.nn,&p.nbrp)!=EOF)
		 {
		 gtk_list_store_append (store, &iter);
		 gtk_list_store_set (store,&iter,IDH,p.id,IDDH,p.r.id,LOGINH,p.login,LIEUX,p.r.lieu,NOM,p.r.nom,ETOILE,p.r.e,CHAMBRE,p.r.chambre,PRIXH,p.r.prix,JH,p.j,MH,p.m,AH,p.a,NN,p.nn,NBRPH,p.nbrp,-1); }
		}
 fclose(f);
	 gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
	 g_object_unref (store);
	
}


void supprimer_reshot(reshot p)
{
char iddn[20],loginn[20],lieun[20], nomn[20],chambren[20],typen[20];
int idn,jn,mn,an,nbrpn,prixn,nn,en;
	FILE *f , *tmp;
	f=fopen("reshot.txt","r");
	tmp=fopen("reshot.tmp","a+");
	while(fscanf(f,"%d %s %s %s %s %d %s %d %d %d %d %d %d\n",&idn,iddn,loginn,lieun,nomn,&en,chambren,&prixn,&jn,&mn,&an,&nn,&nbrpn)!=EOF){
		if(p.id==idn ){continue;}
else fprintf(tmp,"%d %s %s %s %s %d %s %d %d %d %d %d %d\n",idn,iddn,loginn,lieun,nomn,en,chambren,prixn,jn,mn,an,nn,nbrpn);
}
fclose(f);
fclose(tmp);
rename("reshot.tmp","reshot.txt");
}



void modif_reshot(reshot p)
{
char iddn[20],loginn[20],lieun[20], nomn[20],chambren[20],typen[20];
int idn,jn,mn,an,nbrpn,prixn,nn,en;
	FILE *f , *tmp;
	f=fopen("reshot.txt","r");
	tmp=fopen("reshot.tmp","a+");
	while(fscanf(f,"%d %s %s %s %s %d %s %d %d %d %d %d %d\n",&idn,iddn,loginn,lieun,nomn,&en,chambren,&prixn,&jn,&mn,&an,&nn,&nbrpn)!=EOF){
		if(p.id==idn ){fprintf(tmp,"%d %s %s %s %s %d %s %d %d %d %d %d %d\n",p.id,p.r.id,p.login,p.r.lieu,p.r.nom,p.r.e,p.r.chambre,p.r.prix,p.j,p.m,p.a,p.nn,p.nbrp);}
else fprintf(tmp,"%d %s %s %s %s %d %s %d %d %d %d %d %d\n",idn,iddn,loginn,lieun,nomn,en,chambren,prixn,jn,mn,an,nn,nbrpn);
}
fclose(f);
fclose(tmp);
rename("reshot.tmp","reshot.txt");
}
/////////////modresexc/////////
enum   
{       
 
 IDE,
 IDDE,
 LOGINE,
 DES,
 AE,
JE,
ME,
 PRIXE,
PROGE,
 NBRPE,
COLUMNSE
 
};
void affiche_mon_res_exc (GtkWidget *liste )
{
  GtkCellRenderer *renderer;
 GtkTreeViewColumn *column;
 GtkTreeIter    iter;
 GtkListStore *store;

FILE* f;
resexc p ;
/*p=recherche_res_vol_id (d);*/
 store=NULL;
store=gtk_tree_view_get_model(liste);	
 if (store==NULL)
	{
	 renderer = gtk_cell_renderer_text_new ();
	 column = gtk_tree_view_column_new_with_attributes("id du res", renderer,"text",IDE, NULL);
	 gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

       

	 renderer = gtk_cell_renderer_text_new ();
	 column = gtk_tree_view_column_new_with_attributes("id du hotel", renderer, "text",IDDE, NULL);
	 gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);


         renderer = gtk_cell_renderer_text_new ();
	 column = gtk_tree_view_column_new_with_attributes("username", renderer, "text",LOGINE, NULL);
	 gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	 renderer = gtk_cell_renderer_text_new ();
	 column = gtk_tree_view_column_new_with_attributes("destination", renderer, "text",DES, NULL);
	 gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	 

	 
	 renderer = gtk_cell_renderer_text_new ();
	 column = gtk_tree_view_column_new_with_attributes("jour", renderer,"text",JE, NULL);
	 gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

       

	 renderer = gtk_cell_renderer_text_new ();
	 column = gtk_tree_view_column_new_with_attributes("mois", renderer, "text",ME, NULL);
	 gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);


         renderer = gtk_cell_renderer_text_new ();
	 column = gtk_tree_view_column_new_with_attributes("année", renderer, "text",AE, NULL);
	 gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	 renderer = gtk_cell_renderer_text_new ();
	 column = gtk_tree_view_column_new_with_attributes("programe", renderer, "text",PROGE, NULL);
	 gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);


         renderer = gtk_cell_renderer_text_new ();
	 column = gtk_tree_view_column_new_with_attributes("prix", renderer, "text",PRIXE, NULL);
	 gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);



	 renderer = gtk_cell_renderer_text_new ();
	 column = gtk_tree_view_column_new_with_attributes("nombre de place", renderer, "text",NBRPE, NULL);
	 gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
	}
 store=gtk_list_store_new (COLUMNSE,G_TYPE_INT,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT,G_TYPE_STRING,G_TYPE_INT,G_TYPE_INT);
f = fopen("resexc.txt", "r");

 if(f==NULL)
	{
	 return;
	}		
 else 
	{
 	 f = fopen("resexc.txt", "r");
	 while(fscanf(f,"%d %s %s %s %d %d %d %s %d %d\n",&p.id,p.r.id,p.login,p.r.des,&p.r.j,&p.r.m,&p.r.a,p.r.prog,&p.r.prix,&p.nbrp)!=EOF)
		 {
		 gtk_list_store_append (store, &iter);
		 gtk_list_store_set (store,&iter,IDE,p.id,IDDE,p.r.id,LOGINE,p.login,DES,p.r.des,JE,p.r.j,ME,p.r.m,AE,p.r.a,PROGE,p.r.prog,PRIXE,p.r.prix,NBRPH,p.nbrp,-1); }
		}
 fclose(f);
	 gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
	 g_object_unref (store);
	
}
void supprimer_resexc(resexc p)
{
char iddn[20],loginn[20],desn[20], progn[20];
int idn,jn,mn,an,nbrpn,prixn;
	FILE* f , * tmp;
	f=fopen("resexc.txt","r");
	tmp=fopen("resrxc.tmp","a+");
	while(fscanf(f,"%d %s %s %s %d %d %d %s %d %d\n",&idn,iddn,loginn,desn,&jn,&mn,&an,progn,&prixn,&nbrpn)!=EOF){
		if(p.id==idn ){continue;}
else fprintf(tmp,"%d %s %s %s %d %d %d %s %d %d\n",idn,iddn,loginn,desn,jn,mn,an,progn,prixn,nbrpn);
}
fclose(f);
fclose(tmp);
rename("resexc.tmp","resexc.txt");
}



void modif_resexc(resexc p)
{
 char iddn[20],loginn[20],desn[20], progn[20];
int idn,jn,mn,an,nbrpn,prixn;
	FILE * f , * tmp;
	f=fopen("resexc.txt","r");
	tmp=fopen("resexc.tmp","a+");
	while(fscanf(f,"%d %s %s %s %d %d %d %s %d %d\n",&idn,iddn,loginn,desn,&jn,&mn,&an,progn,&prixn,&nbrpn)!=EOF){
		if(p.id==idn ){fprintf(tmp,"%d %s %s %s %d %d %d %s %d %d\n",p.id,p.r.id,p.login,p.r.des,p.r.j,p.r.m,p.r.a,p.r.prog,p.r.prix,p.nbrp);}
else fprintf(tmp,"%d %s %s %s %d %d %d %s %d %d\n",idn,iddn,loginn,desn,jn,mn,an,progn,prixn,nbrpn);
}
fclose(f);
fclose(tmp);
rename("resexc.tmp","resexc.txt");

}


resexc recherche_res_exc_id (int d)
{ 
resexc p;
FILE* f;
f=fopen("resexc.txt","r");
if(f!=NULL)
{ 
while( fscanf(f,"%d %s %s %s %d %d %d %s %d %d\n",&p.id,p.r.id,p.login,p.r.des,&p.r.j,&p.r.m,&p.r.a,p.r.prog,&p.r.prix,&p.nbrp)!=EOF)
			{ 
				if (d==p.id)	
                               return p ;}
                          }

} 
