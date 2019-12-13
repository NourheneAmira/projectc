#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>
#include <string.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "verif.h"
#include "nour.h"
#include "admin.h"
#include "string.h"
#include "recla.h"
#include "hhhh.h"
#include "rese.h"
#include "fact.h"
#include <time.h>
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
FILE* f;
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
compt g;
if(verifidc(g,c.login)==0)
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
if((verifidc(g,c.login)==1) && (verifentryi(c.password)==1))
     {   

ajouteri11(c);



ajouteri12(c);
FILE* f =fopen("util.txt","w");
               fprintf(f,"%s\n",c.login);
              fclose(f);
client= create_client ();
gtk_widget_show (client);
gtk_widget_destroy(aceuil);
}
else
{ gtk_label_set_text(GTK_LABEL(output1422),"veuillez verifiez vos information svp!");}
}





void
on_button1s_clicked                    (GtkWidget      *objet_graphique,
                                        gpointer         user_data)
{ fact g;
factvol t;
res z;
resvol p;
FILE* f;
vol r;
int d;
char e[50];
GtkWidget *client ;
GtkWidget *input1;
GtkWidget *output1;
GtkWidget *n;

client=lookup_widget(objet_graphique,"client");
input1=lookup_widget(client,"entry1s");
output1=lookup_widget(client,"label1s");

n=lookup_widget(client,"spinbutton1s");

p.nbrp=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(n));

strcpy(e,gtk_entry_get_text(GTK_ENTRY(input1)));

p.id= iddd()+idddh()+iddde()-2;
p.r=rechercheduvol(e);


			f=fopen("util.txt","r");
			fscanf(f,"%s",p.login);
			fclose(f);

d=disponiblevol(p.r,p.nbrp);

if (d==1)
{
ajout_resvol_txt( p );
t.k=p;
t.pf=p.r.prixv*p.nbrp;
strcpy(t.type,"vol");
z.id=p.id;
 strcpy(z.type,"vol");
strcpy(z.login , p.login);
z.nbrp=p.nbrp;
g.id=p.id;
 strcpy(g.type,"vol");
strcpy(g.login , p.login);
g.pf=t.pf;
ajout_fact_txt(g);
ajout_res_txt(z);
ajout_factvol_txt(t);
gtk_label_set_text(GTK_LABEL(output1),"place disponible");}
else 
gtk_label_set_text(GTK_LABEL(output1),"place indisponible");

}


void
on_button2s_clicked                    (GtkWidget      *objet_graphique,
                                        gpointer         user_data)
{fact g;
facthot t;
res z;
reshot h;
FILE* f;
hotel r;
int d,k;
char e[50];
GtkWidget *client ;
GtkWidget *input1;
GtkWidget *output1,*output2;
GtkWidget *n,*jj,*mm,*aa,*nnn;
client=lookup_widget(objet_graphique,"client");
input1=lookup_widget(client,"entry2s");
output1=lookup_widget(client,"label2s");
output2=lookup_widget(client,"label3s");
n=lookup_widget(client,"spinbutton2s");
jj=lookup_widget(client,"spinbutton10s");
mm=lookup_widget(client,"spinbutton11s");
aa=lookup_widget(client,"spinbutton12s");
nnn=lookup_widget(client,"spinbutton13s");
h.nbrp=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(n));
h.j=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(jj));
h.m=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(mm));
h.a=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(aa));
h.nn=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(nnn));
strcpy(e,gtk_entry_get_text(GTK_ENTRY(input1)));
h.id= iddd()+idddh()+iddde()-2;
h.r=rechercheduhotel(e);
			f=fopen("util.txt","r");
			fscanf(f,"%s",h.login);
			fclose(f);
k=est_valide(h.j,h.m,h.a);
d=disponiblehot(h.r,h.nbrp);
if ((d==0)&&(k==0))
{gtk_label_set_text(GTK_LABEL(output1),"date non valide");
gtk_label_set_text(GTK_LABEL(output2),"place indisponible");}
else if (k==0)
{gtk_label_set_text(GTK_LABEL(output1),"date non valider");
gtk_label_set_text(GTK_LABEL(output2),"place disponible");}
else if (d==0)
{gtk_label_set_text(GTK_LABEL(output1),"date valide");
gtk_label_set_text(GTK_LABEL(output2),"place indisponible");}
else 
{gtk_label_set_text(GTK_LABEL(output1),"date valide");
ajout_reshot_txt( h );
t.k=h;
t.pf=h.r.prix*h.nn*h.nbrp;
strcpy(t.type,"hotel");
z.id=h.id;
 strcpy(z.type,"hotel");
strcpy(z.login , h.login);
z.nbrp=h.nbrp;
g.id=h.id;
 strcpy(g.type,"hotel");
strcpy(g.login , h.login);
g.pf=t.pf;
ajout_fact_txt(g);
ajout_res_txt(z);
ajout_facthot_txt(t);
gtk_label_set_text(GTK_LABEL(output2),"place disponible");}




}


