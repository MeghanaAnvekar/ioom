#include "header.h"
int main()
{

	char ch = 'y';

	while(ch == 'y')
	{
		int n;
	
		repeat:
		cout<<"********************************************************************\n";
		cout<<"                  	Towers of Hanoi                             \n";
		cout<<"********************************************************************\n";
		cout<<"\n\nPlease enter the height of the tower (No. of disks) ......";
		cin>>n;
		TowersOfHanoi game(n);
		int choice,won;
		while( !(won = game.won()))
		{
			game.print();
			cout<<"\n\n1. MOVE  (disk no. ,destination)  2.QUIT\n\n";
			cin>>choice;
		
			if(choice == 1)
			{
			
				int disk; char des;
				cin>>disk>>des;
			
				game.move(disk,des);
			}
			else
			   exit(0);
		}
	
		if(won)
		{
			game.print();
			cout<<"\n\n\nCONGRATULATIONS !!! YOU WON THE GAME\n\n";
			cout<<"How about one more game...? (y/n)\n\n ";
		
		}
		cin >> ch;
	
		}
	return 0;
}

