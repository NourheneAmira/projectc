#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "verif.h"
#include "nour.h"
#include "admin.h"
#include "string.h"
#include "recla.h"
#include "hhhh.h"


void
on_button1_clicked                     (GtkWidget      *objet_graphique,
                                        gpointer         user_data)
{

	GtkWidget *input1;
	GtkWidget *input2;
        GtkWidget *label104n;

	users u;

	int r=0;


	input1=lookup_widget(objet_graphique,"entry1");
	input2=lookup_widget(objet_graphique,"entry2");
        label104n=lookup_widget(objet_graphique,"label104n");

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

	else if (r==2)
	{	GtkWidget *aceuil;
		GtkWidget *client;
	 	client= create_client ();
  	        gtk_widget_show (client);
		aceuil=lookup_widget(objet_graphique,"aceuil");
		gtk_widget_destroy(aceuil);
	      FILE* f =fopen("util.txt","w");
               fprintf(f,"%s\n",u.log);
              fclose(f);

	}

	 else if (r==3)
	{	
		GtkWidget *aceuil;
		GtkWidget *agent;
	        agent= create_agent();
  	        gtk_widget_show (agent);
		aceuil=lookup_widget(objet_graphique,"aceuil");
		gtk_widget_destroy(aceuil);
	}
else 
{gtk_label_set_text(GTK_LABEL(label104n),"authentification non validée");}
}


