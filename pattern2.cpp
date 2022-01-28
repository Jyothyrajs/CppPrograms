


/*  Print the Pattern

*****
****
***
**
*

*/

#include<iostream>

int main()
{
	int linelimit,i;
	std::cout<<"Enter line limit\n";
	std::cin>>linelimit;
	for(i=1;i<=linelimit;linelimit--)
	{

		int j=linelimit;
		while(j--)
			std::cout<<"* ";
		std::cout<<"\n";

	}
}
