class Product;
class Customer;

class RetailStore
{
	int customer_count;
	int product_count;
	String store_name;
	Product *product_list;
	int product_list_size;
	Customer *customer_list;
	int customer_list_size;
	
	public:
	
		RetailStore(String name)
		{
			store_name = name;
			product_list_size = 10;
			customer_list_size = 10;
			
			product_list = new Product[product_list_size]() ;
			customer_list = new Customer[customer_list_size]() ;
			
			product_count = 0;
			customer_count = 0;
			
		}
		
		int generateCustomerID()
		{
			 return ++customer_count;
			
		}
		
		int generateProductID()
		{
			return ++product_count;
		}
		
		int searchCustomer(String name, int contactNo)
		{
			int found = 0;
			
			for(int i = 0; i < customer_count;++i)
			if(customer_list[i].getCustomerName() == name && customer_list[i].getCustomerContactNo() == contactNo)
			{
				found = customer_list[i].getCustomerID();
				break;	
			}
			
			return found;
			
		}
		
		void addCustomer(String name, int contactNo)
		{
			if(!searchCustomer(name, contactNo))
			{
				if(customer_count > customer_list_size )
				{
					Customer *temp = new Customer[customer_list_size * 2];
					
					for(int i = 0; i < customer_list_size; ++i)
					{
						temp[i] = customer_list[i]; 
					}
					
					free customer_list;
					customer_list = temp; 
					customer_list_size *= 2;
				}
				
				customer_list[customer_count++] = Customer(generateCustomerID(),name,contactNo);
			}
		}
		
		void addProduct(String name, String status, float price)
		{
			if(product_count > product_list_size )
			{
				Product *temp = new Product[product_list_size * 2];
				
				for(int i = 0; i < product_list_size; ++i)
				{
					temp[i] = product_list[i]; 
				}
				
				free product_list;
				product_list = temp; 
				product_list_size *= 2;
			}
			
			product_list[product_count++] = Product(generateProductID(),name,status,price);
				
			
		}
		
		int checkProductAvailability(String name)
		{
			int count = 0;
			
			for(int i = 0; i < product_count;++i)
			if(product_list[i].getStatus() == String('Available'))
			{
				count++;
			}
			
			return count;
		}
		
		int bookProduct(int CustomerID,String ProductName, int NoOfProducts)
		{
			int available_product_count = checkProductAvailability(ProductName);
			if(NoOfProducts > available_product_count)
			{
				NoOfProducts = available_product_count;
			}
			
			int count = 0;
			
			if(CustomerID > 0 && CustomerID <= customer_count)
				for(int i = 0; i < product_count && count < NoOfProducts;++i)
					if(product_list[i].getProductName() == ProductName && product_list[i].getProductAvailability() == 'Available')
					{
						product_list[i].setProductAvailability('Booked');
						customer_list[CustomerID-1].addProduct(product_list[i]);
						count++;
					}
			else
				return 0;
				
			return count;
			
		}
		
		~RetailStore()
		{
			delete product_list;
			delete customer_list;
		}
	
}
