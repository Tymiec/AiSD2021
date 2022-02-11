#include <iostream>
#include <cassert>
#include "rbtree.h"

using namespace std;

int main()
{
    RandomBinaryTree<int> tree;
    srand(time(NULL));
    int count = 10;
    for(int i = 0 ; i < count ; i++)
    {
        tree.insert(i);
    }
    tree.display();
    cout<<endl;
    cout<<"Liscie policzone metoda rekurencyjna: ";
    cout<<tree.calc_leaves_recur(tree.root);
    cout<<endl;
    cout<<"Liscie policzone metoda iteracyjna: ";
    cout<<tree.calc_leaves_iter(tree.root);
    cout<<endl;
}