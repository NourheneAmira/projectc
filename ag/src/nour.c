#include <string.h>

#include <stdio.h>
#include <stdlib.h>
#include "nour.h"
void ajouter1(excursion p)
{

FILE*f;
f=fopen("exc.txt","a+");
if (f!=NULL)
{fprintf(f,"%s %s %d %d %d %s %d %d\n",p.id,p.des,p.j,p.m,p.a,p.prog,p.prix,p.p);
fclose(f);
}
}
enum   
{       
 
 ID,
 DES,
 J,
 M,
 A,
 PROG,
 PRIX,
 P,
 COLUMNS
};

void afficher1(GtkWidget *liste)
{
 GtkCellRenderer *renderer;
 GtkTreeViewColumn *column;
 GtkTreeIter    iter;
 GtkListStore *store;


excursion p;



 store=NULL;

 FILE *f;

 store=gtk_tree_view_get_model(liste);	
 if (store==NULL)
	{
	 renderer = gtk_cell_renderer_text_new ();
	 column = gtk_tree_view_column_new_with_attributes("identifiant", renderer,"text",ID, NULL);
	 gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

       

	 renderer = gtk_cell_renderer_text_new ();
	 column = gtk_tree_view_column_new_with_attributes("description", renderer, "text",DES, NULL);
	 gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);


         renderer = gtk_cell_renderer_text_new ();
	 column = gtk_tree_view_column_new_with_attributes("jour", renderer, "text",J, NULL);
	 gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	 renderer = gtk_cell_renderer_text_new ();
	 column = gtk_tree_view_column_new_with_attributes("mois", renderer, "text",M, NULL);
	 gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	 renderer = gtk_cell_renderer_text_new ();
	 column = gtk_tree_view_column_new_with_attributes("annee", renderer, "text",A, NULL);
	 gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	 renderer = gtk_cell_renderer_text_new ();
	 column = gtk_tree_view_column_new_with_attributes("programme", renderer, "text",PROG, NULL);
	 gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

 	 renderer = gtk_cell_renderer_text_new ();
	 column = gtk_tree_view_column_new_with_attributes("prix", renderer, "text",PRIX, NULL);
	 gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	 renderer = gtk_cell_renderer_text_new ();
	 column = gtk_tree_view_column_new_with_attributes("nbre des places ", renderer, "text",P, NULL);
	 gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	 



	



	}


 store=gtk_list_store_new (COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT,G_TYPE_STRING,G_TYPE_INT,G_TYPE_INT);

 f = fopen("exc.txt", "r");

 if(f==NULL)
	{
	 return;
	}		
 else 
	{
 	 f = fopen("exc.txt", "a+");
	 while(fscanf(f,"%s %s %d %d %d %s %d %d\n",p.id,p.des,&p.j,&p.m,&p.a,p.prog,&p.prix,&p.p)!=EOF)
		{
		 gtk_list_store_append (store, &iter);
		 gtk_list_store_set (store,&iter,ID,p.id,DES,p.des,J,p.j,M,p.m,A,p.a,PROG,p.prog,PRIX,p.prix,P,p.p,-1); 
		}
	 fclose(f);
	 gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
	 g_object_unref (store);
	}
}
///////////////modifier
void modifier1(excursion p )
{ 	
	char idn[20],progn[20],desn[20];
int jn,mn,an,pn,prixn;
	FILE *f , *tmp;
	f=fopen("exc.txt","r");
	tmp=fopen("exc.tmp","a+");
	while(fscanf(f,"%s %s %d %d %d %s %d %d\n",idn,desn,&jn,&mn,&an,progn,&prixn,&pn)!=EOF){
		if(!strcmp(p.id,idn) ){fprintf(tmp,"%s %s %d %d %d %s %d %d\n",p.id,p.des,p.j,p.m,p.a,p.prog,p.prix,p.p);}
else fprintf(tmp,"%s %s %d %d %d %s %d %d\n",idn,desn,jn,mn,an,progn,prixn,pn);
}
fclose(f);
fclose(tmp);
rename("exc.tmp","exc.txt");
}                  
///////supprimer
void supprimer1(excursion p)
{ 	
	char idn[20],progn[20],desn[20];
int jn,mn,an,pn,prixn;
	FILE *f , *tmp;
	f=fopen("exc.txt","r");
	tmp=fopen("exc.tmp","a+");
	while(fscanf(f,"%s %s %d %d %d %s %d %d\n",idn,desn,&jn,&mn,&an,progn,&prixn,&pn)!=EOF){
		if(!strcmp(p.id,idn) ){continue;}
else fprintf(tmp,"%s %s %d %d %d %s %d %d\n",idn,desn,jn,mn,an,progn,prixn,pn);
}
fclose(f);
fclose(tmp);
rename("exc.tmp","exc.txt");
} 
////////////////hotel/////////////
enum   
{       
 
