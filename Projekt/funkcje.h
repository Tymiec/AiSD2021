#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <istream>
#include <sstream>
#include <iomanip>
#include <vector>

using namespace std;

struct Book 
{
    int id;
    string name;
    int year;
    string author;
};


vector<Book> books;

void OpenFile()
{
    string line;
    ifstream myfile("baza.txt");
    if (myfile.is_open())
    {
        while (getline(myfile, line))
        {
            stringstream linestream(line);
            
            Book book;
            string bookID;
            string bookYear;
            
            getline(linestream, bookID, ';');
            book.id = stoi(bookID);
            getline(linestream, book.name, ';');
            getline(linestream, bookYear, ';');
            book.year = stoi(bookYear);
            getline(linestream, book.author, ';');
            
            books.push_back(book);
            
        }
        
    } else { cout<<"Plik jest juz gdzies otwarty, zamknij go i uruchom ponownie program"; }
}

void Dodaj()
{
    cout<<"\033[2J\033[1;1H";
    int bookID;
    int bookYear;
    
    Book book;
    
    while (true)
    {
        cout << "Podaj ID ksiazki: ";
        cin >> bookID;
        while (cin.fail())
        {
            cin.clear();
            cin.ignore();
            cout<<"ID powinno byc liczba!"<<endl;
            cin >> bookID;
        }
        bool found = false;
        for (unsigned int i = 0; i < books.size(); i++)
        {
            if (books[i].id == bookID)
                found = true;
        }
        
        if (found) {
            cout << "Podane ID juz istnieje w bazie!" << endl;
        } else {
            book.id = bookID;
            break;
        }
    }
    cout<<"Podaj tytul ksiazki: ";
    cin.ignore();
    getline(cin, book.name);
    cout<<"Podaj rok wydania ksiazki: ";
    cin >> bookYear;
    while (cin.fail())
    {
        cin.clear();
        cin.ignore();
        cout<<"Rok powinnien byc liczba!"<<endl;
        cin >> bookYear;
    }
    book.year = bookYear;
    cout<<"Podaj autora/autorow ksiazki: ";
    cin.ignore();
    getline(cin, book.author);
    
    books.push_back(book);
    
}

