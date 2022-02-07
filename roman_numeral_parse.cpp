

#include<iostream>
#include<regex>
using namespace std;

bool isValid( string str )
{
	std::regex expr("^M{0,3}(CM|CD|D?C{0,3})(XC|XL|L?X{0,3})(IX|IV|V?I{0,3})$");

	if( std::regex_match(str, expr ))
		return true;
	else
		return false;
}

int value(char r)
{
	if (r == 'I')
 	       return 1;
	  if (r == 'V')
        	return 5;
	if (r == 'X')
        	return 10;
	 if (r == 'L')
	        return 50;
	 if (r == 'C')
        	return 100;
	 if (r == 'D')
        	return 500;
	 if (r == 'M')
        	return 1000;
 
    return -1;
}


int toDecimal( string str )
{
	int val = 0;
	for(int i = 0; i<str.length(); i++)
	{
		int s1 = value(str[i]);
		if( i+1 < str.length() )
		{
			int s2 = str[i+1];
			if( s1 >= s2 )
			{
				val += s1;
			}
			else
			{
				val += s2-s1;
			}
		}
		else
		{
			val += s1;
		}
	}
	return val;
}
string toRoman( int number )
{
	int decimal[] = {1000,900,500,400,100,90,50,40,10,9,5,4,1}; //base values
	vector<string> symbol = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"}; 
	int i = 0;
	string roman = "";
	int num = number;
	while( num)
	{
		if(num/decimal[i] )
		{
			roman.append(symbol[i]);
			num -= decimal[i];
		}
		else
			i++;
	}
	return roman;
}

int main()
{
	string mystr = "CCL";
	if( isValid(mystr) )
	{
		int num = toDecimal(mystr);
		cout << "decimal Value : " << num;
		cout << "\nRoman Value: " << toRoman(num);
	}
	else
	{
		cout << "Invalid \n";
	}
	
}
