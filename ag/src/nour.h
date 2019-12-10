#include <gtk/gtk.h>
typedef struct{
char id[50];
char des[50];
int j; 
int m;
int a;
char prog[50];
int prix;
int p;}excursion;
typedef struct {
char id[30];
char lieu[30];
char nom[30];
int e;
char chambre[30];
int prixh ;
int p;}hotel;
typedef struct {
char id[30];
char dep[30];
char arr[30];
int jv;
int mv;
int av;
char heure[30];
char type[30];
int prixv;
 int pl;}vol;


///////////////excursion
void ajouter1(excursion p);
void afficher1(GtkWidget *liste);
void supprimer1(excursion p);
void modifier1(excursion p);
//////////////hotel
void afficher2(GtkWidget *liste);
void ajouter2(hotel h);
void modifier2(hotel h);
void supprimer2(hotel h);
////////////////vol
void afficher3(GtkWidget *liste);
void ajouter3(vol v);
void modifier3(vol v);
void supprimer3(vol v);
