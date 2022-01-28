

/* Sum of n numbers*/

#include<iostream>

int main()
{
	int i,sum=0,limit;
	std::cout<<"Enter the limit\n";
	std::cin>>limit;
	for(i=1;i<=limit;i++)
		sum+=i;
	std::cout<<"Sum="<<sum<<"\n";
}
	
