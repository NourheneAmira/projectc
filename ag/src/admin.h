#include <gtk/gtk.h>

typedef struct{
char login[20];
char password[30];
int role;
char nom[20] ; char prenom[20];
char cin[10];
int age;
char tel[20];
char ad[25];
char mail[30];
}compt;
void ajouteri1(compt c);
void ajouteri2(compt c);
//void modifier(char login[],char password[],int role,char nom[],char prenom[],char cin[],int age,char tel[],char ad[],char mail[]);
void afficheri(GtkWidget *liste);
void supprimerlog(char LOG[],compt c);
 int verifidi(char id[]);
int verifidc (compt c,char log[]);
void modifierihsen(compt c,char cin1 [30],char ad[30],char tel[20],char mail[20]);
