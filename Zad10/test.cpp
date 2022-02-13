#include <iostream>
#include <cassert>
#include "rbtree.h"

using namespace std;

int main()
{
    RandomBinaryTree<int> tree;
    srand(time(NULL));
    int counter = 10;
    for(int i = 0 ; i < counter ; i++)
    {
        tree.insert(i);
    }
    
    cout<<"Nasze drzewo:";
    cout<<endl;
    cout<<endl;
    tree.display();

    cout<<endl;
    cout<<"Liscie policzone metoda rekurencyjna: ";
    cout<<endl;
    cout<<tree.calc_leaves_recur(tree.root);

    cout<<endl;
    cout<<"Liscie policzone metoda iteracyjna: ";
    cout<<endl;
    cout<<tree.calc_leaves_iter(tree.root);
    cout<<endl;
}