/*
* per compilarla usare la linea di comando:
* g++ carica_immagine.cc -o carica_immagine `pkg-config --cflags --libs gtk+-2.0`
*/

#include <iostream>
#include <gtk/gtk.h>
#include "gui.h"
using namespace std;

GtkWidget *window;

int main(int argc, char** argv)
{
	//int valorespin1,valorespin2;
	gtk_init (&argc, &argv);
	gui();
	/*while(true)
	{
		valorespin1=ret(1);
		valorespin2=ret(2);
		richiama la funzione;
	}*/
	cout<<ret(1);
    return 0;
}