 ID2,
 LIEU,
 NOM,
 E,
 CHAMBRE,
 PRIX2,
 PLACE,
 COLUMN
};

void afficher2(GtkWidget *liste)
{
 GtkCellRenderer *renderer;
 GtkTreeViewColumn *column;
 GtkTreeIter    iter;
 GtkListStore *store;


hotel h;



 store=NULL;

 FILE *f;

 store=gtk_tree_view_get_model(liste);	
 if (store==NULL)
	{
	 renderer = gtk_cell_renderer_text_new ();
	 column = gtk_tree_view_column_new_with_attributes("identifiant", renderer,"text",ID2, NULL);
	 gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

       

	 renderer = gtk_cell_renderer_text_new ();
	 column = gtk_tree_view_column_new_with_attributes("lieux", renderer, "text",LIEU, NULL);
	 gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);


         renderer = gtk_cell_renderer_text_new ();
	 column = gtk_tree_view_column_new_with_attributes("nom", renderer, "text",NOM, NULL);
	 gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	 renderer = gtk_cell_renderer_text_new ();
	 column = gtk_tree_view_column_new_with_attributes("nbre des etoiles", renderer, "text",E, NULL);
	 gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	 renderer = gtk_cell_renderer_text_new ();
	 column = gtk_tree_view_column_new_with_attributes("type chambre", renderer, "text",CHAMBRE, NULL);
	 gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	 renderer = gtk_cell_renderer_text_new ();
	 column = gtk_tree_view_column_new_with_attributes("prix", renderer, "text",PRIX2, NULL);
	 gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

 	 renderer = gtk_cell_renderer_text_new ();
	 column = gtk_tree_view_column_new_with_attributes("nbre des places", renderer, "text",PLACE, NULL);
	 gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	}


 store=gtk_list_store_new (COLUMN,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_INT,G_TYPE_STRING,G_TYPE_INT,G_TYPE_INT);

 f = fopen("hot.txt", "r");

 if(f==NULL)
	{
	 return;
	}		
 else 
	{
 	 f = fopen("hot.txt", "a+");
	 while(fscanf(f,"%s %s %s %d %s %d %d\n",h.id,h.lieu,h.nom,&h.e,h.chambre,&h.prix,&h.p)!=EOF)
		{
		 gtk_list_store_append (store, &iter);
		 gtk_list_store_set (store,&iter,ID2,h.id,LIEU,h.lieu,NOM,h.nom,E,h.e,CHAMBRE,h.chambre,PRIX2,h.prix,PLACE,h.p,-1); 
		}
	 fclose(f);
	 gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
	 g_object_unref (store);
	}
}
void ajouter2(hotel h)
{

FILE*f;

f=fopen("hot.txt","a+");
if (f!=NULL)
{fprintf(f,"%s %s %s %d %s %d %d\n",h.id,h.lieu,h.nom,h.e,h.chambre,h.prix,h.p);
fclose(f);
}
}
void modifier2(hotel h)
{ 	
	char idn[20],chambren[20],nomn[20],lieun[20],progn[20];
int en,pn,prixhn;
	FILE *f , *tmp;
	f=fopen("hot.txt","r");
	tmp=fopen("hot.tmp","a+");
	while(fscanf(f,"%s %s %s %d %s %d %d\n",idn,lieun,nomn,&en,chambren,&prixhn,&pn)!=EOF){
		if(!strcmp(h.id,idn) ){fprintf(tmp,"%s %s %s %d %s %d %d\n",h.id,h.lieu,h.nom,h.e,h.chambre,h.prix,h.p);}
else fprintf(tmp,"%s %s %s %d %s %d %d\n",idn,lieun,nomn,en,chambren,prixhn,pn);
}
fclose(f);
fclose(tmp);
rename("hot.tmp","hot.txt");
}
void supprimer2(hotel h)
{
	char idn[20],lieun[20],nomn[20],chambren[20];
        int en,pn,prixhn;
	FILE *f , *tmp;
	f=fopen("hot.txt","r");
	tmp=fopen("hot.tmp","a+");
	while(fscanf(f,"%s %s %s %d %s %d %d\n",idn,lieun,nomn,&en,chambren,&prixhn,&pn)!=EOF){
		if(!strcmp(h.id,idn) ){continue;}
else fprintf(tmp,"%s %s %s %d %s %d %d\n",idn,lieun,nomn,en,chambren,prixhn,pn);
}
fclose(f);
fclose(tmp);
rename("hot.tmp","hot.txt");
}

