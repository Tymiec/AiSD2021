#include <iostream>
#include "queue.h"

using namespace std;

void test1()
{
    Queue <int> a;
    a.push(2);
    a.push(1);
    a.push(5);
    a.push(7);
    a.reverse();
    a.display();
    cout<<"Expected : 7 5 1 2"<<endl;
}
void test2()
{
    Queue <int> a;
    Queue <int> b;
    a.push(3);
    a.push(5);
    b.push(7);
    b.push(1);
    a = b;
    a.display();
    cout<<"Expected : 7 1"<<endl;
}
void test3()
{
    Queue <int> a;
    a.push(4);
    a.push(6);
    a.push(7);
    a.push(1);
    int x = a.pop();
    cout<<x<<endl;
    cout<<"Expected : 4"<<endl;
}
void test4()
{
    Queue <char> a;
    a.push('3');
    a.push('x');
    a.push('d');
    a.push('O');
    a.clear();
    a.push('e');
    a.push('s');
    a.push('B');
    cout<<a.front()<<" "<<a.back()<<endl;
    cout<<"Expected : e B"<<endl;
}
void test5()
{
    Queue <int> a;
    a.push(7);
    a.push(0);
    Queue <int> b(a);
    b.push(5);
    a.display();
    b.display();
    cout<<"Expected : 7 0 \n7 0 5"<<endl;
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