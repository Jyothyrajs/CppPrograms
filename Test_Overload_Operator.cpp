

#include<iostream>
using namespace std;
class Distance
{
	int iFeet;
	float fInches;
public: Distance();
	Distance(int,float);
	Distance(const Distance&);
	Distance operator ++();
	Distance operator ++(int);
	void operator ++();
	Distance operator =(Distance&);
	void display();
};

Distance::Distance()
{
	iFeet=0;
	fInches=0.0;
}
Distance::Distance(int x,float y)
{
	iFeet=x;
	fInches=y;
}
Distance::Distance(const Distance &d)
{
	iFeet=d.iFeet;
	fInches=d.fInches;
	
}

void Distance:: operator ++()
{
	iFeet++;
	fInches++;
}
Distance Distance:: operator ++()
{
	iFeet++;
	fInches++;
	return *this;
/*	Distance temp;
	temp.iFeet=++iFeet;
	temp.fInches=++fInches;
	return temp;
*/
}
Distance Distance:: operator ++(int x)
{
	iFeet++;
	fInches++;
	return *this;
}
Distance Distance:: operator =(Distance &d)
{
	iFeet=d.iFeet;
	fInches=d.fInches;
	return *this;
/*	Distance temp;
	temp.iFeet=++iFeet;
	temp.fInches=++fInches;
	return temp;
*/
	return *this;
}


void Distance::display()
{
	cout<<iFeet<<"\t"<<fInches<<"\n";
}
int main()
{
	Distance d(10,11.1);
	Distance d3(d);
	d.display();
	Distance d2=++d;
	d2.display();
	d2=d3++;
	d3.display();
	return 0;
}
	

