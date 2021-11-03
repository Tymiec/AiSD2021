#include <iostream>
using namespace std;

void buublesort(int *tablica_sortujaca, int n)
{
	for (int i = 0; i < (n); i++)
	{
		for(int j=0; j<(n-i-1); j++) // zmieniamy n-i-1 na n-i
        {
		if (tablica_sortujaca[j]>tablica_sortujaca[j+1])
		{
			swap(tablica_sortujaca[j], tablica_sortujaca[j+1]);
		}
		}
	}
	
}
int main()
{
	int *tablica_sortujaca, n;
 
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