#Makefile programma project

CXXFLAGS += -Wall `pkg-config --cflags --libs gtk+-2.0`

Oggetti = project.o gui.o

project: Dipendenze $(Oggetti)
	g++ -o project $(Oggetti) `pkg-config --cflags --libs gtk+-2.0`
	
Dipendenze: 
	g++ -MM project.cc gui.cc > Dipendenze

-include Dipendenze
	
.PHONY: clean cleanall 

clean:
	rm $(Oggetti) Dipendenze
	
cleanall:
	rm $(Oggetti) project Dipendenze
