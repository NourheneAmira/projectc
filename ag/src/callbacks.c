#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "verif.h"
#include "nour.h"
#include "string.h"


void
on_button1_clicked                     (GtkWidget      *objet_graphique,
                                        gpointer         user_data)
{

	GtkWidget *input1;
	GtkWidget *input2;

	users u;

	int r=0;


	input1=lookup_widget(objet_graphique,"entry1");
	input2=lookup_widget(objet_graphique,"entry2");

	strcpy(u.log,gtk_entry_get_text(GTK_ENTRY(input1)));
	strcpy(u.pass,gtk_entry_get_text(GTK_ENTRY(input2)));
	
	r=verif(u);
	
	if (r==1)
	{	GtkWidget *admin;
		GtkWidget *aceuil;
		admin= create_admin ();
		gtk_widget_show (admin);
		aceuil=lookup_widget(objet_graphique,"aceuil");
		gtk_widget_destroy(aceuil);
	}	

	if (r==2)
	{	GtkWidget *aceuil;
		GtkWidget *client;
	 	client= create_client ();
  	        gtk_widget_show (client);
		aceuil=lookup_widget(objet_graphique,"aceuil");
		gtk_widget_destroy(aceuil);
	}

	if (r==3)
	{	
		GtkWidget *aceuil;
		GtkWidget *agent;
	        agent= create_agent();
  	        gtk_widget_show (agent);
		aceuil=lookup_widget(objet_graphique,"aceuil");
		gtk_widget_destroy(aceuil);
	}
}


void
on_button50i_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button1s_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button2s_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button3s_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button4s_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_treeview1rec_row_activated          (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}


void
on_actualiser_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button1ajoutrec_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_treeview1n_row_activated            (GtkWidget     *objet_graphique,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkWidget *modifvol,*agent,*notebook1n;
GtkWidget *treeview1n;
GtkWidget *idn,*depn,*arrn,*prixn,*heuren,*typen,*jn,*mn,*an,*pn;


gchar *id,*dep,*arr,*prix,*heure,*type;
gint *j,*m,*a,*p;

agent=lookup_widget(objet_graphique,"agent");
notebook1n=lookup_widget(agent,"notebook1n");
modifvol=create_modifvol();
treeview1n=lookup_widget(notebook1n,"treeview1n");

idn=lookup_widget(modifvol,"entrykh1");
depn=lookup_widget(modifvol,"entrykh2");
arrn=lookup_widget(modifvol,"entrykh3");
heuren=lookup_widget(modifvol,"entrykh4");
prixn=lookup_widget(modifvol,"entrykh5");
jn=lookup_widget(modifvol,"spinbuttonkh1");
mn=lookup_widget(modifvol,"spinbuttonkh2");
an=lookup_widget(modifvol,"spinbuttonkh3");
pn=lookup_widget(modifvol,"spinbuttonkh4");


typen=lookup_widget(modifvol,"comboboxentrykh1");
GtkTreeIter iter;
	GtkTreeModel *model=gtk_tree_view_get_model (GTK_TREE_VIEW(treeview1n));
	gtk_tree_model_get_iter(model,&iter,path);
	gtk_tree_model_get (model,&iter,0,&id,1,&dep,2,&arr,3,&j,4,&m,5,&a,6,&heure,7,&type,8,&prix,9,&p,-1);
	printf("%s %s %s %d %d %d %s %s %s %d",id,dep,arr,j,m,a,heure,type,prix,p);
	gtk_entry_set_text(GTK_ENTRY (idn),_(id));
	gtk_entry_set_text(GTK_ENTRY (depn),_(dep));
        gtk_entry_set_text(GTK_ENTRY (arrn),_(arr));
	gtk_entry_set_text(GTK_ENTRY (heuren),_(heure));
	gtk_entry_set_text(GTK_ENTRY (typen),_(type));
	gtk_entry_set_text(GTK_ENTRY (prixn),_(prix));
	
gtk_window_set_position(GTK_WINDOW(agent),GTK_WIN_POS_CENTER);
gtk_widget_show(modifvol);
}


