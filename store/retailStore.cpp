#include"store.cpp"

int main()
{
	string store_name = "Spencer Home Appliances";
	
	RetailStore store(store_name);
	
	int run_loop = 1;
	int choice = 0;
		
	for(int i =0; i<100 && choice!=8;++i)
	{
		cout<<"\n***********************************************************************************\n";
		cout<<"                            SPENCER HOME APPLIANCES\n";
		cout<<"***********************************************************************************\n";
		cout<<"\n\nMenu :\n";
		cout<<"1. Add  Product\n2. Add Customer\n3. Book product\n4. Generate bill\n5. View Customer Details\n6.View All Customers"
			<<"\n7.View all Products\n8.Quit\n\n";
		cin>>choice;
		
		string name, status, productName;
		int qty,contact,count;
		float discount, price, amount;
		switch(choice)
		{
			case 1:	cout<<"\nEnter Product details....\n";
					cout<<"Name : ";
					cin.ignore();
					getline(cin,name);
					cout<<"Price : ";
					cin>>price;
					cout<<"Qty : ";
					cin>>qty;
					for(int i =0; i < qty;++i)
						store.addProduct(name,price);
					cout<<"\nProduct was added successfully !\n\n";
					break;
			
			case 2: cout<<"\nEnter Customer details....\n";
					cout<<"Name : ";
					cin.ignore();
					getline(cin,name);
					cout<<"Contact number: ";
					cin>>contact;
					store.addCustomer(name,contact);
					cout<<"\nCustomer was added successfully !\n\n";
					break;
			
			case 3: cout<<"\nEnter following details...\n";
					cout<<"\nCustomer Name : ";
					cin.ignore();
					getline(cin, name);
					cout<<"Contact number: ";
					cin>>contact;
					cout<<"Product Name : ";
					cin.ignore();
					getline(cin, productName);
					cout<<"Qty : ";
					cin>>qty;
					count = store.bookProduct(name,contact,productName,qty);
					cout<<"\n count = \n"<<count;
					if(count > 0)
						cout<<"\n\n"<<count<<"items were booked successfully !\n";
					else if(count < 0)
						cout<<"\nCustomer does not exist!\n";
					else
						cout<<"\nOut of Stock !\n";
					break;
			
			case 4: cout<<"\nEnter following details...\n";
					cout<<"\nCustomer Name : ";
					cin.ignore();
					getline(cin, name);
					cout<<"Contact number: ";
					cin>>contact;
					cout<<"\nDiscount : ";
					cin>>discount;
					amount = store.calculateNetAmount(name,contact,discount);
					if(amount < 0)
						cout<<"\nCustomer does not exist !\n";
					else
						{
							store.printBill(name,contact);
							cout<<amount<<endl;
						}
						
					break;
			
			case 5: cout<<"\nEnter following details...\n";
					cout<<"\nCustomer Name : ";
					cin.ignore();
					getline(cin, name);
					cout<<"Contact number: ";
					cin>>contact;
					store.viewCustomerDetails(name,contact);
					break;
					
			case 6: store.viewAllCustomers();
					break;
			case 7: store.viewAllProducts();
					break;
			case 8: choice = 8;
					break;
			default:cout<<"\nInvalid choice!!!";
					break;
					
					
					
		}
		
		
	}
	
	return 0;
}
