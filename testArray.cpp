

#include<iostream>
void manip_list(int[]);
using namespace std;
main()
{
	int list[]={6,7,4,3};
	manip_list(list);
	cout<<list[0];
}


void manip_list(int x[4])
{
	int y=56,i;
	x=&y;
	for(i=0;i<4;i++)
	cout<<x[i]<<"\n";
}

