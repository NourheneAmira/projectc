#include"recla.h"
#include<stdio.h>
#include<stdlib.h>

#include<string.h>
int calculenbrefich()
{
    FILE* f=fopen("recla.txt","r");
    char s[1500];
    int nb=0;

while(fgets(s,1500,f)!=NULL)
nb++;
fclose(f);

return nb ;}
void lirefichrec(rec tab[] )
{
 FILE* f=fopen("recla.txt","r");

 int i;
 i=0;

 while(!feof(f)){ fscanf(f,"%d ;%s ;%d ;%s ;%s\n",&tab[i].id,tab[i].nom_user,&tab[i].etat,tab[i].textrec,tab[i].reponserec);

        i++ ;
            }



 fclose(f);
}
void ecrirerecfich(rec tab[],int n)
{int i;
char s[10]={";"};
    FILE* f=fopen("recla.txt","w");
    for (i=0;i<=n;i++)
    {
        fprintf(f,"%d %s%s %s%d %s%s %s%s\n",tab[i].id,s,tab[i].nom_user,s,tab[i].etat,s,tab[i].textrec,s,tab[i].reponserec);
    }
fclose(f);}
 void ajoutrec(rec tab[],int n,char login[],char text[])
 {char  s[20]="k";

    tab[n].id=n;
   
    strcpy(tab[n].nom_user,login);
    
    strcpy(tab[n].textrec,text);
    tab[n].etat=0;
    strcpy(tab[n].reponserec,s);
   

 }
 void ajoutrep(rec tab[],int n,int id)
 {
     if ((id<0)||(id>n)) printf("id non trouvable");
 else
     {printf("donner la rep pour la rec num %d \n",id);
     fflush(stdin);
       gets(tab[id].reponserec);
     tab[id].etat=1;}


 }
 void affichrecag(rec tab[],int n)
 {int i;
     for (i=0;i<n;i++)
     {
         printf("id de rec: %d la rec de la part de : %s l'etat de la rec: %d la rec: %s votre reponse: %s \n ",tab[i].id,tab[i].nom_user,tab[i].etat,tab[i].textrec,tab[i].reponserec);
     }
 }
 void affichrecuser(rec tab[],int n,char username[])
 {int i;
     for (i=0;i<n;i++)
     {
         if (strcmp(username,tab[i].nom_user)==0)
printf("id de rec: %d la rec de la part de : %s l'etat de la rec: %d la rec: %s votre reponse: %s \n ",tab[i].id,tab[i].nom_user,tab[i].etat,tab[i].textrec,tab[i].reponserec);
     }
 }
 void modifrecus(rec tab[],int n,int id )
 {int  i;

// printf("donner le id de rec");
 //scanf("%d",is);
     for (i=0;i<n;i++)
     {
         if (tab[i].id==id){i=n+1;}
     }
 if (i==n+2){printf("%s",tab[id].textrec);
 printf("donner la nouvelle rec");
 fflush(stdin);
 gets(tab[id].textrec);}
 else printf("la reclamation souhaite n'existe pas ");


 }
enum   
{       
 
 ID,
 USER,
 ETAT,
 TEXTREC,
 TEXTREP,
 COLUMNS
};







void afficher_recag(GtkWidget *liste)
{
 GtkCellRenderer *renderer;
 GtkTreeViewColumn *column;
 GtkTreeIter    iter;
 GtkListStore *store;


 char id[20];
 char user[60];
 char etat[5];
 char textrec[500];
 char textrep[500];



 store=NULL;

 FILE *f;

 store=gtk_tree_view_get_model(liste);	
 if (store==NULL)
	{
	 renderer = gtk_cell_renderer_text_new ();
	 column = gtk_tree_view_column_new_with_attributes("id", renderer, "text",ID, NULL);
	 gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

       

	 renderer = gtk_cell_renderer_text_new ();
	 column = gtk_tree_view_column_new_with_attributes("user", renderer, "text",USER, NULL);
	 gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);


         renderer = gtk_cell_renderer_text_new ();
	 column = gtk_tree_view_column_new_with_attributes("etat", renderer, "text",ETAT, NULL);
	 gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

         renderer = gtk_cell_renderer_text_new ();
	 column = gtk_tree_view_column_new_with_attributes("textrec", renderer, "text",TEXTREC, NULL);
	 gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

         renderer = gtk_cell_renderer_text_new ();
	 column = gtk_tree_view_column_new_with_attributes("textrep", renderer, "text",TEXTREP, NULL);
	 gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);




	



	}


 store=gtk_list_store_new (COLUMNS, G_TYPE_STRING,  G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

 f = fopen("recla.txt", "r");

 if(f==NULL)
	{
	 return;
	}		
 else 
	{
 	 
	 while(fscanf(f,"%s ;%s ;%s ;%s ;%s\n",id,user,etat,textrec,textrep)!=EOF)
		{
		 gtk_list_store_append (store, &iter);
		 gtk_list_store_set (store,&iter,ID,id,USER,user,ETAT,etat,TEXTREC,textrec,TEXTREP,textrep,-1); 
		}
	 fclose(f);
	 gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));

	 g_object_unref (store);
	}
}
void afficher_reccli(GtkWidget *liste)
{
 GtkCellRenderer *renderer;
 GtkTreeViewColumn *column;
 GtkTreeIter    iter;
 GtkListStore *store;


 char id[20];
 char user[60];
 char etat[5];
 char textrec[500];
 char textrep[500];

 char s[50];

 store=NULL;

 FILE *f;

 store=gtk_tree_view_get_model(liste);	
 if (store==NULL)
	{
	 renderer = gtk_cell_renderer_text_new ();
	 column = gtk_tree_view_column_new_with_attributes("id", renderer, "text",ID, NULL);
	 gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

       

	 renderer = gtk_cell_renderer_text_new ();
	 column = gtk_tree_view_column_new_with_attributes("user", renderer, "text",USER, NULL);
	 gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);


         renderer = gtk_cell_renderer_text_new ();
	 column = gtk_tree_view_column_new_with_attributes("etat", renderer, "text",ETAT, NULL);
	 gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

         renderer = gtk_cell_renderer_text_new ();
	 column = gtk_tree_view_column_new_with_attributes("textrec", renderer, "text",TEXTREC, NULL);
	 gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

         renderer = gtk_cell_renderer_text_new ();
	 column = gtk_tree_view_column_new_with_attributes("textrep", renderer, "text",TEXTREP, NULL);
	 gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);




	



	}


 store=gtk_list_store_new (COLUMNS, G_TYPE_STRING,  G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

 f = fopen("recla.txt", "r");

 if(f==NULL)
	{
	 return;
	}		
 else 
	{
 	 
	 while(fscanf(f,"%s ;%s ;%s ;%s ;%s\n",id,user,etat,textrec,textrep)!=EOF)
		{FILE* k=fopen("util.txt","r");
                  fscanf(k,"%s",s);
                fclose(k);
               if (strcmp(s,user)==0){
		 gtk_list_store_append (store, &iter);
		 gtk_list_store_set (store,&iter,ID,id,USER,user,ETAT,etat,TEXTREC,textrec,TEXTREP,textrep,-1); }
		}
	 fclose(f);
	 gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));

	 g_object_unref (store);
	}
}


