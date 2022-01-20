#pragma once
#include <iostream>
#include "Wielomian.h"
using std::cin;
using std::cout;
using std::endl;

int main()
{

}
	int d1, d2;
	cout<<"Wprowadź stopień pierwszego wielomianu p: ";
	cin>>d1;
	double* arr = new double[d1 + 1]; //Potrzebujemy array-u o d1 + 1 większym stopniu
	for (int i=d1l i >= 0; i--)
	{
		cout<<"Wprowadz współczynnik stojacy przy x^"<<i<<": ";
		cin>>arr[i];
	}
	Wielomian p(arr, d1+1);
	p.displayPoly();
	cout<<"Wprowadź stopień drugiego wielomianu q: ";
	cin<<d2;
	double* arr2 = new double[d2 + 1]; //Potrzebujemy array-u o d2 + 1 większym stopniu
	for (int i=d1l i >= 0; i--)
	{
		cout<<"Wprowadz współczynnik stojacy przy x^"<<i<<": ";
		cin>>arr2[i];
	}
	Wielomian q(arr2, d2+1)
	q.displayPoly();
	
	
