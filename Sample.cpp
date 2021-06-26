#include<iostream>
#include<string>
using namespace std;
class Sample
{
	
	public:string name,dob,addr;
	const int id;
	
	public:
	Sample(string nm,string ad,string db,int d) : name(nm),addr(ad),dob(db),id(d)
	{
		
		cout<<name<<"Created "<< " ";
	}
	void print_addr() const
	{
		dob="12-02-87";
		cout<<dob;	
	}
	void print_name()
	{
		cout<<name;
	}
	

	~Sample()
	{
		cout<<name<<"Destroyed "<< " ";
	}

};
static int count=1;

int main()
{
	const Sample e("Jyothy","gwyru","12-02-90",count++);
	Sample s;
	s.dob="12-02-87";
	s.print_addr();
	e.print_addr();
	e.print_name();
	return 0;
}
