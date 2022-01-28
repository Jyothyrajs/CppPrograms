#include<vector>
#include<iostream>
using namespace std;

int longestTradingSeriesAtOnlyTwoPrices(vector<int> tradePrices) 
{
    
     if ( tradePrices.size() == 1)
        return 0;
    int start = 0, length = 1;
    int cur_start = 0, cur_length = 1;
    int a = tradePrices[0];
     int b ;
    for(int i=1; i<tradePrices.size(); i++)
    {
        b = tradePrices[i];
        if( tradePrices[i] != a ||  a !=tradePrices[i-1])
        {
            if( cur_length > length )
            {
                start = cur_start;
                length = cur_length;
            }
            cur_start = i; // mark the start of next sequence
            cur_length = 1;
    	cout << "Changed at " << cur_start <<"\n";
	  }
        else
        {
            cur_length++;
        }
    }
    if( cur_length > length )
    {
        start = cur_start;
    }
    return start;

}

int main()
{
vector<int> tradePrices = {10,20,20,10,20,20,20,20,10,13,1,3,4};
cout << longestTradingSeriesAtOnlyTwoPrices(tradePrices);
} 