/////////////////gestion ****************vol///////////
void ajouter3(vol v)
{

FILE*f;
f=fopen("vol.txt","a+");
if (f!=NULL)
{fprintf(f,"%s %s %s %d %d %d %s %s %d %d\n",v.id,v.dep,v.arr,v.jv,v.mv,v.av,v.heure,v.type,v.prixv,v.pl);
fclose(f);
}
}
/////////////affiche vol
enum   
{       
 
 ID3,
 DEP,
 ARR,
 JV,
 MV,
 AV,
 HEURE,
 TYPEV,
 PRIX3,
 PLACEV,
 COLUM
};

void afficher3(GtkWidget *liste)
{
 GtkCellRenderer *renderer;
 GtkTreeViewColumn *column;
 GtkTreeIter    iter;
 GtkListStore *store;


 char id[30];
 char dep[30];
 char arr[50];
 
 char  type[50];
 char  heure[50];
 int pv,jv,mv,av,prix;



 store=NULL;

 FILE *f;

 store=gtk_tree_view_get_model(liste);	
 if (store==NULL)
	{
	 renderer = gtk_cell_renderer_text_new ();
	 column = gtk_tree_view_column_new_with_attributes("identifiant", renderer,"text",ID3, NULL);
	 gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

       

	 renderer = gtk_cell_renderer_text_new ();
	 column = gtk_tree_view_column_new_with_attributes("depart", renderer, "text",DEP, NULL);
	 gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);


         renderer = gtk_cell_renderer_text_new ();
	 column = gtk_tree_view_column_new_with_attributes("arrivee", renderer, "text",ARR, NULL);
	 gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	 renderer = gtk_cell_renderer_text_new ();
	 column = gtk_tree_view_column_new_with_attributes("jour", renderer, "text",JV, NULL);
	 gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	 renderer = gtk_cell_renderer_text_new ();
	 column = gtk_tree_view_column_new_with_attributes("mois", renderer, "text",MV, NULL);
	 gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	 renderer = gtk_cell_renderer_text_new ();
	 column = gtk_tree_view_column_new_with_attributes("annee", renderer, "text",AV, NULL);
	 gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

 	 renderer = gtk_cell_renderer_text_new ();
	 column = gtk_tree_view_column_new_with_attributes("heure", renderer, "text",HEURE, NULL);
	 gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	 renderer = gtk_cell_renderer_text_new ();
	 column = gtk_tree_view_column_new_with_attributes("type", renderer, "text",TYPEV, NULL);
	 gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
  
         renderer = gtk_cell_renderer_text_new ();
	 column = gtk_tree_view_column_new_with_attributes("prix", renderer, "text",PRIX3, NULL);
	 gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	 renderer = gtk_cell_renderer_text_new ();
	 column = gtk_tree_view_column_new_with_attributes("place", renderer, "text",PLACEV, NULL);
	 gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	}


 store=gtk_list_store_new(COLUM,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_INT,G_TYPE_INT);

 f = fopen("vol.txt", "r");

 if(f==NULL)
	{
	 return;
	}		
 else 
	{
 	 f = fopen("vol.txt", "a+");
	 while(fscanf(f,"%s %s %s %d %d %d %s %s %d %d\n",id,dep,arr,&jv,&mv,&av,heure,type,&prix,&pv)!=EOF)
		{
		 gtk_list_store_append (store, &iter);
		 gtk_list_store_set (store,&iter,ID3,id,DEP,dep,ARR,arr,JV,jv,MV,mv,AV,av,HEURE,heure,TYPEV,type,PRIX3,prix,PLACEV,pv-1); 
		}
	 fclose(f);
	 gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
	 g_object_unref (store);
	}
}
/////////////////////modifier supprimer ///////////
void modifier3(vol v)
{ 	
	char idn[20],depn[20],arrn[20],heuren[20],typen[20];
int jn,mn,an,pn,prixn;
	FILE *f , *tmp;
	f=fopen("vol.txt","r");
	tmp=fopen("vol.tmp","a+");
	while(fscanf(f,"%s %s %s %d %d %d %s %s %d %d\n",idn,depn,arrn,&jn,&mn,&an,heuren,typen,&prixn,&pn)!=EOF){
		if(!strcmp(v.id,idn) ){fprintf(tmp,"%s %s %s %d %d %d %s %s %d %d\n",v.id,v.dep,v.arr,v.jv,v.mv,v.av,v.heure,v.type,v.prixv,v.pl);}
else fprintf(tmp,"%s %s %s %d %d %d %s %s %d %d\n",idn,depn,arrn,jn,mn,an,heuren,typen,prixn,pn);
}
fclose(f);
fclose(tmp);
rename("vol.tmp","vol.txt");
}
void supprimer3(vol v)
{char idn[20],depn[20],arrn[20],heuren[20],typen[20];
int jn,mn,an,pn,prixn;
	FILE *f , *tmp;
	f=fopen("vol.txt","r");
	tmp=fopen("vol.tmp","a+");
	while(fscanf(f,"%s %s %s %d %d %d %s %s %d %d\n",idn,depn,arrn,&jn,&mn,&an,heuren,typen,&prixn,&pn)!=EOF){
		if(!strcmp(v.id,idn) ){continue;}
else fprintf(tmp,"%s %s %s %d %d %d %s %s %d %d\n",idn,depn,arrn,jn,mn,an,heuren,typen,prixn,pn);
}
fclose(f);
fclose(tmp);
rename("vol.tmp","vol.txt");
}//////////////////////////verifier////////////////////
 int verifid(char id[])
{
	for(int i=0;i<strlen(id);i++)
	{
		if ( (strlen(id)==0) || (id[i] < '0') || (id[i] > '9') || (strlen(id)!=8) )
		{return 0;
		}
		else
		 return 1;
	}
}
///////////////////////********/////////////////////////////////
int verifentry(char a[])
{
 if (strlen(a)==0)
{return 0;}
else return 1;
}
////////////////********************************////////////////////
int verifidv (vol v,char log[])
{
FILE *f ;

	f=fopen("vol.txt","r");
   
while(fscanf(f,"%s %s %s %d %d %d %s %s %d %d\n",v.id,v.dep,v.arr,&v.jv,&v.mv,&v.av,v.heure,v.type,&v.prixv,&v.pl)!=EOF){
if(strcmp(log,v.id)==0)
{fclose(f);
return 0; }
 }
fclose(f);
return 1;
}
/////////////
int verifide (excursion e ,char log[])
{
FILE *f ;

	f=fopen("exc.txt","r");
   
while(fscanf(f,"%s %s %s %d %d %d %s %s %d %d\n",e.id,e.des,&e.j,&e.m,&e.a,e.prog,&e.prix,e.p)!=EOF){
if(strcmp(log,e.id)==0)
{fclose(f);
return 0; }
 }
fclose(f);
return 1;
}
//////////////////////////////////////////////////
int verifidh (hotel h,char log[])
{
FILE *f ;

	f=fopen("hot.txt","r");
   
while(fscanf(f,"%s %s %s %d %s %d %d\n",h.id,h.lieu,h.nom,&h.e,h.chambre,&h.prix,&h.p)!=EOF){
if(strcmp(log,h.id)==0)
{fclose(f);
return 0; }
 }
fclose(f);
return 1;
}
////////////////////////commbobox////////////////
void afficherkhkh(GtkWidget *liste,char combo[]){

enum   
{       
 
 ID,
 DES,
 J,
 M,
 A,
 PROG,
 PRIX,
 P,
 COLUMNS
};

        GtkCellRenderer *renderer;
        GtkTreeViewColumn *column;
        GtkTreeIter    iter;
        GtkListStore *store;

        char id[30];
        char des[10];
        char prog[30];
        int je,me,ae,pe;
        int prixe;
        store=NULL;

        FILE *f;

store=gtk_tree_view_get_model(liste);
        if (store==NULL)
        {

                renderer = gtk_cell_renderer_text_new ();
                column = gtk_tree_view_column_new_with_attributes("identifiant",
renderer, "text",ID, NULL);
                gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

                renderer = gtk_cell_renderer_text_new ();
                column = gtk_tree_view_column_new_with_attributes("description",
renderer, "text",DES, NULL);
                gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

                renderer = gtk_cell_renderer_text_new ();
                column = gtk_tree_view_column_new_with_attributes("jour", renderer,
"text",J, NULL);
                gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);        

 renderer = gtk_cell_renderer_text_new ();
                column = gtk_tree_view_column_new_with_attributes("mois",
renderer, "text",M, NULL);
                gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

                renderer = gtk_cell_renderer_text_new ();
                column = gtk_tree_view_column_new_with_attributes("annee", renderer,
"text",A, NULL);
                gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
                renderer = gtk_cell_renderer_text_new ();
                column = gtk_tree_view_column_new_with_attributes("programme",
renderer, "text",PROG, NULL);
                gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

                renderer = gtk_cell_renderer_text_new ();
                column = gtk_tree_view_column_new_with_attributes("prix",
renderer, "text",PRIX, NULL);
                gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new ();
                column = gtk_tree_view_column_new_with_attributes("nbre des places",
renderer, "text",P, NULL);
                gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
 

        }
