/*
 * DO NOT EDIT THIS FILE - it is generated by Glade.
 */

#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

#include <gdk/gdkkeysyms.h>
#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"

#define GLADE_HOOKUP_OBJECT(component,widget,name) \
  g_object_set_data_full (G_OBJECT (component), name, \
    gtk_widget_ref (widget), (GDestroyNotify) gtk_widget_unref)

#define GLADE_HOOKUP_OBJECT_NO_REF(component,widget,name) \
  g_object_set_data (G_OBJECT (component), name, widget)

GtkWidget*
create_window1 (void)
{
  GtkWidget *window1;
  GtkWidget *fixedWindow1;
  GtkWidget *labelDR;
  GtkWidget *labelJour;
  GtkObject *spinbuttonJour_adj;
  GtkWidget *spinbuttonJour;
  GtkObject *spinbuttonMois_adj;
  GtkWidget *spinbuttonMois;
  GtkObject *spinbuttonAnnee_adj;
  GtkWidget *spinbuttonAnnee;
  GtkWidget *labelAnnee;
  GtkWidget *labelMois;
  GtkWidget *labelChoisirSalle;
  GtkWidget *labelHR;
  GtkWidget *comboboxHR;
  GtkWidget *labelBloc;
  GtkWidget *comboboxBloc;
  GtkWidget *comboboxSalle;
  GtkWidget *buttonConfirmer;
  GtkWidget *buttonValider;
  GtkWidget *labelSortie;

  window1 = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title (GTK_WINDOW (window1), _("window1"));

  fixedWindow1 = gtk_fixed_new ();
  gtk_widget_show (fixedWindow1);
  gtk_container_add (GTK_CONTAINER (window1), fixedWindow1);
  gtk_widget_set_size_request (fixedWindow1, 600, 300);

  labelDR = gtk_label_new (_("Date de r\303\251servation :"));
  gtk_widget_show (labelDR);
  gtk_fixed_put (GTK_FIXED (fixedWindow1), labelDR, 24, 24);
  gtk_widget_set_size_request (labelDR, 160, 30);

  labelJour = gtk_label_new (_("Jour"));
  gtk_widget_show (labelJour);
  gtk_fixed_put (GTK_FIXED (fixedWindow1), labelJour, 192, 24);
  gtk_widget_set_size_request (labelJour, 40, 30);

  spinbuttonJour_adj = gtk_adjustment_new (1, 1, 31, 1, 10, 10);
  spinbuttonJour = gtk_spin_button_new (GTK_ADJUSTMENT (spinbuttonJour_adj), 1, 0);
  gtk_widget_show (spinbuttonJour);
  gtk_fixed_put (GTK_FIXED (fixedWindow1), spinbuttonJour, 240, 24);
  gtk_widget_set_size_request (spinbuttonJour, 60, 25);

  spinbuttonMois_adj = gtk_adjustment_new (1, 1, 12, 1, 10, 10);
  spinbuttonMois = gtk_spin_button_new (GTK_ADJUSTMENT (spinbuttonMois_adj), 1, 0);
  gtk_widget_show (spinbuttonMois);
  gtk_fixed_put (GTK_FIXED (fixedWindow1), spinbuttonMois, 360, 24);
  gtk_widget_set_size_request (spinbuttonMois, 60, 25);

  spinbuttonAnnee_adj = gtk_adjustment_new (1990, 1990, 2020, 1, 10, 10);
  spinbuttonAnnee = gtk_spin_button_new (GTK_ADJUSTMENT (spinbuttonAnnee_adj), 1, 0);
  gtk_widget_show (spinbuttonAnnee);
  gtk_fixed_put (GTK_FIXED (fixedWindow1), spinbuttonAnnee, 496, 24);
  gtk_widget_set_size_request (spinbuttonAnnee, 60, 25);

  labelAnnee = gtk_label_new (_("Ann\303\251e"));
  gtk_widget_show (labelAnnee);
  gtk_fixed_put (GTK_FIXED (fixedWindow1), labelAnnee, 432, 24);
  gtk_widget_set_size_request (labelAnnee, 60, 30);

  labelMois = gtk_label_new (_("Mois"));
  gtk_widget_show (labelMois);
  gtk_fixed_put (GTK_FIXED (fixedWindow1), labelMois, 320, 24);
  gtk_widget_set_size_request (labelMois, 40, 30);

  labelChoisirSalle = gtk_label_new (_("Choisir une salle   :"));
  gtk_widget_show (labelChoisirSalle);
  gtk_fixed_put (GTK_FIXED (fixedWindow1), labelChoisirSalle, 64, 176);
  gtk_widget_set_size_request (labelChoisirSalle, 160, 30);

  labelHR = gtk_label_new (_("Heure de r\303\251servation :"));
  gtk_widget_show (labelHR);
  gtk_fixed_put (GTK_FIXED (fixedWindow1), labelHR, 24, 104);
  gtk_widget_set_size_request (labelHR, 160, 30);

  comboboxHR = gtk_combo_box_new_text ();
  gtk_widget_show (comboboxHR);
  gtk_fixed_put (GTK_FIXED (fixedWindow1), comboboxHR, 184, 104);
  gtk_widget_set_size_request (comboboxHR, 100, 30);
  gtk_combo_box_append_text (GTK_COMBO_BOX (comboboxHR), _("   9H==>12H15"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (comboboxHR), _("14H==>17H15"));

  labelBloc = gtk_label_new (_("Bloc :"));
  gtk_widget_show (labelBloc);
  gtk_fixed_put (GTK_FIXED (fixedWindow1), labelBloc, 288, 104);
  gtk_widget_set_size_request (labelBloc, 60, 30);

  comboboxBloc = gtk_combo_box_new_text ();
  gtk_widget_show (comboboxBloc);
  gtk_fixed_put (GTK_FIXED (fixedWindow1), comboboxBloc, 344, 104);
  gtk_widget_set_size_request (comboboxBloc, 100, 30);
  gtk_combo_box_append_text (GTK_COMBO_BOX (comboboxBloc), _("A"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (comboboxBloc), _("B"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (comboboxBloc), _("C"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (comboboxBloc), _("D"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (comboboxBloc), _("E"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (comboboxBloc), _("H"));

  comboboxSalle = gtk_combo_box_new_text ();
  gtk_widget_show (comboboxSalle);
  gtk_fixed_put (GTK_FIXED (fixedWindow1), comboboxSalle, 232, 176);
  gtk_widget_set_size_request (comboboxSalle, 100, 30);

  buttonConfirmer = gtk_button_new_with_mnemonic (_("Confirmer"));
  gtk_widget_show (buttonConfirmer);
  gtk_fixed_put (GTK_FIXED (fixedWindow1), buttonConfirmer, 368, 176);
  gtk_widget_set_size_request (buttonConfirmer, 80, 30);

  buttonValider = gtk_button_new_with_mnemonic (_("Valider"));
  gtk_widget_show (buttonValider);
  gtk_fixed_put (GTK_FIXED (fixedWindow1), buttonValider, 472, 104);
  gtk_widget_set_size_request (buttonValider, 80, 30);

  labelSortie = gtk_label_new ("");
  gtk_widget_show (labelSortie);
  gtk_fixed_put (GTK_FIXED (fixedWindow1), labelSortie, 136, 248);
  gtk_widget_set_size_request (labelSortie, 300, 30);

  g_signal_connect ((gpointer) buttonConfirmer, "clicked",
                    G_CALLBACK (on_buttonConfirmer_clicked),
                    NULL);
  g_signal_connect ((gpointer) buttonValider, "clicked",
                    G_CALLBACK (on_buttonValider_clicked),
                    NULL);

  /* Store pointers to all widgets, for use by lookup_widget(). */
  GLADE_HOOKUP_OBJECT_NO_REF (window1, window1, "window1");
  GLADE_HOOKUP_OBJECT (window1, fixedWindow1, "fixedWindow1");
  GLADE_HOOKUP_OBJECT (window1, labelDR, "labelDR");
  GLADE_HOOKUP_OBJECT (window1, labelJour, "labelJour");
  GLADE_HOOKUP_OBJECT (window1, spinbuttonJour, "spinbuttonJour");
  GLADE_HOOKUP_OBJECT (window1, spinbuttonMois, "spinbuttonMois");
  GLADE_HOOKUP_OBJECT (window1, spinbuttonAnnee, "spinbuttonAnnee");
  GLADE_HOOKUP_OBJECT (window1, labelAnnee, "labelAnnee");
  GLADE_HOOKUP_OBJECT (window1, labelMois, "labelMois");
  GLADE_HOOKUP_OBJECT (window1, labelChoisirSalle, "labelChoisirSalle");
  GLADE_HOOKUP_OBJECT (window1, labelHR, "labelHR");
  GLADE_HOOKUP_OBJECT (window1, comboboxHR, "comboboxHR");
  GLADE_HOOKUP_OBJECT (window1, labelBloc, "labelBloc");
  GLADE_HOOKUP_OBJECT (window1, comboboxBloc, "comboboxBloc");
  GLADE_HOOKUP_OBJECT (window1, comboboxSalle, "comboboxSalle");
  GLADE_HOOKUP_OBJECT (window1, buttonConfirmer, "buttonConfirmer");
  GLADE_HOOKUP_OBJECT (window1, buttonValider, "buttonValider");
  GLADE_HOOKUP_OBJECT (window1, labelSortie, "labelSortie");

  return window1;
}

