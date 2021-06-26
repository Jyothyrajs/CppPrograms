//
//  main.cpp
//  LongestStrsVector
//
//  Created by Jyothyraj S on 10/02/2021.
//

#include <iostream>
#include <vector>
using namespace std;
vector<string> allLongestStrings(vector<string> inputArray)
{
    vector<string> longStrs ;
    int max = 0;
    for( auto i = 0; i < inputArray.size(); i++)
    {
        
        if( inputArray[i].length() == max )
        {
            longStrs.push_back(inputArray[i]);
            max = inputArray[i].length();
        }
        if( inputArray[i].length() > max )
        {
            
            while(!longStrs.empty())
            {
                longStrs.pop_back();
            }
            longStrs.push_back(inputArray[i]);
            max = inputArray[i].length();
        }
       
        
    }
    return  longStrs;
}

int main(int argc, const char * argv[])
{
    std::cout  << " Hello";
   string strArray[] = {"abat","aa","bcd", "abc", "a"};
    vector<string> inputArray ( strArray,strArray+5 );
    vector<string> res = allLongestStrings(inputArray);

    for( auto&& item : res )
    {
        std::cout << item << " ";
    }
    std::cout <<"\n";
    return 0;
}
