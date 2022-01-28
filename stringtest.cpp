#include<iostream>
#include<string>
using namespace std;
int main()
{
	string mystr ="Welcome";
	std::cout << mystr[0]<<endl;	
	cout << mystr.append("Hi") << endl;
	cout << mystr.append(mystr,3,1)<<endl;
	char ch = mystr[0];
	if( ch !=' ')
		cout << "Check" <<endl;
}
