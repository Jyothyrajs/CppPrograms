



/* Reverse of an Octal*/


#include<iostream>
int powerfunction(int,int);
int main()
{
	int i,quotient,number,Reverse_number=0,remainder,octal_number=0;
	std::cout<<"Enter the inetger number to reverse:";
	std::cin>>number;
//Octal Conversion
	for(i=number;i>0;)
	{
//		sum_of_digits+=remainder;
		remainder=i%8;

		i=i/8;

		octal_number+=i;
		i=remainder;
//Shift a position left
		if(i!=0)
			octal_number=octal_number*10;
	}
//Reverse
	/*int k=number;
	--j;//number of digits
	for(j;j>=0;j--)
	{
		
		remainder=k%8;
		Reverse_number+=(remainder*(powerfunction(8,j)));
		k=k/8;
	}*/


std::cout<<"Equivalent Octal Number:"<<octal_number<<"\n";

std::cout<<"Reverse:"<<Reverse_number<<"\n";

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

