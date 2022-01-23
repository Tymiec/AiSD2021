#include <iostream>
#include "singlelist.h"

using namespace std;

void test1()
{
    SingleList <int> a;
    a.push_front(2);
    a.push_front(1);
    SingleList <int> b(a);
    b.push_back(3);
    cout<<"Wynik: "<<endl;
    a.display();
    b.display();
    cout<<"Oczekiwany:"<<endl<<"1 2"<<endl<<"1 2 3"<<endl<<endl;
}

void test2()
{
    SingleList <int> a;
    a.push_front(2);
    a.push_front(4);
    a.push_front(4);
    a.push_front(4);
    a.push_back(6);
    a.push_back(5);
    a.pop_back();
    cout<<"Wynik: "<<endl;
    cout<<a.size()<<endl;
    cout<<"Oczekiwany:"<<endl<<"5"<<endl<<endl;
}

void test3()
{
    SingleList <int> a;
    SingleList <int> b;
    a.push_back(3);
    a.push_back(5);
    a.push_front(9);
    b.push_back(7);
    b.push_back(1);
    b.push_front(2);
    b = a;
    cout<<"Wynik: "<<endl;
    b.display();
    cout<<"Oczekiwany:"<<endl<<"9 3 5"<<endl<<endl;
}



void test4()
{
    SingleList <char> a;
    a.push_front('error1');
    a.push_front('error2');
    a.push_back('error3');
    a.push_back('error4');
    a.clear();
    a.push_back('error5');
    a.push_front('T');
    a.push_back('B');
    cout<<"Wynik: "<<endl;
    cout<<a.front()<<" "<<a.back()<<endl;
    cout<<"Oczekiwany:"<<endl<<"T B"<<endl<<endl;
}
void test5()
{
    SingleList <int> a;
    a.push_back(4);
    a.push_front(2);
    a.push_front(1);
    a.push_back(5);
    a.reverse();
    a.push_front(3);
    cout<<"Wynik: "<<endl;
    a.display();
    cout<<"Oczekiwany:"<<endl<<"3 5 4 2 1"<<endl<<endl;
}


int main()
{
    cout<<endl;
    test1();
    test2();
    test3();
    test4();
    test5();
    return 0;
}