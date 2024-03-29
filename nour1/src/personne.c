#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <gtk/gtk.h>
#include "personne.h"


enum
{
  CIN,
  NOM,
  PRENOM,
  DATE,
  ADRESSE,
  COLUMNS
};

void ajouter_personne(Personne p)
{
FILE* f;
f=fopen("/home/nour/Projects/nour1/src/utilisateur.txt","a");
  if(f!=NULL)
   {
   fprintf(f,"%s %s %s %s %s \n",p.cin,p.nom,p.prenom,p.date_naissence,p.adresse);
   }
fclose(f);
}

void afficher_personne(GtkWidget *liste)
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;

char nom[30];
char prenom[30];
char date[30];
char adresse[30];
char cin[30];
store=NULL;

FILE  *f;

store=gtk_tree_view_get_model(liste);

  if(store==NULL)
  {
   renderer=gtk_cell_renderer_text_new();
   column=gtk_tree_view_column_new_with_attributes("cin",renderer,"text",CIN,NULL);
   gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

   renderer=gtk_cell_renderer_text_new();
   column=gtk_tree_view_column_new_with_attributes("nom",renderer,"text",NOM,NULL);
   gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);	

   renderer=gtk_cell_renderer_text_new();
   column=gtk_tree_view_column_new_with_attributes("prenom",renderer,"text",PRENOM,NULL);
   gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

   renderer=gtk_cell_renderer_text_new();
   column=gtk_tree_view_column_new_with_attributes("date_naissence",renderer,"text",DATE,NULL);
   gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

   renderer=gtk_cell_renderer_text_new();
   column=gtk_tree_view_column_new_with_attributes("adresse",renderer,"text",ADRESSE,NULL);
   gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

   store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

   f=fopen("/home/nour/Projects/nour1/src/utilisateur.txt","r");

     if(f!=NULL)
        {
         f=fopen("/home/nour/Projects/nour1/src/utilisateur.txt","a+");
         while(fscanf(f,"%s %s %s %s %s",cin,nom,prenom,date,adresse)!=EOF)
          {
           gtk_list_store_append(store,&iter);
           gtk_list_store_set(store,&iter,CIN,cin,NOM,nom,PRENOM,prenom,DATE,date,ADRESSE,adresse,-1);
          }
        }
   fclose(f);
   gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
   g_object_unref(store);  
   }
}
		
