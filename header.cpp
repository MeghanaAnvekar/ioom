#include "header.h"
        Rod::Rod(int n)
		{
			arr = new int[n];
			top = 0;
			size = n;
		}
		Rod::~Rod()
		{
			delete arr;
		}
		int Rod::push(int disk)
		{
			if(top == size)
				return 0;
			else
				arr[top++] = disk;
			return 1;
		}
		int Rod::pop()
		{
			if(!top)
				return 0;
			else
				top--;
			return 1;
		}
		int Rod::peek()
		{
			if(top == 0)
				return -1;
			else
				return arr[top-1];
		}
		
		int Rod::at(int index)
		{
			if(index > -1 && index < size)
			{
				return arr[index];
			}
			else
			return -1;
		}
		int Rod::top_value()
		{
			return top;
		}
		TowersOfHanoi::TowersOfHanoi(int n)
		{
			a = new Rod(n);
			b = new Rod(n);
			c = new Rod(n);
			total_disks = n;
			for(int i = n; i> 0;--i)
				a->push(i);
		}
	
	TowersOfHanoi::~TowersOfHanoi()
	{
		delete a;
		delete b;
		delete c;
	}
	
	int TowersOfHanoi::valid(int disk,char des)
	{
		
		int retval = 1;
		if(disk > total_disks || disk < 1)
		{
			cout<<"ERROR : No such disk available !!!\n";
			retval =0;
		}
		 if( des !='a'&& des !='b' && des != 'c' && des != 'A' && des != 'B' && des != 'C')
		{
			cout<<"ERROR: No such rod exists !!!\n";
			retval =0;
		}
		 if(a->peek() != disk && b->peek() != disk && c->peek() != disk)
		{
			retval =0;
			cout<<"INVALID MOVE !!! disk not free to move\n";
		}
		
		return retval;
	}
	void TowersOfHanoi::move(int disk, char d)
	{
		Rod *src,*des;
		 
		if(valid(disk,d))
		{
			if(a->peek() == disk)
				src = a;
			else if(b->peek() == disk)
				src = b;
			else
				src = c;
			
				
			if(d == 'a')
				des = a;
			else if(d == 'b')
				des = b;
			else
				des = c;
				
			if(src != des)
			{
				if(des->top_value() > 0 && des->peek() < disk)
				{
					cout<<"INVALID MOVE !!! bigger disk can't be placved over smaller disk\n";
				}
				else
				{
					src->pop();
					des->push(disk);
				}
			}
			
		}
	} 
	
	int TowersOfHanoi::won()
	{
		int i,j;
		if(c->top_value() == total_disks)
			for( i = total_disks -1, j =1; c->at(i) == j && i>=0;--i,++j);
			
			if(j == total_disks+1 && i == -1)
			{
				return 1;
			}
			else
			{
				return 0;
			}
			
	}
	
	void TowersOfHanoi::print()
	{
		int height_a = a->top_value();
		int height_b = b->top_value();
		int height_c = c->top_value();
		
		int max = (height_a > height_b) ? height_a:height_b;
		
		max = (max > height_c) ? max:height_c;
		cout<<"\n\n";
		for(int i = max-1; i >= 0; --i)
		{
			if(i <= a->top_value()-1)
			{
				
				printf("%2d \t",a->at(i) );
			}
			else
			cout<<"  \t";
			
			if(i <= b->top_value()-1)
			{
				
				printf("%2d \t",b->at(i) );
			}
			else
			cout<<"  \t";
			
			if(i <= c->top_value()-1)
			{
				
				printf("%2d \t",c->at(i) );
			}
			else
			cout<<"  \t";
			
			cout<<"\n";
		}
		cout<<"---\t---\t---\n";
		cout<<" a \t b \t c \n\n";
	}
	
	
	
