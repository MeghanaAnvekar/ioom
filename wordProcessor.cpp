#include <iostream>
#include <fstream>
#include <map>
#include <ctype.h>
#include <locale>

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

map <string, int> identifiers;
map <string, int> numbers;
map <char, int> chars;

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
		map<string,int>::iterator i = identifiers.begin();cout<<"\n";
		cout<<"\n\n";
		for(;i != identifiers.end();i++)
			cout<<i->first<<" "<<i->second<<"\n";
			

cout<<"\n--------------------------\n\n";

		for(i = numbers.begin();i != numbers.end();i++)
			cout<<i->first<<" "<<i->second<<"\n";
cout<<"\n--------------------------\n\n";
		map<char,int>::iterator j = chars.begin();

		for(j = chars.begin();j != chars.end();j++)
			if(j->first != '\n' && j->first != '\t' )
			cout<<j->first<<" "<<j->second<<"\n";
			else
			{
				if(j->first == '\n')
					cout<<"\\n "<<j->second<<"\n";
				else if(j->first == '\t')
					cout<<"\\t "<<j->second<<"\n";
			}



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

			map<string,int> :: iterator i = identifiers.find(id);

			if(i == identifiers.end())
				identifiers.insert(pair <string, int>(id,1));
			else
				i->second ++;
			
		}
		
	}
	fseek(fp,0L,SEEK_SET);
}

void find_numbers(FILE *fp)
{

	char ch;
	string num;
	map <string,int> :: iterator i;
	while((ch = fgetc(fp)) != EOF )
	{
		if(num.length() == 0 && isdigit(ch))
		{
			num += ch;

			while( (ch = fgetc(fp)) != EOF && isdigit(ch))
			{
				num += ch;
			}
	
		    i  = numbers.find(num);

		    if(i == numbers.end())
		    	numbers.insert(pair <string,int>(num,1));
		    else
		    	i->second++;
		    num ="";
		}
	}

	fseek(fp,0L,SEEK_SET);

}

void find_chars(FILE * fp)
{
	char ch;
	map<char,int> :: iterator i ;

	while((ch = fgetc(fp)) != EOF)
	{
		i =  chars.find(ch);

		if(i == chars.end())
			chars.insert(pair<char,int>(ch,1));
		else
			i->second++;
	}
	fseek(fp,0L,SEEK_SET);
}

void most_used_numbers(int k)
{
	int ctr = k;
	map <string,int> :: iterator i,ptr;
	while(ctr-- && numbers.size())
	{
		int max = 0;
		for(i = numbers.begin(); i != numbers.end();i++)
			if(i->second > max)
			{	max = i->second;
				ptr = i;
			} 

		cout<<endl<<ctr+1<<"th most used number "<<ptr->first;
		numbers.erase(ptr);
	}
	
}

void most_used_identifiers(int k)
{
	int ctr = k;
	map <string,int> :: iterator i,ptr;
	while(ctr-- && identifiers.size())
	{
		int max = 0;
		for( i = identifiers.begin(); i != identifiers.end();i++)
			if(i->second > max)
			{	max = i->second;
				ptr = i;
			} 

		cout<<endl<<ctr+1<<"th most used identifier "<<ptr->first;
		identifiers.erase(ptr);
	}
	
}

void most_used_chars(int k)
{
	int ctr = k;
	map <char,int> :: iterator i,ptr;
	while(ctr-- && chars.size())
	{
		int max = 0;
		for(i = chars.begin(); i != chars.end();i++)
			if(i->second > max)
			{	max = i->second;
				ptr = i;
			} 
		if(ptr->first != '\t' && ptr->first !='\n')
		cout<<endl<<ctr<<"th most used character "<<ptr->first;

		if(ptr->first == '\t' )
			cout<<endl<<ctr<<"th most used character \t";

		if(ptr->first == '\n' )
			cout<<endl<<ctr<<"th most used character \n";
			chars.erase(ptr);
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
