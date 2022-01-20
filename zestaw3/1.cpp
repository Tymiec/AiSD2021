#include <iostream>
#include "arraylist.h"

using namespace std;
void test_1()
{
    ArrayList <int> a(5);
    a.push_back(8);
    a.push_back(-13);
    a.push_back(46);
    a.push_back(4);
    a.push_back(5);
    a.push_back(6);
    a.sort();
    a.reverse();
    cout<<"Wynik: "<<endl<<a<<endl;
    cout<<"Oczekiwany:"<<endl<<"46 8 5 4 -13"<<endl;
    cout<<endl;
}

void test_2()
{
    ArrayList <int> a;
    a.push_back(4);
    a.push_front(1);
    a.push_back(5);
    a.push_front(3);
    a.push_front(9);
    cout<<"Wynik: "<<endl<<a<<endl;
    cout<<"Oczekiwany:"<<endl<<"9 3 1 4 5"<<endl;
    cout<<endl;

}

void test_3()
{
    ArrayList <string> a;
    ArrayList <string> b;
    a.push_back("blad1");
    a.push_back("blad2");
    a.push_back("blad3");
    b.push_back("Mr");
    b.push_back("T");
    a = b;
    cout<<"Wynik: "<<endl<<a<<endl;
    cout<<"Oczekiwany:"<<endl<<"Mr T"<<endl;
    cout<<endl;
}


void test_4()
{
    ArrayList <char> a;
    a.push_back('x');
    a.push_back('y');
    a.push_front('z');
    a.clear();
    a.push_back('l');
    a.push_back('a');
    a.push_front('o');
    a.push_front('p');
    a.push_back('n');
    a.push_back('d');
    cout<<"Wynik: "<<endl<<a<<endl;
    cout<<"Oczekiwany:"<<endl<<"p o l a n d"<<endl;
    cout<<endl;
}

void test_5()
{
    ArrayList <int> a;
    a.push_back(304);
    a.push_back(13);
    a.push_back(2000);
    a.push_front(11);
    a.insert(1,12);
    a.erase(2);
    cout<<"Wynik: "<<endl<<a<<endl;
    cout<<"Oczekiwany:"<<endl<<"11 12 13 2000"<<endl;
    cout<<endl;
}


// opisac ktoe testy sluza do czego
int main()
{
    ArrayList <int> a(5);
    test_1();
    test_2();
    test_3();
    test_4();
    test_5();
    return 0;
}

// poprzestawiać kolejność testów, zmienić zawartość
