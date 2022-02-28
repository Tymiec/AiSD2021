#include <iostream>
#include "queue.h"

using namespace std;

void test1()
{
    Queue <int> a;
    Queue <int> b;
    a.push(3);
    a.push(4);
    b.push(1);
    b.push(2);
    a = b;
    cout<<"Otrzymane: \n";
    a.display();
    cout<<"Oczekiwane: \n";
    cout<<"1 2 \n \n";
}

void test2()
{
    Queue <int> a;
    a.push(2);
    a.push(8);
    a.push(3);
    a.push(9);
    a.push(1);
    int x = a.pop();
    cout<<"Otrzymane: \n"<<x<<endl;
    cout<<"Oczekiwane: \n";
    cout<<"2 \n \n";
}
void test3()
{
    Queue <int> a;
    a.push(2);
    a.push(1);
    Queue <int> b(a);
    b.push(3);
    b.push(7);
    cout<<"Otrzymane: \n";
    a.display();
    b.display();
    cout<<"Oczekiwane: \n";
    cout<<"2 1 \n";
    cout<<"2 1 3 7 \n \n";
}

void test4()
{
    Queue <char> a;
    a.push('e');
    a.push('r');
    a.push('r');
    a.push('o');
    a.clear();
    a.push('T');
    a.push('r');
    a.push('B');
    cout<<"Otrzymane: \n"<<a.front()<<" "<<a.back()<<endl;
    cout<<"Oczekiwane: \n";
    cout<<"T B \n \n";
}

void test5()
{
    Queue <int> a;
    a.push(2);
    a.push(1);
    a.push(5);
    a.push(7);
    a.reverse();
    cout<<"Otrzymane: \n";
    a.display();
    cout<<"Oczekiwane: \n";
    cout<<"7 5 1 2 \n \n";
}



int main()
{
    test1();
    test2();
    test3();
    test4();
    test5();
    return 0;
}