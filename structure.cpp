#include<iostream>
using namespace std;
class Cube
{
	int side;
public:	Cube()
	{
		side=10;
	}
	int getside()
	{
		return side;
	}
	int area()
	{
		return(side*side*side);
	}
};
int main()
{

	Cube c;
	std::cout<<"Side:"<<c.getside();	
	int a=c.area();
	std::cout<<"\n"<<"Area:"<<a;
	return 0;
}
