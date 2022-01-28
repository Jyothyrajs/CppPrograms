
#include<iostream>
#include<algorithm>

using namespace std;

bool srt(int i,int j)
{
	return(i<j);	
}

int main()
{
	int data[]={52,76,19,5,10,100,56,98,17};
	sort(data+1,data+8,srt);
	for(int i=0;i<9;i++)
		cout<<data[i]<<" ";	
	return 0;
}
