#include <iostream>
using namespace std;


void quicksort(int *tablica_sortujaca, int left, int right)
{
	if(right <= left) return;
	
	int i = left - 1, j = right + 1, 
	pivot = tablica_sortujaca[(left+right)/2];
	
	while(1)
	{
		while(pivot>tablica_sortujaca[++i]);

		while(pivot<tablica_sortujaca[--j]);

		if( i <= j)
			swap(tablica_sortujaca[i],tablica_sortujaca[j]);
		else
			break;
	}

	if(j > left)
	quicksort(tablica_sortujaca, left, j);
	if(i < right)
	quicksort(tablica_sortujaca, i, right);
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
 
  	quicksort(tablica_sortujaca,0, n-1);
	
  	for(int i=0;i<n;i++)
	{
		cout<<tablica_sortujaca[i]<<" ";
	}
          
 
  	cin.ignore();
  	cin.get();
  	return 0;
}