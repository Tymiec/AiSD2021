#include <iostream>
#include <unistd.h>
#include "doublelist.h"

using namespace std;



void test1()
{
    DoubleList <int> x;

    x.push_back(1);
    x.push_back(4);

    DoubleList <int> y(x);

    y.pop_front();
    y.push_back(6);

    cout<<"Wynik: "<<endl;
    y.display();
    cout<<"Oczekiwany:"<<endl<<"4 6"<<endl<<endl;
}

void test2()
{
    DoubleList <int> x;
    x.push_back(6);
    x.push_back(10);

    DoubleList <int> y;
    y = x;
    x.clear();

    cout<<"Wynik: "<<endl;
    x.display();
    y.display();
    cout<<"Oczekiwany:"<<endl<<"6 10"<<endl<<endl;
}

void test3()
{
    DoubleList <int> x;
    x.push_back(6);
    x.push_back(5);
    x.push_front(4);
    x.push_back(2);

    x.pop_front();
    x.pop_back();
    x.pop_back();
    x.pop_front();

    cout<<"Wynik: "<<endl;
    cout<<x.size()<<endl;
    cout<<"Oczekiwany:"<<endl<<"0"<<endl<<endl;
}



void test4()
{
    DoubleList <int> x;
    x.push_front(5);
    x.push_back(7);    
    x.push_front(9);    
    x.push_back(3);

    cout<<"Wynik: "<<endl;
    x.display();
    cout<<"Oczekiwany:"<<endl<<"9 5 7 3"<<endl<<endl;
}

int main()
{
    cout<<endl;
    test1();
    test2();
    test3();
    test4();
    return 0;
}