//
//  main.cpp
//  CommonCharCount
//
//  Created by Jyothyraj S on 10/02/2021.
//

#include <iostream>
using namespace std;

int commonCharacterCount(string s1, string s2)
{
    int count = 0;
    int cc= 0;
    for(auto i = 0; i < s1.size(); i++)
   
    {
        char ch = s1[i];
        if( ch != '$')
        {
        int p = i;
        int q = 0;
        int c1 = 0;
        int c2 = 0;
            while(p < s1.size()  )
                    {
                        if(s1[p] == ch  )
                        {
                            s1[p] = '$';
                            
                            c1++;
                        }
                        p++;
                    }
                    while( q< s2.size() )
                    {
                               if(s2[q] == ch  )
                               {
                                   s2[q] = '$';
                                   
                                   c2++;
                               }
                        q++;
                               
                    }
                    if(c2 > 0)
                    {
                        cc = c1 > c2 ?c2:c1;
                
                        count = count + cc;
                    }
                    }
                }
                return count;
            }

int main()
{
    
    std::cout << "Hello, World!\n";
    std::cout << commonCharacterCount("aabcc","adcaa");
    return 0;
}