void
on_button50i_clicked                   (GtkWidget      *objet_graphique,
                                        gpointer         user_data)
{
compt c;

GtkWidget *input1;
GtkWidget *input2;
GtkWidget *input3;
GtkWidget *input4;
GtkWidget *input5;
GtkWidget *input6;
GtkWidget *input7,*notebook3;
GtkWidget *input8,*output1402,*output1412,*output1422;
GtkWidget *aceuil,*client;
GtkWidget *na;
input1= lookup_widget(objet_graphique,"entry67i");
input2= lookup_widget(objet_graphique,"entry68i");
input3= lookup_widget(objet_graphique,"entry70i");
input4= lookup_widget(objet_graphique,"entry69i");
input5= lookup_widget(objet_graphique,"entry71i");
input6= lookup_widget(objet_graphique,"entry72i");
input7= lookup_widget(objet_graphique,"entry73i");
input8= lookup_widget(objet_graphique,"entry74i");
output1402=lookup_widget(objet_graphique,"label100i");
output1412=lookup_widget(objet_graphique,"label101i");
output1422=lookup_widget(objet_graphique,"label102i");
aceuil=lookup_widget(objet_graphique,"aceuil");


na=lookup_widget(objet_graphique,"spinbutton30i");
c.age=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(na));
strcpy(c.login,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(c.password,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(c.nom,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(c.prenom,gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy(c.cin,gtk_entry_get_text(GTK_ENTRY(input5)));
strcpy(c.tel,gtk_entry_get_text(GTK_ENTRY(input6)));
strcpy(c.ad,gtk_entry_get_text(GTK_ENTRY(input7)));
strcpy(c.mail,gtk_entry_get_text(GTK_ENTRY(input8)));
if(verifidi(c.login)==0)
{ 

gtk_label_set_text(GTK_LABEL(output1402)," X ");}
else
{gtk_label_set_text(GTK_LABEL(output1402)," √ ");}
//login pass
if(verifentryi(c.password)==0)
{ gtk_label_set_text(GTK_LABEL(output1412)," X ");}
else
{gtk_label_set_text(GTK_LABEL(output1412)," √ ");}
//
if((verifidi(c.login)==1) && (verifentryi(c.password)==1))
     {   

ajouteri11(c);



ajouteri12(c);
client= create_client ();
gtk_widget_show (client);
gtk_widget_destroy(aceuil);
}
else
{ gtk_label_set_text(GTK_LABEL(output1422),"veuillez verifiez vos information svp!");}
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
on_actualiser_clicked                 (GtkWidget      *objet,
                                        gpointer         user_data)
{
GtkWidget *client;
GtkWidget *notebook3;
GtkWidget *treeview1rec ;
client=lookup_widget(objet,"client");
notebook3=lookup_widget(client,"notebook3");
treeview1rec=lookup_widget(notebook3,"treeview1rec") ;

afficher_reccli(treeview1rec);

}


void
on_button1ajoutrec_clicked             (GtkWidget      *objet_graphique,
                                        gpointer         user_data)
{char login[50],txt[500];
int n;
rec tab[100];


GtkWidget *input2,*client;

input2=lookup_widget(objet_graphique,"entry1txtrec");
client= lookup_widget(objet_graphique,"client");

strcpy(txt,gtk_entry_get_text(GTK_ENTRY(input2)));
FILE* k=fopen("util.txt","r");
                  fscanf(k,"%s",login);
                fclose(k);
n= calculenbrefich();
 lirefichrec(tab);

ajoutrec(tab,n,login,txt);
ecrirerecfich( tab , n);

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


gchar *id,*dep,*arr,*heure,*type;
gint *j,*m,*a,*p,*prix;

agent=lookup_widget(objet_graphique,"agent");
notebook1n=lookup_widget(agent,"notebook1n");
modifvol=create_modifvol();
treeview1n=lookup_widget(notebook1n,"treeview1n");

idn=lookup_widget(modifvol,"entrykh1");
depn=lookup_widget(modifvol,"entrykh2");
arrn=lookup_widget(modifvol,"entrykh3");
heuren=lookup_widget(modifvol,"entrykh4");

jn=lookup_widget(modifvol,"spinbuttonkh1");
mn=lookup_widget(modifvol,"spinbuttonkh2");
an=lookup_widget(modifvol,"spinbuttonkh3");
prixn=lookup_widget(modifvol,"spinbuttonkh3");
pn=lookup_widget(modifvol,"spinbuttonkh4");


typen=lookup_widget(modifvol,"comboboxentrykh1");
GtkTreeIter iter;
	GtkTreeModel *model=gtk_tree_view_get_model (GTK_TREE_VIEW(treeview1n));
	gtk_tree_model_get_iter(model,&iter,path);
	gtk_tree_model_get (model,&iter,0,&id,1,&dep,2,&arr,3,&j,4,&m,5,&a,6,&heure,7,&type,8,&prix,9,&p,-1);
	printf("%s %s %s %d %d %d %s %s %d %d",id,dep,arr,j,m,a,heure,type,prix,p);
	gtk_entry_set_text(GTK_ENTRY (idn),_(id));
	gtk_entry_set_text(GTK_ENTRY (depn),_(dep));
        gtk_entry_set_text(GTK_ENTRY (arrn),_(arr));
	gtk_entry_set_text(GTK_ENTRY (heuren),_(heure));
	gtk_entry_set_text(GTK_ENTRY (typen),_(type));
	
	
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
GtkWidget *idn,*lieun,*nomn,*prixhn,*en,*pn,*chambren;
gchar *id,*lieu,*nom,*chambre;
gint *e,*p,*prixh;

agent=lookup_widget(objet_graphique,"agent");
notebook1n=lookup_widget(agent,"notebook1n");
modifhotel=create_modifhotel();
treeview2n=lookup_widget(notebook1n,"treeview2n");

idn=lookup_widget(modifhotel,"entry100n");
lieun=lookup_widget(modifhotel,"entry200n");
nomn=lookup_widget(modifhotel,"entry300n");

en=lookup_widget(modifhotel,"spinbutton100n");
prixhn=lookup_widget(modifhotel,"spinbuttonkhn4");
pn=lookup_widget(modifhotel,"spinbutton200n");

chambren=lookup_widget(modifhotel,"comboboxentry100n");
GtkTreeIter iter;
	GtkTreeModel *model=gtk_tree_view_get_model (GTK_TREE_VIEW(treeview2n));
	gtk_tree_model_get_iter(model,&iter,path);
	gtk_tree_model_get (model,&iter,0,&id,1,&lieu,2,&nom,3,&e,4,&chambre,5,&prixh,6,&p,-1);
	printf("%s %s %s %d %s %d %d",id,lieu,nom,e,chambre,prixh,p);
	gtk_entry_set_text(GTK_ENTRY (idn),_(id));
	gtk_entry_set_text(GTK_ENTRY (lieun),_(lieu));
        gtk_entry_set_text(GTK_ENTRY (nomn),_(nom));
	gtk_entry_set_text(GTK_ENTRY (chambren),_(chambre));
	
	
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
gchar *id,*des,*prog;
gint *j,*m,*a,*pp,*prix;
agent=lookup_widget(objet_graphique,"agent");
notebook1n=lookup_widget(agent,"notebook1n");
modifexcu=create_modifexcu();
treeview3n=lookup_widget(notebook1n,"treeview3n");
idn=lookup_widget(modifexcu,"entry5n");
desn=lookup_widget(modifexcu,"entry6n");
progn=lookup_widget(modifexcu,"entry7n");

jn=lookup_widget(modifexcu,"spinbutton5n");
mn=lookup_widget(modifexcu,"spinbutton6n");
an=lookup_widget(modifexcu,"spinbutton7n");
prixn=lookup_widget(modifexcu,"spinbuttonkn2");
pn=lookup_widget(modifexcu,"spinbutton8n");
GtkTreeIter iter;
	GtkTreeModel *model=gtk_tree_view_get_model (GTK_TREE_VIEW(treeview3n));
	gtk_tree_model_get_iter(model,&iter,path);
	gtk_tree_model_get (model,&iter,0,&id,1,&des,2,&j,3,&m,4,&a,5,&prog,6,&prix,7,&pp,-1);
	printf("%s %s %d %d %d %s %d %d",id,des,j,m,a,prog,prix,pp);
	gtk_entry_set_text(GTK_ENTRY (idn),_(id));
	gtk_entry_set_text(GTK_ENTRY (desn),_(des));
        gtk_entry_set_text(GTK_ENTRY (progn),_(prog));
	
	
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
GtkWidget *output10,*output11,*output12;
GtkWidget *ajouexcu,*agent;
GtkWidget *nj,*nm,*na,*np,*nprix;

input1= lookup_widget(objet_graphique,"entry1n");
input2= lookup_widget(objet_graphique,"entry2n");
input3= lookup_widget(objet_graphique,"entry3n");

output10=lookup_widget(objet_graphique,"label0001n");
output11=lookup_widget(objet_graphique,"label0002n");
output12=lookup_widget(objet_graphique,"label0003n");
ajouexcu= lookup_widget(objet_graphique,"ajouexcu");
agent= lookup_widget(objet_graphique,"agent");


nj=lookup_widget(objet_graphique,"spinbutton1n");
nm=lookup_widget(objet_graphique,"spinbutton2n");
na=lookup_widget(objet_graphique,"spinbutton3n");
nprix=lookup_widget(objet_graphique,"spinbuttonkn1");
np=lookup_widget(objet_graphique,"spinbutton4n");


p.j=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(nj));
p.m=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(nm));
p.a=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(na));
p.prix=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(nprix));
p.p=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(np));