void
on_button3s_clicked                    (GtkWidget      *objet_graphique,
                                        gpointer         user_data)
{fact g;
factexc a;
res z;
resexc t;
FILE* f;
excursion r;
int d;
char e[50];
GtkWidget *client ;
GtkWidget *input1;
GtkWidget *output1;
GtkWidget *n;
client=lookup_widget(objet_graphique,"client");
input1=lookup_widget(client,"entry3s");
output1=lookup_widget(client,"label4s");
n=lookup_widget(client,"spinbutton3s");

t.nbrp=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(n));

strcpy(e,gtk_entry_get_text(GTK_ENTRY(input1)));

t.id= iddd()+idddh()+iddde()-2;
t.r=rechercheduexc(e);


			f=fopen("util.txt","r");
			fscanf(f,"%s",t.login);
			fclose(f);

d=disponibleexc(t.r,t.nbrp);

if (d==1)
{
ajout_resexc_txt( t );
a.k=t;
a.pf=t.r.prix*t.nbrp;
strcpy(a.type,"excursion");
z.id=t.id;
 strcpy(z.type,"excursion");
strcpy(z.login , t.login);
z.nbrp=t.nbrp;
g.id=t.id;
 strcpy(g.type,"excursion");
strcpy(g.login , t.login);
g.pf=a.pf;
ajout_fact_txt(g);
ajout_res_txt(z);
ajout_factexc_txt(a);
gtk_label_set_text(GTK_LABEL(output1),"place disponible");}
else 
gtk_label_set_text(GTK_LABEL(output1),"place indisponible");



}


void
on_button4s_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *client;
GtkWidget *notebook3;
GtkWidget *treeview1s;
client=lookup_widget(button,"client");
notebook3=lookup_widget(client,"notebook3");
treeview1s=lookup_widget(notebook3,"treeview1s");
afficher_reservation(treeview1s);
}


void
on_treeview1rec_row_activated          (GtkWidget     *objet_graphique,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)

{
GtkWidget *window2h,*notebook3;
GtkWidget *treeview1rec;
GtkWidget *idh,*txtrech;


gchar *id, *user,*etat,*textrec,*txtrep,*date;
 

notebook3=lookup_widget(objet_graphique,"notebook3");

window2h=create_window2h();
treeview1rec=lookup_widget(notebook3,"treeview1rec");

txtrech=lookup_widget(window2h,"entry3hedi");

idh=lookup_widget(window2h,"entry1hedi");

GtkTreeIter iter;
	GtkTreeModel *model=gtk_tree_view_get_model (GTK_TREE_VIEW(treeview1rec));
	gtk_tree_model_get_iter(model,&iter,path);
	gtk_tree_model_get (model,&iter,0,&id,1,&user,2,&etat,3,&textrec,4,&txtrep,5,&date,-1);
	printf("%s %s %s %s %s %s",id,user,etat,textrec,txtrep,date);
	gtk_entry_set_text(GTK_ENTRY (txtrech),_(textrec));
	gtk_entry_set_text(GTK_ENTRY (idh),_(id));
gtk_window_set_position(GTK_WINDOW(notebook3),GTK_WIN_POS_CENTER);
gtk_widget_show(window2h);
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
char y[70];
date_a (y);

ajoutrec(tab,n,login,txt);
ecrirerecfich( tab , n,y);

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

excursion m;
if(verifide(m,p.id)==0)
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
if((verifide(m,p.id)==1) && (verifentry(p.des)==1))
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
hotel h,s;

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
h.prix=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(nprixh));
h.p=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(np));



