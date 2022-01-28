
#include<iostream>
//Program checks the number even or odd without % Operator
int main()
{
	int number;
	std::cout<<"Enter the number to check\n";
	std::cin>>number;
	int check=number/2;
	if (check*2==number)
	{
		std::cout<<"Number";
		std::cout<<number;
		std::cout<<" is Even\n";
	}
	else
	{
		std::cout<<"Number ";
		std::cout<<number;
		std::cout<<"is Odd\n";
		
	}
}