strcpy(p.id,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(p.des,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(p.prog,gtk_entry_get_text(GTK_ENTRY(input3)));


if(verifid(p.id)==0)
{ 

gtk_label_set_text(GTK_LABEL(output10)," X ");}
else
{gtk_label_set_text(GTK_LABEL(output10)," √ ");}
//login pass
if(verifentry(p.des)==0)
{ gtk_label_set_text(GTK_LABEL(output11)," X ");}
else
{gtk_label_set_text(GTK_LABEL(output11)," √ ");}
//
if((verifid(p.id)==1) && (verifentry(p.des)==1))
     {   
ajouter1(p);
gtk_widget_hide(ajouexcu);}
else
{ gtk_label_set_text(GTK_LABEL(output12),"veuillez verifiez vos information svp!");}

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



j=lookup_widget(modifexcu,"spinbutton5n");
m=lookup_widget(modifexcu,"spinbutton6n");
a=lookup_widget(modifexcu,"spinbutton7n");
prix=lookup_widget(modifexcu,"spinbuttonkn2");
pl=lookup_widget(modifexcu,"spinbutton8n");
	
	strcpy(p.id,gtk_entry_get_text(GTK_ENTRY(id)));
	strcpy(p.des,gtk_entry_get_text(GTK_ENTRY(des)));
        strcpy(p.prog,gtk_entry_get_text(GTK_ENTRY(prog)));
	
	p.j = gtk_spin_button_get_value_as_int(j);
        p.m = gtk_spin_button_get_value_as_int(m); 
	p.a = gtk_spin_button_get_value_as_int(a);
       p.prix= gtk_spin_button_get_value_as_int(prix);
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



j=lookup_widget(modifexcu,"spinbutton5n");
m=lookup_widget(modifexcu,"spinbutton6n");
a=lookup_widget(modifexcu,"spinbutton7n");
prix=lookup_widget(modifexcu,"spinbuttonkn2");
pl=lookup_widget(modifexcu,"spinbutton8n");
	
	strcpy(p.id,gtk_entry_get_text(GTK_ENTRY(id)));
	strcpy(p.des,gtk_entry_get_text(GTK_ENTRY(des)));
        strcpy(p.prog,gtk_entry_get_text(GTK_ENTRY(prog)));
	
	p.j = gtk_spin_button_get_value_as_int(j);
        p.m = gtk_spin_button_get_value_as_int(m); 
	p.a = gtk_spin_button_get_value_as_int(a);
	p.prix = gtk_spin_button_get_value_as_int(prix);
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
GtkWidget *output20,*output21,*output22;
GtkWidget *ajouhotel,*agent;
GtkWidget *ne,*np,*CHAMBRE,*nprixh;

input1= lookup_widget(objet_graphique,"entry1nn");
input2= lookup_widget(objet_graphique,"entry2nn");
input3= lookup_widget(objet_graphique,"entry3nn");

output20=lookup_widget(objet_graphique,"label001n");
output21=lookup_widget(objet_graphique,"label002n");
output22=lookup_widget(objet_graphique,"label003n");

ajouhotel= lookup_widget(objet_graphique,"ajouhotel");
agent= lookup_widget(objet_graphique,"agent");

CHAMBRE=lookup_widget(objet_graphique,"comboboxentry1nn");
ne=lookup_widget(objet_graphique,"spinbutton1nn");
nprixh=lookup_widget(objet_graphique,"spinbuttonkhn3");
np=lookup_widget(objet_graphique,"spinbutton2nn");



h.e=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(ne));
h.prixh=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(nprixh));
h.p=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(np));