strcpy(h.id,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(h.lieu,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(h.nom,gtk_entry_get_text(GTK_ENTRY(input3)));

strcpy(h.chambre,gtk_combo_box_get_active_text (GTK_COMBO_BOX(CHAMBRE)));

if(verifidh(s,h.id)==0)
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
if((verifidh(s,h.id)==1) && (verifentry(h.lieu)==1))
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
	h.prix = gtk_spin_button_get_value_as_int(prixh);
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
	h.prix = gtk_spin_button_get_value_as_int(prixh);
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
vol k;
/////////////////controle de saisie///////////
if(verifidv(k,v.id)==0)
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
if((verifidv(k,v.id)==1) && (verifentry(v.dep)==1))
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


compt m;

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


if(verifidc(m,c.login)==0)
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
if((verifidc(m,c.login)==1) && (verifentryi(c.password)==1))
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
char y[100];
date_a(y);
f=fopen("avis.txt","a+");
fprintf(f,"%s %s %s %s %s \n",nom,prenom,cin,y,message);
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
//GtkWidget *input4;
GtkWidget *input5;

char nom[300];
char prenom[300];
char cin[300];
//char date[300];
char message[300];



input1=lookup_widget(button,"nomay");
strcpy(nom,gtk_entry_get_text(GTK_ENTRY(input1)));
input2=lookup_widget(button,"prenomay");
strcpy(prenom,gtk_entry_get_text(GTK_ENTRY(input2)));
input3=lookup_widget(button,"cinay");  
strcpy(cin,gtk_entry_get_text(GTK_ENTRY(input3)));
//input4=lookup_widget(button,"dateay");
//strcpy(date,gtk_entry_get_text(GTK_ENTRY(input4)));
input5=lookup_widget(button,"messageay");
strcpy(message,gtk_entry_get_text(GTK_ENTRY(input5)));


FILE *f;
char y[100];
date_a(y);
f=fopen("avis.txt","a+");
fprintf(f,"%s %s %s %s %s \n",nom,prenom,cin,y,message);
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


void
on_buttonki_clicked                    (GtkWidget                *objet_graphique,
                                        gpointer         user_data)
{

GtkWidget *admin;
GtkWidget *notebook7;
GtkWidget *notebook4;
char x [20];
compt c;
GtkWidget *input12;

 admin=lookup_widget(objet_graphique,"admin");
notebook7=lookup_widget(admin,"notebook7");

 
    
    input12=lookup_widget(notebook7,"entryki"); 
    strcpy(x,gtk_entry_get_text(GTK_ENTRY(input12)));

    supprimerlog(x,c);
   ///gtk_label_set_text(GTK_LABEL(label86),"***Suppression réussite***");
}


void
on_button104s_clicked                  (GtkWidget                *button,
                                        gpointer         user_data)
{
GtkWidget *modresh ;
GtkWidget *client ;
client=lookup_widget(button,"client");
modresh=lookup_widget(button,"modresh");
gtk_widget_hide (modresh);
gtk_widget_show (client);
}


void
on_button105s_clicked                  (GtkWidget                *objet_graphique,
                                        gpointer         user_data)
{
fact g;
facthot t;
res z;
reshot p;
hotel x;
int k,d,i;

GtkWidget *modresh ;
GtkWidget *input1;
GtkWidget *output1,*output2;
GtkWidget *n,*nnn,*jj,*mm,*aa;

modresh=lookup_widget(objet_graphique,"modresh");
input1=lookup_widget(modresh,"spinbutton1001s");
output1=lookup_widget(modresh,"label102s");
output2=lookup_widget(modresh,"label101s");
n=lookup_widget(modresh,"spinbutton101s");
jj=lookup_widget(modresh,"spinbutton102s");
mm=lookup_widget(modresh,"spinbutton103s");
aa=lookup_widget(modresh,"spinbutton104s");
nnn=lookup_widget(modresh,"spinbutton105s");

i=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(input1));

p= recherche_res_hot_id (i);
x=rechercheduhotel(p.r.id);
p.r=x;
p.nbrp=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(n));
p.j=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(jj));
p.m=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(mm));
p.a=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(aa));
p.nn=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(nnn));

k=est_valide(p.j,p.m,p.a);
d=disponiblehot(p.r,p.nbrp);

