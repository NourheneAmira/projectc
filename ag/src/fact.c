#include <stdlib.h>
#include <stdio.h>
#include "nour.h"
#include "string.h"
#include <gtk/gtk.h>
/////////facturationvol//////////
void ajout_factvol_txt( factvol t )
{
FILE* f;
f=fopen("factvol.txt","a");
  if(f!=NULL)
   {
   fprintf(f,"%d %s %s %s %s %s %d %d %d %s %s %d %d %d\n",t.k.id,t.type,t.k.r.id,t.k.login,t.k.r.dep,t.k.r.arr,t.k.r.jv,t.k.r.mv,t.k.r.av,t.k.r.heure,t.k.r.type,t.k.r.prixv,t.k.nbrp,t.pf);
   }
fclose(f);
}

void ajout_facthot_txt( facthot t )
{
FILE* f;
f=fopen("facthot.txt","a");
  if(f!=NULL)
   {
   fprintf(f,"%d %s %s %s %s %s %d %s %d %d %d %d %d %d %d\n",t.k.id,t.type,t.k.r.id,t.k.login,t.k.r.lieu,t.k.r.nom,t.k.r.e,t.k.r.chambre,t.k.r.prix,t.k.j,t.k.m,t.k.a,t.k.nn,t.k.nbrp,t.pf);
   }
fclose(f);
}

void ajout_factexc_txt( factexc t )
{
FILE* f;
f=fopen("factexc.txt","a");
  if(f!=NULL)
   {
   fprintf(f,"%d %s %s %s %s %d %d %d %s %d %d %d\n",t.k.id,t.type,t.k.r.id,t.k.login,t.k.r.des,t.k.r.j,t.k.r.m,t.k.r.a,t.k.r.prog,t.k.r.prix,t.k.nbrp,t.pf);
   }
fclose(f);
}

void ajout_fact_txt( fact z)
{
FILE* f;
f=fopen("facture.txt","a");
  if(f!=NULL)
   {
   fprintf(f,"%d %s %s %d\n",z.id,z.type,z.login,z.pf);
   }
fclose(f);
}
enum   
{       
 
 ID,
 TYPE,
 LOGIN,
 PF,
COLUMNS
 
}; 

void afficher_facture(GtkWidget *liste)
{
 GtkCellRenderer *renderer;
 GtkTreeViewColumn *column;
 GtkTreeIter    iter;
 GtkListStore *store;
fact z;
 store=NULL;
FILE* g;
 FILE* f;
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
	 column = gtk_tree_view_column_new_with_attributes("prix final", renderer, "text",PF, NULL);
	 gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
 }


 store=gtk_list_store_new (COLUMNS,G_TYPE_INT,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_INT);
g=fopen("util.txt","r");
			fscanf(g,"%s",d);
			fclose(g);

f = fopen("facture.txt", "r");

 if(f==NULL)
	{
	 return;
	}		
 else 
	{
 	 f = fopen("facture.txt", "a+");
	 while(fscanf(f," %d %s %s %d\n",&z.id,z.type,z.login,&z.pf)!=EOF)
		{if (strcmp(d,z.login)==0)
		 {
			gtk_list_store_append (store, &iter);
		 	gtk_list_store_set (store,&iter,ID,z.id,TYPE,z.type,LOGIN,z.login,PF,z.pf,-1); }
		}
	 fclose(f);
	 gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
	 g_object_unref (store);
	}

}
void modif_facthot(facthot p)
{
char iddn[20],loginn[20],lieun[20], nomn[20],chambren[20],typen[20];
int idn,jn,mn,an,nbrpn,prixn,nn,en,pfn;
	FILE *f , *tmp;
	f=fopen("facthot.txt","r");
	tmp=fopen("facthot.tmp","a+");
	while(fscanf(f,"%d %s %s %s %s %s %d %s %d %d %d %d %d %d %d\n",&idn,typen,iddn,loginn,lieun,nomn,&en,chambren,&prixn,&jn,&mn,&an,&nn,&nbrpn,&pfn)!=EOF){
		if(p.k.id==idn ){fprintf(tmp,"%d %s %s %s %s %s %d %s %d %d %d %d %d %d %d\n",p.k.id,p.type,p.k.r.id,p.k.login,p.k.r.lieu,p.k.r.nom,p.k.r.e,p.k.r.chambre,p.k.r.prix,p.k.j,p.k.m,p.k.a,p.k.nn,p.k.nbrp,p.pf);}
else fprintf(tmp,"%d %s %s %s %s %s %d %s %d %d %d %d %d %d %d\n",&idn,typen,iddn,loginn,lieun,nomn,&en,chambren,&prixn,&jn,&mn,&an,&nn,&nbrpn,&pfn);
}
fclose(f);
fclose(tmp);
rename("facthot.tmp","facthot.txt");
}
  

void modif_factvol(factvol p)
{
char iddn[20],loginn[20],depn[20], arrn[20],heuren[20],typen[20],typenn[20];
int idn,jvn,mvn,avn,nbrpn,prixvn,pfn;
	FILE *f , *tmp;
	f=fopen("factvol.txt","r");
	tmp=fopen("factvol.tmp","a+");
	while(fscanf(f,"%d %s %s %s %s %s %d %d %d %s %s %d %d %d\n",&idn,typenn,iddn,loginn,depn,arrn,&jvn,&mvn,&avn,heuren,typen,&prixvn,&nbrpn,&pfn)!=EOF){
		if(p.k.id==idn ){fprintf(tmp,"%d %s %s %s %s %s %d %d %d %s %s %d %d %d\n",p.k.id,p.type,p.k.r.id,p.k.login,p.k.r.dep,p.k.r.arr,p.k.r.jv,p.k.r.mv,p.k.r.av,p.k.r.heure,p.k.r.type,p.k.r.prixv,p.k.nbrp,p.pf);}
else fprintf(tmp,"%d %s %s %s %s %s %d %d %d %s %s %d %d %d\n",idn,typenn,iddn,loginn,depn,arrn,jvn,mvn,avn,heuren,typen,prixvn,nbrpn,pfn);
}
fclose(f);
fclose(tmp);
rename("factvol.tmp","factvol.txt");
}