strcpy(h.id,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(h.lieu,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(h.nom,gtk_entry_get_text(GTK_ENTRY(input3)));

strcpy(h.chambre,gtk_combo_box_get_active_text (GTK_COMBO_BOX(CHAMBRE)));

if(verifid(h.id)==0)
{ 

gtk_label_set_text(GTK_LABEL(output20)," X ");}
else
{gtk_label_set_text(GTK_LABEL(output20)," √ ");}
//login pass
if(verifentry(h.lieu)==0)
{ gtk_label_set_text(GTK_LABEL(output21)," X ");}
else
{gtk_label_set_text(GTK_LABEL(output21)," √ ");}
//
if((verifid(h.id)==1) && (verifentry(h.lieu)==1))
     {   
ajouter2(h);
gtk_widget_hide(ajouhotel);}
else
{ gtk_label_set_text(GTK_LABEL(output22),"veuillez verifiez vos information svp!");}
}


void
on_button102n_clicked                  (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *modifhotel;
GtkWidget *id,*lieu,*nom,*e,*chambre,*prixh,*p;

hotel h;
  /* char idk[20],lieuk[20],chambrek[20],prixk[20],nomk[20];
	int ek,pk;*/
modifhotel=lookup_widget(objet_graphique,"modifhotel");
   

id=lookup_widget(objet_graphique,"entry100n");
 
lieu=lookup_widget(objet_graphique,"entry200n");
nom=lookup_widget(objet_graphique,"entry300n");


e=lookup_widget(modifhotel,"spinbutton100n");
prixh=lookup_widget(modifhotel,"spinbuttonkhn4");
p=lookup_widget(modifhotel,"spinbutton200n");

	chambre=lookup_widget(modifhotel,"comboboxentry100n");
	strcpy(h.id,gtk_entry_get_text(GTK_ENTRY(id)));
	strcpy(h.lieu,gtk_entry_get_text(GTK_ENTRY(lieu)));
        strcpy(h.nom,gtk_entry_get_text(GTK_ENTRY(nom)));
	
	strcpy(h.chambre,gtk_combo_box_get_active_text(GTK_COMBO_BOX(chambre)));
	h.e = gtk_spin_button_get_value_as_int(e);
	h.prixh = gtk_spin_button_get_value_as_int(prixh);
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
 GtkWidget *id,*lieu,*nom,*e,*chambre,*prixh,*p;

hotel h;
   /*char idk[20],lieuk[20],chambrek[20],prixk[20],nomk[20];
	int ek,pk;*/
modifhotel=lookup_widget(objet_graphique,"modifhotel");
   

id=lookup_widget(objet_graphique,"entry100n");
 
lieu=lookup_widget(objet_graphique,"entry200n");
nom=lookup_widget(objet_graphique,"entry300n");



e=lookup_widget(modifhotel,"spinbutton100n");
prixh=lookup_widget(modifhotel,"spinbuttonkhn4");
p=lookup_widget(modifhotel,"spinbutton200n");

	chambre=lookup_widget(modifhotel,"comboboxentry100n");
	strcpy(h.id,gtk_entry_get_text(GTK_ENTRY(id)));
	strcpy(h.lieu,gtk_entry_get_text(GTK_ENTRY(lieu)));
        strcpy(h.nom,gtk_entry_get_text(GTK_ENTRY(nom)));
	 
	strcpy(h.chambre,gtk_combo_box_get_active_text(GTK_COMBO_BOX(chambre)));
	h.e = gtk_spin_button_get_value_as_int(e);
	h.prixh = gtk_spin_button_get_value_as_int(prixh);
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

GtkWidget *output200;
GtkWidget *output201;
GtkWidget *output202;
GtkWidget *ajouvol,*agent;
GtkWidget *nj,*nm,*na,*np,*nprixv,*TYPE;
output200=lookup_widget(objet_graphique,"label01n");
output201=lookup_widget(objet_graphique,"label02n");
output202=lookup_widget(objet_graphique,"label03n");

input1= lookup_widget(objet_graphique,"entry01n");
input2= lookup_widget(objet_graphique,"entry02n");
input3= lookup_widget(objet_graphique,"entry03n");
input4= lookup_widget(objet_graphique,"entry04n");

ajouvol= lookup_widget(objet_graphique,"ajouvol");
agent= lookup_widget(objet_graphique,"agent");

TYPE=lookup_widget(objet_graphique,"comboboxentry01n");
nj=lookup_widget(objet_graphique,"spinbutton01n");
nm=lookup_widget(objet_graphique,"spinbutton02n");
na=lookup_widget(objet_graphique,"spinbutton03n");
np=lookup_widget(objet_graphique,"spinbutton04n");
nprixv=lookup_widget(objet_graphique,"spinbuttonkhn1");


v.jv=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(nj));
v.mv=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(nm));
v.av=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(na));
v.prixv=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(nprixv));
v.pl=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(np));



