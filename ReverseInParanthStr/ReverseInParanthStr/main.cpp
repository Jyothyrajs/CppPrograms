//
//  main.cpp
//  ReverseInParanthStr
//
//  Created by Jyothyraj S on 10/02/2021.
//

#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;


string reverseInParentheses(string inputString)
{
    char* res  = new char(inputString.length());
    int i = 0;
    int j = 0;
    stack<char> s;
    while( i< inputString.length() )
    {
        
        if( inputString[i] != '(' &&  inputString[i] != ')')
        {
            res[j++] = inputString[i++];
        }
        else
        {
            while( inputString[i] != ')')
                s.push(inputString[i++]);
            i++;
            if( inputString[i] != '(')
            {
                while( s.top() != '('  )
                {
                   res[j++] = s.top();
                    s.pop();
                }
                s.pop();
            }
            
        }
    }
    res[j] = '\0';
    return res;
}



int main(int argc, const char * argv[])
{
    string str = "foo(bar(baz))blim";
    
    std::cout << reverseInParentheses(str) << "\n";
    return 0;
}
