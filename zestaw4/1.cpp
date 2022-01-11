#include <iostream>
#include "singlelist.h"

using namespace std;

void test1()
{
    SingleList <int> a;
    a.push_back(2);
    a.push_front(1);
    a.push_front(5);
    a.push_back(7);
    a.reverse();
    a.display();
    cout<<"Expected : 7 2 1 5"<<endl;
}
void test2()
{
    SingleList <int> a;
    SingleList <int> b;
    a.push_back(3);
    a.push_back(5);
    b.push_back(7);
    b.push_back(1);
    a = b;
    a.display();
    cout<<"Expected : 7 1"<<endl;
}
void test3()
{
    SingleList <int> a;
    a.push_back(4);
    a.push_back(6);
    a.push_front(7);
    a.push_front(1);
    a.pop_back();
    cout<<a.size()<<endl;
    cout<<"Expected : 3"<<endl;
}
void test4()
{
    SingleList <char> a;
    a.push_front('3');
    a.push_front('x');
    a.push_back('d');
    a.push_back('O');
    a.clear();
    a.push_back('e');
    a.push_back('s');
    a.push_front('B');
    cout<<a.front()<<" "<<a.back()<<endl;
    cout<<"Expected : B s"<<endl;
}
void test5()
{
    SingleList <int> a;
    a.push_back(7);
    a.push_back(0);
    SingleList <int> b(a);
    b.push_back(5);
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