strcpy(v.id,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(v.dep,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(v.arr,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(v.heure,gtk_entry_get_text(GTK_ENTRY(input4)));

strcpy(v.type,gtk_combo_box_get_active_text (GTK_COMBO_BOX(TYPE)));

/////////////////controle de saisie///////////
if(verifid(v.id)==0)
{ 

gtk_label_set_text(GTK_LABEL(output200)," X ");}
else
{gtk_label_set_text(GTK_LABEL(output200)," √ ");}
//login pass
if(verifentry(v.dep)==0)
{ gtk_label_set_text(GTK_LABEL(output201)," X ");}
else
{gtk_label_set_text(GTK_LABEL(output201)," √ ");}
//
if((verifid(v.id)==1) && (verifentry(v.dep)==1))
     {   
ajouter3(v);
gtk_widget_hide(ajouvol);}
else
{ gtk_label_set_text(GTK_LABEL(output202),"veuillez verifiez vos information svp!");}
    
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



j=lookup_widget(modifvol,"spinbuttonkh1");
m=lookup_widget(modifvol,"spinbuttonkh2");
a=lookup_widget(modifvol,"spinbuttonkh3");
prix=lookup_widget(modifvol,"spinbuttonkhn2");
p=lookup_widget(modifvol,"spinbuttonkh4");

	type=lookup_widget(modifvol,"comboboxentrykh1");
	strcpy(v.id,gtk_entry_get_text(GTK_ENTRY(id)));
	strcpy(v.dep,gtk_entry_get_text(GTK_ENTRY(dep)));
        strcpy(v.arr,gtk_entry_get_text(GTK_ENTRY(arr)));
	strcpy(v.heure,gtk_entry_get_text(GTK_ENTRY(heure)));
	
	strcpy(v.type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(type)));
	v.jv = gtk_spin_button_get_value_as_int(j);
	v.mv = gtk_spin_button_get_value_as_int(m);
	v.av = gtk_spin_button_get_value_as_int(a);
	v.prixv = gtk_spin_button_get_value_as_int(prix);
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



j=lookup_widget(modifvol,"spinbuttonkh1");
m=lookup_widget(modifvol,"spinbuttonkh2");
a=lookup_widget(modifvol,"spinbuttonkh3");
prix=lookup_widget(modifvol,"spinbuttonkhn2");
p=lookup_widget(modifvol,"spinbuttonkh4");

	type=lookup_widget(modifvol,"comboboxentrykh1");
	strcpy(v.id,gtk_entry_get_text(GTK_ENTRY(id)));
	strcpy(v.dep,gtk_entry_get_text(GTK_ENTRY(dep)));
        strcpy(v.arr,gtk_entry_get_text(GTK_ENTRY(arr)));
	strcpy(v.heure,gtk_entry_get_text(GTK_ENTRY(heure)));
	 
	strcpy(v.type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(type)));
	v.jv = gtk_spin_button_get_value_as_int(j);
	v.mv = gtk_spin_button_get_value_as_int(m);
	v.av = gtk_spin_button_get_value_as_int(a);
	v.prixv = gtk_spin_button_get_value_as_int(prix);
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


void
on_button1i_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *admin;
GtkWidget *notebook7;
GtkWidget *treeview1i;
admin=lookup_widget(button,"admin");
 notebook7=lookup_widget(admin,"notebook7");
 treeview1i=lookup_widget(notebook7,"treeview1i");
afficheri(treeview1i);
}


