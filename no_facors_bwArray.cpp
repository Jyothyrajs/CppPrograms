#include <iostream>
#include <vector>
using namespace std;


/*
Example


There are two numbers between the arrays:[2,4]  and [24,36]
6%2=0 6%6=0 24%6=0 36%6=0  for the first value.
12%2=0, 12%6=0 24%12 = 0, 36%12 = 0 for the second value. Return .
 * Complete the 'getTotalX' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY a
 *  2. INTEGER_ARRAY b
 */
vector<int> myfactors(int a)
{
    vector<int>  fs = {};
    for(int i= 2; i<a; i++)
    {
        if( a%i == 0)
        {
            fs.push_back(i);
        }
    }
    return fs;
}
bool isFactor(int elem, int fact)
{
	bool r = false;
	if( !elem % fact )
		r = true;
	return r;	
}
int getTotalX(vector<int> a, vector<int> b) 
{
    sort(a.begin(),a.end());
    int a_max =  a[a.size() - 1];
    sort(b.begin(),b.end());
    int b_min = b[0];
    vector<int> res = {};
    for( int i = a_max; i <= b_min; i++)
    {
	int j = 0;
        for( ; j<a.size(); j++)
        {
            	if(i%a[j] != 0)
                break;
    	}    
	int k =0;
	if(j == a.size())
        for(k=0 ; k<b.size(); k++)
        {
            	if(b[k]%i != 0)
                	break;
        }
	if(k== b.size())
            res.push_back(i);
    }
    for(int k = 0; k < res.size(); k++)
	cout << res[k]<<" " ;
	
    return res.size();
}

int main()
{
	vector<int> a = {2,4};
	vector<int> b = {16,32,96};
	cout << getTotalX(a,b); 
}
