//Find the maximum sub array 
#include<iostream>
using namespace std;

int maxSubArraySum(int a[], int size)
{
	int max_sum = INT_MIN;	
	int sum = 0;
	int start_indx = 0;
	int end_indx = 0;
	for(int i = 0; i<size; i++)
	{ 
   		 sum = a[i];
   		for (int j = i+1; j < size; j++)
   		{
			sum += a[j];
			if( sum > max_sum)
			{
				max_sum = sum ;
				start_indx = i;
				end_indx = j;
			}
		}

	}  
for( int i = start_indx; i<=end_indx; i++)
	printf("%d ",a[i]); 
return max_sum;
}
 
/* Driver program to test maxSubArraySum */
int main()
{
   int a[] =  {-2, -3, 4, -1, -2, 1, 5, -3};
   int n = sizeof(a)/sizeof(a[0]);
   int max_sum = maxSubArraySum(a, n);
   cout << "\nMaximum contiguous sum is " << max_sum;
   return 0;
}
