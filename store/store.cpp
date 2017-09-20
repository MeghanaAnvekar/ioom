#include<iostream>
#include<stdio.h>
#include<iomanip>
#include<string>

using namespace std;

class Product;
class Customer;
class RetailStore
{
	int customer_count;
	int product_count;
	string store_name;
	Product *product_list;
	int product_list_size;
	Customer *customer_list;
	int customer_list_size;
	
	public:
	
		RetailStore(string name);
		int searchCustomer(string name, int contactNo);
		void addCustomer(string name, int contactNo);
		void addProduct(string name, float price);
		int checkProductAvailability(string name);
		int bookProduct(string CustomerName,int contactNo,string ProductName, int NoOfProducts);
		float calculateNetAmount(string CustomerName,int contactNo, float discount);
		void printBill(string CustomerName,int contactNo);
		int generateCustomerID();
		int generateProductID();
		void viewCustomerDetails(string CustomerName,int contactNo);
		void viewAllCustomers();
		void viewAllProducts();
		~RetailStore();	
		
		
	
};


class Customer
{
	int customerID;
	string customerName;
	int contactNumber;
	int list_size;
	int list_count;
	Product * list;
	
	public:
	Customer();
	void setCustomerDetails(int id, string name, long number);
	void addBookedProduct(Product x);
	float getTotalAmount();
	string getCustomerName();
	int getCustomerContactNo();
	void printCustomerDetails();
	int getCustomerID();
	Product inListAtIndex(int i);
	int productListCount();
	
};

class Product
{
	int productID;
	string productName;
	string productStatus;
	float productPrice;


	public:
	Product();
	void setProductDetails(int id, string name, string status, float price);
	string getProductName();
	string getProductAvailability();
	string getStatus();
	void setProductAvailability(string status);	
	float getProductPrice();
	int getProductID();
	void printProductDetails();
	
	
};


RetailStore::RetailStore(string name)
{
	store_name = name;
	product_list_size = 10;
	customer_list_size = 10;
	
	product_list = new Product[product_list_size] ;
	customer_list = new Customer[customer_list_size] ;
	
	product_count = 0;
	customer_count = 0;
	
}

int RetailStore::searchCustomer(string name, int contactNo)
{
	int found = 0;
	
	for(int i = 0; i < customer_count;++i)
	if(customer_list[i].getCustomerName()==name && customer_list[i].getCustomerContactNo() == contactNo)
	{
		found = customer_list[i].getCustomerID();
		break;	
	}
	
	return found;
	
}
		
void RetailStore::addCustomer(string name, int contactNo)
{
	if(!searchCustomer(name, contactNo))
	{
		if(customer_count > customer_list_size )
		{
			Customer *temp = new Customer[customer_list_size * 2]();
			
			for(int i = 0; i < customer_list_size; ++i)
			{
				temp[i] = customer_list[i]; 
			}
			
			delete customer_list;
			customer_list = temp; 
			customer_list_size *= 2;
		}
		
		customer_list[customer_count - 1].setCustomerDetails(generateCustomerID(),name,contactNo);
	}
}
		
void RetailStore::addProduct(string name, float price)
{
	if(product_count == product_list_size )
	{
		Product *temp = new Product[product_list_size * 2];
		
		for(int i = 0; i < product_list_size; ++i)
		{
			temp[i] = product_list[i]; 
		}
		
		delete product_list;
		product_list = temp; 
		product_list_size *= 2;
	}
	
	product_list[product_count-1].setProductDetails(generateProductID(),name,string("Available"),price);
	
	
}
		
int RetailStore::checkProductAvailability(string name)
{
	int count = 0;
	const string temp = "Available";
	for(int i = 0; i < product_count;++i)
	if(product_list[i].getStatus()== temp)
	{
		count++;
	}
	
	return count;
}
		
int RetailStore::bookProduct(string CustomerName,int contactNo,string ProductName, int NoOfProducts)
{
	
	const string status = "Booked";
	int count = 0;
	cout<<CustomerName<<" "<<contactNo;
	int CustomerID =  searchCustomer(CustomerName, contactNo);
	if(CustomerID)
	{
		int available_product_count = checkProductAvailability(ProductName);
		if(NoOfProducts > available_product_count)
		{
			NoOfProducts = available_product_count;
		}
	
		for(int i = 0; i < product_count && count < NoOfProducts;++i)
			if(product_list[i].getProductName() == ProductName && product_list[i].getProductAvailability() ==  string("Available"))
			{
				product_list[i].setProductAvailability(status);
				customer_list[CustomerID-1].addBookedProduct(product_list[i]);
				count++;
			}
	}
	else
		return -1;
		
	return count;
	
}
		
inline float RetailStore::calculateNetAmount(string CustomerName,int contactNo, float discount)
{
	float amount = -1;int customerID =  searchCustomer(CustomerName, contactNo);
	if(customerID)
	{
		amount = customer_list[customerID-1].getTotalAmount();
		amount *= (1 - discount);
	}
	
	return amount;
}