void
on_button1n_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *agent;
GtkWidget *notebook1n;
GtkWidget *treeview1n;
agent=lookup_widget(button,"agent");
notebook1n=lookup_widget(agent,"notebook1n");
treeview1n=lookup_widget(notebook1n,"treeview1n");
afficher3(treeview1n);
}


void
on_button2n_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *ajouvol,*agent,*notebook1n;
agent=lookup_widget(objet_graphique,"agent");
notebook1n=lookup_widget(agent,"notebook1n");
ajouvol=create_ajouvol();
gtk_widget_show(ajouvol);
}


void
on_treeview2n_row_activated            (GtkWidget     *objet_graphique,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkWidget *modifhotel,*agent,*notebook1n;
GtkWidget *treeview2n;
GtkWidget *idn,*lieun,*nomn,*prixn,*en,*pn,*chambren;
gchar *id,*lieu,*nom,*prix,*chambre;
gint *e,*p;

agent=lookup_widget(objet_graphique,"agent");
notebook1n=lookup_widget(agent,"notebook1n");
modifhotel=create_modifhotel();
treeview2n=lookup_widget(notebook1n,"treeview2n");

idn=lookup_widget(modifhotel,"entry100n");
lieun=lookup_widget(modifhotel,"entry200n");
nomn=lookup_widget(modifhotel,"entry300n");
prixn=lookup_widget(modifhotel,"entry400n");
en=lookup_widget(modifhotel,"spinbutton100n");
pn=lookup_widget(modifhotel,"spinbutton200n");

chambren=lookup_widget(modifhotel,"comboboxentry100n");
GtkTreeIter iter;
	GtkTreeModel *model=gtk_tree_view_get_model (GTK_TREE_VIEW(treeview2n));
	gtk_tree_model_get_iter(model,&iter,path);
	gtk_tree_model_get (model,&iter,0,&id,1,&lieu,2,&nom,3,&e,4,&chambre,5,&prix,6,&p,-1);
	printf("%s %s %s %d %s %s %d",id,lieu,nom,e,chambre,prix,p);
	gtk_entry_set_text(GTK_ENTRY (idn),_(id));
	gtk_entry_set_text(GTK_ENTRY (lieun),_(lieu));
        gtk_entry_set_text(GTK_ENTRY (nomn),_(nom));
	gtk_entry_set_text(GTK_ENTRY (chambren),_(chambre));
	gtk_entry_set_text(GTK_ENTRY (prixn),_(prix));
	
gtk_window_set_position(GTK_WINDOW(agent),GTK_WIN_POS_CENTER);
gtk_widget_show(modifhotel);
}


void
on_button3n_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *agent;
GtkWidget *notebook1n;
GtkWidget *treeview2n;
 agent=lookup_widget(button,"agent");
 notebook1n=lookup_widget(agent,"notebook1n");
 treeview2n=lookup_widget(notebook1n,"treeview2n");
afficher2(treeview2n);
}


void
on_button4n_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *ajouhotel,*agent,*notebook1n;
agent=lookup_widget(objet_graphique,"agent");
notebook1n=lookup_widget(agent,"notebook1n");
ajouhotel=create_ajouhotel();
gtk_widget_show(ajouhotel);
}


