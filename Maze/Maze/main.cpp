//Users/jyothyrajs/Documents/Programs/C++Programs/myInheritance/myInheritance/Pattern.hpp
//
//  main.cpp
//  Maze
//
//  Created by Jyothyraj S on 08/02/2021.
//

#include <iostream>

#define row 4
#define col 3

void print ( int sol[][3] )
{
    std::cout << "Safe path: " ;
    for(int i = 0; i < row; i++)
    for(int j = 0; j < col; j++)
    {
        if( sol[i][j] == 1)
            std::cout <<"[" << i << ","<< j <<"]->";
    }
    std::cout << std::endl;
}

bool mazepath ( int a[][3], int i, int j,  int sol[][col] )
{
    if(i == row-1 && j == col-1 && a[i][j] == 1 )
    {
        sol[i][j] = 1;
        return true;
    }
    
       
        if( ( i < row && j < col ) && a[i][j] == 1 )
        {

           if( mazepath( a,i+1,j,sol ) )
           {
               sol[i][j] = 1;
              return true ;
           }
            if( mazepath( a,i,j+1,sol) )
            {
                sol[i][j] = 1;
                return true;
            }
            sol[i][j] = 0;
            return false;
        }
        return false;
    
}


int path_count = 0;
void _mazepath ( int a[][3], int i=0, int j=0)
{
    if(i == row-1 && j == col-1 && a[i][j] == 1 )
    {
        path_count++;
        return;
    }
    
       
    if( ( i < row && j < col ) && a[i][j] == 1 )
    {
        _mazepath( a,i+1,j);
        _mazepath( a,i,j+1);
    }
}

int main()
{
    
    int a[row][col] = { {1,0,1},{1,1,1},{0,1,1},{1,1,1}};
    int sol[row][col];
    if ( mazepath( a,0,0,sol ) )
        print(sol);
    else
        std::cout << "No solution !!! " << std::endl;

    _mazepath(a);
    std::cout <<"No of paths :" << path_count << std::endl;
}