void modif_factexc(factexc p)
{
 char iddn[20],loginn[20],desn[20], progn[20],typen[20];
int idn,jn,mn,an,nbrpn,prixn,pfn;
	FILE * f , * tmp;
	f=fopen("factexc.txt","r");
	tmp=fopen("factexc.tmp","a+");
	while(fscanf(f,"%d %s %s %s %s %d %d %d %s %d %d %d\n",&idn,typen,iddn,loginn,desn,&jn,&mn,&an,progn,&prixn,&nbrpn,&pfn)!=EOF){
		if(p.k.id==idn ){fprintf(tmp,"%d %s %s %s %s %d %d %d %s %d %d %d\n",p.k.id,p.type,p.k.r.id,p.k.login,p.k.r.des,p.k.r.j,p.k.r.m,p.k.r.a,p.k.r.prog,p.k.r.prix,p.k.nbrp,p.pf);}
else fprintf(tmp,"%d %s %s %s %s %d %d %d %s %d %d %d\n",idn,typen,iddn,loginn,desn,jn,mn,an,progn,prixn,nbrpn,pfn);
}
fclose(f);
fclose(tmp);
rename("factexc.tmp","factexc.txt");
}

void modif_fact(fact p)
{
char typen[20],loginn[20];
int idn,pfn;
	FILE *f , *tmp;
	f=fopen("facture.txt","r");
	tmp=fopen("facture.tmp","a+");
	while(fscanf(f,"%d %s %s %d\n",&idn,typen,loginn,&pfn)!=EOF){
		if(p.id==idn ){fprintf(tmp,"%d %s %s %d\n",p.id,p.type,p.login,p.pf);}
else fprintf(tmp,"%d %s %s %d\n",idn,typen,loginn,pfn);
}
fclose(f);
fclose(tmp);
rename("facture.tmp","facture.txt");
}


void supp_factvol(factvol p)
{
char iddn[20],loginn[20],depn[20], arrn[20],heuren[20],typen[20],typenn[20];
int idn,jvn,mvn,avn,nbrpn,prixvn,pfn;
	FILE *f , *tmp;
	f=fopen("factvol.txt","r");
	tmp=fopen("factvol.tmp","a+");
	while(fscanf(f,"%d %s %s %s %s %s %d %d %d %s %s %d %d %d\n",&idn,typenn,iddn,loginn,depn,arrn,&jvn,&mvn,&avn,heuren,typen,&prixvn,&nbrpn,&pfn)!=EOF){
		if(p.k.id==idn ){continue;}
else fprintf(tmp,"%d %s %s %s %s %s %d %d %d %s %s %d %d %d\n",idn,typenn,iddn,loginn,depn,arrn,jvn,mvn,avn,heuren,typen,prixvn,nbrpn,pfn);
}
fclose(f);
fclose(tmp);
rename("factvol.tmp","factvol.txt");
}
void supp_facthot(facthot p)
{
char iddn[20],loginn[20],lieun[20], nomn[20],chambren[20],typen[20];
int idn,jn,mn,an,nbrpn,prixn,nn,en,pfn;
	FILE *f , *tmp;
	f=fopen("facthot.txt","r");
	tmp=fopen("facthot.tmp","a+");
	while(fscanf(f,"%d %s %s %s %s %s %d %s %d %d %d %d %d %d %d\n",&idn,typen,iddn,loginn,lieun,nomn,&en,chambren,&prixn,&jn,&mn,&an,&nn,&nbrpn,&pfn)!=EOF){
		if(p.k.id==idn ){continue;}
else fprintf(tmp,"%d %s %s %s %s %s %d %s %d %d %d %d %d %d %d\n",&idn,typen,iddn,loginn,lieun,nomn,&en,chambren,&prixn,&jn,&mn,&an,&nn,&nbrpn,&pfn);
}
fclose(f);
fclose(tmp);
rename("facthot.tmp","facthot.txt");
}

void supp_factexc(factexc p)
{
 char iddn[20],loginn[20],desn[20], progn[20],typen[20];
int idn,jn,mn,an,nbrpn,prixn,pfn;
	FILE * f , * tmp;
	f=fopen("factexc.txt","r");
	tmp=fopen("factexc.tmp","a+");
	while(fscanf(f,"%d %s %s %s %s %d %d %d %s %d %d %d\n",&idn,typen,iddn,loginn,desn,&jn,&mn,&an,progn,&prixn,&nbrpn,&pfn)!=EOF){
		if(p.k.id==idn ){continue;}
else fprintf(tmp,"%d %s %s %s %s %d %d %d %s %d %d %d\n",idn,typen,iddn,loginn,desn,jn,mn,an,progn,prixn,nbrpn,pfn);
}
fclose(f);
fclose(tmp);
rename("factexc.tmp","factexc.txt");
}

void supp_fact(fact p)
{
char typen[20],loginn[20];
int idn,pfn;
	FILE *f , *tmp;
	f=fopen("facture.txt","r");
	tmp=fopen("facture.tmp","a+");
	while(fscanf(f,"%d %s %s %d\n",&idn,typen,loginn,&pfn)!=EOF){
		if(p.id==idn ){continue;}
else fprintf(tmp,"%d %s %s %d\n",idn,typen,loginn,pfn);
}
fclose(f);
fclose(tmp);
rename("facture.tmp","facture.txt");
}




