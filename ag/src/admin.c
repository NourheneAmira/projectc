

#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>
#include "admin.h"
#include "string.h"
//////////////////////ajout///////////////////////////////////////////////////////////
void ajouteri1(compt c)
{
FILE*f;

f=fopen("compt.txt","a+");
if (f!=NULL){
fprintf(f,"%s %s %d %s %s %s %d %s %s %s\n",c.login,c.password,c.role,c.nom,c.prenom,c.cin,c.age,c.tel,c.ad,c.mail);
fclose(f);}

}
void ajouteri11(compt c)
{
FILE*f;

f=fopen("compt.txt","a+");
if (f!=NULL){
fprintf(f,"%s %s %d %s %s %s %d %s %s %s\n",c.login,c.password,2,c.nom,c.prenom,c.cin,c.age,c.tel,c.ad,c.mail);
fclose(f);}

}
void ajouteri12(compt c)
{
FILE*f;
f=fopen("user.txt","a+");
if (f!=NULL){
fprintf(f,"%s %s %d\n",c.login,c.password,2);
fclose(f);}
}
void ajouteri2(compt c)
{
FILE*f;
f=fopen("user.txt","a+");
if (f!=NULL){
fprintf(f,"%s %s %d\n",c.login,c.password,c.role);
fclose(f);}
}
//////////////////////////////////////////////afficher/////////////////////
enum  
{      
 
 LOG,
 PASS,
 R,
 NOM,
 PRE,
 CIN,
 AGE,
 TEL,
 ADRESS,
 MAIL,
 COLUMNS
};

void afficheri(GtkWidget *liste)
{
 GtkCellRenderer *renderer;
 GtkTreeViewColumn *column;
 GtkTreeIter    iter;
 GtkListStore *store;


 char log[30];
 char pass[30];
 char prenom[50];
 char nom[50];
 char cin[30];
 char adress[50];
 char mail[30];
 char tel[20];
 int r;
 int age;



 store=NULL;

 FILE *f;

 store=gtk_tree_view_get_model(liste);
 if (store==NULL)
{
renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("login", renderer,"text",LOG, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

       

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("passwor", renderer, "text",PASS, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);


         renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("role", renderer, "text",R, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("nom", renderer, "text",NOM, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("prenom", renderer, "text",PRE, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("cin", renderer, "text",CIN, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

  renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("age", renderer, "text",AGE, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("num", renderer, "text",TEL, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

 renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("adresse", renderer, "text",ADRESS, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("mail ", renderer, "text",MAIL, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);










}


 store=gtk_list_store_new (COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_INT,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_INT,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

 f = fopen("compt.txt", "r");

 if(f==NULL)
{
return;
}
 else
{
  f = fopen("compt.txt", "a+");
while(fscanf(f,"%s %s %d %s %s %s %d %s %s %s",log,pass,&r,nom,prenom,cin,&age,tel,adress,mail)!=EOF)
{
gtk_list_store_append (store, &iter);
gtk_list_store_set (store,&iter,LOG,log,PASS,pass,R,r,NOM,nom,PRE,prenom,CIN,cin,AGE,age,TEL,tel,ADRESS,adress,MAIL,mail,-1);
}
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
g_object_unref (store);
}
}

//////////////////modifier ///////////////////////////////////////////////////////////////

/*
void modifier(char login[],char password[],int role,char nom[],char prenom[],char cin[],int age,char tel[],char ad[],char mail[])
{
char logi[20],passi[20],nomi[20],prenomi[20],cini[20],teli[20],adi[20],maili[30],rolei[30];
int ai;
FILE *f , *tmp;
f=fopen("compt.txt","r");
tmp=fopen("compt.tmp","a+");
while(fscanf(f,"%s %s %d %s %s %s %d %s %s %s\n",logi,passi,rolei,nomi,prenomi,cini,ai,teli,adi,maili)!=EOF){
if(!strcmp(login,logi) ){fprintf(tmp,"%s %s %d %s %s %s %d %s %s %s\n",login,password,role,nom,prenom,cin,age,tel,ad,mail);}
else fprintf(tmp,"%s %s %d %s %s %s %d %s %s %s\n",logi,passi,rolei,nomi,prenomi,cini,ai,teli,adi,maili);
}
fclose(f);
fclose(tmp);
rename("compt.tmp","compt.txt");
}                  



////////////////////////////////supprimer//////////////////////////////////*/
////////////// //////////////////////////verifier////////////////////
int verifidc (compt c,char log[])
{
FILE *f ;

	f=fopen("compt.txt","r");
   
while(fscanf(f,"%s %s %d %s %s %s %s %s %s %s\n",c.login,c.password,&c.role,c.nom,c.prenom,c.cin,&c.age,c.tel,c.ad,c.mail)!=EOF){
if(strcmp(log,c.login)==0)
{fclose(f);
return 0; }
 }
fclose(f);
return 1;
}

 int verifidi(char id[])
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
int verifentryi(char a[])
{
 if (strlen(a)==0)
{return 0;}
else return 1;}///////////////////supprimer ///////////////////


void supprimerlog(char LOG[],compt c)
{
 
  FILE *f;
  FILE *compt_tmp;

 

  f=fopen("compt.txt","a+");
	compt_tmp=fopen("compt_tmp.txt","a+");
  while(fscanf(f,"%s %s %d %s %s %s %d %s %s %s\n",c.login,c.password,&c.role,c.nom,c.prenom,c.cin,&c.age,c.tel,c.ad,c.mail)!=EOF)
        {
          if (strcmp(c.login,LOG)!=0)
          {
            fprintf(compt_tmp,"%s %s %d %s %s %s %d %s %s %s\n",c.login,c.password,c.role,c.nom,c.prenom,c.cin,c.age,c.tel,c.ad,c.mail);
          }
        }
        fclose(f);
      	fclose(compt_tmp);

      	remove("compt.txt");
      	rename("compt_tmp.txt","compt.txt");

}
///////////////********************
void modifierihsen(compt c,char cin1 [30],char ad[30],char tel[20],char mail[20])
{
 /*char nom[300];
char prenom[300];
char cin[300];
char date[300];
char message[300];*/
 

  FILE *f;
  FILE *f_tmp;

 

  f=fopen("compt.txt","a+");
f_tmp=fopen("compt_tmp.txt","a+");
  if (f!=NULL)
  {
    while(fscanf(f,"%s %s %d %s %s %s %d %s %s %s\n",c.login,c.password,&c.role,c.nom,c.prenom,c.cin,&c.age,c.tel,c.ad,c.mail)!=EOF)
          {
                if (strcmp(c.login,cin1)!=0)
                  {
                   fprintf(f_tmp,"%s %s %d %s %s %s %d %s %s %s\n",c.login,c.password,c.role,c.nom,c.prenom,c.cin,c.age,c.tel,c.ad,c.mail);
                   
                   }
               else
                 {strcpy(c.tel,tel);strcpy(c.ad,ad);strcpy(c.mail,mail);

                   fprintf(f_tmp,"%s %s %d %s %s %s %d %s %s %s\n",c.login,c.password,c.role,c.nom,c.prenom,c.cin,c.age,c.tel,c.ad,c.mail);
                 }
          }
     }
          fclose(f);
          fclose(f_tmp);
          rename("compt_tmp.txt","compt.txt");
}
