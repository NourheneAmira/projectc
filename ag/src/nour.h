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
int prix;
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
////////////////////////////////////////////adib+thamer////////////////
typedef struct{
 	int id;
        vol r;
	char login[50];
	int nbrp;
}resvol;

typedef struct{
 	int id;
        hotel r;
	int j;
	int m;
	int a;
	int nn;
	char login[50];
	int nbrp;
}reshot;

typedef struct{
 	int id;
        excursion r;
	char login[50];
	int nbrp;
}resexc;
typedef struct{
 	int id;
	char type[10];
	char login[50];
	int nbrp;
}res;

typedef struct{
 	resvol k;
	char type[10];
	int pf;
}factvol;
typedef struct{
 	reshot k;
	char type[10];
	int pf;
}facthot;
typedef struct{
 	resexc k;
	char type[10];
	int pf;
}factexc;
typedef struct{
 	int id;
	char type[10];
	char login[50];
	int pf;
}fact;




///////resvol/////
void ajout_resvol_txt(resvol p );
vol rechercheduvol(char id[]);
int iddd ();
int disponiblevol (vol v, int a);
/////////reshot//////////
hotel rechercheduhotel(char d[]);
void ajout_reshot_txt( reshot p );
int idddh ();
void modif_reshot(reshot p);
int disponiblehot (hotel v, int a);
reshot recherche_res_hot_id (int d);
int bissextile(int an);
int longueur_mois(int m,int a);
int est_valide(int j, int m, int a);
//////////resexc////////////
excursion rechercheduexc(char d[]);
void ajout_resexc_txt( resexc p );
void modif_resexc(resexc p);
int iddde ();
int disponibleexc (excursion v, int a);
////////////////reservation//////////////
void ajout_res_txt( res z);
void afficher_reservation(GtkWidget *liste);
void affiche_mon_res_vol (GtkWidget *liste );
resvol recherche_res_vol_id (int d);
void affiche_mon_res_exc (GtkWidget *liste );
void affiche_mon_res_hotel (GtkWidget *liste );
void supprimer_resvol(resvol p);
void modif_resvol(resvol p);
void supprimer_res(res p);
void modif_res(res p);  
resexc recherche_res_exc_id (int d);

////////////////////facturation////////////////////
void modif_fact(fact p);
/******factvol******/
void ajout_factvol_txt( factvol t );
void modif_factvol(factvol p);
void supp_factvol(factvol p);
/*******facthot******/
void ajout_facthot_txt( facthot t );
void modif_facthot(facthot p);
void supp_facthot(facthot p);
/*******factexc*******/
void ajout_factexc_txt( factexc t );
void modif_factexc(factexc p);
void supp_factexc(factexc p);
/////////////////////////////////
void ajout_fact_txt( fact z);
void supp_fact(fact p);
void afficher_facture(GtkWidget *liste);
//////////////////
int verifidv (vol v,char log[]);
int verifentry(char a[]);

int verifidh (hotel h,char log[]);

int verifide (excursion e ,char log[]);
 int verifid(char id[]);
///////////////////////////***
void afficherkhkh(GtkWidget *liste,char combo[]);
void afficherhh(GtkWidget *liste,char comboo[]);
void afficherhhh(GtkWidget *liste,char combo[]);
void afficherkhkh1(GtkWidget *liste,char combo[]);
void afficherhh1(GtkWidget *liste,char comboo[]);
