#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "nour.h"
#include "string.h"

void
on_button2n_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
char id[30];char des[30];char prog[30]; int nbr;
GtkWidget *input1;
GtkWidget *input2;
GtkWidget *input3;
GtkWidget *window1;
GtkWidget *nbrplace;

input1= lookup_widget(objet_graphique,"entry1n");
input2= lookup_widget(objet_graphique,"entry2n");
input3= lookup_widget(objet_graphique,"entry3n");
window1= lookup_widget(objet_graphique,"window1");


nbrplace=lookup_widget(objet_graphique,"spinbutton1n");


nbr=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(nbrplace));


strcpy(id,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(des,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(prog,gtk_entry_get_text(GTK_ENTRY(input3)));

ajouterex(id,des,prog,nbr);

}


void
on_button1n_clicked                    (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *window1;
GtkWidget *notebook1;
GtkWidget *treeview1n;
 window1=lookup_widget(button,"window1");
 notebook1=lookup_widget(window1,"notebook1");
 treeview1n=lookup_widget(notebook1,"treeview1n");
afficherex(treeview1n);




	
gtk_window_set_position(GTK_WINDOW(window1),GTK_WIN_POS_CENTER);

}


void
on_treeview1n_row_activated            (GtkWidget     *objet_graphique,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkWidget *window2,*window1,*notebook1;
GtkWidget *treeview1n;
GtkWidget *idn,*desn,*progn,*nbrn;
gchar *id,*des,*prog;
gint *nbre;
window1=lookup_widget(objet_graphique,"window1");
notebook1=lookup_widget(window1,"notebook1");
window2=create_window2();
treeview1n=lookup_widget(notebook1,"treeview1n");
idn=lookup_widget(window2,"entry122n");
desn=lookup_widget(window2,"entry123n");
progn=lookup_widget(window2,"entry124n");
nbrn=lookup_widget(window2,"spinbutton120n");
GtkTreeIter iter;
	GtkTreeModel *model=gtk_tree_view_get_model (GTK_TREE_VIEW(treeview1n));
	gtk_tree_model_get_iter(model,&iter,path);
	gtk_tree_model_get (model,&iter,0,&id,1,&des,2,&prog,3,&nbre,-1);
	printf("%s %s %s %d",id,des,prog,nbre);
	gtk_entry_set_text(GTK_ENTRY (idn),_(id));
	gtk_entry_set_text(GTK_ENTRY (desn),_(des));
        gtk_entry_set_text(GTK_ENTRY (progn),_(prog));
gtk_window_set_position(GTK_WINDOW(window1),GTK_WIN_POS_CENTER);
gtk_widget_show(window2);
/*
GtkWidget *window1;
GtkWidget *notebook1;
GtkWidget *treeview1n;
GtkWidget *idn,*desn,*progn,*nbrn;
gchar *id,*des,*prog;
gint *nbre;
window1=lookup_widget(objet_graphique,"window1");
notebook1=lookup_widget(window1,"notebook1");
treeview1n=lookup_widget(notebook1,"treeview1n");
idn=lookup_widget(window1,"entry100n");
desn=lookup_widget(window1,"entry101n");
progn=lookup_widget(window1,"entry102n");
nbrn=lookup_widget(window1,"spinbutton11n");
GtkTreeIter iter;
	GtkTreeModel *model=gtk_tree_view_get_model (GTK_TREE_VIEW(treeview1n));
	gtk_tree_model_get_iter(model,&iter,path);
	gtk_tree_model_get (model,&iter,0,&id,1,&des,2,&prog,3,&nbre,-1);
	printf("%s %s %s %d",id,des,prog,nbre);
	gtk_entry_set_text(GTK_ENTRY (idn),_(id));
	gtk_entry_set_text(GTK_ENTRY (desn),_(des));
        gtk_entry_set_text(GTK_ENTRY (progn),_(prog));
gtk_window_set_position(GTK_WINDOW(window1),GTK_WIN_POS_CENTER);
*/
} 
/*
void
on_treeview2n_row_activated            (GtkWidget     *objet_graphique,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{GtkWidget *idn,*nomn,*journ,*moisn,*anneen,*fraisn,*GestionEvent,*ModifEvent,*treeview;
gchar *id,*nom,*frais;
gint *jour,*mois,*annee;
	ModifEvent=create_ModifEvent();//
	treeview=lookup_widget(objet_graphique,"treeview2n");//
	GestionEvent=lookup_widget(objet_graphique,"GestionEvent");
	idn=lookup_widget(ModifEvent,"entry13n");
	nomn=lookup_widget(ModifEvent,"entry14n");
	
	journ=lookup_widget(ModifEvent,"spinbutton5n");
	moisn=lookup_widget(ModifEvent,"spinbutton6n");
 	anneen=lookup_widget(ModifEvent,"spinbutton7n");
	fraisn=lookup_widget(ModifEvent,"comboboxentry2n");
	
	
	GtkTreeIter iter;
	GtkTreeModel *model=gtk_tree_view_get_model (GTK_TREE_VIEW(treeview));
	gtk_tree_model_get_iter(model,&iter,path);
	gtk_tree_model_get (model,&iter,0,&id,1,&nom,2,&jour,3,&mois,4,&annee,5,&frais,-1);
	printf("%s %s %d %d %d %s",id,nom,jour,mois,annee,frais);
	gtk_entry_set_text(GTK_ENTRY (idn),_(id));
	gtk_entry_set_text(GTK_ENTRY (nomn),_(nom));
        gtk_entry_set_text(GTK_ENTRY (fraisn),_(frais));
	///////////////////////////
	/*gtk_entry_set_text(GTK_ENTRY (journ),_(jour));
	gtk_entry_set_text(GTK_ENTRY (moisn),_(mois));
	gtk_entry_set_text(GTK_ENTRY (anneen),_(annee));*/

	/*gtk_widget_hide(GestionEvent);
	gtk_widget_show(ModifEvent);//

		
/*}///
*/






void
on_button100n_clicked                  (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

}


void
on_button119n_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window2;

     window2=lookup_widget(button,"window2");
     gtk_widget_hide(window2);
}


