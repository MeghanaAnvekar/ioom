#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include "mylist.h"

using namespace std;

long num_chars(FILE * fp);
long num_lines(FILE * fp);
long num_words(FILE * fp);

void find_chars(FILE * fp);
void find_identifiers(FILE * fp);
void find_numbers(FILE * fp);

void most_used_chars(int);
void most_used_identifiers(int);
void most_used_numbers(int);
int isaplha(char);
int isdigit(char);

mylist identifiers;
mylist numbers;
mylist chars;

int main()
{
	string file_name;
	
	cout<<"\nEnter the name of the file...";
	cin>>file_name;
	const char *file = file_name.c_str();
	int k = 5;

	FILE * fp = fopen(file,"r");
	
	if(fp == NULL)
	{
		cout<<"\nError : NO SUCH FILE EXISTS ! \n";
	}
	else if(feof(fp))
	{
		cout<<"\nError : EMPTY FILE\n";
		fclose(fp);
	}
	else
	{
		
		cout<<"\nNo. of  Characters = "<<num_chars(fp);
		cout<<"\nNo. of Lines = "<<num_lines(fp);
		cout<<"\nNo. of Words = "<<num_words(fp);

		find_chars(fp);
		find_identifiers(fp);
		find_numbers(fp);
		
		fclose(fp);	
		cout<<"\n";
		identifiers.print();
			
		numbers.print();
		
		chars.print();



		most_used_chars(k);
		cout<<"\n";
		most_used_numbers(k);
		cout<<"\n";
		most_used_identifiers(k);
	}

	return 0;

}

long num_chars(FILE * fp)
{
	fseek(fp,0L,SEEK_END);
	long i = ftell(fp);
	fseek(fp,0L,SEEK_SET);
	return i;
}

long num_lines(FILE * fp)
{
	long ctr = 0;
	char ch;

	while((ch = fgetc(fp)) && !feof(fp))
	{
		if(ch == '\n')
			++ctr;
	}

	fseek(fp,0L,SEEK_SET);
	return ctr;
}

long num_words(FILE * fp)
{
	int ctr = 0;
	char ch;
	//skipping initial spaces if any
	while((ch = fgetc(fp))!= EOF && (ch == ' ' || ch == '\t'))
		;

	while((ch = fgetc(fp)) && !feof(fp))
	{
		if(ch == ' ')
			ctr++;
	}

	fseek(fp,0L,SEEK_SET);
	return ctr;

}

void find_identifiers(FILE * fp)
{
	
	char ch;
	while((ch = fgetc(fp)) != EOF )
	{
		string id;
		if(id.length() == 0 && isaplha(ch))
		{	id += ch;
			
			while((ch = fgetc(fp))  != EOF && (isaplha(ch) || isdigit(ch)) )
				id += ch;
			for (int i =0; i < id.length();++i)
				if(isaplha(id[i]))
				id[i] = tolower(id[i]);
				
			if(!identifiers.searchandinc(id))
			{
				mylist aux;
				int found_place = 0;
				
				while(!found_place && identifiers.length())
				{
					listnode temp = identifiers.front();
					
					if(strcmp(temp.s.c_str(),id.c_str()) < 0 )
					{
						identifiers.removefront();
						aux.insertfront(temp.s,temp.count);
					}
					else
						found_place = 1;
				} 
				
				identifiers.insertfront(id,1);
				
				
				while(aux.length())
				{
					listnode temp = aux.front();
					aux.removefront();
					identifiers.insertfront(temp.s,temp.count);
					
				}
				
				
			}
			
			
			
		}
		
	}
	fseek(fp,0L,SEEK_SET);
}

void find_numbers(FILE *fp)
{

	char ch;
	string num;
	
	while((ch = fgetc(fp)) != EOF )
	{
		if(num.length() == 0 && isdigit(ch))
		{
			num += ch;

			while( (ch = fgetc(fp)) != EOF && isdigit(ch))
			{
				num += ch;
			}
	
		    if(!numbers.searchandinc(num))
			{
				mylist aux;
				int found_place = 0;
				
				while(!found_place && numbers.length())
				{
					listnode temp = numbers.front();
					
					if(strcmp(temp.s.c_str(),num.c_str()) < 0 )
					{
						numbers.removefront();
						aux.insertfront(temp.s,temp.count);
					}
					else
						found_place = 1;
				} 
				
				numbers.insertfront(num,1);
				
				while(aux.length())
				{
					listnode temp = aux.front();
					aux.removefront();
					numbers.insertfront(temp.s,temp.count);
				}
			}
		    num ="";
		}
	}

	fseek(fp,0L,SEEK_SET);

}

void find_chars(FILE * fp)
{
	char ch;

	while((ch = fgetc(fp)) != EOF)
	{
		string str;
		str += ch;
		if(!chars.searchandinc(str))
			{
				mylist aux;
				int found_place = 0;
				
				while(!found_place && chars.length())
				{
					listnode temp = chars.front();
					
					if(strcmp(temp.s.c_str(),str.c_str()) < 0 )
					{
						chars.removefront();
						aux.insertfront(temp.s,temp.count);
					}
					else
						found_place = 1;
				} 
				
				chars.insertfront(str,1);
				
				while(aux.length())
				{
					listnode temp = aux.front();
					aux.removefront();
					chars.insertfront(temp.s,temp.count);
				}
			}
	}
	fseek(fp,0L,SEEK_SET);
}

void most_used_numbers(int k)
{
	int ctr = k;
	
	while(ctr-- && numbers.length())
	{
		listnode * temp = numbers.findmaxcount();
		cout<<endl<<ctr+1<<"th most used number "<<temp->s;
		numbers.removemaxcount();

		
		
	}
	
}

void most_used_identifiers(int k)
{
	int ctr = k;
	
	while(ctr-- && identifiers.length())
	{
		listnode * temp = identifiers.findmaxcount();
		cout<<endl<<ctr+1<<"th most used identifier "<<temp->s;
		identifiers.removemaxcount();
		
		
	}
	
}

void most_used_chars(int k)
{
	int ctr = k;
	
	while(ctr-- && chars.length())
	{
		listnode * temp = chars.findmaxcount();
		cout<<endl<<ctr+1<<"th most used character "<<temp->s;
		chars.removemaxcount();
		
			
	}
	
}

int isaplha(char c)
{
	if( c >= 'A' && c <='Z' || c >='a' && c <= 'z')
		return 1;
	else
		return 0;
}
int isdigit(char c)
{
	if(c >= '0' && c <= '9')
		return 1;
	else
		return 0;
}
