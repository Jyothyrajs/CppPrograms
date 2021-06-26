#include<iostream>
#include<string.h>
using namespace std;
int main(void)
{

/*	int x=10,y=20;
	int *ptr=&x;
	int &ref=y;
	cout<<ptr<<endl;
	y++;
	*ptr;
	ref++;
	cout<<"X:"<<x<<"\n";
	cout<<"Y:"<<y<<"\n";
	cout<<"Ptr:"<<*ptr<<"\n";
	cout<<"*Ptr++:"<<*++ptr<<"\n";

	cout<<"&y:"<<&y<<"\n";
	cout<<"Ptr:"<<ptr<<"\n";
*/
	string str1="Welcome";
	char st[19]="Programming";
	string str2="Jyothy";
	string str3=str1+str2;
	cout<<str3;
	cout<<strlen(st)<<"\n";
	for(int i=0;i<strlen(st)-1;i++)	
		cout<<st[i]<<"\n";
	return 0;
}
