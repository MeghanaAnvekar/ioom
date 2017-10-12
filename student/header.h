#include "header.h"

int main()
{
	Student s;
	fStudent x;
	string name;
	int marks[6];
	int id;
	int dd,mm,yy;
	
	cout<<"\nEnter the following details....\n";
	cout<<"\nID No. : ";
	cin>>id;
	
	cout<<"\nName : ";
	cin.ignore();

	getline(cin, name);
	
	cout<<"\nD.O.B : ";
	cout<<"\n\tDay : ";
	cin>>dd;
	
	cout<<"\n\tMonth : ";
	cin>>mm;
	
	cout<<"\n\tYear : ";
	cin>>yy;

	cout<<"Marks obtained :";

	for(int i = 0; i  < 6;++i)
	{	cout<<"\nSubject "<<i+1<<" : ";
		cin>>marks[i];
	}

	date dob(dd,mm,yy);
	s.initialize(id, name, marks, dob);
	x.display(s);
	return 0;
}
