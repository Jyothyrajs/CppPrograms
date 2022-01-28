//
//  main.cpp
//  Techgig_Test
//
//  Created by Jyothyraj S on 02/02/2021.
//


#include <iostream>
using namespace std;
int main()
{
    int count;
    cin >> count;
    
    int ls = count;
    for(int i = 1; i <= count; i++)
    {
        char ch = 'A';
        for(int k = ls; k >= 0; k--)
            cout <<  " ";
        ls--;
        for(int j = 1; j <= i; j++)
        {
            cout << ch << " " ;
            ch++;
        }
        cout << endl;
    }
    cout << endl;
}
