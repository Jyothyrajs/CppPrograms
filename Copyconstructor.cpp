
#include <iostream>
using namespace std;

class Copyconstructor
{
	int number;
	string name;
	public:
	Copyconstructor(int value=10,string Sname="hi") //Default value 10 without passing parameter 
	{
		number=value;
		name=Sname;
	}
	
	Copyconstructor(const Copyconstructor& obj)
	{
		number=obj.number;
		name=obj.name;	
	}
	void print();
	void concate(const Copyconstructor&);
};

void Copyconstructor::print()
{
	cout<<"object: "<<this<<" number:"<<number<<"\t"<<"name:"<<name<<"\n";
}
void Copyconstructor::concate(const Copyconstructor& obj2)
{
	name=name+obj2.name;
}
int main()
{
	Copyconstructor C1(20,"hello");
	C1.print();
	Copyconstructor C2=C1;
	C2.print();
	Copyconstructor C3; //constructor with default value
	C3.print();
	C2.concate(C1);
	C2.print();
	return 0;
}
