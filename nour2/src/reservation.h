typedef struct
{
int jour;
int mois;
int annee;
}Date;

typedef struct
{
char num[5];
char bloc;
Date dt_resr;
int  hr_resr;
}ReservationSalle;

int tableau_salle_reserver(ReservationSalle tab[50]);
int verifier_reserver(ReservationSalle sa);
int tableau_salle_disponible(char nom_salle[50][10],char bloc,Date dt_resr,int hr_resr);
void reserver_salle(ReservationSalle s); 
