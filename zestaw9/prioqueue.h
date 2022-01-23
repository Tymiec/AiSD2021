// singlelist.h

#ifndef PRIOQUEUE_H
#define PRIOQUEUE_H

#include <iostream>     
#include <cassert>    

template <typename T>
struct SingleNode 
{
    T value;
    int priority;
    SingleNode *next;
    SingleNode() : value(T()),priority(1), next(nullptr) {} // konstruktor domyslny
    SingleNode(const T& item, const int priority,SingleNode *ptr=nullptr) : value(item), priority(priority),next(ptr) {}
    ~SingleNode() {} // destruktor
};

template <typename T>
class SingleList 
{
    SingleNode<T> *head;
    int rozmiar_tablicy;
public:

    SingleList() : head(nullptr)
    {
        rozmiar_tablicy = 0;
    }

    ~SingleList()
    {
        while(!empty())
            pop();
    }

    SingleList(const SingleList& other)
    {
        head = nullptr;
        SingleNode<T> *node = other.head;
        while(node)
        {
            push(node -> value, node -> priority);
            node = node -> next;
        }
    }
    SingleList& operator=(const SingleList& other)
    {
        if(this != &other)
        {
            clear();
            if(other.head == nullptr)
            head = nullptr;

            else
            {
                SingleNode<T> *p1,*p2;
                head = new SingleNode<T>;
                head -> value = other.head -> value;

                p1 = head;
                p2 = other.head -> next;

                while(p2)
                {
                    p1 -> next = new SingleNode<T>;
                    p1 = p1 -> next;
                    p1 -> value = p2 -> value;
                    p2 = p2 -> next;
                }   
                p1 -> next = nullptr;
                rozmiar_tablicy = other.rozmiar_tablicy;
            }
        }
        return *this;
    }

    bool empty() const 
    {
        return head == nullptr; 
    }

    int size() const
    {
        return rozmiar_tablicy;
    }

    void push(const T& item, int priority)
    {
        if (!empty()) 
        {
            if(priority >= head -> priority)
                head = new SingleNode<T>(item, priority, head);
            else
            {
                SingleNode <T> *insert = new SingleNode <T> (item, priority);
                SingleNode <T> *temporary = head;

                if(temporary -> next == nullptr)
                {
                    head -> next = insert;
                    return;
                }
                while(insert -> priority <= temporary -> next -> priority)
                {
                    temporary = temporary -> next;
                    if(temporary -> next == nullptr)
                        break;
                }
                insert -> next = temporary -> next;
                temporary -> next = insert;
            }
        } 
        else 
        {
            head = new SingleNode<T>(item, priority);
        }
        rozmiar_tablicy++;
    }

    void push(T&& item, int priority)
    {
        if (!empty()) 
        {
            if(priority >= head -> priority)
                head = new SingleNode<T>(std::move(item), priority, head);

            else
            {
                SingleNode <T> *insert = new SingleNode <T> (std::move(item),priority);
                SingleNode <T> *temporary = head;
                if(temporary -> next == nullptr)
                {
                    head -> next = insert;
                    return;
                }
                while(insert -> priority <= temporary -> next -> priority)
                {
                    temporary = temporary -> next;
                    if(temporary -> next == nullptr)
                    break;
                }
                insert -> next = temporary -> next;
                temporary -> next = insert;
            }
        } 
        else 
        {
            head = new SingleNode<T>(std::move(item),std::move(priority));
        }
        rozmiar_tablicy++;
    } // O(1), L.push_back(std::move(item)) NIEOBOWIAZKOWE
    T top()
    {
        return head->value;
    }
    T pop()
    {
        assert(!empty());
        //std::cout<<head->next<<std::endl;
        SingleNode<T> *node = head; // zapamietujemy
        if (head -> next == nullptr) 
        { // jeden wezel na liscie
            head = nullptr;
        } 

        else 
        { // wiecej niz jeden wezel na liscie
            //std::cout<<"We enter reassigning head\n";
            head = node -> next;
            //std::cout<<"Head = "<<head<<std::endl;
        }
        rozmiar_tablicy--;
        T val;
        val = node -> value;
        delete node;
        return val;
    }

    void clear()
    {
        while(!empty())
            pop();
    }
    
    void display()
    {
        SingleNode<T> *node = head;
        while (node != nullptr){
            std::cout << "("<<node->value << " , "<<node-> priority <<")";
            node = node->next;
            if(node!=nullptr)
                std::cout<<" , ";
        }
        std::cout << std::endl;
    }
};
#endif