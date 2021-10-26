$ ls                # zawartość katalogu z projektem
atrapa.cpp  atrapa.h  main.cpp  Makefile

# Zależności między plikami:
# atrapa.cpp zawiera #include "atrapa.h"
# main.cpp zawiera #include "atrapa.h"

$ make              # kompilacja
g++ -Wall -std=c++11 -c main.cpp -o main.o
g++ -Wall -std=c++11 -c atrapa.cpp -o atrapa.o
g++ -Wall -std=c++11  main.o atrapa.o -o main.out
$ make clean        # czyszczenie po kompilacji
rm -f main.out *.o core
# Makefile
# Kompilator g++.
CC = g++
# Mozliwe dodatkowe zmienne
# LIBS = -ll -lm
LIBS =
CFLAGS = -Wall -std=c++11
# Pliki obiektowe - powstaja z plikow *.cpp.
OBJECTS = main.o atrapa.o
# Pliki naglowkowe - sa wlaczane do plikow *.cpp.
HFILES = atrapa.h
# Koncowy plik wykonywalny.
TARGET = main.out

# Definicja domyslnej reguly wzorcowej.
# $< oznacza nazwe pliku pierwszej zaleznosci reguly.
# $@ oznacza nazwe pliku celu w regule.
# Wszystkie pliki obiektowe zaleza od wszystkich plikow naglowkowych.
%.o : %.cpp $(HFILES) Makefile
	$(CC) $(CFLAGS) -c $< -o $@

$(TARGET) : $(OBJECTS)
	$(CC) $(CFLAGS) $(LIBS) $(OBJECTS) -o $(TARGET)

# Okreslenie celow sztucznych.
.PHONY : clean

clean :
	$(RM) $(TARGET) *.o core