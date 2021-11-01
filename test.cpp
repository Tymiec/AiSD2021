#include <iostream>
using namespace std;


void buublesort(int *tablica_sortujaca, int length)
{
	for(int i=1; i<length; ++i)
    {
        for(int j=length-1; j>=i; --j)
        {
            if(tablica_sortujaca[j-1]>tablica_sortujaca[j])
            {
                swap(tablica_sortujaca[j-1], tablica_sortujaca[j]);
            }
		}
	}
}
int main()
{
	int *tablica_sortujaca;
	int n;
 
  	cout<<"Ile liczb bedziemy sortowac ? \n";
  	cin>>n;
	cout<<"Dobrze, posortujemy "<<n<<" liczb. \n";
  	
	tablica_sortujaca = new int [n];
  	
	
  	for(int i=0;i<n;i++)
	  {
	  	cout<<"Wprowadz liczbe: ";
    	cin>>tablica_sortujaca[i];
	  }
 
  	buublesort(tablica_sortujaca, n);
	
  	for(int i=0;i<n;i++)
	{
		cout<<tablica_sortujaca[i]<<" ";
	}
          
 
  	cin.ignore();
  	cin.get();
  	return 0;
}