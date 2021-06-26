//
//  main.cpp
//  SortWithTree
//
//  Created by Jyothyraj S on 10/02/2021.
//

#include <iostream>
#include <vector>
using namespace std;

vector<int> sortByHeight(vector<int> a)
{
    for( int k = 0; k < a.size(); k++ )
    {
        int i = k;
        for( int j = i+1; j < a.size();j++)
        {
            while( a[i] == -1)
            {
                i++;
             }
            while( a[j] == -1)
            {
                j++;
             }
                if( a[i]> a[j])
                {
                    int t = a[i];
                    a[i] = a[j];
                    a[j] = t;
                }
            
        }
    
    }
    for( auto&& item : a )
    {
        std::cout << item << " ";
    }
    return a;
}
int main(int argc, const char * argv[]) {
    std::cout << "Hello, World!\n";
    vector<int> a = {-1, 150,190,170,-1,-1,160,180};
    vector<int> sort_arr = sortByHeight(a);
    for( auto&& item : sort_arr )
    {
        std::cout << item << " ";
    }
    return 0;
}
