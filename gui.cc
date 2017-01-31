#include <iostream>
#include <cstdlib>
#include <gtk/gtk.h>
#include "gui.h"

using namespace std;
//spin buttons
	GtkWidget *spin1=gtk_spin_button_new_with_range (0,5,1);
    GtkWidget *spin2=gtk_spin_button_new_with_range (0,8,1);


void fun (GtkWidget *pulsante, GtkWidget *image)
{
	extern GtkWidget *window;
	//selettore le immagini
	GtkFileFilter *estensione=gtk_file_filter_new();
	gtk_file_filter_set_name(estensione, "Immagini");
	gtk_file_filter_add_pattern(estensione,"*.jpg");
	
    GtkWidget *dialog = gtk_file_chooser_dialog_new ("Open File",GTK_WINDOW(window),GTK_FILE_CHOOSER_ACTION_OPEN,
				      GTK_STOCK_CANCEL, GTK_RESPONSE_CANCEL,GTK_STOCK_OPEN, GTK_RESPONSE_ACCEPT, NULL);
	
	gtk_file_chooser_add_filter(GTK_FILE_CHOOSER(dialog), estensione);
	
	if (gtk_dialog_run (GTK_DIALOG (dialog)) == GTK_RESPONSE_ACCEPT)
	{
		char *filename;
		filename = gtk_file_chooser_get_filename (GTK_FILE_CHOOSER (dialog));
		gtk_image_set_from_file (GTK_IMAGE(image), filename);
		g_free (filename);
	}
	
	gtk_widget_destroy (dialog);
}
void gui(void)
{
    //finestra
    extern GtkWidget *window;
    window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    gtk_window_set_default_size(GTK_WINDOW(window),600,400);
    gtk_window_set_title(GTK_WINDOW(window), "Guest");
    
    GtkWidget *box1 = gtk_vbox_new(FALSE,5);
    
    //box 2
    GtkWidget *box2 = gtk_hbox_new(FALSE,5);
	 //pulsante
     GtkWidget *pulsante = gtk_button_new_with_label ("Image Loader");
     //label
     GtkWidget *label1=gtk_label_new("Nodo di partenza");
     GtkWidget *label2=gtk_label_new("Nodo di arrivo");
    //barra menu
    GtkWidget *menubar = gtk_menu_bar_new();
     GtkWidget *child1 = gtk_menu_item_new_with_mnemonic("_File");
     GtkWidget *menu1 = gtk_menu_new();
      GtkWidget *childm1 = gtk_menu_item_new_with_mnemonic("_Apri");
      GtkWidget *childm2 = gtk_menu_item_new_with_mnemonic("_Calcola");
      GtkWidget *childm3 = gtk_menu_item_new_with_mnemonic("_Esci");
     GtkWidget *child2 = gtk_menu_item_new_with_mnemonic("_Aiuto");
     GtkWidget *menu2 = gtk_menu_new();
      GtkWidget *childm4 = gtk_menu_item_new_with_mnemonic("_Cos'e`?");
    
    GtkWidget *image = gtk_image_new();
    GtkWidget *statbar = gtk_statusbar_new();

    //box e figli
    gtk_container_add (GTK_CONTAINER (window), box1);
     gtk_box_pack_start(GTK_BOX(box1), menubar, FALSE, TRUE, 0);
    gtk_window_set_title(GTK_WINDOW(window), "Guest");
      gtk_menu_bar_append(GTK_MENU_BAR(menubar),child1);
      gtk_menu_item_set_submenu(GTK_MENU_ITEM(child1),menu1);
       gtk_menu_shell_append (GTK_MENU_SHELL (menu1), childm1);
       gtk_menu_shell_append (GTK_MENU_SHELL (menu1), childm2);
       gtk_menu_shell_append (GTK_MENU_SHELL (menu1), childm3);
      gtk_menu_bar_append(GTK_MENU_BAR(menubar),child2);
      gtk_menu_item_set_submenu(GTK_MENU_ITEM(child2),menu2); 
       gtk_menu_shell_append (GTK_MENU_SHELL (menu2), childm4);
       
     //disposizione
     gtk_box_pack_start(GTK_BOX(box1), statbar, FALSE, FALSE, 0);
     gtk_box_pack_start(GTK_BOX(box1), image, TRUE, TRUE, 0);
     gtk_box_pack_start(GTK_BOX(box1), box2, FALSE, FALSE, 0);
      gtk_box_pack_start(GTK_BOX(box2), label1, FALSE, FALSE, 0);
      gtk_box_pack_start(GTK_BOX(box2), GTK_WIDGET(spin1), TRUE, TRUE, 0);
      gtk_box_pack_start(GTK_BOX(box2), pulsante, FALSE, FALSE, 0);
      gtk_box_pack_start(GTK_BOX(box2), label2, FALSE, FALSE, 0);
      gtk_box_pack_start(GTK_BOX(box2), GTK_WIDGET(spin2), TRUE, TRUE, 0);
    
    
    gtk_widget_show_all  (window);	//gtk_widget_show_all permette di fare lo show di tutti i figli di "window"

    //segnali
    g_signal_connect (pulsante, "clicked", G_CALLBACK (fun), image);
    g_signal_connect (childm1, "activate", G_CALLBACK (fun), image);
    if(g_signal_connect (window, "delete-event",G_CALLBACK (gtk_main_quit), NULL))
      cout<<"Gui haven't any problem"<<endl;
    else
      cerr<<"We have got a problem"<<endl;
    g_signal_connect (childm3, "activate",G_CALLBACK (gtk_main_quit), NULL);
    
    gtk_main ();
}
int ret(int button)
{
	if(button==1)
		return gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spin1));
	if(button==2)
		return gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spin2));
	else
	{
		cerr<<"errore: spin button non esistente"<<endl;
		exit(1);
	}
}
