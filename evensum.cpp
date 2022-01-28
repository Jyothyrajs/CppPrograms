


/* Sum of even numbers between a & b */


#include<iostream>

int main()
{
	int lowerlimit,upperlimit,sum=0,i;
	std::cout<<"Enter lower and upper limits\n";
	std::cin>>lowerlimit>>upperlimit;
	for(i=lowerlimit;i<=upperlimit;i++)
	{
		if(i%2==0)
			sum=sum+i;
	}
	std::cout<<"Sumof even numbers between"<<lowerlimit<<"and"<<upperlimit<<":"<<sum<<"\n";
	
}