void
on_treeview3n_row_activated           (GtkWidget     *objet_graphique,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkWidget *modifexcu,*agent,*notebook1n;
GtkWidget *treeview3n;
GtkWidget *idn,*desn,*progn,*prixn,*jn,*mn,*an,*pn;
gchar *id,*des,*prog,*prix;
gint *j,*m,*a,*pp;
agent=lookup_widget(objet_graphique,"agent");
notebook1n=lookup_widget(agent,"notebook1n");
modifexcu=create_modifexcu();
treeview3n=lookup_widget(notebook1n,"treeview3n");
idn=lookup_widget(modifexcu,"entry5n");
desn=lookup_widget(modifexcu,"entry6n");
progn=lookup_widget(modifexcu,"entry7n");
prixn=lookup_widget(modifexcu,"entry8n");
jn=lookup_widget(modifexcu,"spinbutton5n");
mn=lookup_widget(modifexcu,"spinbutton6n");
an=lookup_widget(modifexcu,"spinbutton7n");
pn=lookup_widget(modifexcu,"spinbutton8n");
GtkTreeIter iter;
	GtkTreeModel *model=gtk_tree_view_get_model (GTK_TREE_VIEW(treeview3n));
	gtk_tree_model_get_iter(model,&iter,path);
	gtk_tree_model_get (model,&iter,0,&id,1,&des,2,&j,3,&m,4,&a,5,&prog,6,&prix,7,&pp,-1);
	printf("%s %s %d %d %d %s %s %d",id,des,j,m,a,prog,prix,pp);
	gtk_entry_set_text(GTK_ENTRY (idn),_(id));
	gtk_entry_set_text(GTK_ENTRY (desn),_(des));
        gtk_entry_set_text(GTK_ENTRY (progn),_(prog));
	gtk_entry_set_text(GTK_ENTRY (prixn),_(prix));
	
gtk_window_set_position(GTK_WINDOW(agent),GTK_WIN_POS_CENTER);
gtk_widget_show(modifexcu);
}

void
on_button5n_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *agent;
GtkWidget *notebook1n;
GtkWidget *treeview3n;
 agent=lookup_widget(button,"agent");
 notebook1n=lookup_widget(agent,"notebook1n");
 treeview3n=lookup_widget(notebook1n,"treeview3n");
afficher1(treeview3n);
}


void
on_button6n_clicked                   (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *ajouexcu,*agent,*notebook1n;
agent=lookup_widget(objet_graphique,"agent");
notebook1n=lookup_widget(agent,"notebook1n");
ajouexcu=create_ajouexcu();
gtk_widget_show(ajouexcu);
}



void
on_button8n_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *ajouexcu;

     ajouexcu=lookup_widget(button,"ajouexcu");
     gtk_widget_hide(ajouexcu);
}


void
on_button7n_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
excursion p;
GtkWidget *input1;
GtkWidget *input2;
GtkWidget *input3;
GtkWidget *input4;
GtkWidget *ajouexcu,*agent;
GtkWidget *nj,*nm,*na,*np;

input1= lookup_widget(objet_graphique,"entry1n");
input2= lookup_widget(objet_graphique,"entry2n");
input3= lookup_widget(objet_graphique,"entry3n");
input4= lookup_widget(objet_graphique,"entry4n");
ajouexcu= lookup_widget(objet_graphique,"ajouexcu");
agent= lookup_widget(objet_graphique,"agent");


nj=lookup_widget(objet_graphique,"spinbutton1n");
nm=lookup_widget(objet_graphique,"spinbutton2n");
na=lookup_widget(objet_graphique,"spinbutton3n");
np=lookup_widget(objet_graphique,"spinbutton4n");


p.j=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(nj));
p.m=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(nm));
p.a=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(na));
p.p=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(np));


