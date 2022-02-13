#include <iostream>
#include <vector>
#include <cassert>
#include <stdlib.h>

using namespace std;

bool isnumber(string input)
{
    bool dot = false;
    for(char &t : input)
    {
        if(t==46 && dot==false)
            dot=true;
        else if(t==46 && dot==true)
            return false;
        else if(t<48 || t>57)
            return false;
    }
    return true;
}

void push(double stack[],int &counter,double &x)
{
    stack[counter] = x;
    counter++;
}

double pop(double stack[],int &counter)
{
    double x = stack[counter-1];
    counter--;
    stack[counter] = 0;
    return x;
}

double onp (std::vector<string> input)
{
    double array[50];
    double x;
    double y;
    double z;
    for(int i = 0 ; i < 50 ; i++)
        array[i] = 0;
    int counter = 0;
    for(unsigned int i = 0 ; i < input.size() ; i++)
    {
        if(isnumber(input[i]))
        {
            x = stod(input[i]);
            push(array,counter,x);
        }
        else if(input[i]=="+")
        {
            x = pop(array,counter);
            y = pop(array,counter);
            z = x + y;
            push(array,counter,z);
        }
        else if(input[i]=="-")
        {
            x = pop(array,counter);
            y = pop(array,counter);
            z = y - x;
            push(array,counter,z);
        }
        else if(input[i]=="*")
        {
            x = pop(array,counter);
            y = pop(array,counter);
            z = x*y;
            push(array,counter,z);
        }
        else if(input[i]=="/")
        {
            x = pop(array,counter);
            y = pop(array,counter);
            assert(x!=0);
            z = y / x;
            push(array,counter,z);
        }
    }
    return array[counter-1];
}

int main()
{
    std::vector <std::string> input = {"4","7","+","4","*","16","/"};
    double x = onp(input);
    cout<<"Poprawnym wynikiem operacji ((4+7)*4)/16 = 2,75 \n";    // zakomentować jeżeli zmieniamy liczby w vectorze
    cout<<"Wynik kalkulatora: "<<x<<endl;
    cout<<endl;

    std::vector <std::string> input2 = {"10","3","-"};
    double x2 = onp(input2);
    cout<<"Poprawnym wynikiem operacji 10-3 = 7 \n";    // zakomentować jeżeli zmieniamy liczby w vectorze
    cout<<"Wynik kalkulatora: "<<x2<<endl;
    cout<<endl;

    std::vector <std::string> input3 = {"7","7","*","7","7","*","+"};
    double x3 = onp(input3);
    cout<<"Poprawnym wynikiem operacji (7*7)+(7*7) = 98 \n";    // zakomentować jeżeli zmieniamy liczby w vectorze
    cout<<"Wynik kalkulatora: "<<x3<<endl;
    cout<<endl;

    std::vector <std::string> input4 = {"35","5","*","5","*"};
    double x4 = onp(input4);
    cout<<"Poprawnym wynikiem operacji 35*5*5 = 875 \n";    // zakomentować jeżeli zmieniamy liczby w vectorze
    cout<<"Wynik kalkulatora: "<<x4<<endl;
    cout<<endl;

    std::vector <std::string> input5 = {"21","3","*","5","20","*","+"};
    double x5 = onp(input5);
    cout<<"Poprawnym wynikiem operacji 21*3+5*20 = 163 \n";    // zakomentować jeżeli zmieniamy liczby w vectorze
    cout<<"Wynik kalkulatora: "<<x5<<endl;
    cout<<endl;

    return 0;
}