void Wypisz()
{
    cout<<"\033[2J\033[1;1H";
    int max_dlugosc_counter = 3;//No. = 3 na sztywno zapisujemy to ile zajmuje nam napis nad menu ew jaki format chcemy zeby byl minimalny
    int max_dlugosc_id = 2;     //ID = 2
    int max_dlugosc_year = 3;   //ROK = 3
    int max_dlugosc_name = 5;   //TYTUL = 5
    int max_dlugosc_author = 5; //AUTOR = 5
    
    int counter = 0;

    for (unsigned int i = 0; i < books.size(); i++) // petla ktora liczy nam dlugosci wartosci przed kazdym wypisaniem aby ładnie dopasować tabelkę
    {
        //liczymy dlugosc ID
        int temp_id = books[i].id;
        int len1 = 1;

        if (temp_id > 0) 
        {
            for (len1 = 0; temp_id > 0; len1++) 
            {
                temp_id = temp_id / 10;
            }
        }
        if (len1 > max_dlugosc_id) { max_dlugosc_id = len1; }   //cout<<max_dlugosc_id<<endl; //odkomentowac w razie niepoprawnego dzialania programu
        

        //liczymy dlugosc najdluzszego roku, moznaby ograniczyc wpisywanie roku do tylko 4 cyfr ale po co
        int temp_year = books[i].year;
        int len2 = 1;

        if (temp_year > 0) 
        {
            for (len2 = 0; temp_year > 0; len2++) 
            {
                temp_year = temp_year / 10;
            }
        }
        if (len2 > max_dlugosc_year) { max_dlugosc_year = len2; } //cout<<max_dlugosc_year<<endl; //odkomentowac w razie niepoprawnego dzialania programu

        //liczymy dlugosc najdluzszego tytulu
        string temp3;
        int temp_name;

        temp3 = books[i].name;
        temp_name = temp3.length();
        if (temp_name > max_dlugosc_name) { max_dlugosc_name = temp_name; } //cout<<max_dlugosc_name<<endl; //odkomentowac w razie niepoprawnego dzialania programu

        //liczymy dlugosc najdluzszego autora
        string temp4;
        int temp_author;

        temp4 = books[i].author;
        temp_author= temp4.length();
        if (temp_author > max_dlugosc_author) { max_dlugosc_author = temp_author; } //cout<<max_dlugosc_author<<endl; //odkomentowac w razie niepoprawnego dzialania programu

        //liczymy dlugosc najdluzszego licznika
        int temp_counter = counter; //teoretycznie możnaby zamiast countera użyc books_size ale przeszkadzałoby to w wypisywaniu przy wyszukiwaniu
        int len5 = 1;

        if (temp_counter > 0) 
        {
            for (len5 = 0; temp_counter > 0; len5++) 
            {
                temp_counter = temp_counter / 10;
            }
        }
        if (len5 > max_dlugosc_counter) { max_dlugosc_counter = len5; }     //cout<<max_dlugosc_counter<<endl; //odkomentowac w razie niepoprawnego dzialania programu
        
    }
    
    int a = 0; //zmienna estetyczna
    int temp_suma = (max_dlugosc_author + max_dlugosc_id + max_dlugosc_name + max_dlugosc_year + 9 + (5*a)); //tutaj dopisujemy ile bedziemy na sztywno mieli 9 wpisywanych recznie + 5 dla estetyki
    if (temp_suma < 80)
    {
        cout<<setfill('=')<<setw(temp_suma)<<"=";
        cout<<endl;
        cout<<"|";
        cout<<right<<setfill(' ')<<setw(max_dlugosc_counter + a)<<"No."<<"|";    // +1 dodajemy dla estetyki żeby zamiast |ROK| mieć | ROK|
        cout<<right<<setfill(' ')<<setw(max_dlugosc_id + a)<<"ID"<<"|";
        cout<<left<<setfill(' ')<<setw(max_dlugosc_name + a)<<"TYTUL"<<"|";
        cout<<left<<setfill(' ')<<setw(max_dlugosc_author + a)<<"AUTOR"<<"|";
        cout<<right<<setfill(' ')<<setw(max_dlugosc_year + a)<<"ROK"<<"|";
        cout<<endl;

        for (unsigned int i = 0; i < books.size(); i++)
        {
        counter++;
        cout<<"|";
        cout<<right<<setfill(' ')<<setw(max_dlugosc_counter + a)<<counter<<"|";
        cout<<right<<setfill(' ')<<setw(max_dlugosc_id + a)<<books[i].id<<"|";
        cout<<left<<setfill(' ')<<setw(max_dlugosc_name + a)<<books[i].name<<"|";
        cout<<left<<setfill(' ')<<setw(max_dlugosc_author + a)<<books[i].author<<"|";
        cout<<right<<setfill(' ')<<setw(max_dlugosc_year + a)<<books[i].year<<"|";
        cout<<endl;
        }
    } else {
        cout<<setfill('=')<<setw(temp_suma - 1 - max_dlugosc_author)<<"=";
        cout<<endl;
        cout<<"|";
        cout<<right<<setfill(' ')<<setw(max_dlugosc_counter + a)<<"No."<<"|";    // +1 dodajemy dla estetyki żeby zamiast |ROK| mieć | ROK|
        cout<<right<<setfill(' ')<<setw(max_dlugosc_id + a)<<"ID"<<"|";
        cout<<left<<setfill(' ')<<setw(max_dlugosc_name + a)<<"TYTUL"<<"|";
        cout<<right<<setfill(' ')<<setw(max_dlugosc_year + a)<<"ROK"<<"|";
        cout<<endl;

        for (unsigned int i = 0; i < books.size(); i++)
    {
        
        counter++;
        cout<<"|";
        cout<<right<<setfill(' ')<<setw(max_dlugosc_counter + a)<<counter<<"|";
        cout<<right<<setfill(' ')<<setw(max_dlugosc_id + a)<<books[i].id<<"|";
        cout<<left<<setfill(' ')<<setw(max_dlugosc_name + a)<<books[i].name<<"|";
        cout<<right<<setfill(' ')<<setw(max_dlugosc_year + a)<<books[i].year<<"|";
        cout<<endl;
    }
    }

    if (counter == 0 ) 
    { 
        cout<<"Baza jest pusta! \n"; 
    }

    if (temp_suma < 80)
    {
        cout<<setfill('=')<<setw(temp_suma)<<"="<<endl;
    } else { 
        cout<<setfill('=')<<setw(temp_suma - 1 - max_dlugosc_author)<<"="<<endl;

    }
}

bool Sprawdz(int wybor, Book& book, string search) {
    switch (wybor)
    {
    case 1:
        if (book.id == stoi(search))
            return true;
        else
            return false;
        break;
    case 2:
        if (book.name == search)
            return true;
        else
            return false;
        break;
    case 3: 
        if (book.year == stoi(search))
            return true;
        else
            return false;
        break;
    case 4:
        if (book.author == search)
            return true;
        else
            return false;
        break;
    default:
        return false;
    }
}

