#ifndef RECLA_H_INCLUDED
#define RECLA_H_INCLUDED

#include <gtk/gtk.h>
typedef struct reclamation {
int id;
char nom_user[60];
int etat;
char textrec[500];
char reponserec[500];
char date[70];
}rec;
int calculenbrefich();
void lirefichrec(rec tab[] );
void ecrirerecfich(rec tab[],int n,char y[]);
void ajoutrec(rec tab[],int n,char login[],char text[]);
void ajoutrep(rec tab[],int n,int id);
void affichrecag(rec tab[],int n);
void affichrecuser(rec tab[],int n,char username[]);
void modifrecus(rec tab[],int n,int id1,char text[] );
void afficher_recag(GtkWidget *liste);
void afficher_reccli(GtkWidget *liste);
void supprimer(int id,rec p);
void modifrecag(rec tab[],int n,int id1,char text[] );

#endif // RECLA_H_INCLUDED