store=gtk_list_store_new (COLUMNS, G_TYPE_STRING, G_TYPE_STRING,G_TYPE_UINT,G_TYPE_UINT,G_TYPE_UINT, G_TYPE_STRING,G_TYPE_UINT,G_TYPE_UINT);


        f = fopen("exc.txt", "r");

if(f!=NULL)

        { f = fopen("exc.txt", "a+");
              while(fscanf(f,"%s %s %d %d %d %s %d %d\n",id,des,&je,&me,&ae,prog,&prixe,&pe)!=EOF)

                {
                        if(strcmp(des,combo)==0 )

                                        {
                                        gtk_list_store_append (store, &iter);
                                        gtk_list_store_set (store, &iter, ID, id,
DES,des,J,je,M,me,A,ae,PROG,prog,PRIX,prixe,P,pe,-1);
                                                
                                        }/*else if ((strcmp(ville,combo)==0 &&
nbetoiles==nbetoile)||nbchambres==nbchambre||nbsuites==nbsuite)
                                                {
                                                gtk_list_store_append (store, &iter);
                                        gtk_list_store_set (store, &iter, IDHOTEL, idhotel,
NOMHOTEL,nomhotel, VILLE,ville, NBETOILE,nbetoile,
                                                        PRIX,prix,NBCHAMBRE,nbchambre,NBSUITE,nbsuite, -1);
                                                }*/
                }
                fclose(f);
        gtk_tree_view_set_model (GTK_TREE_VIEW (liste),  GTK_TREE_MODEL (store));
        g_object_unref (store);
        }
}
/////////////////
void afficherhh(GtkWidget *liste,char comboo[]){

enum   
{       
 
 ID2,
 LIEU,
 NOM,
 E,
 CHAMBRE,
 PRIX2,
 PLACE,
 COLUMNS
};

        GtkCellRenderer *renderer;
        GtkTreeViewColumn *column;
        GtkTreeIter    iter;
        GtkListStore *store;

        char id[30];
        char lieu[10];
        char nom[30];
	char chambre[30];
        int prix,e,p;
       
        store=NULL;

        FILE *f;

store=gtk_tree_view_get_model(liste);
        if (store==NULL)
        {

                renderer = gtk_cell_renderer_text_new ();
                column = gtk_tree_view_column_new_with_attributes("identifiant",
renderer, "text",ID2, NULL);
                gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

                renderer = gtk_cell_renderer_text_new ();
                column = gtk_tree_view_column_new_with_attributes("lieux",
renderer, "text",LIEU, NULL);
                gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

                renderer = gtk_cell_renderer_text_new ();
                column = gtk_tree_view_column_new_with_attributes("nom", renderer,
"text",NOM, NULL);
                gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);        

 renderer = gtk_cell_renderer_text_new ();
                column = gtk_tree_view_column_new_with_attributes("nbre des etoiles",
renderer, "text",E, NULL);
                gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

                renderer = gtk_cell_renderer_text_new ();
                column = gtk_tree_view_column_new_with_attributes("type chambre", renderer,
"text",CHAMBRE, NULL);
                gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
                renderer = gtk_cell_renderer_text_new ();
                column = gtk_tree_view_column_new_with_attributes("prix",
renderer, "text",PRIX2, NULL);
                gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

                renderer = gtk_cell_renderer_text_new ();
                column = gtk_tree_view_column_new_with_attributes("nbre des places",
renderer, "text",PLACE, NULL);
                gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);


         
 

        }
