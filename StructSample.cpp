


/*
Program to implement structure
*/
#include<iostream>
#include <iomanip>
using namespace std;
struct Distance
{
	int iFeet;
	long fInches;

}d[2];
struct Room
{
	Distance length;
	Distance width;
};
int main()
{

	Room bedroom;
	bedroom.length.iFeet=12;
	bedroom.length.fInches=2.3;
	bedroom.width.iFeet=22;
	bedroom.width.fInches=1.3;
	 Distance d2={20,1.1L};
	 Distance d1={10,2.2L};
	//struct Distance d1,d2;
	cout<<"D1 Details\n"<<d1.iFeet<<"\t"<<d1.fInches;

	cout<<"\nD2 Details\n"<<d2.iFeet<<"\t"<<d2.fInches;
	cout<<endl<<"Size of fInches : "<<sizeof(d1.fInches)<<endl;
	cout<<endl<<"Size of iFeet: "<<sizeof(d1.iFeet)<<endl;
	cout<<endl<<"Size of Distance D1 : "<<sizeof(d1)<<endl;
	
	cout<<endl<<"Size of Distance D2: "<<sizeof(d2)<<endl;
	cout<<endl<<"Size of Room: "<<sizeof(bedroom)<<endl;
	float length=	bedroom.length.iFeet+bedroom.length.fInches;
	
	float width=	bedroom.width.iFeet+bedroom.width.fInches;

	cout<<"Room Details\n"<<"Length:"<<length<<"\n"<<"width:"<<width<<endl;
	
	cout<< "Size of Distance: "<<(&d[1].iFeet-&d[0].iFeet)<< endl;

	return 0;
}
