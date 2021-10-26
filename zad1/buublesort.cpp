#include<iostream>
using namespace std;
int main ()
{
   int i, j,temp,pass=0;
   int a[10] = {134,120,143,110,59,34,13,8,2,1}; //     tutaj zmieniamy zmienne w tablicy, 
   cout <<"Tablica ktora bedziemy sortowac: \n"; //     podany przyklad jest jednym z najgorszych dla sortowania babelkowego gdyz najmniejsza liczba jest po prawej stronie
   for(i = 0; i<10; i++) 
   {
      cout <<a[i]<<"\t";
   }
cout<<endl;
for(i = 0; i<10; i++) 
{

   for(j = i+1; j<10; j++)
   {
      if(a[j] < a[i]) 
      {
         temp = a[i];
         a[i] = a[j];
         a[j] = temp;
      }
   }
pass++;
cout<<"Iteracja numer: "<<pass<<"\n";
for(int z = 0; z<10; z++) 
{
   cout <<a[z]<<"\t";
}
cout<<"\n_______________________________________________________________________________________________________________\n"; 
}
cout <<"Lista posortowana:\n";
for(i = 0; i<10; i++) 
{
   cout <<a[i]<<"\t";
}
return 0;
}