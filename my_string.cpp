//
//  my_string.cpp
//  Utilities
//
//  Created by Jyothyraj S on 16/12/2020.
//

//To do: complete reverse words in  a sentence

#include "my_string.hpp"
#include "Stack.hpp"

#include <iostream>
void ReadStr(char* msg, char* i)
{
    printf("%s: ",msg);
    scanf("%s",i);

}
void StrCopy(char* dest, char* src)
{
           
    char* s = src;
    char* d =dest;
    while(*s)
    {
        *d = *s;
        s++;
        d++;
    }
    *d = '\0';
}

void StrConcate(char* str1, char* str2)
{
    char* r = str1;
    while(*r)
        r++;
    StrCopy(r,str2);
}

int StrLength(char* str)
{
    int count = 0;
    char *p = str;
    while(*p)
    {
        count++;
        p++;
    }
    return count;
}
enum CompareResult StrCompare(char* str1, char* str2)
{
    char* p1 = str1;
    char* p2 = str2;
    while(*p1 && *p2)
    {
        char c = *p1 - *p2;

        if( c == 0 )
        {
            p1++; p2++;
        }
        else
        {
            if( c < 0)
                return STR_LESSER;
            else if ( c > 0)
                return STR_GREATER;
        }
    }

    if( *p1 )
    {
                return STR_GREATER;

    }
    else if( *p2 )
    {
                return STR_LESSER;
    }
    else
    {
        return STR_EQUAL;
    }
            
}
char* StrCompareResult(enum CompareResult eResult)
{
    switch(eResult)
    {
        case STR_LESSER: return "LESSER";
        case STR_GREATER: return "GREATER";
        case STR_EQUAL: return "EQUAL";
    }
}
void swap(char* p, char* q)
{
        char c = *p;
        *p = *q;
        *q = c;

}
void StrReverse(char* str)
{
   
    char* p = str;
    char* q = str + StrLength(str) - 1;
    while(p < q)
    {
        swap(p++, q--);
    }
}
/*
void reverseWords ( char* str )
{
    char* p = str;
   const char* x = "";
    Stack<char*> s;
    int wl = 0;
    int cl = 0;
    char* nl = "\n";
    while ( *p != *nl )
    {
        if ( *p == '\0')
        {
            wl++;
        }
        cl++;
    }
    
    char *temp = new char[wl];
    for ( int i = 0; i < wl; i++ )
    {
        temp[i] = new char[];
    }
    
    for ( int i = 0; i < cl; i++ )
    {
        p++;
        if ( *p == *x )
        {
            s.push(temp+i);
            
        }
        else
        {
            temp[i] = temp[i] + *p;
        }
        
    }
}
*/

char* FindString(char* str, char* pattern)
{
    char* p = str;
    char* c = p;
    char* q = pattern;
    while( *p &&  *q )
    {
        if( *p == *q )
        {
            p++;
            q++;

        }
        else
        {
            if ( *q )
            {
                c++;
                p = c;
                q = pattern;
            }
            else
            {
                return c;
            }
        }
    }
    if ( !( *p && *q ) )
        return c;
    return p;
}


