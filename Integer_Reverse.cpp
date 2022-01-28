


/* Reverse of an Integer and the Sum of its Digits*/


#include<iostream>
int powerfunction(int,int);
int main()
{
	int i,number,Reverse_number=0,sum_of_digits=0,remainder;
	std::cout<<"Enter the Integer to reverse:";
	std::cin>>number;
	//Sum of digits
	for( i=number;i>0;)
	{
		remainder=i%10;
		Reverse_number+=remainder;
		sum_of_digits+=remainder;
		i=i/10;
		if(i!=0)
			Reverse_number=Reverse_number*10;//One digit left shift
	}

	std::cout<<"Reverse:"<<Reverse_number<<"\n";
	std::cout<<"Sum of Digits:"<<sum_of_digits<<"\n";

}

//Power Computation

int powerfunction(int number,int power)
{
	int value=1;
	if(power>1)
	{
		for(int k=1;k<=power;k++)
			value=value*number;	
			
		return value;
	}
	else
	{
		 if (power!=0)
			return number;
		else return 1;
	}
}	

