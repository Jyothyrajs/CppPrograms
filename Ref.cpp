

#include <iostream>
using namespace std;
inline int cube(int x)
{
	return(x*x*x);
}


class Ref
{
	int a,b;

	public:
	Ref(int x,int y)
	{
		a=x,b=y;	
	}
	void fun_pointer( int &a, int &b)
	{
		int x=a;
		a=b;
		b=x;
		std::cout<<a<<" "<<b;	
	}

	void fun_reference(int& a,int& b)
	{
		std::cout<<a<<" "<<b;	
	}
};

int main()
{
	int x=5,y=10,z=0,c;
	c=cube(z++);
	cout<<"z= "<<z<<endl<<"Cube of c"<<c;
	Ref r(x,y);
	r.fun_pointer(x,y);
//	r.fun_reference();
return 0;
}