strcpy(p.id,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(p.des,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(p.prog,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(p.prix,gtk_entry_get_text(GTK_ENTRY(input4)));
ajouter1(p);
gtk_widget_hide(ajouexcu);
}



void
on_button11n_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *modifexcu;
 GtkWidget *id,*des,*prog,*prix,*j,*m,*a,*pl;

excursion p;
  /* char idk[20],desk[20],progk[20],prixk[20];
	int jk,mk,ak,pk;*/
modifexcu=lookup_widget(button,"modifexcu");
   

id=lookup_widget(button,"entry5n");
 
des=lookup_widget(button,"entry6n");
prog=lookup_widget(button,"entry7n");
prix=lookup_widget(button,"entry8n");


j=lookup_widget(modifexcu,"spinbutton5n");
m=lookup_widget(modifexcu,"spinbutton6n");
a=lookup_widget(modifexcu,"spinbutton7n");
pl=lookup_widget(modifexcu,"spinbutton8n");
	
	strcpy(p.id,gtk_entry_get_text(GTK_ENTRY(id)));
	strcpy(p.des,gtk_entry_get_text(GTK_ENTRY(des)));
        strcpy(p.prog,gtk_entry_get_text(GTK_ENTRY(prog)));
	 strcpy(p.prix,gtk_entry_get_text(GTK_ENTRY(prix)));
	p.j = gtk_spin_button_get_value_as_int(j);
        p.m = gtk_spin_button_get_value_as_int(m); 
	p.a = gtk_spin_button_get_value_as_int(a);
       p.p= gtk_spin_button_get_value_as_int(pl);	
	supprimer1(p);
gtk_widget_hide(modifexcu);
}


void
on_button10n_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *modifexcu;
 GtkWidget *id,*des,*prog,*prix,*j,*m,*a,*pl;
excursion p;
/*
   char idk[20],desk[20],progk[20],prixk[20];
	int jk,mk,ak,pk;*/
modifexcu=lookup_widget(button,"modifexcu");
   

id=lookup_widget(button,"entry5n");
 
des=lookup_widget(button,"entry6n");
prog=lookup_widget(button,"entry7n");
prix=lookup_widget(button,"entry8n");


j=lookup_widget(modifexcu,"spinbutton5n");
m=lookup_widget(modifexcu,"spinbutton6n");
a=lookup_widget(modifexcu,"spinbutton7n");
pl=lookup_widget(modifexcu,"spinbutton8n");
	
	strcpy(p.id,gtk_entry_get_text(GTK_ENTRY(id)));
	strcpy(p.des,gtk_entry_get_text(GTK_ENTRY(des)));
        strcpy(p.prog,gtk_entry_get_text(GTK_ENTRY(prog)));
	 strcpy(p.prix,gtk_entry_get_text(GTK_ENTRY(prix)));
	p.j = gtk_spin_button_get_value_as_int(j);
        p.m = gtk_spin_button_get_value_as_int(m); 
	p.a = gtk_spin_button_get_value_as_int(a);
       p.p = gtk_spin_button_get_value_as_int(pl);	
	modifier1(p);
gtk_widget_hide(modifexcu);
}


void
on_button9n_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *modifexcu;

     modifexcu=lookup_widget(button,"modifexcu");
     gtk_widget_hide(modifexcu);
}


void
on_button13nn_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *ajouhotel;

     ajouhotel=lookup_widget(button,"ajouhotel");
     gtk_widget_hide(ajouhotel);
}


void
on_button12nn_clicked                  (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
hotel h;

GtkWidget *input1;
GtkWidget *input2;
GtkWidget *input3;
GtkWidget *input4;
GtkWidget *ajouhotel,*agent;
GtkWidget *ne,*np,*CHAMBRE;

input1= lookup_widget(objet_graphique,"entry1nn");
input2= lookup_widget(objet_graphique,"entry2nn");
input3= lookup_widget(objet_graphique,"entry3nn");
input4= lookup_widget(objet_graphique,"entry4nn");
ajouhotel= lookup_widget(objet_graphique,"ajouhotel");
agent= lookup_widget(objet_graphique,"agent");

CHAMBRE=lookup_widget(objet_graphique,"comboboxentry1nn");
ne=lookup_widget(objet_graphique,"spinbutton1nn");
np=lookup_widget(objet_graphique,"spinbutton2nn");



h.e=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(ne));
h.p=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(np));



