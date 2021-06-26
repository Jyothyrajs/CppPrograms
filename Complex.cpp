#include<iostream>

using namespace std;
class Complex
{
	public: double *re,*im;
	Complex(const double &r,const double &m)
	{
		re=new double(r);
		im=new double(m);

	}
};
int main()
{
	double x,y,z;
	cin>>x>>y>>z;
	Complex n1(x,y);
	cout<<*n1.re<<"+"<<*n1.im<<"i";
	return 0;
}
