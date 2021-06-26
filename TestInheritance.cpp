

#include<iostream>

using namespace std;

class A
{
	int i,j;
	public:A();
	A(int,int);
	void read();
	void display();
};
A::A()
{
	i=0;
	j=0;
}
A::A(int x,int y)
{
	i=x;
	j=y;
}
void A::read()
{
	cout<<"Enter i:";
	cin>>i;
	cout<<"Enter j:";
	cin>>j;
}
void A::display()
{
	cout<<" i:"<<i<<"\n";
	cout<<" j:"<<j<<"\n";
}

class B:public A
{
	int k;
	public:B();
	B(int x,int y,int z);
/*
	B(int x,int y,int z):A(x,y)
	{
		k=z;
	}
*/
	void read();
	void display();
};
B::B()
{
	k=0;
}
B::B(int x, int y,int z):A(x,y)
{
	k=z;	
}
void B::read()
{
	A::read();
	cout<<"Enter k:";
	cin>>k;
}
void B::display()
{
	A::display();
	cout<<" k:"<<k<<"\n";
}

int main()
{
	A a1;
	A a2(10,20);
	B b1;
	B b2(100,200,300);
	a1.display();
	cout<<"a1 after read\n";
	a1.read();
	a1.display();
	a2.display();
	b1.display();
	b2.display();
	return 0;
}
