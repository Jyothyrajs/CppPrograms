#include<iostream>
using namespace std;

int main()
{
	//day (d+m+y+[y/4]+c)mod 7
	int d = 22;
	int m = 11;
	int y = 2021;
	int c = 21;
	int day = (d+m+y+y/4+c)%7;
	cout << day<< endl;
}
