
using namespace std;
#include<iostream>
void display(const char *,int);
void display2(char*,int);
int main()
{
	char p[]="Hello";
	const char *str="Welcome"; // using pointer to a character constant
	int count;
	char *data;
	display(str,3);
	cout<<"Enter String & number of times to print:";
	cin>>data;
	cin>>count;
//	display2(data,count);
	int i=0;
	cout<<"\n";
	cout<<"Character by character";
	cout<<"\n";
	while(p[i]!='\0')
		cout<<p[i++]<<" ";
	cout<<"\n";
	cout<<p;
	cout<<"\n";
	return 0;
}

void display(const char *s,int n)
{
	while(n>0)
	{
		cout<<s<<"\n";
		n--;
	}
}
void display2( char *s,int n)
{
	while(n>0)
	{
		cout<<s<<"\n";
		n--;
	}
}
