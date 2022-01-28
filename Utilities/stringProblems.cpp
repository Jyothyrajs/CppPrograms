//
//  stringProblems.cpp
//  
//
//  Created by Jyothyraj S on 14/02/2021.
//

#include "stringProblems.hpp"
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
