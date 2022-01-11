#include <iostream>
#include "arraylist.h"

using namespace std;

void test1()
{
    ArrayList <int> a;
    a.push_back(3);
    a.push_front(1);
    a.push_back(7);
    a.push_front(2);
    a.push_front(0);
    cout<<"Result : "<<a<<endl;
    cout<<"Expected : 0 2 1 3 7"<<endl;
}

void test2()
{
    ArrayList <string> a;
    ArrayList <string> b;
    a.push_back("kota");
    a.push_back("czarnego");
    a.push_back("Mam");
    b.push_back("Mateusz");
    b.push_back("Gotowka");
    a = b;
    cout<<"Result : "<<a<<endl;
    cout<<"Expected : Mateusz Gotowka"<<endl;
}

void test3()
{
    ArrayList <int> a(5);
    a.push_back(8);
    a.push_back(-3);
    a.push_back(53);
    a.push_back(4);
    a.push_back(7);
    a.push_back(6);
    a.sort();
    a.reverse();
    cout<<"Result : "<<a<<endl;
    cout<<"Expected : 53 8 7 4 -3"<<endl;
}

void test4()
{
    ArrayList <int> a;
    a.push_back(34);
    a.push_back(12);
    a.push_back(7);
    a.push_front(68);
    a.insert(1,3);
    a.erase(2);
    cout<<"Result : "<<a<<endl;
    cout<<"Expected : 68 3 12 7"<<endl;
}

void test5()
{
    ArrayList <char> a;
    a.push_back('u');
    a.push_back('x');
    a.push_front('a');
    a.clear();
    a.push_back('o');
    a.push_back('r');
    a.push_front('c');
    a.push_back('d');
    cout<<"Result : "<<a<<endl;
    cout<<"Expected : c o r d"<<endl;
}

int main()
{
    ArrayList <int> a(5);
    test1();
    test2();
    test3();
    test4();
    test5();
    return 0;
}