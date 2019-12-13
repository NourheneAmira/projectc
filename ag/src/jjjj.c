#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "hhhh.h"
#include <gtk/gtk.h>
#include <time.h>
/****************************************RDV******************************************************************************************/












enum
{
NOM,
PRENOM,
CIN,
DATE,
MESSAGE,
COLUMNS


};

void afficher_avis(GtkWidget *treeview2) {

GtkCellRenderer *renderer ;
GtkTreeViewColumn *column ;
GtkTreeIter iter ;
GtkListStore *store ;

char nom[300];
char prenom[300];
char cin[300];
char date[300];
char message[300];





FILE *f ;
store =NULL ;
store=gtk_tree_view_get_model(treeview2);
if (store == NULL)
{
            renderer=gtk_cell_renderer_text_new ();
            column=gtk_tree_view_column_new_with_attributes ("nom",renderer,"text",NOM,NULL);
            gtk_tree_view_append_column(GTK_TREE_VIEW(treeview2),column);

            renderer=gtk_cell_renderer_text_new ();
            column=gtk_tree_view_column_new_with_attributes ("prenom",renderer,"text",PRENOM,NULL);
            gtk_tree_view_append_column(GTK_TREE_VIEW(treeview2),column);

            renderer=gtk_cell_renderer_text_new ();
            column=gtk_tree_view_column_new_with_attributes ("cin",renderer,"text",CIN,NULL);
            gtk_tree_view_append_column(GTK_TREE_VIEW(treeview2),column);

             renderer=gtk_cell_renderer_text_new ();
            column=gtk_tree_view_column_new_with_attributes ("date",renderer,"text",DATE,NULL);
            gtk_tree_view_append_column(GTK_TREE_VIEW(treeview2),column);
            renderer=gtk_cell_renderer_text_new ();
            column=gtk_tree_view_column_new_with_attributes ("message",renderer,"text",MESSAGE,NULL);
            gtk_tree_view_append_column(GTK_TREE_VIEW(treeview2),column);


 

          
}


store =gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING ,G_TYPE_STRING );

char s[9]={"********"};

            f=fopen("avis.txt","r");
            if (f!=NULL){
		while (fscanf(f,"%s %s %s %s %s",nom,prenom,cin,date,message)!=EOF) {
            gtk_list_store_append(store,&iter);
            gtk_list_store_set
            (store,&iter,NOM,nom,PRENOM,prenom,CIN,s,DATE,date,MESSAGE,message,-1);
		}
		}
		fclose(f);
            gtk_tree_view_set_model(GTK_TREE_VIEW(treeview2),GTK_TREE_MODEL(store));
            g_object_unref(store);
	    

}



	



 
void modifier_avis(char cin1 [300],char messagec[300])
{
FILE *f;
FILE* f_tmp;
 admin R;
 char nom[300];
char prenom[300];
char cin[300];
char date[300];
char message[300];
 

f=fopen("avis.txt","r");
  f_tmp=fopen("avis_tmp.txt","a+");
  if (f!=NULL)
  {
    while(fscanf(f,"%s %s %s %s %s",nom,prenom,cin,date,message)!=EOF)
          {
                if (strcmp(cin,cin1)!=0)
                  {
                   fprintf(f_tmp,"%s %s %s %s %s\n",nom,prenom,cin,date,message);
                   
                   }
               else
                 {
                   fprintf(f_tmp,"%s %s %s %s %s\n",nom,prenom,cin,date,messagec);
                 }
          }
     }
          fclose(f);
          fclose(f_tmp);
///remove("avis.tmp");

     
          rename("avis_tmp.txt","avis.txt");

  
}
void supprimer_avis(char CIN[])
{


  admin R;
  FILE *f;
  FILE *f_tmp;
   char nom[300];
char prenom[300];
char cin[300];
char date[300];
char message[300];
 

  f=fopen("avis.txt","a+");
	f_tmp=fopen("avis_tmp.txt","a+");
  while(fscanf(f,"%s %s %s %s %s \n",nom,prenom,cin,date,message)!=EOF)
        {
          if (strcmp(cin,CIN)!=0)
          {
            fprintf(f_tmp,"%s %s %s %s %s \n",nom,prenom,cin,date,message);
          }
  //else
                  //{
                   // fprintf(f,"%s %s %s %s %s \n",nom,prenom,cin,date,message);
                  //}
          
        }
        fclose(f);
      	fclose(f_tmp);

      	remove("avis.txt");
      	rename("avis_tmp.txt","avis.txt");

}

void date_a (char dt[])
{
 int jour,mois,annee;
 char j[10];
 char m[10];
 char a[10];
 char sl[5]="/";
 time_t now;
 time(&now);
 struct tm *local=localtime(&now);
 jour = local->tm_mday;
 mois = local->tm_mon+1;
 annee= local->tm_year+1900;
 sprintf(j,"%d",jour);
 sprintf(m,"%d",mois);
 sprintf(a,"%d",annee);
 strcpy(dt," ");
 strcat(dt,j);
 strcat(dt,sl);
 strcat(dt,m);
 strcat(dt,sl);
 strcat(dt,a);
}





	











