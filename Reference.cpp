#include <iostream>

void swap(int&,int&);
void swap(int* p, int *q);

int main()
{
	int x=10,y=30;
	std::cout<<"X:"<<x<<" and y = " << y << "\n";
	swap(x,y);
	std::cout<<"X:"<<x<<" and y = " << y << "\n";
	swap(&x,&y);
	std::cout<<"X:"<<x<<" and y = " << y << "\n";
	return 0;
}
	
	void swap(int& a, int &b)
	{ 
		int temp;
		temp=a;
		a=b;
		b=temp;
		
	}
	void swap(int *a, int *b)
	{
		int temp=*a;
		*a=*b;
		*b=temp;
	}

