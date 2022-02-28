# Baza danych

## Cel projektu

Celem projektu było stworzenie bazy danych książek posiadającej operacje:
 - Wstawiania
 - Usuwania 
 - Wyszukiwania
 - Wypisywania zawartości
 - Edycji ( zrobione dodatkowo )

## Ogólna struktura plików

Projekt zawiera pliki: 
 - Baza.cpp
 - Funkcje.h
 - Makefile
 - Baza.txt
 - Baza_dluga.txt
 - Baza_krotka.txt

Baza.cpp – zawiera main w którym wywołujemy funkcje zawarte w funkcje.h za pomocą switcha z którego użytkownik może wyjść wpisując 6 w konsoli o czym informuje go program.

Funkcje.h – zawiera wszystkie funkcje wykorzystywane w baza.cpp
Makefile – program kompilujemy wpisując Make all a potem ./baza.out

Baza.txt – domyślna baza zawierająca książki
Baza_dluga.txt – baza zawierająca długi tytuł który pokazuje jak baza dopasowuje się do długiego tytułu

Baza_krotka.txt – baza zawierająca krótkie wartości pokazująca jak wygląda baza gdy nie jest powiększana przez inne funkcje

Aby przetestować baza_krotka lub baza_dluga wystarczy zamknąć program, zmienić nazwę pliku baza.txt na tymczasowa a nazwę bazy którą chcemy przetestować zamienić na baza.txt

## Omówienie programu

Book przechowuje:
 - ID
 - Tytuł
 - Rok wydania
 - Autora/Autorów

OpenFile() odpowiada za otwieranie pliku baza.txt i załadowanie go do Book

Dodaj() odpowiada za dodawanie książek. Posiada zabezpieczenie przed wprowadzeniem tekstu jako ID lub rok

Wypisz() wypisuje tabele wszystkich książek, uwzględnia przy tym przed wypisaniem najdłuższy napis w danej kolumnie dodając jedną spację dla estetyki. W przypadku krótkich napisów mamy zabezpieczenie w postaci początkowych deklaracji

Wyszukaj() odpowiada za wyszukiwanie po ID, przeszukujemy po prostu całą bazę aż do momentu gdy szukane ID będzie takie samo jak znalezione ID, jeżeli przejdziemy przez całą bazę informujemy użytkownik iż podane przez niego ID nie znajduje się w bazie.

Do wypisywania wyszukiwania używamy głównie kodu z Wypisz() ale zamiast przechodzić po całej tablicy robimy to tylko dla znalezionego i.

Edytuj() odpowiada za edytowanie książki o wybranym ID, wyszukujemy ją tak jak w Wyszukaj() i pytamy użytkownika czy chce zmienić daną wartość, jeżeli tak to po prostu podmieniamy ją, jeżeli nie to przechodzimy dalej

Usun() odpowiada za usuwanie książki o wybranym ID, wyszukujemy ją tak jak w Wyszukaj(), „zasłaniamy ją” i zmniejszamy rozmiar i dzięki temu książka zostaje usunięta z bazy danych.

SaveToFile() zapisuje naszą bazę do pliku baza.txt


##### Zaktualizowano 01.03.2022