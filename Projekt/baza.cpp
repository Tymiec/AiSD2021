#include <iostream>
#include <string>
#include <fstream>
#include <istream>
#include "funkcje.h"

using namespace std;

int main()
{
    int wybor;
    int bookID;
    cout<<"\033[2J\033[1;1H";
    OpenFile();
    
    do
    {

    cout<<"MENU: \n";
    cout<<"1 Dodaj ksiazke \n";
    cout<<"2 Wypisz ksiazki \n";
    cout<<"3 Wyszukaj ksiazke \n";
    cout<<"4 Zaktualizuj dane \n";
    cout<<"5 Usun ksiazke \n";
    cout<<"6 Wyjdz i zapisz \n"; 
    cout<<"Wpisz numer funkcji ktorej chcesz uzyc: "; cin>>wybor; cout<<endl;

    switch (wybor)
    {
    case 1: Dodaj();
        break;
    case 2: Wypisz();
        break;
    case 3: 
        Wyszukaj();
        break;
    case 4:
        cin.ignore();
        cout<<"Wyszukaj po ID: ";
        cin >> bookID;
        while (cin.fail())
        {
            cin.clear();
            cin.ignore();
            cout<<"ID powinno byc liczba"<<endl;
            cin >> bookID;
        }
        Edytuj(bookID);
        break;
    case 5:
        cin.ignore();
        cout<<"Usun ksiazke o ID: ";
        cin >> bookID;
        while (cin.fail())
        {
            cin.clear();
            cin.ignore();
            cout<<"ID powinno byc liczba"<<endl;
            cin >> bookID;
        }
        Usun(bookID);
        cin.ignore();

        break;
    case 6: wybor = 6;
        cout<<"Program zostanie zamkniety a baza danych zapisana \n";

        break;
    default:
            cout<<"Wpisana liczba nie odpowiada zadnej funkcji, wpisz liczbe od 1-6 \n";
        break;
    }
    } while (wybor != 6);

    SaveToFile();
    
    return 0;
}