void
on_button2i_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *ajoutcompt,*admin,*notebook7;
admin=lookup_widget(objet_graphique,"admin");
notebook7=lookup_widget(admin,"notebook7");
ajoutcompt=create_ajoutcompt();
gtk_widget_show(ajoutcompt);
}


void
on_button3i_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
compt c;

GtkWidget *input1;
GtkWidget *input2;
GtkWidget *input3;
GtkWidget *input4;
GtkWidget *input5;
GtkWidget *input6;
GtkWidget *input7;
GtkWidget *input8,*output140,*output141,*output142;
GtkWidget *ajoutcompt,*combobox1i;
GtkWidget *na;
input1= lookup_widget(objet_graphique,"entry1i");
input2= lookup_widget(objet_graphique,"entry2i");
input3= lookup_widget(objet_graphique,"entry3i");
input4= lookup_widget(objet_graphique,"entry4i");
input5= lookup_widget(objet_graphique,"entry5i");
input6= lookup_widget(objet_graphique,"entry6i");
input7= lookup_widget(objet_graphique,"entry7i");
input8= lookup_widget(objet_graphique,"entry8i");
output140=lookup_widget(objet_graphique,"label01i");
output141=lookup_widget(objet_graphique,"label02i");
output142=lookup_widget(objet_graphique,"label03i");
ajoutcompt= lookup_widget(objet_graphique,"ajoutcompt");
//admin=lookup_widget(objet_graphique,"admin");


