//
//  FirstNonRepeatingCharacter.cpp
//  Number OfRepeatedChars
//
//  Created by Jyothyraj S on 13/02/2021.
//

#include "FirstNonRepeatingCharacter.hpp"
#include <string.h>
#include <iostream>
using namespace std;

char firstNotRepeatingCharacter(string s)
 {
     int a[256];
    for( int i = 0; i< 256; i++)
    {
        a[i] = 0;
    }
    for( int i = 0; i< s.length(); i++)
    {
        a[s[i]]++;
    }
    for( int i = 0; i< s.length(); i++)
    {
        if(a[s[i]] == 1)
            return s[i];
    }
        
       
   
    char ch = '_';
    return ch;

 }
