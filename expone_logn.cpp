


//Find expenential in logn : recursion, Iteration with binary & exponential modulo


#include<iostream>
using namespace std;
long long binpow_rec( int a, int n)
{
    
    if( n == 0)
    {
        return 1;
    }
    long long res = binpow_rec( a, n/2);
    if ( n%2 )
    {
          return res*res*a;
    }
    else
         return res * res;
   
}
long long binpow_iter( int a, int n)
{
    long long res = 1;
     while( n )
    {
        if( n & 1 )
        {
            res =  a*res;
        }
       
        a = a * a;
        n = n>>1;
    }
    return res;
}
long long binpow_modulo( int a, int n, int m)
{
     a= a % m;
    long long res = 1;
     while( n )
    {
        if( n & 1 )
        {
            res =  res * a % m;
        }
       
        a = a * a % m;
        n = n>>1;
    }
    return res;
}
int main()
{
    int a = 3;
    int n = 8;
    long long res = binpow_rec(a,n);

    cout << " Recursion : " << res << endl;
    res = binpow_iter(a,n);
    cout << " Binary Iteration : " << res << endl;
    int m = 5;
    res = binpow_modulo(a,n,m);
    cout << " Binary Modulo : " << res << endl;
}