na=lookup_widget(objet_graphique,"spinbutton1i");
c.age=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(na));
combobox1i=lookup_widget(objet_graphique, "combobox1i");
/*if(strcmp("adhérent",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox2n)))==0)
{c=6;}
else if(strcmp("médecien",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox2n)))==0)
{c=2;}*/




strcpy(c.login,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(c.password,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(c.nom,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(c.prenom,gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy(c.cin,gtk_entry_get_text(GTK_ENTRY(input5)));
strcpy(c.tel,gtk_entry_get_text(GTK_ENTRY(input6)));
strcpy(c.ad,gtk_entry_get_text(GTK_ENTRY(input7)));
strcpy(c.mail,gtk_entry_get_text(GTK_ENTRY(input8)));
if(strcmp("client",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox1i)))==0)
{c.role=2;}
else if(strcmp("agent",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox1i)))==0)
{c.role=3;}


if(verifidi(c.login)==0)
{ 

gtk_label_set_text(GTK_LABEL(output140)," X ");}
else
{gtk_label_set_text(GTK_LABEL(output140)," √ ");}
//login pass
if(verifentryi(c.password)==0)
{ gtk_label_set_text(GTK_LABEL(output141)," X ");}
else
{gtk_label_set_text(GTK_LABEL(output141)," √ ");}
//
if((verifidi(c.login)==1) && (verifentryi(c.password)==1))
     {   

ajouteri1(c);



ajouteri2(c);
gtk_widget_hide(ajoutcompt);}
else
{ gtk_label_set_text(GTK_LABEL(output142),"veuillez verifiez vos information svp!");}
}


void
on_actualiser2h_clicked                (GtkWidget      *objet,
                                        gpointer         user_data)
{
GtkWidget *agent;
GtkWidget *notebook5;
GtkWidget *treeview1h ;
agent=lookup_widget(objet,"agent");
notebook5=lookup_widget(agent,"notebook5");
treeview1h=lookup_widget(notebook5,"treeview1h") ;

afficher_recag(treeview1h);

}


void
on_envoyer_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
gtk_widget_hide(GTK_WIDGET(lookup_widget(button,"avis")));
GtkWidget *input1;
GtkWidget *input2;
GtkWidget *input3;
GtkWidget *input4;
GtkWidget *input5;

char nom[300];
char prenom[300];
char cin[300];
char date[300];
char message[300];



input1=lookup_widget(button,"nomc");
strcpy(nom,gtk_entry_get_text(GTK_ENTRY(input1)));
input2=lookup_widget(button,"prenomc");
strcpy(prenom,gtk_entry_get_text(GTK_ENTRY(input2)));
input3=lookup_widget(button,"cinc");  
strcpy(cin,gtk_entry_get_text(GTK_ENTRY(input3)));
input4=lookup_widget(button,"datec");
strcpy(date,gtk_entry_get_text(GTK_ENTRY(input4)));
input5=lookup_widget(button,"messagec");
strcpy(message,gtk_entry_get_text(GTK_ENTRY(input5)));


