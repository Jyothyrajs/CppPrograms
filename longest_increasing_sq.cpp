

// Longest increasing sequence

#include <iostream>
#include<vector>

using namespace std;

int long_incr_sub_seq ( vector<int> a )
{
	int lis[a.size()];
	lis[0] = 1;
	for( int i = 1; i<a.size(); i++)
	{
		lis[i] = 1;
		for( int j = 0; j <= i; j++ )
		{
			if( a[i] > a[j] && lis[i] < lis[j]+1 )
			{
				lis[i] = lis[j] + 1;
			}
		}
	}
	int max = lis[0];
	for (int i = 1; i<a.size(); i++)
	{
		if( lis[i] > max )
			max = lis[i];
	}	
	return max;
}


int long_incr_seq(vector<int> a)
{
	int length = 0;
	int curr_length = 1;
	int curr_val = a[0];;
	int start_indx = 0;
	int end_indx = 0;
	for( int i = 1; i< a.size(); i++ )
	{
		if( a[i] > curr_val)
		{
			curr_length++;
		}
		else
		{
			
			if( curr_length > length )
			{
				length = curr_length;
				end_indx = i-1;
			}	
	
					curr_length = 1;
					start_indx = i;
		}
		curr_val = a[i];
	}
	if(length < curr_length)
	{
		length = curr_length;
		end_indx = a.size();
	}
	cout << "\nLong seq : \n"; 
	for( int i = start_indx; i < end_indx; i++ )
		cout << a[i] << " ";
	return length;
}


int main()
{
	vector<int> a = {1,2,3,2,3,1,54,46,58,87,98,202,1,23,2,3,4,23,45,46};
	cout << "\nLongest increasing Sub Sequence length : " << long_incr_sub_seq(a);
	cout << "\nLongest increasing Sequence length : " << long_incr_seq(a);
}
