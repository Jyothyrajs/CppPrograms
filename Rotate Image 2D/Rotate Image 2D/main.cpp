//
//  main.cpp
//  Rotate Image 2D
/*a:
[[1,2,3],
 [4,5,6],
 [7,8,9]]
Output:
[[7,4,1],
 [8,5,2],
 [9,6,3]]
Expected Output:
[[7,4,1],
 [8,5,2],
 [9,6,3]]*/
//
//  Created by Jyothyraj S on 14/02/2021.
//

#include <iostream>
vector<vector<int>> rotateImage(vector<vector<int>> a)
{
    vector<vector<int>> ri;
    size_t r = a.size();
    size_t c = 0;
    if( r!=0 )
        c = a[0].size();
    else {
        return ri;
    }
        
    for(int i = 0; i< c; i++)
    {
        ri.push_back(vector<int>(r, 0));
    }
    
    
    for(int i = 0; i< a.size(); i++)
    {
        for (int j = 0; j < a[i].size(); j++)
        {
            ri[j][a.size()-i-1] = a[i][j];
        }
    }
    return ri;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
