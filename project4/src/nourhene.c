#include <string.h>
#include "nourhene.h"
#include <stdio.h>
#include <stdlib.h>
enum { 
       COL_ID,
       COL_DepartDe,
       COL_ArriveeA,
       COL_Ddepart,
       COL_Darrivee,
       COL_Retour,
       COL_Classe,	
       NUM_COLS
      };
void ajouterv(char id[],char dep[],char arr[],char ddep[],char darr[],char retour[],char classe[], int nbreplace)
{

FILE*f;
f=fopen("/home/nour/Projects/project4/src/vols.txt","a+");
if(f!=NULL)
{fprintf(f,"%s %s %s %s %s %s %s %d\n",id,dep,arr,ddep,darr,retour,classe,nbreplace);

fclose(f);}
}
//////////////ajouter excursion/////////////
/*
void ajouterex(char id[],char des[],char date[])
{

FILE*f;
f=fopen("/home/nour/Projects/project4/src/excu.txt","a+");
if(f!=NULL)
{fprintf(f,"%s %s %s %s %s %s %s %d\n",id,des,date);

fclose(f);}
}
//////////////////afficher excursion////////////////////////////
void afficher2(GtkWidget *liste)
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;

char id[30];
char des[30];
char date[30];

store=NULL;

FILE  *f;

store=gtk_tree_view_get_model(liste);

  if(store==NULL)
  {
   renderer=gtk_cell_renderer_text_new();
   column=gtk_tree_view_column_new_with_attributes("identifiant",renderer,"text",ID,NULL);
   gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

   renderer=gtk_cell_renderer_text_new();
   column=gtk_tree_view_column_new_with_attributes("destination",renderer,"text",DES,NULL);
   gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);	

   renderer=gtk_cell_renderer_text_new();
   column=gtk_tree_view_column_new_with_attributes("date",renderer,"text",DATE,NULL);
   gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

   

   store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

   f=fopen("/home/nour/Projects/project4/src/excu.txt","r");

     if(f!=NULL)
        {
         f=fopen("/home/nour/Projects/project4/src/excu.txt","a+");
         while(fscanf(f,"%s %s %s %s %s",id,des,date)!=EOF)
          {
           gtk_list_store_append(store,&iter);
           gtk_list_store_set(store,&iter,ID,id,DES,des,DATE,date,-1);
          }
        }
   fclose(f);
   gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
   g_object_unref(store);  
   }
}
*/
//////////////////////////afficher vols////////////////////
void afficher1(GtkWidget *plistview)
{


}
/*

void afficher1(GtkWidget *plistview)
{ 

char id[20],dep[20],arr[20],ddep[20],darr[20],retour[20],classe[20];


GtkListStore *liststore;
GtkCellRenderer *celrender;
GtkTreeViewColumn *col;
liststore = gtk_list_store_new (NUM_COLS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
FILE *f1;
f1=fopen("/home/nour/Projects/project4/vols.txt","r");
if(f1!=NULL){
       while(fscanf(f1,"%s %s %s %s %s %s %s\n",id,dep,arr,ddep,darr,retour,classe)!=EOF){
           GtkTreeIter iter;
            gtk_list_store_append(liststore, &iter);
            gtk_list_store_set(liststore, &iter,COL_ID,id,COL_DepartDe,dep,COL_ArriveeA,arr,COL_Ddepart,ddep,COL_Darrivee,darr,    			COL_Retour,retour,COL_Classe,classe,-1);
}
	celrender = gtk_cell_renderer_text_new();
	col = gtk_tree_view_column_new_with_attributes("identifiant",celrender,"text",COL_ID,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(plistview),col);

	celrender = gtk_cell_renderer_text_new();
	col = gtk_tree_view_column_new_with_attributes("depart de",celrender,"text",COL_DepartDe,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(plistview),col);

	celrender = gtk_cell_renderer_text_new();
	col = gtk_tree_view_column_new_with_attributes("arrivee a",celrender,"text",COL_ArriveeA,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(plistview),col);

        celrender = gtk_cell_renderer_text_new();
	col = gtk_tree_view_column_new_with_attributes("D depart",celrender,"text",COL_Ddepart,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(plistview),col);
        
       celrender = gtk_cell_renderer_text_new(); 
	col = gtk_tree_view_column_new_with_attributes("D arrive",celrender,"text",COL_Darrivee,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(plistview),col);  
       
       celrender = gtk_cell_renderer_text_new(); 
	col = gtk_tree_view_column_new_with_attributes("retour",celrender,"text",COL_Retour,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(plistview),col);
	
	celrender = gtk_cell_renderer_text_new(); 
	col = gtk_tree_view_column_new_with_attributes("classe",celrender,"text",COL_Classe,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(plistview),col);
 
      gtk_tree_view_set_model (GTK_TREE_VIEW(plistview), GTK_TREE_MODEL (liststore));

}
fclose(f1);
} */
