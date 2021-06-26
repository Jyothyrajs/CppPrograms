//
//  main.cpp
//  Number OfRepeatedChars
//
//  Created by Jyothyraj S on 12/02/2021.
//

#include <iostream>
#include "Utilities/stringProblems.hpp"
using namespace std;
int main(int argc, const char * argv[])
{
    char ar[256];
    for( int i =0; i<256; i++)
    {
        ar[i] = 0;
    }
    string name = "Irinjalakudakkaran";
    for( int i = 0; i < name.length(); i++)
    {
        char ch = name[i];
        ar[ch] = ar[ch] +1;
    }
    int count = 0;
    for( int i = 0; i < 256; i++)
    {
        if( ar[i] > 0  )
            count++;
    }
    std::cout << "Repeated Chars count:" << count <<"\n";
    std::cout << "First Non reating Character: " << firstNotRepeatingCharacter(name) <<"\n";
    return 0;
}
