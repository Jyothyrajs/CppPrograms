//
//  my_string.hpp
//  Utilities
//
//  Created by Jyothyraj S on 16/12/2020.
//

#ifndef my_string_hpp
#define my_string_hpp

#include <stdio.h>
#ifndef __MY_STRING_H__
#define __MY_STRING_H__

enum CompareResult
{
    STR_LESSER = -1,
    STR_EQUAL,
    STR_GREATER
};

void ReadStr(char* msg, char *str);
void StrCopy(char* dest,char* src);
void StrConcate(char* str1, char* str2);
int StrLength(char* str);
enum CompareResult StrCompare(char* str1, char* str2);
char* StrCompareResult(enum CompareResult eResult);
void StrReverse(char* str);
void reverseWords( char* str);
void swap(char* p, char* q);//Swap two characters
char* FindString(char* str1, char* pattern);

#endif

#endif /* my_string_hpp */