FILE *f;
f=fopen("avis.txt","a+");
fprintf(f,"%s %s %s %s %s \n",nom,prenom,cin,date,message);
fclose(f); 

//gtk_widget_show(avis);
gtk_widget_hide(GTK_WIDGET(lookup_widget(button,"avis")));
}


void
on_affich_clicked                      (GtkWidget       *objet,
                                        gpointer         user_data)
{

GtkWidget *notebook3;
GtkWidget *treeview2; 
GtkWidget *client;
client=lookup_widget(objet,"client");
notebook3=lookup_widget(client,"notebook3");
//=create_window1();
//gtk_widget_show (window1);
treeview2=lookup_widget(client,"treeview2");
//gtk_widget_show (window1);
afficher_avis(treeview2);



 //window1=lookup_widget(objet_graphique,"window1");

}


void
on_affichay_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *notebook3;
GtkWidget *treeview2ay; 
GtkWidget *client;
client=lookup_widget(objet,"client");
notebook3=lookup_widget(client,"notebook3");
//=create_window1();
//gtk_widget_show (window1);
treeview2ay=lookup_widget(client,"treeview2ay");
//gtk_widget_show (window1);
afficher_avis(treeview2ay);



 //window1=lookup_widget(objet_graphique,"window1");
}


void
on_envoyeray_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{

gtk_widget_hide(GTK_WIDGET(lookup_widget(button,"avis")));
GtkWidget *input1;
GtkWidget *input2;
GtkWidget *input3;
GtkWidget *input4;
GtkWidget *input5;

char nom[300];
char prenom[300];
char cin[300];
char date[300];
char message[300];



input1=lookup_widget(button,"nomay");
strcpy(nom,gtk_entry_get_text(GTK_ENTRY(input1)));
input2=lookup_widget(button,"prenomay");
strcpy(prenom,gtk_entry_get_text(GTK_ENTRY(input2)));
input3=lookup_widget(button,"cinay");  
strcpy(cin,gtk_entry_get_text(GTK_ENTRY(input3)));
input4=lookup_widget(button,"dateay");
strcpy(date,gtk_entry_get_text(GTK_ENTRY(input4)));
input5=lookup_widget(button,"messageay");
strcpy(message,gtk_entry_get_text(GTK_ENTRY(input5)));


FILE *f;
f=fopen("avis.txt","a+");
fprintf(f,"%s %s %s %s %s \n",nom,prenom,cin,date,message);
fclose(f); 

//gtk_widget_show(avis);
gtk_widget_hide(GTK_WIDGET(lookup_widget(button,"avis")));
}


void
on_modif_clicked                       (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window3;
window3=create_window3();
gtk_widget_show (window3);
}


void
on_modifier_clicked                    (GtkWidget                *objet_graphique,
                                        gpointer         user_data)
{
char y[300];char z[300];
GtkWidget *window3;
window3=lookup_widget(objet_graphique,"window3");


GtkWidget *input13;
GtkWidget *input14;

 input13=lookup_widget(objet_graphique,"entry4ay"); 
    strcpy(y,gtk_entry_get_text(GTK_ENTRY(input13)));
input14=lookup_widget(objet_graphique,"entry5ay"); 
    strcpy(z,gtk_entry_get_text(GTK_ENTRY(input14)));

    modifier_avis(y,z);
gtk_widget_hide(window3);
}


void
on_supp_clicked                        (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window2;
window2=create_window2();
gtk_widget_show (window2);

}


void
on_valider_clicked                     (GtkWidget                *objet_graphique,
                                        gpointer         user_data)
{
char x[20];
GtkWidget *window2;
window2=lookup_widget(objet_graphique,"window2");


GtkWidget *input12;

 input12=lookup_widget(objet_graphique,"entry3ay"); 
    strcpy(x,gtk_entry_get_text(GTK_ENTRY(input12)));

    supprimer_avis(x);
gtk_widget_hide(window2);
}