void
on_button120n_clicked                  (GtkWidget       *button,
                                        gpointer         user_data)
{

 
  GtkWidget *window2;
 GtkWidget *id,*des,*prog,*nbr;


   char idk[20],desk[20],progk[20];
	int nbrk;
window2=lookup_widget(button,"window2");
   

id=lookup_widget(button,"entry122n");
 
des=lookup_widget(button,"entry123n");
prog=lookup_widget(button,"entry124n");


	nbr=lookup_widget(window2,"spinbutton120n");
	
	strcpy(idk,gtk_entry_get_text(GTK_ENTRY(id)));
	strcpy(desk,gtk_entry_get_text(GTK_ENTRY(des)));
        strcpy(progk,gtk_entry_get_text(GTK_ENTRY(prog)));
	nbrk = gtk_spin_button_get_value_as_int(nbr);
	
	modifier1(idk,desk,progk,nbrk);
gtk_widget_hide(window2);




/*
GtkWidget *window1,*window2;
GtkWidget *notebook1;
GtkWidget *treeview1n;
GtkWidget *id,*des,*prog,*nbr;
	char idk[20],desk[20],progk[20];
	int nbrk;
 window1=lookup_widget(objet_graphique,"window1");
 notebook1=lookup_widget(window1,"notebook1");
treeview1n=lookup_widget(notebook1,"treeview1n");
 window2=lookup_widget(objet_graphique,"window2");
	id=lookup_widget(window2,"entry122n");
	des=lookup_widget(window2,"entry123n");
	prog=lookup_widget(window2,"entry123n");
	nbr=lookup_widget(window2,"spinbutton120n");
	
	strcpy(idk,gtk_entry_get_text(GTK_ENTRY(id)));
	strcpy(desk,gtk_entry_get_text(GTK_ENTRY(des)));
        strcpy(progk,gtk_entry_get_text(GTK_ENTRY(prog)));
	nbrk = gtk_spin_button_get_value_as_int(nbr);
	
	modifier1(idk,desk,progk,nbrk);


gtk_window_set_position(GTK_WINDOW(window2),GTK_WIN_POS_CENTER);
gtk_widget_hide(window2);*/

}


void
on_button121n_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{

  GtkWidget *window2;
 GtkWidget *id,*des,*prog,*nbr;


   char idk[20],desk[20],progk[20];
	int nbrk;
window2=lookup_widget(button,"window2");
   

id=lookup_widget(button,"entry122n");
 
des=lookup_widget(button,"entry123n");
prog=lookup_widget(button,"entry124n");


	nbr=lookup_widget(window2,"spinbutton120n");
	
	strcpy(idk,gtk_entry_get_text(GTK_ENTRY(id)));
	strcpy(desk,gtk_entry_get_text(GTK_ENTRY(des)));
        strcpy(progk,gtk_entry_get_text(GTK_ENTRY(prog)));
	nbrk = gtk_spin_button_get_value_as_int(nbr);
	
	supprimer1(idk,desk,progk,nbrk);
gtk_widget_hide(window2);
}

