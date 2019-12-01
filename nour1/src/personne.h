#include <gtk/gtk.h>

typedef struct
{
char cin[30];
char nom[30];
char prenom[30];
char date_naissence[30];
char adresse[30];
}Personne;

void ajouter_personne(Personne p);
void afficher_personne(GtkWidget *liste);
