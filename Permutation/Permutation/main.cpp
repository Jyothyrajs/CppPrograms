//
//  main.cpp
//  Permutation
//
//  Created by Jyothyraj S on 16/12/2020.
//

/* Permutation of string*/

#include <iostream>

#include <Utilities/my_string.hpp>

void permute(char* st,int n=0 )
{
    if( strlen(st) == n+1 )
    {
        std::cout << st <<"\n";
        return;
    }

    int s = StrLength(st);
    for(int i=n; i < s; i++)
    {
        char a[20];
        strcpy(a, st);
        char c = a[i]; a[i]=a[n]; a[n]=c;
        permute(a, n+1);
    }

}
int main()
{
    char str[] = "gromue";
    char patt[] = "lot";
   // std::cout << FindString(str, patt);
   //std::cout << "Input string :";
   // std::cin >> str;
    permute(str);
}