store=gtk_list_store_new (COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING,G_TYPE_UINT, G_TYPE_STRING,G_TYPE_UINT,G_TYPE_UINT);


        f = fopen("hot.txt", "r");

if(f!=NULL)

        { f = fopen("hot.txt", "a+");
              while(fscanf(f,"%s %s %s %d %s %d %d\n",id,lieu,nom,&e,chambre,&prix,&p)!=EOF)

                {
                        if(strcmp(lieu,comboo)==0 )

                                        {
                                        gtk_list_store_append (store, &iter);
                                        gtk_list_store_set (store, &iter, ID2, id,
LIEU,lieu,NOM,nom,E,e,CHAMBRE,chambre,PRIX2,prix,PLACE,p,-1);
                                                
                                        }/*else if ((strcmp(ville,combo)==0 &&
nbetoiles==nbetoile)||nbchambres==nbchambre||nbsuites==nbsuite)
                                                {
                                                gtk_list_store_append (store, &iter);
                                        gtk_list_store_set (store, &iter, IDHOTEL, idhotel,
NOMHOTEL,nomhotel, VILLE,ville, NBETOILE,nbetoile,
                                                        PRIX,prix,NBCHAMBRE,nbchambre,NBSUITE,nbsuite, -1);
                                                }*/
                }
                fclose(f);
        gtk_tree_view_set_model (GTK_TREE_VIEW (liste),  GTK_TREE_MODEL (store));
        g_object_unref (store);
        }
}
///////////////************////////////filtre vol/////////////////
void afficherhhh(GtkWidget *liste,char combo[]){

enum   
{       
 
 ID3,
 DEP,
 ARR,
 JV,
 MV,
 AV,
 HEURE,
 TYPEV,
 PRIX3,
 PLACEV,
 COLUMS
};

        GtkCellRenderer *renderer;
        GtkTreeViewColumn *column;
        GtkTreeIter    iter;
        GtkListStore *store;

        char id[30];
        char dep[10];
        char arr[30];
	char heure[30];
        char type[30];
        int jv,mv,av,pl;
        int prixv;
        store=NULL;

        FILE *f;

store=gtk_tree_view_get_model(liste);
        if (store==NULL)
        {

                renderer = gtk_cell_renderer_text_new ();
                column = gtk_tree_view_column_new_with_attributes("identifiant",
renderer, "text",ID3, NULL);
                gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

                renderer = gtk_cell_renderer_text_new ();
                column = gtk_tree_view_column_new_with_attributes("depart",
renderer, "text",DEP, NULL);
                gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

                renderer = gtk_cell_renderer_text_new ();
                column = gtk_tree_view_column_new_with_attributes("arrivee", renderer,
"text",ARR, NULL);
                gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);        

 renderer = gtk_cell_renderer_text_new ();
                column = gtk_tree_view_column_new_with_attributes("jour",
renderer, "text",JV, NULL);
                gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

                renderer = gtk_cell_renderer_text_new ();
                column = gtk_tree_view_column_new_with_attributes("mois", renderer,
"text",MV, NULL);
                gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
                renderer = gtk_cell_renderer_text_new ();
                column = gtk_tree_view_column_new_with_attributes("annee",
renderer, "text",AV, NULL);
                gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

                renderer = gtk_cell_renderer_text_new ();
                column = gtk_tree_view_column_new_with_attributes("heure",
renderer, "text",HEURE, NULL);
                gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new ();
                column = gtk_tree_view_column_new_with_attributes("type",
renderer, "text",TYPEV, NULL);
                gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
 
renderer = gtk_cell_renderer_text_new ();
                column = gtk_tree_view_column_new_with_attributes("prix",
renderer, "text",PRIX3, NULL);
                gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new ();
                column = gtk_tree_view_column_new_with_attributes("place",
renderer, "text",PLACEV, NULL);
                gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

        }
