

#include<iostream>
using namespace std;
int sum(int a,int b,int c)
{
	return a+b+c/2;
}

int main()
{
	int (*function_pointer)(int,int,int);
	function_pointer=sum;	
	cout<<function_pointer(2,3,4);
	return 0;
}