strcpy(h.id,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(h.lieu,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(h.nom,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(h.prix,gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy(h.chambre,gtk_combo_box_get_active_text (GTK_COMBO_BOX(CHAMBRE)));
ajouter2(h);
gtk_widget_hide(ajouhotel);
}


void
on_button102n_clicked                  (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *modifhotel;
GtkWidget *id,*lieu,*nom,*e,*chambre,*prix,*p;

hotel h;
  /* char idk[20],lieuk[20],chambrek[20],prixk[20],nomk[20];
	int ek,pk;*/
modifhotel=lookup_widget(objet_graphique,"modifhotel");
   

id=lookup_widget(objet_graphique,"entry100n");
 
lieu=lookup_widget(objet_graphique,"entry200n");
nom=lookup_widget(objet_graphique,"entry300n");
prix=lookup_widget(objet_graphique,"entry400n");


e=lookup_widget(modifhotel,"spinbutton100n");
p=lookup_widget(modifhotel,"spinbutton200n");

	chambre=lookup_widget(modifhotel,"comboboxentry100n");
	strcpy(h.id,gtk_entry_get_text(GTK_ENTRY(id)));
	strcpy(h.lieu,gtk_entry_get_text(GTK_ENTRY(lieu)));
        strcpy(h.nom,gtk_entry_get_text(GTK_ENTRY(nom)));
	 strcpy(h.prix,gtk_entry_get_text(GTK_ENTRY(prix)));
	strcpy(h.chambre,gtk_combo_box_get_active_text(GTK_COMBO_BOX(chambre)));
	h.e = gtk_spin_button_get_value_as_int(e);

        h.p = gtk_spin_button_get_value_as_int(p); 
		
	supprimer2(h);
gtk_widget_hide(modifhotel);
}

void
on_button100n_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *modifhotel;

     modifhotel=lookup_widget(button,"modifhotel");
     gtk_widget_hide(modifhotel);
}


void
on_button101n_clicked                  (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *modifhotel;
 GtkWidget *id,*lieu,*nom,*e,*chambre,*prix,*p;

hotel h;
   /*char idk[20],lieuk[20],chambrek[20],prixk[20],nomk[20];
	int ek,pk;*/
modifhotel=lookup_widget(objet_graphique,"modifhotel");
   

id=lookup_widget(objet_graphique,"entry100n");
 
lieu=lookup_widget(objet_graphique,"entry200n");
nom=lookup_widget(objet_graphique,"entry300n");
prix=lookup_widget(objet_graphique,"entry400n");


e=lookup_widget(modifhotel,"spinbutton100n");
p=lookup_widget(modifhotel,"spinbutton200n");

	chambre=lookup_widget(modifhotel,"comboboxentry100n");
	strcpy(h.id,gtk_entry_get_text(GTK_ENTRY(id)));
	strcpy(h.lieu,gtk_entry_get_text(GTK_ENTRY(lieu)));
        strcpy(h.nom,gtk_entry_get_text(GTK_ENTRY(nom)));
	 strcpy(h.prix,gtk_entry_get_text(GTK_ENTRY(prix)));
	strcpy(h.chambre,gtk_combo_box_get_active_text(GTK_COMBO_BOX(chambre)));
	h.e = gtk_spin_button_get_value_as_int(e);

        h.p = gtk_spin_button_get_value_as_int(p); 
		
	modifier2(h);
gtk_widget_hide(modifhotel);
}


void
on_button01n_clicked                   (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
vol v;
GtkWidget *input1;
GtkWidget *input2;
GtkWidget *input3;
GtkWidget *input4;
GtkWidget *input5;
GtkWidget *ajouvol,*agent;
GtkWidget *nj,*nm,*na,*np,*TYPE;

input1= lookup_widget(objet_graphique,"entry01n");
input2= lookup_widget(objet_graphique,"entry02n");
input3= lookup_widget(objet_graphique,"entry03n");
input4= lookup_widget(objet_graphique,"entry04n");
input5= lookup_widget(objet_graphique,"entry05n");
ajouvol= lookup_widget(objet_graphique,"ajouvol");
agent= lookup_widget(objet_graphique,"agent");

TYPE=lookup_widget(objet_graphique,"comboboxentry01n");
nj=lookup_widget(objet_graphique,"spinbutton01n");
nm=lookup_widget(objet_graphique,"spinbutton02n");
na=lookup_widget(objet_graphique,"spinbutton03n");
np=lookup_widget(objet_graphique,"spinbutton04n");



v.jv=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(nj));
v.mv=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(nm));
v.av=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(na));
v.pl=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(np));



