//
//  Pattern.cpp
//  
//
//  Created by Jyothyraj S on 02/02/2021.
//

#include "Pattern.hpp"
#include <iostream>
using namespace std;
int main()
{
    int count;
    cin >> count;
    
    int ls = count;
    for(int i = 1; i <= count--; i++)
    {
        char ch = 'A';
        for(int j = 1; j <= i; j++)
        {
            for(int k = ls; k >= 0; k--)
                cout <<  " ";
            ls--;
            cout << ch ;
            ch++;
        }
        cout << endl;
    }
    cout << endl;
}
