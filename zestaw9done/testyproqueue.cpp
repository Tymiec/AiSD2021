#include <iostream>
#include "prioqueue.h"

using namespace std;



void test1()
{
    SingleList <int> a;
    a.push(3,7);
    a.push(1,2);
    a.push(2,4);
    int x;
    x = a.pop();
    cout<<x<<endl;
    cout<<a.top()<<endl;
    cout<<"Pierwszy test zakonczony"<<endl<<endl;
}

void test2()
{
    SingleList <int> a;
    a.push(5,6);
    a.push(1,2);
    a.push(2,4);
    a.display();
    cout<<"Test drugi zakonczony"<<endl<<endl;

}

void test3()
{
    SingleList <int> a;
    a.push(2,1);
    a.push(7,4);
    a.clear();
    a.push(5,2);
    a.push(8,8);
    a.display();
    cout<<"Test trzeci zakonczony"<<endl<<endl;
}

int main()
{
    SingleList<int>a;

    cout<<"Testy"<<endl;
    cout<<"_______________________"<<endl<<endl;
    test1();
    test2();
    test3();
    return 0;
}