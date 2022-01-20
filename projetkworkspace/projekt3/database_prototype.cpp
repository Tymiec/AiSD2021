# include <iostream>
# include <string >
# include <fstream>
using namespace std ;
void name () ;
void ID () ;
int main ()
{
	system ("cls") ;
	system ("color 0F") ;
	int ch1 ;
	cout << "1 for new data" << endl;
	cout << "2 for seaching by ID" << endl;
        cin >> ch1 ;
	if (ch1 == 1)
	{
		name () ;
	}
	else if (ch1 == 2)
	{
		ID () ;
	}

}

void name ()
{
	system ("cls") ;
	string name ;
	ofstream worker ("eslam.txt",ios ::app);
	int ID , salary ;
	cout << "Name : ";
	cin >> name ;
	cout << "ID : " ;
	cin >> ID ;
	cout << "Salary : " ;
	cin >> salary ;

	worker << name << " " << ID << " " << salary << endl;
	worker.close () ;
	cin.get () ;
	main () ;
}

void ID ()
{
	ifstream worker ("eslam.txt") ;
	int ID , salary , str ;
	string name  ;
	cout << "Enter ID : " ;
	cin >> str ;

	while (worker >> name >> ID >> salary)
	{
		if (str == ID)
		{
			system ("cls") ;
			cout << "Data found !" << endl;
			cout << name << " " << ID << " "  << salary << endl; 
		}

		else if (!(str == ID))
		{
			system ("cls") ;
			cout << "Not Found !" << endl;
		}
	}

	system ("pause") ;
	main () ;
}