if ((d==0)&&(k==0))
{gtk_label_set_text(GTK_LABEL(output1),"date non valide");
gtk_label_set_text(GTK_LABEL(output2),"place indisponible");}
else if (k==0)
{gtk_label_set_text(GTK_LABEL(output1),"date non valider");
gtk_label_set_text(GTK_LABEL(output2),"place disponible");}
else if (d==0)
{gtk_label_set_text(GTK_LABEL(output1),"date valide");
gtk_label_set_text(GTK_LABEL(output2),"place indisponible");}
else 
{gtk_label_set_text(GTK_LABEL(output1),"date valide");
modif_reshot( p);
t.k=p;
t.pf=p.r.prix*p.nn*p.nbrp;
strcpy(t.type,"hotel");
z.id=p.id;
 strcpy(z.type,"hotel");
strcpy(z.login , p.login);
z.nbrp=p.nbrp;
g.id=p.id;
 strcpy(g.type,"hotel");
strcpy(g.login , p.login);
g.pf=t.pf;
modif_fact(g);
modif_res(z);
modif_facthot(t);
gtk_label_set_text(GTK_LABEL(output2),"place disponible");}
}


void
on_button106s_clicked                  (GtkWidget                *objet_graphique,
                                        gpointer         user_data)
{
fact g;
facthot t;
res z;
reshot p;
hotel x;
int i;

GtkWidget *modresh;
GtkWidget *input1;
GtkWidget *output1;


modresh=lookup_widget(objet_graphique,"modresh");
input1=lookup_widget(modresh,"spinbutton1001s");
output1=lookup_widget(modresh,"label102s");



i=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(input1));

p= recherche_res_hot_id (i);
x=rechercheduhotel(p.r.id);
p.r=x;

supprimer_reshot( p);
t.k=p;
t.pf=p.r.prix*p.nn*p.nbrp;
strcpy(t.type,"hotel");
z.id=p.id;
 strcpy(z.type,"hotel");
strcpy(z.login , p.login);
z.nbrp=p.nbrp;
g.id=p.id;
 strcpy(g.type,"hotel");
strcpy(g.login , p.login);
g.pf=t.pf;
supp_fact(g);
supprimer_res(z);
supp_facthot(t);
gtk_label_set_text(GTK_LABEL(output1),"suppression valider");
}


void
on_button109s_clicked                  (GtkWidget                *objet_graphique,
                                        gpointer         user_data)
{
excursion x;
fact g;
factexc t;
res z;
resexc p;
int i;
GtkWidget *modrese ;
GtkWidget *input1;
GtkWidget *output1;


modrese=lookup_widget(objet_graphique,"modrese");
input1=lookup_widget(modrese,"spinbutton1002s");
output1=lookup_widget(modrese,"label103s");


i=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(input1));

p= recherche_res_exc_id (i);
x=rechercheduexc(p.r.id);
p.r=x;







supprimer_resexc( p);
z.id=p.id;
 strcpy(z.type,"excursion");
strcpy(z.login , p.login);
z.nbrp=p.nbrp;
supprimer_res(z);
strcpy(t.type,"excursion");
t.k=p;
t.pf=p.r.prix*p.nbrp;
strcpy(g.type,"excursion");
g.id=p.id;
strcpy(g.login , p.login);
g.pf=t.pf;
supp_factexc(t);
supp_fact(g);
gtk_label_set_text(GTK_LABEL(output1),"suppression valider");

}


void
on_button108s_clicked                  (GtkWidget                *objet_graphique,
                                        gpointer         user_data)
{
excursion x;
fact g;
factexc t;
res z;
resexc p;
int d,i;
GtkWidget *modrese ;
GtkWidget *input1;
GtkWidget *output1;
GtkWidget *n;

modrese=lookup_widget(objet_graphique,"modrese");
input1=lookup_widget(modrese,"spinbutton1002s");
output1=lookup_widget(modrese,"label103s");
n=lookup_widget(modrese,"spinbutton41");

i=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(input1));

p= recherche_res_exc_id (i);
x=rechercheduexc(p.r.id);
p.r=x;

p.nbrp=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(n));


d=disponibleexc(p.r,p.nbrp);

if (d==1)
{
modif_resexc( p);
z.id=p.id;
 strcpy(z.type,"excursion");
strcpy(z.login , p.login);
z.nbrp=p.nbrp;
 modif_res(z);
strcpy(t.type,"excursion");
t.k=p;
t.pf=p.r.prix*p.nbrp;
strcpy(g.type,"excursion");
g.id=p.id;
strcpy(g.login , p.login);
g.pf=t.pf;
modif_factexc(t);
modif_fact(g);
gtk_label_set_text(GTK_LABEL(output1),"place disponible");}
else 
gtk_label_set_text(GTK_LABEL(output1),"place indisponible");
 
}


