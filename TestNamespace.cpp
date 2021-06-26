#include<iostream>
using namespace std;
class Test
{
	int x,y;
	
	unsigned char str[8];
 
public:	void func(int z)
	{
		x=y=z;
		cout<<" "<<x<<" "<<y<<"\n";
	}
};

class Sample
{
public:	void display(Test t)
	{
		t.func(9);
	}
};
int main()
{
	Test t;
//	Test.x=1;
	cout<<sizeof(t);
	t.func(10);
//	cout<<Test.x;
	Sample e;
	e.display(t);
	return 0;
}
