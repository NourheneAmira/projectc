#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "reservation.h"
#include <string.h>

void on_buttonValider_clicked (GtkWidget *objet_graphique,gpointer user_data)
{
GtkWidget *Jour;
GtkWidget *Mois;
GtkWidget *Annee;
GtkWidget *Combobox1;
GtkWidget *Combobox2;
GtkWidget *Combobox3;

char bloc;
char Blocs[50];
char nom_salle[50][10];
Date dt_resr;
int i,n,hr_resr;

Jour=lookup_widget(objet_graphique,"spinbuttonJour");
Mois=lookup_widget(objet_graphique,"spinbuttonMois");
Annee=lookup_widget(objet_graphique,"spinbuttonAnnee");
Combobox1=lookup_widget(objet_graphique,"comboboxHR");
Combobox2=lookup_widget(objet_graphique,"comboboxBloc");
Combobox3=lookup_widget(objet_graphique,"comboboxSalle");

dt_resr.jour=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(Jour));
dt_resr.mois=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(Mois));
dt_resr.annee=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(Annee));

  if(strcmp("9H==>12H15",gtk_combo_box_get_active_text(GTK_COMBO_BOX(Combobox1)))==0)
   {
    hr_resr=1;
   }
  else
   {
    hr_resr=2;
   }

strcpy(Blocs,gtk_combo_box_get_active_text(GTK_COMBO_BOX(Combobox2)));
bloc=Blocs[0];
n=tableau_salle_disponible(nom_salle,bloc,dt_resr,hr_resr);

  for(i=0;i<n;i++)
   {
    gtk_combo_box_append_text(GTK_COMBO_BOX(Combobox3),nom_salle[i]);
   }
}

void on_buttonConfirmer_clicked (GtkWidget *objet_graphique,gpointer  user_data)
{
GtkWidget *Jour;
GtkWidget *Mois;
GtkWidget *Annee;
GtkWidget *Combobox1;
GtkWidget *Combobox2;
GtkWidget *Combobox3;
GtkWidget *sortie;

char Blocs[50];
ReservationSalle s;

Jour=lookup_widget(objet_graphique,"spinbuttonJour");
Mois=lookup_widget(objet_graphique,"spinbuttonMois");
Annee=lookup_widget(objet_graphique,"spinbuttonAnnee");
Combobox1=lookup_widget(objet_graphique,"comboboxHR");
Combobox2=lookup_widget(objet_graphique,"comboboxBloc");
Combobox3=lookup_widget(objet_graphique,"comboboxSalle");
sortie=lookup_widget(objet_graphique,"labelSortie");

s.dt_resr.jour=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(Jour));
s.dt_resr.mois=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(Mois));
s.dt_resr.annee=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(Annee));

  if(strcmp("9H==>12H15",gtk_combo_box_get_active_text(GTK_COMBO_BOX(Combobox1)))==0)
   {
    s.hr_resr=1;
   }
  else
   {
    s.hr_resr=2;
   }

strcpy(Blocs,gtk_combo_box_get_active_text(GTK_COMBO_BOX(Combobox2)));
s.bloc=Blocs[0];
strcpy(s.num,gtk_combo_box_get_active_text(GTK_COMBO_BOX(Combobox3)));
reserver_salle(s);
GdkColor color;
gdk_color_parse ("blue", &color);
gtk_widget_modify_fg (sortie, GTK_STATE_NORMAL, &color);
gtk_label_set_text(GTK_LABEL(sortie),"reservation réussite");
}