void RetailStore::printBill(string CustomerName,int contactNo)
{
	int customerID =  searchCustomer(CustomerName, contactNo);
	if(customerID)
	{	
		Customer temp = customer_list[customerID-1];
		cout<<"\n\n                        SPENCERS HOME APPLIANCES\n";
		cout<<"________________________________________________________________________________________\n";
		cout<<"********************************* Invoice **********************************************\n";
		
		cout<<"Sr.No.       Product ID          Product Name              Price\n";
		cout<<"----------------------------------------------------------------\n\n";
		
		int list_count = temp.productListCount();
		for(int i =0; i < list_count;++i)
		{
			Product x = temp.inListAtIndex(i);
			cout<<"  "<<i+1<<"            ";
			cout<<left<<setw(10)<<x.getProductID();
			cout<<left<<setw(30)<<x.getProductName();
			cout<<left<<setw(20)<<x.getProductPrice();
			cout<<"\n";
		}
		
		cout<<"\n----------------------------------------------------------------\n";
		cout<<"                                             TOTAL = Rs.";
		
		
	}
}


inline int RetailStore::generateCustomerID()
{
	 return ++customer_count;
	
}

inline int RetailStore::generateProductID()
{
	return ++product_count;
}

void RetailStore::viewCustomerDetails(string CustomerName,int contactNo)
{
	int customerID =  searchCustomer(CustomerName, contactNo);
	if(customerID)
			customer_list[customerID-1].printCustomerDetails();
		else
			cout<<"\nCustomer does not exist !\n";
}

void RetailStore::viewAllCustomers()
{
	if(customer_count > 0)
		for(int i = 0; i < customer_count;++i)
			customer_list[i].printCustomerDetails();
	else
	 cout<<"No customers registered yet!";
}

void RetailStore::viewAllProducts()
{
	if(product_count  > 0)
	{
		cout<<"Sr no\t    Product ID\t\t  Product Name\t\tProduct Status\t\t        Price";
		for(int i = 0; i < product_count;++i)
		{	cout<<"\n  "<<i+1<<"\t";
			product_list[i].printProductDetails();
		}
	}
	else
		cout<"\nNo products in the store\n";
}
inline RetailStore::~RetailStore()
{
	delete[] product_list;
	delete[] customer_list;
}


Customer::Customer()
{
	customerID = 0;
	customerName  = "\0";
	contactNumber = 0;
	list_size = 10;
	list_count = 0;
	list = new Product[list_size];
}
void Customer::setCustomerDetails(int id, string name, long number)
{
	customerID = id;
	customerName = name;
	contactNumber = number;
	list_size = 10;
	list_count = 0;
	list = new Product[list_size];
}

void Customer::addBookedProduct(Product x)
{
	if(list_count == list_size )
		{
			Product *temp = new Product[list_size * 2];
			
			for(int i = 0; i < list_size; ++i)
			{
				temp[i] = list[i]; 
			}
			
			delete[] list;
			list = temp; 
			list_size *= 2;
		}
		
		list[list_count++] = x;
}
inline Product Customer::inListAtIndex(int i)
{
	return list[i];
}
inline int Customer::getCustomerID()
{
	return customerID;
}
inline string Customer::getCustomerName()
{
	return customerName;
}

inline int Customer::getCustomerContactNo()
{
	return contactNumber;
}

inline int Customer::productListCount()
{
	return list_count;
}

void Customer::printCustomerDetails()
{
	cout<<"\n\nCustomer ID : "<<customerID<<"\nCustomer Name : "<<customerName<<"\nCustomer Contact No. : "<<contactNumber;
	
	cout<<"\n ----------------------Product List----------------\n\n";
	if(list_count)
	{
		
		cout<<"Sr no\t\tProduct ID\t\tProduct Name\t\tPrice";
		for(int i  =0; i < list_count;++i)
		{	cout<<i+1<<"\t";list[i].printProductDetails();cout<<endl;
		}
	}
	else
		cout<<"Empty cart\n";
	
}


	
float Customer::getTotalAmount()
{
	float amount = 0;
	
	for(int i =0; i < list_count; ++i)
	
		amount += list[i].getProductPrice();
		
	return amount;
}

Product::Product()
{
	productID = 0;
	productName = "\0";
	productStatus,"\0";
	productPrice = 0.0; 
	
}

void Product::setProductDetails(int id, string name, string status, float price)
{
	productID = id;
	productName =  name;
	productStatus = status;
	productPrice = price; 
}


inline string Product::getProductName()
{
	return productName;
}

inline string Product::getStatus()
{
	return productStatus;
}
inline string Product::getProductAvailability()
{
	return productStatus;
}

inline void Product::setProductAvailability(string status)
{
	productStatus =  status ;
}

inline float Product::getProductPrice()
{
	return productPrice;
}

inline int Product::getProductID()
{
	return productID;
}

void Product::printProductDetails()
{
	cout<<"\t"<<left<<setw(13)<<productID<<"\t    "<<left<<setw(20)<<productName<<"  "<<productStatus<<"\t\t\t"<<left<<setw(20)<<productPrice<<"\n";
	
}

