#include <string.h>

#include <stdio.h>
#include <stdlib.h>
#include "nour.h"
void ajouterex(char id[],char des[],char prog[],int nbre)
{

FILE*f;
f=fopen("vol.txt","a+");
if (f!=NULL)
{fprintf(f,"%s %s %s %d\n",id,des,prog,nbre);
fclose(f);
}
}
///////////////////////////////////////
//Afficher un excursion par la treeview
enum   
{       
 
 ID,
 DES,
 PROG,
 Nbre,
 COLUMNS
};

void afficherex(GtkWidget *liste)
{
 GtkCellRenderer *renderer;
 GtkTreeViewColumn *column;
 GtkTreeIter    iter;
 GtkListStore *store;


 char id[30];
 char prog[30];
 char des[50];
 int nbre;



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
	 column = gtk_tree_view_column_new_with_attributes("programme", renderer, "text",PROG, NULL);
	 gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	 renderer = gtk_cell_renderer_text_new ();
	 column = gtk_tree_view_column_new_with_attributes("nbre de place", renderer, "text",Nbre, NULL);
	 gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);



	



	}


 store=gtk_list_store_new (COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_INT);

 f = fopen("vol.txt", "r");

 if(f==NULL)
	{
	 return;
	}		
 else 
	{
 	 f = fopen("vol.txt", "a+");
	 while(fscanf(f,"%s %s %s %d\n",id,des,prog,&nbre)!=EOF)
		{
		 gtk_list_store_append (store, &iter);
		 gtk_list_store_set (store,&iter,ID,id,DES,des,PROG,prog,Nbre,nbre,-1); 
		}
	 fclose(f);
	 gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
	 g_object_unref (store);
	}
}
////////////modfier//
void modifier1(char id[],char des[],char prog[],int nbr)
{ 	
	char idn[20],progn[20],desn[20];
int nbrn;
	FILE *f , *tmp;
	f=fopen("vol.txt","r");
	tmp=fopen("vol.tmp","a+");
	while(fscanf(f,"%s %s %s %d\n",idn,desn,progn,&nbrn)!=EOF){
		if(!strcmp(id,idn) ){fprintf(tmp,"%s %s %s %d\n",id,des,prog,nbr);}
else fprintf(tmp,"%s %s %s %d\n",idn,desn,progn,nbrn);
}
fclose(f);
fclose(tmp);
rename("vol.tmp","vol.txt");
}                  
///////supprimer
void supprimer1(char id[],char des[],char prog[],int nbr)
{ 	
	char idn[20],progn[20],desn[20];
int nbrn;
	FILE *f , *tmp;
	f=fopen("vol.txt","r");
	tmp=fopen("vol.tmp","a+");
	while(fscanf(f,"%s %s %s %d\n",idn,desn,progn,&nbrn)!=EOF){
		if(!strcmp(id,idn) ){continue;}
else fprintf(tmp,"%s %s %s %d\n",idn,desn,progn,nbrn);
}
fclose(f);
fclose(tmp);
rename("vol.tmp","vol.txt");
} 