void
on_button107s_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *modrese ;
GtkWidget *client ;
client=lookup_widget(button,"client");
modrese=lookup_widget(button,"modrese");
gtk_widget_hide (modrese);
gtk_widget_show (client);
}



void
on_button1th_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{GtkWidget *client,*notebook3;
GtkWidget *output1;
GtkWidget *output2;
client=lookup_widget(button,"client");
notebook3=lookup_widget(client,"notebook3");
output1=lookup_widget(client,"label1th");
output2=lookup_widget(client,"label2th");
gtk_label_set_text(GTK_LABEL(output1),"resevation confirmée");
char hh[10];
char d[10];
fact z;
int s;
FILE* f;
FILE* g;
s=0;
g=fopen("util.txt","r");
			fscanf(g,"%s",d);
			fclose(g);
f = fopen("facture.txt", "r");

 if(f==NULL)
	{
	 return;
	}		
 else 
	{
 	 f = fopen("facture.txt", "a+");
	 while(fscanf(f," %d %s %s %d\n",&z.id,z.type,z.login,&z.pf)!=EOF)
		{if (strcmp(d,z.login)==0)
		 s+=z.pf;
		}
	 fclose(f);
	 
	}
sprintf(hh,"%d",s);
gtk_label_set_text(GTK_LABEL(output2),hh);
}


void
on_button2th_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
FILE *f=fopen("destroy.txt","w");
FILE *g=fopen("facture.txt","r");
fclose(f);
fclose(g);
remove("facture.txt");
rename("destroy.txt","facture.txt");

}


void
on_treeview1s_row_activated            (GtkWidget     *objet_graphique,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
 GtkWidget *modresv,*modrese,*modresh,*client,*notebook3;
GtkWidget *treeview1s,*input1;
gchar  *type[10] ,*login[20];
gint *id,*nbrp,*idd;
/*input1=lookup_widget(modresv,"entry1000s");*/
client=lookup_widget(objet_graphique,"client");
notebook3=lookup_widget(client,"notebook3");
modresv=create_modresv();
modresh=create_modresh();
modrese=create_modrese();
treeview1s=lookup_widget(notebook3,"treeview1s");


GtkTreeIter iter;
	GtkTreeModel *model=gtk_tree_view_get_model (GTK_TREE_VIEW(treeview1s));
	gtk_tree_model_get_iter(model,&iter,path);
	gtk_tree_model_get (model,&iter,0,&id,1,&type,2,&login,3,&nbrp,-1);
if (strcmp(*type,"vol")==0)
		  {gtk_window_set_position(GTK_WINDOW(client),GTK_WIN_POS_CENTER);
				gtk_widget_show(modresv);
/*gtk_entry_set_text(GTK_ENTRY (input1),_(id));*/
}
else if (strcmp(*type,"hotel")==0)
		 {gtk_window_set_position(GTK_WINDOW(client),GTK_WIN_POS_CENTER);
				gtk_widget_show(modresh);}
else
		{gtk_window_set_position(GTK_WINDOW(client),GTK_WIN_POS_CENTER);
				gtk_widget_show (modrese);}


}
void
on_button100s_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{GtkWidget *modresv ;
GtkWidget *client ;
client=lookup_widget(button,"client");
modresv=lookup_widget(button,"modresv");
gtk_widget_hide (modresv);
gtk_widget_show (client);
}


void
on_button101s_clicked                  (GtkWidget      *objet_graphique,
                                        gpointer         user_data)
{
vol x;
fact g;
factvol t;
res z;
resvol p;
int d,i;
GtkWidget *modresv ;
GtkWidget *input1;
GtkWidget *output1;
GtkWidget *n;

modresv=lookup_widget(objet_graphique,"modresv");
input1=lookup_widget(modresv,"spinbutton1000s");
output1=lookup_widget(modresv,"label100s");
n=lookup_widget(modresv,"spinbutton100s");

i=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(input1));

p= recherche_res_vol_id (i);
x=rechercheduvol(p.r.id);
p.r=x;

p.nbrp=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(n));


d=disponiblevol(p.r,p.nbrp);

