


/*  Print the Pattern
1
2 2
3 3 3
4 4 4 4

*/

#include<iostream>

int main()
{
	int linelimit,i,j=1;
	std::cout<<"Enter line limit\n";
	std::cin>>linelimit;
	for(i=1;i<=linelimit;i++)
	{
		j=i;
		while(j)
		{
			std::cout<<i;
			std::cout<<" ";
			j--;
		}
		std::cout<<"\n";
	
	}
}
