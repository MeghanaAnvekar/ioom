#include "header.h"

date& operator++(date& d)
{
	switch(d.mm)
	{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10: if (d.dd < 31)
					d.dd++;
				  
				 else
				 	{
				 		d.mm++;
				 		d.dd = 1;
				 	}
				 break;
		case 4 :
		case 6:
		case 9:
		case 11: if (d.dd < 30)
					d.dd++;
				  
				 else
				 	{
				 		d.mm++;
				 		d.dd = 1;
				 	}
				 break;
		case 2: if(d.dd < 28)
					d.dd++;

				else if (d.yy % 4 == 0 && d.dd == 28)
					d.dd++;
				else
				{
					d.dd = 1;
					d.mm = 3;
				}

				break;
		case 12 : if(d.dd < 31)
					d.dd++;
				  else
				  {
				  	d.dd = 1;
				  	d.mm = 1;
				  	d.yy++;
				  }
				 break;
		default: cout<<"\nInvalid month ! Error in code\n";

	}

	return d;
	
}

date operator++(date& d,int y)
{
	date x = d;

	switch(d.mm)
	{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10: if (d.dd < 31)
					d.dd++;
				  
				 else
				 	{
				 		d.mm++;
				 		d.dd = 1;
				 	}
				 break;
		case 4 :
		case 6:
		case 9:
		case 11: if (d.dd < 30)
					d.dd++;
				  
				 else
				 	{
				 		d.mm++;
				 		d.dd = 1;
				 	}
				 break;
		case 2: if(d.dd < 28)
					d.dd++;

				else if (d.yy % 4 == 0 && d.dd == 28)
					d.dd++;
				else
				{
					d.dd = 1;
					d.mm = 3;
				}

				break;
		case 12 : if(d.dd < 31)
					d.dd++;
				  else
				  {
				  	d.dd = 1;
				  	d.mm = 1;
				  	d.yy++;
				  }
				 break;
		default: cout<<"\nInvalid month ! Error in code\n";

	}

	return x;


}


date& operator--(date &d)
{
	switch(d.mm)
	{
		case 1: if (d.dd > 1)
					d.dd--;
				  
				 else
				 	{
				 		d.dd = 31;
				 		d.mm = 12;
				 		d.yy--;
				 	}
				 break;
		case 3: if(d.dd > 1)
					d.dd--;
				else if (d.yy % 4 == 0 )
				{	
					d.dd = 29;
					d.mm = 2; 
				}
				else
				{
					d.dd = 28;
					d.mm = 2; 
				}

				
				break;
		case 2:
		case 4:
		case 6:
		case 8:
		case 9:
		case 11: if(d.dd > 1)
					d.dd--;
				 else
				 {
				 	d.dd = 31;
				 	d.mm--;
				 }
				 break;
		case 5:
		case 7:
		case 10:
		case 12: if(d.dd > 1)
					d.dd--;
				 else
				 {
				 	d.dd = 30;
				 	d.mm--;
				 }
				 break;

		default: cout<<"\nInvalid month ! Error in code\n";

	}

	return d;
}
date operator--(date& d,int y)
{
	date x = d;

	switch(d.mm)
	{
		case 1: if (d.dd > 1)
					d.dd--;
				  
				 else
				 	{
				 		d.dd = 31;
				 		d.mm = 12;
				 		d.yy--;
				 	}
				 break;
		case 3: if(d.dd > 1)
					d.dd--;
				else if (d.yy % 4 == 0)
				{	
					d.dd = 29;
					d.mm = 2; 
				}
				else
				{
					d.dd = 28;
					d.mm = 2; 
				}

				
				break;
		case 2:
		case 4:
		case 6:
		case 8:
		case 9:
		case 11: if(d.dd > 1)
					d.dd--;
				 else
				 {
				 	d.dd = 31;
				 	d.mm--;
				 }
				 break;
		case 5:
		case 7:
		case 10:
		case 12: if(d.dd > 1)
					d.dd--;
				 else
				 {
				 	d.dd = 30;
				 	d.mm--;
				 }
				 break;

		default: cout<<"\nInvalid month ! Error in code\n";

	}

	return x;

}
date::date()
{
	dd = 10;
	mm = 10;
	yy = 2017; 
}
date::date(int dd, int mm, int yy)
{
	this->dd= dd;
	this->mm =mm;
	this->yy = yy;
}

Student::Student()
{
	studentID = 0;
	name = "\0";

	for(int i = 0; i< 6;++i)
		marks[i] = 0.0;

}

void Student::initialize(int id, string sname, int *m,date & d)
{
	studentID = id;
	name = sname;

	for(int i = 0; i < 6;++i)
		marks[i] = m[i];

	int incr = 0;

	if(dob.dd != d.dd || dob.mm != d.mm || dob.yy != d.yy)
	{
		if(dob.yy < d.yy)
			incr = 1;
		else if(dob.yy > d.yy)
			incr = 0;
		else if (dob.mm < d.mm)
			incr = 1;
		else if(dob.mm > d.mm)
			incr = 0;
		else if(dob.dd < d.dd)
			incr = 1;
		else
			incr = 0;

		if(incr)
		{
			cout<<"yes\n";
			while(dob.dd != d.dd || dob.mm != d.mm || dob.yy != d.yy)
			{
				++dob;
				cout<<dob.dd<<"/"<<dob.mm<<"/"<<dob.yy<<"\n";
			}	
		}
		else
		{
			while(dob.dd != d.dd || dob.mm != d.mm || dob.yy != d.yy)
			{
				--dob;
				cout<<dob.dd<<"/"<<dob.mm<<"/"<<dob.yy<<"\n";
			}	
		}	
	}	

	
	avg = 0.0;
}

	




void fStudent::tot_avg(Student& x)
{
	for(int i = 0; i < 6;++i)
		x.avg += x.marks[i];

	x.avg /= 6; 
}

void fStudent::leap(const Student& x)
{
	if(x.dob.yy % 100 == 0 && x.dob.yy % 400 == 0)
	{
		cout<<"\n You were born during a leap year ! :)\n";
	}	
}

void fStudent::lastDate(const Student& x)
{
	switch(x.dob.mm)
	{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12: if (x.dob.dd == 31)
					cout<<"\nIt is the last day of the month \n";
				 break;
		case 4 :
		case 6:
		case 9:
		case 11: if (x.dob.dd == 30)
					cout<<"\nIt is the last day of the month \n";
				 break;
		case 2: if ((x.dob.yy % 100 == 0 && x.dob.yy % 400 == 0 && x.dob.dd == 29) || x.dob.dd == 28)
					cout<<"\nIt is the last day of the month \n";
				 break;

		default: cout<<"\nInvalid month ! Error in code\n";

	}
}

void fStudent::display(Student& x)
{
	cout<<"\nStudent details:\n";
	cout<<"______________________________\n";
	cout<<"\nID No. : "<<x.studentID;
	cout<<"\nName :\t"<<x.name;
	cout<<"\nD.O.B :\t"<<x.dob.dd<<"/"<<x.dob.mm<<"/"<<x.dob.yy;
	cout<<"\nMARK LIST\n";

	for(int i = 1; i <= 6;++i )
		cout<<"\nSubject "<<i<<"  "<<x.marks[i-1];

	tot_avg(x);

	cout<<"\n\nAverage marks = "<<x.avg<<"\n";
	lastDate(x);
	leap(x);

}