void Wyszukaj() 
{
    cout<<"\033[2J\033[1;1H";

    int temp_suma = 0;   
    int wybor = 5;
    string search;
    
    do {
        
        cout<<"MENU WYSZUKIWANIA: \n";
        cout<<"1 Wyszukaj po ID \n";
        cout<<"2 Wyszukaj po tytule \n";
        cout<<"3 Wyszukaj po roku wydania \n";
        cout<<"4 Wyszukaj po autorze \n";
        cout<<"Wpisz numer metody wyszukiwania: "; 
        cin.ignore();
        cin>>wybor; 
        while (cin.fail())
        {
            cin.clear();
            cin.ignore();
            cout<<"ID powinno byc liczba!"<<endl;
            cin>>wybor;
        }
        cout<<endl;
        
    } while (wybor > 4);
    
    cin.ignore();
    cout<<"Wpisz wyszukiwana fraze: "; getline(cin, search); cout<<endl;
    
    vector<Book*> results;
    
    int max_dlugosc_counter = 3;//No. = 3 na sztywno zapisujemy to ile zajmuje nam napis nad menu ew jaki format chcemy zeby byl minimalny
    int max_dlugosc_id = 2;     //ID = 2
    int max_dlugosc_year = 3;   //ROK = 3
    int max_dlugosc_name = 5;   //TYTUL = 5
    int max_dlugosc_author = 5; //AUTOR = 5
    int counter = 0;
    
    for (unsigned int i = 0; i < books.size(); i++)
    {
        if (Sprawdz(wybor, books[i], search))
        {
            results.push_back(&books[i]);
        }
    }
    
    if (results.size() > 0)
    {
        
        for (unsigned int i = 0; i < results.size(); i++)
        {
            
            //liczymy dlugosc ID
            int temp_id = results[i]->id;
            int len1 = 1;

            if (temp_id > 0) 
            {
                for (len1 = 0; temp_id > 0; len1++) 
                {
                    temp_id = temp_id / 10;
                }
            }
            if (len1 > max_dlugosc_id) { max_dlugosc_id = len1; }   //cout<<max_dlugosc_id<<endl; //odkomentowac w razie niepoprawnego dzialania programu
            

            //liczymy dlugosc najdluzszego roku, moznaby ograniczyc wpisywanie roku do tylko 4 cyfr ale po co
            int temp_year = results[i]->year;
            int len2 = 1;

            if (temp_year > 0) 
            {
                for (len2 = 0; temp_year > 0; len2++) 
                {
                    temp_year = temp_year / 10;
                }
            }
            if (len2 > max_dlugosc_year) { max_dlugosc_year = len2; } //cout<<max_dlugosc_year<<endl; //odkomentowac w razie niepoprawnego dzialania programu

            //liczymy dlugosc najdluzszego tytulu
            string temp3;
            int temp_name;

            temp3 = results[i]->name;
            temp_name = temp3.length();
            if (temp_name > max_dlugosc_name) { max_dlugosc_name = temp_name; } //cout<<max_dlugosc_name<<endl; //odkomentowac w razie niepoprawnego dzialania programu

            //liczymy dlugosc najdluzszego autora
            string temp4;
            int temp_author;

            temp4 = results[i]->author;
            temp_author= temp4.length();
            if (temp_author > max_dlugosc_author) { max_dlugosc_author = temp_author; } //cout<<max_dlugosc_author<<endl; //odkomentowac w razie niepoprawnego dzialania programu

            //liczymy dlugosc najdluzszego licznika
            int temp_counter = counter; //teoretycznie możnaby zamiast countera użyc books_size ale przeszkadzałoby to w wypisywaniu przy wyszukiwaniu
            int len5 = 1;

            if (temp_counter > 0) 
            {
                for (len5 = 0; temp_counter > 0; len5++) 
                {
                    temp_counter = temp_counter / 10;
                }
            }
            if (len5 > max_dlugosc_counter) { max_dlugosc_counter = len5; }     //cout<<max_dlugosc_counter<<endl; //odkomentowac w razie niepoprawnego dzialania programu
            
        }
        
        int a = 0; //zmienna estetyczna
        temp_suma = (max_dlugosc_author + max_dlugosc_id + max_dlugosc_name + max_dlugosc_year + 9 + (5*a)); //tutaj dopisujemy ile bedziemy na sztywno mieli 9 wpisywanych recznie + 5 dla estetyki
        if (temp_suma < 80)
        {
            cout<<setfill('=')<<setw(temp_suma)<<"=";
            cout<<endl;
            cout<<"|";
            cout<<right<<setfill(' ')<<setw(max_dlugosc_counter + a)<<"No."<<"|";    // +1 dodajemy dla estetyki żeby zamiast |ROK| mieć | ROK|
            cout<<right<<setfill(' ')<<setw(max_dlugosc_id + a)<<"ID"<<"|";
            cout<<left<<setfill(' ')<<setw(max_dlugosc_name + a)<<"TYTUL"<<"|";
            cout<<left<<setfill(' ')<<setw(max_dlugosc_author + a)<<"AUTOR"<<"|";
            cout<<right<<setfill(' ')<<setw(max_dlugosc_year + a)<<"ROK"<<"|";
            cout<<endl;

            for (unsigned int i = 0; i < results.size(); i++)
                {
                    counter++;
                    cout<<"|";
                    cout<<right<<setfill(' ')<<setw(max_dlugosc_counter + a)<<counter<<"|";
                    cout<<right<<setfill(' ')<<setw(max_dlugosc_id + a)<<results[i]->id<<"|";
                    cout<<left<<setfill(' ')<<setw(max_dlugosc_name + a)<<results[i]->name<<"|";
                    cout<<left<<setfill(' ')<<setw(max_dlugosc_author + a)<<results[i]->author<<"|";
                    cout<<right<<setfill(' ')<<setw(max_dlugosc_year + a)<<results[i]->year<<"|";
                    cout<<endl;
                }
            cout<<setfill('=')<<setw(temp_suma)<<"="<<endl;
        } else { 
            cout<<setfill('=')<<setw(temp_suma - 1 - max_dlugosc_author)<<"=";
            cout<<endl;
            cout<<"|";
            cout<<right<<setfill(' ')<<setw(max_dlugosc_counter + a)<<"No."<<"|";    // +a dodajemy dla estetyki żeby zamiast |ROK| mieć | ROK| lub inne
            cout<<right<<setfill(' ')<<setw(max_dlugosc_id + a)<<"ID"<<"|";
            cout<<left<<setfill(' ')<<setw(max_dlugosc_name + a)<<"TYTUL"<<"|";
            cout<<right<<setfill(' ')<<setw(max_dlugosc_year + a)<<"ROK"<<"|";
            cout<<endl;

            for (unsigned int i = 0; i < results.size(); i++)
                {
                    counter++;
                    cout<<"|";
                    cout<<right<<setfill(' ')<<setw(max_dlugosc_counter + a)<<counter<<"|";
                    cout<<right<<setfill(' ')<<setw(max_dlugosc_id + a)<<results[i]->id<<"|";
                    cout<<left<<setfill(' ')<<setw(max_dlugosc_name + a)<<results[i]->name<<"|";
                    cout<<right<<setfill(' ')<<setw(max_dlugosc_year + a)<<results[i]->year<<"|";
                    cout<<endl;
                }
            cout<<setfill('=')<<setw(temp_suma - 1 - max_dlugosc_author)<<"="<<endl;
        }
    }

    else
    { 
        cout<<"     Baza jest pusta! \n";
    }
}

