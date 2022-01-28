


/* Print the following Pattern

*
**
***

*/

#include<iostream>

int main()
{
	int linecount;
	std::cout<<"Enter number of lines  to limit the pattern\n";

	std::cin>>linecount;
	
	for(int i=1,j=i;i<=linecount;i++)
	{
		j=i;
		while(j)
		{
			std::cout<<"*";
			j--;
		}
		std::cout<<"\n";
	}
}

