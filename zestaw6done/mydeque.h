#ifndef MYDEQUE_H
#define MYDEQUE_H

#include <iostream>


template <typename T>
class MyDeque 
{
    T* tab;
    int msize; // największa możliwa liczba elementów plus jeden
    int head; // pierwszy do pobrania
    int tail; // pierwsza wolna pozycja
public:
    MyDeque(int s=10) : msize(s+1), head(0), tail(0) {
        tab = new T[s+1];
        assert( tab != nullptr );
    } // default constructor
    ~MyDeque() { delete [] tab; }
    MyDeque(const MyDeque& other); // copy constructor
    //MyDeque(MyDeque&& other); // move constructor
    MyDeque& operator=(const MyDeque& other); // copy assignment operator, return *this
    //MyDeque& operator=(MyDeque&& other); // move assignment operator, return *this
    bool empty() const { return head == tail; }
    bool full() const { return (tail + 1) % msize == head; }
    int size() const { return (tail - head + msize) % msize; }
    int max_size() const { return msize-1; }
    void push_front(const T& item); // dodanie na początek O(1)
    //void push_front(T&& item); // dodanie na początek O(1)
    void push_back(const T& item); // dodanie na koniec O(1)
    //void push_back(T&& item); // dodanie na koniec O(1)
    T& front() { return tab[head]; } // zwraca poczatek
    T& back() { return tab[(tail + msize -1) % msize]; } // zwraca koniec
    void pop_front(); // usuwa początek kolejki O(1)
    void pop_back(); // usuwa koniec kolejki O(1)
    void clear(); // czyszczenie listy z elementow
    void display();
    // Operacje z indeksami.
    T& operator[](int pos); // podstawienie L[pos]=item
    const T& operator[](int pos) const; // odczyt L[pos]
    void erase(int pos);
    int index(const T& item); // jaki index na liscie (-1 gdy nie ma)
    void insert(int pos, const T& item); // inserts item before pos
    //void insert(int pos, T&& item); // inserts item before pos
    std::string to_string() const;
};

template <typename T>
// pushfront
void MyDeque<T>::push_front(const T& item) 
{
    head = (head + msize -1) % msize;
    tab[head] = item;
}
template <typename T>
//pushback
void MyDeque<T>::push_back(const T& item) 
{
    tab[tail] = item;
    tail = (tail + 1) % msize;
}
template <typename T>
//display
void MyDeque<T>::display() 
{
    for (int i = head; i != tail; i=(i+1) % msize) 
    {
        std::cout << tab[i] << " ";
    }
    std::cout << std::endl;
}

template <class T>
//MyDeque
MyDeque<T>::MyDeque(const MyDeque<T>& other){
    msize = other.msize;

    head = 0;
    tail = 0;

    tab = new T[msize+1];
    
    for (int i = other.head; i != other.tail; i = (i+1)% other.msize) 
    {
        push_back(other.tab[i]);
    }
}

template <class T>
//operator
MyDeque<T>& MyDeque<T>::operator = (const MyDeque<T>& other)
{
    delete[] tab;
    head = 0;
    tail = 0;
    tab = new T[msize+1];
    for (int i = other.head; i != other.tail; i = (i+1)% other.msize) 
    {
        push_back(other.tab[i]);
    }
    return *this;
}

template <class T>
//popfront
void MyDeque<T>::pop_front()
{
    head = (head + 1) % msize;
}

template <class T>
//popback
void MyDeque<T>::pop_back()
{
    tail = (tail - 1);
    if (tail < 0)
        tail = msize - 1;
}

template <class T>
//clear
void MyDeque<T>::clear() 
{
    head = 0;
    tail = 0;
}

template <class T>
//to_string
std::string MyDeque<T>::to_string() const 
{
    std::string s;
    for (int i=head; i!= tail; i=(i+1) % msize)
    {
        if (i != head)

        s = s + ",";
        s+=std::to_string(tab[i]);
    }
    return s;   
}



#endif