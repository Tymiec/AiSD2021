#include <iostream>
#include <vector>
#include <cassert>
#include <stdlib.h>

using namespace std;

bool isnumber(string input)     //sprawdzamy czym jest wprowadzony znak
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

void push(double stack[], int &iterator, double &x)
{
    stack[iterator] = x;
    iterator++;
}

double pop(double stack[], int &iterator)
{
    double x = stack[iterator-1];
    iterator--;

    stack[iterator] = 0;

    return x;
}

double rpn (std::vector<string> input)
{
    double array[50];
    double x;
    double y;
    double z;

    for (int i = 0 ; i < 50 ; i++)
        array[i] = 0;

    int iterator = 0;

    for (unsigned int i = 0 ; i < input.size(); i++)
    {
        if (isnumber(input[i]))
        {
            x = stod(input[i]);
            push(array,iterator,x);
        }
        else
        switch (input[i])
        {
        case '+':
        x = pop(array,iterator);
        y = pop(array,iterator);
        z = x + y;
        push(array,iterator,z);
        break;

        case '-':
        x = pop(array,iterator);
        y = pop(array,iterator);
        z = y - x;
        push (array,iterator,z);       
        break;

        case '*':
        x = pop(array,iterator);
        y = pop(array,iterator);
        z = x*y;
        push(array,iterator,z);        
        break;

        case '/':
        x = pop(array,iterator);
        y = pop(array,iterator);
        assert(x!=0);)
        z = y / x;
        push(array,iterator,z);
        break;
        
        default:
            break;
        }
    }
    return array[iterator-1];
}

int main()
{

    std::vector <std::string> input = {"60","2","4","+","/"};
    double x = rpn(input);
    cout<<x<<endl;

    std::vector <std::string> input2 = {"4", "2","+"};
    double x2 = rpn(input2);
    cout<<x2<<endl;

    std::vector <std::string> input3 = {"75","5","/","5","+"};
    double x3 = rpn(input3);
    cout<<x3<<endl;
    
    return 0;
}