#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include <iostream>
#include <cassert> 

template <typename T>
class ArrayList 
{
    T* tab;
    int msize; // max liczba elementów
    int last; // pierwsza wolna pozycja
public:
    ArrayList(int s=10) : msize(s), last(0) // domyślny constructor
    {
        tab = new T[s];
        assert( tab != nullptr );
    }
    ~ArrayList() 
    { 
        delete [] tab; 
    }
    ArrayList(const ArrayList& other) // kopiowanie constructora
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
    } 
    // copy assignment operator, return *this
    // usage:   list2 = list1;
    /*ArrayList& operator=(ArrayList&& other); // move assignment operator, return *this
    // usage:   list2 = std::move(list1);*/
    int max_size() const 
    { 
        return msize; // zwraca maksymalna wielkosc
    }

    int size() const 
    {
        return last; // zwraca liczbe elementow w liscie
    }

    bool full() const 
    { 
        return last == msize; // sprawdzamy czy pelny
    }

    bool empty() const 
    {
        return last == 0;   // sprawdzamy czy pusty
    }
    

    void push_front(const T& item)
    {
        if(full())
            std::cout<<"Lista = pelna\n";
        else
        {
            for (int  i = last; i > 0; i--)
            {
                tab[i] = std::move(tab[i-1]);   // dodajemy z przodu
            }
            tab[0] = std::move(item);
            std::cout<<"     "<<tab;
            last++;
        } 
    }

    void push_front(T&& item)
    {
        if(full())
        std::cout<<"Lista = pelna";
        else
        {
            for (int  i = last; i > 0; i--)
            {
                tab[i] = std::move(tab[i-1]);   // dodajemy z przodu
            }
            tab[0] = std::move(item);
            last++;
        }
    } 

    void push_back(const T& item)
    {
        if(full())
            std::cout<<"Lista = pelna\n";
        else
        {
            tab[last] = std::move(item);        // dodajemy na ostania pozycje
            last++;
        }
    } 
    
    void push_back(T&& item)
    {
        if(full())
            std::cout<<"Lista = pelna\n";
        else
        {
            tab[last] = std::move(item);        // dodajemy na ostania pozycje
            last++;
        }
    }

    T& front()
    {
        if(last==0)
            std::cout<<"Lista = pusta \n";      // pobiera pierwszy element i zwraca, zwraca blad jesli lista jest pusta
        return tab[0];
    }
    T& back()
    {
        if(last==0)
            std::cout<<"Lista = pusta \n";      // pobiera ostatni element i zwraca, zwraca blad jesli lista jest pusta
        return tab[last-1];
    }
    void pop_front()
    {
        if(empty())
            std::cout<<"Lista = pusta\n";
        else
        {
            for(int i=0;i<size();i++)  
                tab[i] = tab[i+1];              // usuwa pierwszy element, zwraca blad jesli lista jest pusta
            last--;
        }
    }

    void pop_back()
    {
        if(empty())
            std::cout<<"Lista pusta\n";
        else                                    // usuwa ostatni element, zwraca blad jesli lista jest pusta
            last--; 
    }

    void clear()
    {
        for(int i=0;i<last;i++)
            tab[i] = NULL;                      // czyscimy liste z wszystkich elementow
        last = 0;
    }

    void display()
    {
        for(int i=0;i<size();i++)
            std::cout<<tab[i]<<" ";             // wyswietla tablice
        std::cout<<std::endl;
    }

    void reverse()
    {
        for(int i=0;i<size()/2;i++)
        {
            T temp = tab[i];
            tab[i] = tab[last-i-1];             // odwraca kolejnosc elementow w liscie
            tab[last-i-1] = temp;
        }
    }
    
    void sort()
    {
        int index = 0;
        for(int i=0 ; i<size();i++)
        {
            index = 0;
            for(int j = 0;j<size()-i;j++)
            {
                if(tab[j]>=tab[index])          // sortuje liste
                    index = j;
            }
            T temp = tab[last-i-1];
            tab[last-i-1] = tab[index];
            tab[index] = temp;
        }
    }

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
                else                                      //  laczy dwie posortowane listy w jedna
                {
                    if(other.tab[x]<tab[i])
                    {
                        insert(i,other.tab[x]);
                        x++;
                    }
                }
            }
        }

    }

    // Operacje na indeksach
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
    
    // https://en.cppreference.com/w/cpp/language/operators
    // Array subscript operator

    T& operator[](int pos)
    {
        if(pos>=last)
            std::cout<<"Indeks poza granicami tablicy\n";       // podstawienie w L[pos]=item
        return tab[pos];
    }

    const T& operator[](int pos) const
    {
        if(pos>=last)
            std::cout<<"Indeks poza granicami tablicy\n";        // odczyt co jest naL[pos]
        return tab[pos];
    } // odczyt L[pos]

    int index(const T& item)
    {
        for(int i = 0;i<size();i++)
        {
            if(tab[i]==item)
            {
                return i;                                       // sprawdzenie indexu, zwracamy -1 gdy index jest poza zakresem
            }
        }
        return -1;
    }

    int insert(int pos, const T& item)                          // wstawianie przed punktem pos
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
    }

    int insert(int pos, T&& item)
    {
        if(size() == msize)
        {
            std::cout<<"Lista pelna\n";
            return -1;
        }
        else if(pos == 0)                       // Jezeli pos=0, to wstawiamy na poczatek.  
        {                                       
            push_front(item);                   
            return 0;                           
        }
        else if(pos == size())                  // Jezeli pos=size(), to wstawiamy na koniec.
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
            return pos;                         // zwraca pozycje wstawionego elementu
        }
    }


    

    friend std::ostream& operator<<(std::ostream& os, const ArrayList& L) {
        for (int i=0; i < L.last; ++i) {        // odwolanie L.last
            os << L.tab[i] << " ";              // odwolanie L.tab
        }
        return os;
    }
    // usage:   std::cout << L << std::endl;
};

#endif

// EOF
