//
//  main.cpp
//  Right_Left_Lucky
//
//  Created by Jyothyraj S on 10/02/2021.
//

#include <iostream>

bool isLucky(int n)
{
    
    int ts = 0;
    int dc = 0;
    int x = n;
    while( x != 0 )
    {
        dc++;
        ts = ts + x%10;
        x = x/10;
        
    }
    int rs = 0;
    dc = dc /2;
     while ( dc)
     {
         rs = rs + n%10;
         dc--;
         n = n/10;
     }
     int ls = ts - rs;
     if( ls == rs)
        return true;
    return false;

}
int main(int argc, const char * argv[]) {
    
    std::cout <<isLucky(1230);
    return 0;
}
