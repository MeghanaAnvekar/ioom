#include <iostream>
#include <stdio.h>
#include <stdlib.h>


using namespace std;
class Rod
{
	private:
	int* arr;
	int top;
	int size;
	public:
	 Rod(int n);
	~Rod();
	int push(int disk);
	int pop();
	int peek();
	int at(int index);
	int top_value();
		
};
class TowersOfHanoi
{
private: Rod *a,*b,*c;
	int total_disks;
public:
	 TowersOfHanoi(int n);
	~TowersOfHanoi();
	int valid(int disk,char des);
	void move(int disk, char d);
	int won();
	void print();
};