store=gtk_list_store_new (COLUMNS, G_TYPE_STRING, G_TYPE_STRING,G_TYPE_STRING,G_TYPE_UINT,G_TYPE_UINT,G_TYPE_UINT,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_UINT,G_TYPE_UINT);


        f = fopen("vol.txt", "r");

if(f!=NULL)

        { f = fopen("vol.txt", "a+");
              while(fscanf(f,"%s %s %s %d %d %d %s %s %d %d\n",id,dep,arr,&jv,&mv,&av,heure,type,&prixv,&pl)!=EOF)

                {
                        if(strcmp(dep,combo)==0 )

                                        {
                                        gtk_list_store_append (store, &iter);
                                        gtk_list_store_set (store, &iter, ID3, id,
DEP,dep,ARR,arr,JV,jv,MV,mv,AV,av,HEURE,heure,TYPEV,type,PRIX3,prixv,PLACEV,pl,-1);
                                                
                                        }/*else if ((strcmp(ville,combo)==0 &&
nbetoiles==nbetoile)||nbchambres==nbchambre||nbsuites==nbsuite)
                                                {
                                                gtk_list_store_append (store, &iter);
                                        gtk_list_store_set (store, &iter, IDHOTEL, idhotel,
NOMHOTEL,nomhotel, VILLE,ville, NBETOILE,nbetoile,
                                                        PRIX,prix,NBCHAMBRE,nbchambre,NBSUITE,nbsuite, -1);
                                                }*/
                }
                fclose(f);
        gtk_tree_view_set_model (GTK_TREE_VIEW (liste),  GTK_TREE_MODEL (store));
        g_object_unref (store);
        }
}