if (d==1)
{
modif_resvol( p);
z.id=p.id;
 strcpy(z.type,"vol");
strcpy(z.login , p.login);
z.nbrp=p.nbrp;
 modif_res(z);
strcpy(t.type,"vol");
t.k=p;
t.pf=p.r.prixv*p.nbrp;
strcpy(g.type,"vol");
g.id=p.id;
strcpy(g.login , p.login);
g.pf=t.pf;
modif_factvol(t);
modif_fact(g);
gtk_label_set_text(GTK_LABEL(output1),"place disponible");
}
else 
gtk_label_set_text(GTK_LABEL(output1),"place indisponible");
 
}




void
on_button102s_clicked                  (GtkWidget      *objet_graphique,
                                        gpointer         user_data)
{
vol x;
fact g;
factvol t;
res z;
resvol p;
int i;
GtkWidget *modresv ;
GtkWidget *input1;
GtkWidget *output1;

modresv=lookup_widget(objet_graphique,"modresv");
input1=lookup_widget(modresv,"spinbutton1000s");
output1=lookup_widget(modresv,"label100s");

i=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(input1));

p= recherche_res_vol_id (i);
x=rechercheduvol(p.r.id);
p.r=x;


supprimer_resvol( p);
z.id=p.id;
 strcpy(z.type,"vol");
strcpy(z.login , p.login);
z.nbrp=p.nbrp;
supprimer_res(z);
strcpy(t.type,"vol");
t.k=p;
t.pf=p.r.prixv*p.nbrp;
strcpy(g.type,"vol");
g.id=p.id;
strcpy(g.login , p.login);
g.pf=t.pf;
supp_factvol(t);
supp_fact(g);
gtk_label_set_text(GTK_LABEL(output1),"supprission valider");
}


void
on_button2hedi_clicked                 (GtkWidget      *objet,
                                        gpointer         user_data)
{int n,nb;
char text[500];
char *id;
rec tab1[100];
GtkWidget *window2h,*idh,*txtrech;

window2h=lookup_widget(objet,"window2h") ;

idh=lookup_widget(window2h,"entry1hedi");

txtrech=lookup_widget(window2h,"entry3hedi");




id=malloc(3);
strcpy(id,gtk_entry_get_text(GTK_ENTRY(idh)));
char y[70];
date_a (y);
n= calculenbrefich();
 lirefichrec(tab1);
strcpy(text,gtk_entry_get_text(GTK_ENTRY(txtrech)));
nb=atoi(id);
modifrecus(tab1, n,nb, text);
ecrirerecfich( tab1 , n-1,y);
gtk_widget_hide(window2h);

}


void
on_button1hedi_clicked                 (GtkWidget     *objet,
                                        gpointer         user_data)
{

int nb;
char text[500];
char *id;
rec p;
GtkWidget *window2h,*idh;
window2h=lookup_widget(objet,"window2h") ;
idh=lookup_widget(window2h,"entry1hedi");


id=malloc(3);
strcpy(id,gtk_entry_get_text(GTK_ENTRY(idh)));

nb=atoi(id);

supprimer(nb, p);
gtk_widget_hide(window2h);
}



void
on_hedi_clicked                        (GtkWidget     *objet,
                                        gpointer         user_data)
{int n,nb;
char text[500];
char *id;
rec tab1[100];
GtkWidget *windowhad,*idh,*txtreph;

windowhad=lookup_widget(objet,"windowhad") ;

idh=lookup_widget(windowhad,"hedi1");

txtreph=lookup_widget(windowhad,"hedi2");




id=malloc(3);
strcpy(id,gtk_entry_get_text(GTK_ENTRY(idh)));
char y[70];
date_a (y);
n= calculenbrefich();
 lirefichrec(tab1);
strcpy(text,gtk_entry_get_text(GTK_ENTRY(txtreph)));
nb=atoi(id);
modifrecag(tab1, n,nb, text);
ecrirerecfich( tab1 , n-1,y);
gtk_widget_hide(windowhad);

}




void
on_treeview1h_row_activated            (GtkWidget     *objet_graphique,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkWidget *windowhag,*notebook5;
GtkWidget *treeview1h;
GtkWidget *idh,*txtreph;


gchar *id, *user,*etat,*textrec,*txtrep,*date;
 

notebook5=lookup_widget(objet_graphique,"notebook5");

windowhag=create_windowhag();
treeview1h=lookup_widget(notebook5,"treeview1h");

txtreph=lookup_widget(windowhag,"hedi002");

idh=lookup_widget(windowhag,"hedi001");

GtkTreeIter iter;
	GtkTreeModel *model=gtk_tree_view_get_model (GTK_TREE_VIEW(treeview1h));
	gtk_tree_model_get_iter(model,&iter,path);
	gtk_tree_model_get (model,&iter,0,&id,1,&user,2,&etat,3,&textrec,4,&txtrep,5,&date,-1);
	printf("%s %s %s %s %s %s",id,user,etat,textrec,txtrep,date);
	gtk_entry_set_text(GTK_ENTRY (txtreph),_(txtrep));
	gtk_entry_set_text(GTK_ENTRY (idh),_(id));
gtk_window_set_position(GTK_WINDOW(notebook5),GTK_WIN_POS_CENTER);
gtk_widget_show(windowhag);
}


