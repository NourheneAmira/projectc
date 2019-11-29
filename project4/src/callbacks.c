#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif
#include <gtk/gtkclist.h>
#include <gdk/gdkkeysyms.h>
#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "string.h"
#include "verif.h"
#include "nourhene.h"



void
on_button1_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

	GtkWidget *input1;
	GtkWidget *input2;

	char identifiant[30];
	char password[30];

	int r=0;


	input1=lookup_widget(objet_graphique,"entry1");
	input2=lookup_widget(objet_graphique,"entry2");

	strcpy(identifiant,gtk_entry_get_text(GTK_ENTRY(input1)));
	strcpy(password,gtk_entry_get_text(GTK_ENTRY(input2)));
	
	r=verif(identifiant,password);
	
	if (r==1)
	{	GtkWidget *window2;
		GtkWidget *window1;
		window2= create_window2 ();
		gtk_widget_show (window2);
		window1=lookup_widget(objet_graphique,"window1");
		gtk_widget_destroy(window1);
	}	

	if (r==2)
	{	GtkWidget *window1;
		GtkWidget *window3;
	 	window3= create_window3 ();
  	        gtk_widget_show (window3);
		window1=lookup_widget(objet_graphique,"window1");
		gtk_widget_destroy(window1);
	}

	if (r==3)
	{	
		GtkWidget *window1;
		GtkWidget *window4;
	        window4= create_window4();
  	        gtk_widget_show (window4);
		window1=lookup_widget(objet_graphique,"window1");
		gtk_widget_destroy(window1);
	}

	
	
	
}


void
on_button2n_clicked (GtkWidget       *objet_graphique,
                                        gpointer         user_data)                  
{
char id[30];char dep[30];char arr[30];char ddep[30];char darr[30];char rtour[30];char clsse[30]; int nbr;
GtkWidget *input1;
GtkWidget *input2;
GtkWidget *input3;
GtkWidget *input4;
GtkWidget *input5;
GtkWidget *window4;
GtkWidget *nbrplace;
GtkWidget *retour;
GtkWidget *classe;

input1= lookup_widget(objet_graphique,"entry3n");
input2= lookup_widget(objet_graphique,"entry4n");
input3= lookup_widget(objet_graphique,"entry5n");
input4= lookup_widget(objet_graphique,"entry6n");
input5= lookup_widget(objet_graphique,"entry7n");
window4= lookup_widget(objet_graphique,"window4");


nbrplace=lookup_widget(objet_graphique,"spinbutton1n");
retour=lookup_widget(objet_graphique,"comboboxentry1n"); 
classe=lookup_widget(objet_graphique,"comboboxentry2n"); 

nbr=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(nbrplace));


strcpy(id,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(dep,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(arr,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(ddep,gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy(darr,gtk_entry_get_text(GTK_ENTRY(input5)));
strcpy(rtour,gtk_combo_box_get_active_text (GTK_COMBO_BOX(retour)));
strcpy(clsse,gtk_combo_box_get_active_text (GTK_COMBO_BOX(classe))); 
ajouterv(id,dep,arr,ddep,darr,rtour,clsse,nbr);

}


void
on_comboboxn_changed                   (GtkComboBox     *combobox,
                                        gpointer         user_data)
{

}

/*
void
on_button22n_clicked                   (GtkButton       *button,
                                        gpointer         user_data)  
{
GtkWidget *window4,*List_View;


window4= lookup_widget(button,"window4");
window4= create_window4();
List_View=lookup_widget(window4,"treeview2n");
afficher1(List_View);

}*/
/*void on_button_afficher_clicked (GtkWidget *objet_graphique,gpointer user_data)
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
}*/

