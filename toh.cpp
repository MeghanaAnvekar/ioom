#include <iostream>

using namespace std;

class Rod
{
	private:
		int* arr;
		int top;
		int size;
	
	public:
		Rod(int n)
		{
			arr = new int[n];
			top = 0;
			size = n;
		}
		
		~Rod()
		{
			delete arr;
		}
		
		int push(int disk)
		{
			if(top == size)
				return 0;
			else
				arr[top++] = disk;
			return 1;
		}
		
		int pop()
		{
			if(!top)
				return 0;
			else
				top--;
			return 1;
		}
		
		int peek()
		{
			if(top == 0)
			return -1;
			else
			return arr[top-1];
		}


};
class TowersOfHanoi
{
	private: Rod *a,*b,*c;
	
	public:
		TowersOfHanoi(int n)
		{
		   a = new Rod(n);
		   b = new Rod(n);
		   c = new Rod(n);
		}
		
		~TowersOfHanoi()
		{
			delete a;
			delete b;
			delete c;
		}
};

