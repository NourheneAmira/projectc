#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include <string.h>
#include "personne.h"


void on_buttonajouter_clicked (GtkWidget *objet_graphique,gpointer user_data)
{
Personne p;
GtkWidget *input1,*input2,*input3,*input4,*input5;
GtkWidget *fenetre_ajout;

fenetre_ajout=lookup_widget(objet_graphique,"fenetre_ajout");

input1=lookup_widget(objet_graphique,"entry_cin");
input2=lookup_widget(objet_graphique,"entry_nom");
input3=lookup_widget(objet_graphique,"entry_prenom");
input4=lookup_widget(objet_graphique,"entry_date_naissence");
input5=lookup_widget(objet_graphique,"entry_adresse");

strcpy(p.cin,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(p.nom,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(p.prenom,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(p.date_naissence,gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy(p.adresse,gtk_entry_get_text(GTK_ENTRY(input5)));

ajouter_personne(p);
}


void on_button_afficher_clicked (GtkWidget *objet_graphique,gpointer user_data)
{
GtkWidget *fenetre_ajout;
GtkWidget *fenetre_afficher;
GtkWidget *treeview1;

fenetre_ajout=lookup_widget(objet_graphique,"fenetre_ajout");

gtk_widget_destroy(fenetre_ajout);
fenetre_afficher=create_window2();
gtk_widget_show(fenetre_afficher);

treeview1=lookup_widget(fenetre_afficher,"treeview1");

afficher_personne(treeview1);
}


void on_button_retour_clicked   (GtkWidget *objet_graphique,gpointer user_data)
{
GtkWidget *fenetre_ajout;
GtkWidget *fenetre_afficher;

fenetre_afficher=lookup_widget(objet_graphique,"window2");
gtk_widget_destroy(fenetre_afficher);
fenetre_ajout=create_fenetre_ajout();
gtk_widget_show(fenetre_ajout);

}

