
//
//A Robot moves based on the command  Left, Right or Front. Find out number of moves to //return to its original position

#include <iostream>
using namespace std;

int changeDirection(int cur_dir,char cmd)
{
    if( cmd == 'R')
    {
        cur_dir = (cur_dir+1)%4;
    }
    else if( cmd == 'L')
    {
        cur_dir = (cur_dir+3)%4;
    }
    return cur_dir;
}

void makeMove( char cmd, int cur_dir, int &x, int &y  )
{
    switch( cur_dir )
    {
        case 0: y++;
                break;
        case 1: x++;
                break;
        case 2: y--;
                break;
        case 3: x--;
                break;
    }
    
}

int findMinMoves( int cur_dir, int x, int y)
{
    int num_moves = 0;
    if( x < 0)
    {
        if( cur_dir == 0 || cur_dir == 2 )
        {
            num_moves++;
        }
        else if( cur_dir == 3 )
        {
            num_moves = num_moves+2;
        }
    }
    else if( x > 0 )
    {
        if( cur_dir == 0 || cur_dir == 2 )
        {
            num_moves++;
        }
        else if( cur_dir == 1 )
        {
            num_moves = num_moves+2;
        }
        
    }
    
    if( y < 0)
    {
        if(cur_dir == 1 || cur_dir == 3 )
        {
            num_moves++;
        }
        else if( cur_dir == 2)
        {
            num_moves+=2;
        }
    }
    else if(y >0 )
    {
        if( cur_dir == 0 )
        {
            num_moves = num_moves+2;
        }
        else if(cur_dir ==1 || cur_dir == 3)
        {
            num_moves++;
        }
    }
    num_moves = num_moves + abs(x) +abs(y);
    return num_moves;
}

int flr(string directions)
{
    int cur_dir = 0;
    int x = 0;
    int y = 0;
    for( int i = 0; i< directions.length(); i++)
    {
        char cmd = directions[i];
        if( cmd == 'L' ||  cmd =='R')
        {
            cur_dir = changeDirection( cur_dir, cmd );
        }
        else if( directions[i] == 'F' )
        {
            makeMove ( cmd, cur_dir, x, y );
        }
    }
   return findMinMoves(cur_dir,x,y);
}

int main()
{
    string cmd = "LLRFR";
    std::cout << "No of Moves :" << flr(cmd) <<std::endl;
    return 0;
}
