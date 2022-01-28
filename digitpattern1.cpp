

/*Program prints the digit pattern with the line number input

1 2 3 4
1 2 3
1 2
1

*/


#include<iostream>
int main()
{
	int linelimit,j;
	std::cout<<"Enter line limit\n";
	std::cin>>linelimit;
	for(int i=1; i<=linelimit;)
	{	j=linelimit;
		while(j)
		{		
			std::cout<<i;
			std::cout<<" ";
			j--;
			i++;
		}
		linelimit--;i=1;
		std::cout<<"\n";
	}
}