strcpy(v.id,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(v.dep,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(v.arr,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(v.heure,gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy(v.prixv,gtk_entry_get_text(GTK_ENTRY(input5)));
strcpy(v.type,gtk_combo_box_get_active_text (GTK_COMBO_BOX(TYPE)));
ajouter3(v);
gtk_widget_hide(ajouvol);
}

void
on_buttonkh3_clicked                   (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *modifvol;
GtkWidget *id,*dep,*arr,*j,*m,*a,*heure,*type,*prix,*p;


   vol v;
modifvol=lookup_widget(objet_graphique,"modifvol");
   

id=lookup_widget(objet_graphique,"entrykh1");
 
dep=lookup_widget(objet_graphique,"entrykh2");
arr=lookup_widget(objet_graphique,"entrykh3");
heure=lookup_widget(objet_graphique,"entrykh4");
prix=lookup_widget(objet_graphique,"entrykh5");


j=lookup_widget(modifvol,"spinbuttonkh1");
m=lookup_widget(modifvol,"spinbuttonkh2");
a=lookup_widget(modifvol,"spinbuttonkh3");
p=lookup_widget(modifvol,"spinbuttonkh4");

	type=lookup_widget(modifvol,"comboboxentrykh1");
	strcpy(v.id,gtk_entry_get_text(GTK_ENTRY(id)));
	strcpy(v.dep,gtk_entry_get_text(GTK_ENTRY(dep)));
        strcpy(v.arr,gtk_entry_get_text(GTK_ENTRY(arr)));
	strcpy(v.heure,gtk_entry_get_text(GTK_ENTRY(heure)));
	 strcpy(v.prixv,gtk_entry_get_text(GTK_ENTRY(prix)));
	strcpy(v.type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(type)));
	v.jv = gtk_spin_button_get_value_as_int(j);
	v.mv = gtk_spin_button_get_value_as_int(m);
	v.av = gtk_spin_button_get_value_as_int(a);
        v.pl = gtk_spin_button_get_value_as_int(p); 
		
	supprimer3(v);
gtk_widget_hide(modifvol);
}


void
on_buttonkh2_clicked                   (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *modifvol;
GtkWidget *id,*dep,*arr,*j,*m,*a,*heure,*type,*prix,*p;


   vol v;
modifvol=lookup_widget(objet_graphique,"modifvol");
   

id=lookup_widget(objet_graphique,"entrykh1");
 
dep=lookup_widget(objet_graphique,"entrykh2");
arr=lookup_widget(objet_graphique,"entrykh3");
heure=lookup_widget(objet_graphique,"entrykh4");
prix=lookup_widget(objet_graphique,"entrykh5");


j=lookup_widget(modifvol,"spinbuttonkh1");
m=lookup_widget(modifvol,"spinbuttonkh2");
a=lookup_widget(modifvol,"spinbuttonkh3");
p=lookup_widget(modifvol,"spinbuttonkh4");

	type=lookup_widget(modifvol,"comboboxentrykh1");
	strcpy(v.id,gtk_entry_get_text(GTK_ENTRY(id)));
	strcpy(v.dep,gtk_entry_get_text(GTK_ENTRY(dep)));
        strcpy(v.arr,gtk_entry_get_text(GTK_ENTRY(arr)));
	strcpy(v.heure,gtk_entry_get_text(GTK_ENTRY(heure)));
	 strcpy(v.prixv,gtk_entry_get_text(GTK_ENTRY(prix)));
	strcpy(v.type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(type)));
	v.jv = gtk_spin_button_get_value_as_int(j);
	v.mv = gtk_spin_button_get_value_as_int(m);
	v.av = gtk_spin_button_get_value_as_int(a);
        v.pl = gtk_spin_button_get_value_as_int(p); 
		
	modifier3(v);
gtk_widget_hide(modifvol);
}


void
on_buttonkh1_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *modifvol;

     modifvol=lookup_widget(button,"modifvol");
     gtk_widget_hide(modifvol);
}

