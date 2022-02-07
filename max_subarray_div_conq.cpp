//Find the maximum sub array using divide and conquer 
#include<iostream>
using namespace std;

int max ( int a, int b)
{
	return( (a>b)?a:b);
}

int max (int a, int b, int c)
{
	return(max(max(a,b),c));
}
int max_crossing_sum( int a[],  int l, int m, int r )
{
	int left_sum = INT_MIN;
	int sum = 0;
	for( int i =l; i<=m; i++)
	{
		sum += a[i];
		if( sum > left_sum )
		{
			left_sum = sum;
		}

	}
	int right_sum = INT_MIN;
	sum = 0;
	for( int i =m+1; i<r; i++)
	{
		sum += a[i];
		if( sum > right_sum )
		{
			right_sum = sum;
		}

	}
	sum =  ( max( left_sum + right_sum, left_sum, right_sum));
	printf("%d %d %d\n", left_sum, right_sum,sum);
	return sum;
}

int maxSubArraySum(int a[], int l, int h)
{
	if( l == h)
		return a[h];
	
	int m = (l+h)/2;
	return  max(maxSubArraySum(a,l,m),maxSubArraySum(a,m+1,h), max_crossing_sum(a,l,m,h));
}  
 
/* Driver program to test maxSubArraySum */
int main()
{
   int a[] =  {-2, -3, 4, -1, -2, 1, 5, -3};
   int n = sizeof(a)/sizeof(a[0]);
   int max_sum = maxSubArraySum(a,0, n);
   cout << "\nMaximum contiguous sum is " << max_sum;
   return 0;
}
