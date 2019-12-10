#include <gtk/gtk.h>



typedef struct
{
char nom[300];
char prenom[300];
char cin[300];
char date[300];
char message[300];


}admin;

//void ajouter_avis(reservationrdv R);
void afficher_avis(GtkWidget *liste);
void supprimer_avis(char x[]);

void modifier_avis(y,z);
//void afficher_ad(GtkWidget *liste);
//void suprrimer_rg(char ID []);

//void modifier_rg(char ID [], char regime1[]);

//void afficher_ev(GtkWidget *liste);

//int calcul_imc (char ide []);
