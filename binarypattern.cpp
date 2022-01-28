


/*  Print the Pattern
1
2 2
3 3 3
4 4 4 4

*/

#include<iostream>

int main()
{
	int linelimit,i,j=1,k=1;
	std::cout<<"Enter line limit\n";
	std::cin>>linelimit;
	for(i=1;i<=linelimit;i++)
	{
		if(i%2!=0)
			k=1;		
		j=i;
		while(j)
		{
			std::cout<<k;
			std::cout<<" ";
			j--;
			if(k==1)
				k=0;
			else k=1;
		}
		std::cout<<"\n";
	
	}
}
