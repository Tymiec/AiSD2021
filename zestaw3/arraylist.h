// arraylist.h

#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include <iostream>     // deklaracje strumieni cout, cin, cerr
#include <cassert>    // assert()

template <typename T>
class ArrayList 
{
    T* tab;
    int msize; // najwieksza mozliwa liczba elementow
    int last; // pierwsza wolna pozycja
public:
    ArrayList(int s=10) : msize(s), last(0) // default constructor
    {
        tab = new T[s];
        assert( tab != nullptr );
    }
    ~ArrayList() 
    { 
        delete [] tab; 
    }
    ArrayList(const ArrayList& other) // copy constructor
    {
        msize = other.msize;
        last = other.last;
        tab = nullptr;
        if(msize > 0)
        {
            tab = new T[msize];
            for(int i = 0;i<last;i++)
                tab[i] = other.tab[i];
        }
    }
    // usage:   ArrayList<int> list2(list1);
    /*ArrayList(ArrayList&& other)
    {

    };*/ // move constructor
    // usage:   ArrayList<int> list2(std::move(list1));
    ArrayList& operator=(const ArrayList& other)
    {
        if(&other == this)
            return *this;
        else
        {
            msize = other.msize;
            last = other.last;
            delete [] tab;
            tab = nullptr;
            if(msize>0)
            {
                tab = new T[msize];
                for(int i=0;i<last;i++)
                {
                    tab[i] = other.tab[i];
                }
            }
            return *this;
        }
    } // copy assignment operator, return *this
    // usage:   list2 = list1;
    /*ArrayList& operator=(ArrayList&& other); // move assignment operator, return *this
    // usage:   list2 = std::move(list1);*/
    bool empty() const 
    {
        return last == 0; 
    } // checks if the container has no elements
    bool full() const 
    { 
        return last == msize; 
    } // checks if the container is full
    int size() const 
    {
        return last; 
    } // liczba elementow na liscie
    int max_size() const 
    { 
        return msize; 
    } // najwieksza mozliwa liczba elementow
    void push_front(const T& item)
    {
        if(full())
            std::cout<<"Lista jest pelna\n";
        else
        {
            for (int  i = last; i > 0; i--)
            {
                tab[i] = std::move(tab[i-1]);
            }
            tab[0] = std::move(item);
            std::cout<<"     "<<tab;
            last++;
        }
    } // dodanie na poczatek
    void push_front(T&& item)
    {
        if(full())
            std::cout<<"Lista jest pelna";
        else
        {
            for (int  i = last; i > 0; i--)
            {
                tab[i] = std::move(tab[i-1]);
            }
            tab[0] = std::move(item);
            last++;
        }
    } // dodanie na poczatek
    void push_back(const T& item)
    {
        if(full())
            std::cout<<"Lista jest pelna\n";
        else
        {
            tab[last] = std::move(item);
            last++;
        }
    } // dodanie na koniec
    void push_back(T&& item)
    {
        if(full())
            std::cout<<"Lista jest pelna\n";
        else
        {
            tab[last] = std::move(item);
            last++;
        }
    } // dodanie na koniec
    T& front()
    {
        if(last==0)
            std::cout<<"Lista pusta \n";
        return tab[0];
    } // zwraca poczatek, nie usuwa, error dla pustej listy
    T& back()
    {
        if(last==0)
            std::cout<<"Lista pusta \n";
        return tab[last-1];
    } // zwraca koniec, nie usuwa, error dla pustej listy
    void pop_front()
    {
        if(empty())
            std::cout<<"Lista pusta\n";
        else
        {
            for(int i=0;i<size();i++)
                tab[i] = tab[i+1];
            last--;
        }
    } // usuwa poczatek, error dla pustej listy
    void pop_back()
    {
        if(empty())
            std::cout<<"Lista pusta\n";
        else
            last--;
    } // usuwa koniec, error dla pustej listy
    void clear()
    {
        for(int i=0;i<last;i++)
            tab[i] = NULL;
        last = 0;
    } // czyszczenie listy z elementow
    void display()
    {
        for(int i=0;i<size();i++)
            std::cout<<tab[i]<<" ";
        std::cout<<std::endl;
    } // lepiej zdefiniowac operator<<
    void reverse()
    {
        for(int i=0;i<size()/2;i++)
        {
            T temp = tab[i];
            tab[i] = tab[last-i-1];
            tab[last-i-1] = temp;
        }
    } // odwracanie kolejnosci
    void sort()
    {
        int index = 0;
        for(int i=0 ; i<size();i++)
        {
            index = 0;
            for(int j = 0;j<size()-i;j++)
            {
                if(tab[j]>=tab[index])
                    index = j;
            }
            T temp = tab[last-i-1];
            tab[last-i-1] = tab[index];
            tab[index] = temp;
        }
    } // sortowanie listy
    void merge(ArrayList& other)
    {
        if(size()+other.size() - 2 > msize)
            std::cout<<"Brak miejsca w liscie\n";
        else
        {
            int x = 0;
            for(int i = 0;i<last;i++)
            {
                if(x == other.last)
                    break;
                else
                {
                    if(other.tab[x]<tab[i])
                    {
                        insert(i,other.tab[x]);
                        x++;
                    }
                }
            }
        }

    } //  merges two sorted lists into one
    // Operacje z indeksami.
    int erase(int pos)
    {
        if(size()==0)
            return -1;
        else
        {
            for(int i=pos;i<last;i++)
                tab[i]=tab[i+1];
            last--;
            return pos;
        }
    }
     // return Iterator following the last removed element,
    // czyli u mnie pos, bo ten element za usunietym sie przesunie na pos;
    // ale jak usune ostatni, to chyba powinien zwrocic -1 (niewlasciwy indeks)
    //
    // https://en.cppreference.com/w/cpp/language/operators
    // Array subscript operator
    T& operator[](int pos)
    {
        if(pos>=last)
            std::cout<<"Indeks poza granicami tablicy\n";
        return tab[pos];
    } // podstawienie L[pos]=item
    const T& operator[](int pos) const
    {
        if(pos>=last)
            std::cout<<"Indeks poza granicami tablicy\n";
        return tab[pos];
    } // odczyt L[pos]
    int index(const T& item)
    {
        for(int i = 0;i<size();i++)
        {
            if(tab[i]==item)
            {
                return i;
            }
        }
        return -1;
    } // jaki index na liscie (-1 gdy nie ma)
    int insert(int pos, const T& item)
    {
        if(size() == msize)
        {
            std::cout<<"Lista pelna\n";
            return -1;
        }
        else if(pos == 0)
        {
            push_front(item);
            return 0;
        }
        else if(pos == size())
        {
            push_back(item);
            return last-1;
        }
        else
        {
            for(int i=size();i>pos;i--)
            {
                tab[i] = std::move(tab[i-1]);
            }
            tab[pos] = std::move(item);
            last++;
            return pos-1;
        }
    } // inserts item before pos,
    int insert(int pos, T&& item)
    {
        if(size() == msize)
        {
            std::cout<<"Lista pelna\n";
            return -1;
        }
        else if(pos == 0)
        {
            push_front(item);
            return 0;
        }
        else if(pos == size())
        {
            push_back(item);
            return last-1;
        }
        else
        {
            for(int i=size();i>pos;i--)
            {
                tab[i] = std::move(tab[i-1]);
            }
            tab[pos] = std::move(item);
            last++;
            return pos;
        }
    } // inserts item before pos,
    // Jezeli pos=0, to wstawiamy na poczatek.
    // Jezeli pos=size(), to wstawiamy na koniec.
    // zwraca pozycje wstawionego elementu
    // zwraca pozycje wstawionego elementu
    friend std::ostream& operator<<(std::ostream& os, const ArrayList& L) {
        for (int i=0; i < L.last; ++i) { // odwolanie L.last
            os << L.tab[i] << " ";   // odwolanie L.tab
        }
        return os;
    }
    // usage:   std::cout << L << std::endl;
};

#endif

// EOF