void
on_actualiser3_clicked                 (GtkWidget      *objet,
                                        gpointer         user_data)
{
GtkWidget *admin;
GtkWidget *notebook7;
GtkWidget *treeview2h ;
admin=lookup_widget(objet,"admin");
notebook7=lookup_widget(admin,"notebook7");
treeview2h=lookup_widget(notebook7,"treeview2h") ;

afficher_recag(treeview2h);
}


void
on_hedi003_clicked                     (GtkWidget      *objet,
                                        gpointer         user_data)
{
int n,nb;
char text[500];
char *id;
rec tab1[100];
GtkWidget *windowhag,*idh,*txtreph;

windowhag=lookup_widget(objet,"windowhag") ;

idh=lookup_widget(windowhag,"hedi001");

txtreph=lookup_widget(windowhag,"hedi002");




id=malloc(3);
strcpy(id,gtk_entry_get_text(GTK_ENTRY(idh)));
char y[70];
date_a (y);
n= calculenbrefich();
 lirefichrec(tab1);
strcpy(text,gtk_entry_get_text(GTK_ENTRY(txtreph)));
nb=atoi(id);
modifrecag(tab1, n,nb, text);
ecrirerecfich( tab1 , n-1,y);
gtk_widget_hide(windowhag);

}


void
on_treeview2h_row_activated            (GtkWidget     *objet_graphique,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkWidget *windowhad,*notebook7;
GtkWidget *treeview2h;
GtkWidget *idh,*txtreph;


gchar *id, *user,*etat,*textrec,*txtrep,*date;
 

notebook7=lookup_widget(objet_graphique,"notebook7");

windowhad=create_windowhad();
treeview2h=lookup_widget(notebook7,"treeview2h");

txtreph=lookup_widget(windowhad,"hedi2");

idh=lookup_widget(windowhad,"hedi1");

GtkTreeIter iter;
	GtkTreeModel *model=gtk_tree_view_get_model (GTK_TREE_VIEW(treeview2h));
	gtk_tree_model_get_iter(model,&iter,path);
	gtk_tree_model_get (model,&iter,0,&id,1,&user,2,&etat,3,&textrec,4,&txtrep,5,&date,-1);
	printf("%s %s %s %s %s %s",id,user,etat,textrec,txtrep,date);
	gtk_entry_set_text(GTK_ENTRY (txtreph),_(txtrep));
	gtk_entry_set_text(GTK_ENTRY (idh),_(id));
gtk_window_set_position(GTK_WINDOW(notebook7),GTK_WIN_POS_CENTER);
gtk_widget_show(windowhad);
}


void
on_buttonihsen1_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *modcompt;
modcompt=create_modcompt();
gtk_widget_show (modcompt);
}


void
on_buttonihsen2_clicked                (GtkWidget     *objet_graphique,
                                        gpointer         user_data)
{
char a[300];char b[300];char c1[300];char d[300];
GtkWidget *modcompt;
modcompt=lookup_widget(objet_graphique,"modcompt");
compt c;
GtkWidget *input1;
GtkWidget *input2;
GtkWidget *input3;
GtkWidget *input4;
input1=lookup_widget(objet_graphique,"entryihsen1"); 
    strcpy(a,gtk_entry_get_text(GTK_ENTRY(input1)));
input2=lookup_widget(objet_graphique,"entryihsen2"); 
    strcpy(b,gtk_entry_get_text(GTK_ENTRY(input2)));
 input3=lookup_widget(objet_graphique,"entryihsen3"); 
    strcpy(c1,gtk_entry_get_text(GTK_ENTRY(input3)));
input4=lookup_widget(objet_graphique,"entryihsen4"); 
    strcpy(d,gtk_entry_get_text(GTK_ENTRY(input4)));

    modifierihsen(c,a,b,c1,d);
gtk_widget_hide(modcompt);
}