void Edytuj(int search)

{
    string bookname;
    int bookyear;
    string bookauthor;

    int counter = 0;

    for (unsigned int i = 0; i < books.size(); i++)
    {
        if (books[i].id == search)
        {
        counter++;
        
        cout<<"Jesli nie chcesz zmieniac danych wpisz -"<<endl;
        
        cout<<"Tytul ksiazki. ["<<books[i].name<<"] ";
        cin >> bookname;
        if (bookname != "-") 
        {
            books[i].name = bookname;
        }
        
        cout<<"Jesli nie chcesz zmieniac danych wpisz 0"<<endl;
        
        cout<<"Rok wydania. ["<<books[i].year<<"] "; 
        cin >> bookyear;
        if (bookyear != 0) 
        {
            books[i].year = bookyear;
        } else {
            while (cin.fail())
            {
                cin.clear();
                cin.ignore();
                cout<<"Rok powinnen byc liczba!"<<endl;
                cin >> bookyear;
                if (bookyear != 0) 
                {
                    books[i].year = bookyear;
                }
            }
        }
        cout<<"Jesli nie chcesz zmieniac danych wpisz -"<<endl;

        cout<<"Autor ksiazki. ["<<books[i].author<<"] "; 
        cin >> bookauthor;
        if (bookauthor != "-") 
        {
            books[i].author = bookauthor;
        }

        cout<<"Dane ksiazki zostaly zaktualizowane! \n";
        return;
        }
    }
    cout<<"Nie znaleziono ksiazki o podanym id!"<<endl;
}

void Usun(int search)
{
    
    for (unsigned int i = 0; i < books.size(); i++)
    {
        if (books[i].id == search)
        {
            books.erase(books.begin() + i);
            cout<<"\033[2J\033[1;1H";
            cout<<"Ksiazka zostala usunieta z bazy \n";  
            return;
        }
    }
    cout<<"Nie znaleziono ksiazki o tym ID \n"; 
}

void SaveToFile()
{
    ofstream myfile;
    myfile.open("baza.txt");

    for (unsigned int i = 0; i < books.size(); i++)
    {
        myfile<<books[i].id<<";"<<books[i].name<<";"<<books[i].year<<";"<<books[i].author<<endl;
    }
}