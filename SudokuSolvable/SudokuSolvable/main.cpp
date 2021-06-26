#include <iostream>
#include <vector>
using namespace std;

bool isInSquare( int p, int q, vector<vector<char>>& grid, int ch)
{
    int r = (p/3) *3;
    int c = (q/3) * 3;
    int _r = r+3;
    int _c = c+3;
    for(int i = r; i < _r; i++)
    {
        for(int j = c; j < _c; j++)
        {
            if(grid[i][j] == ch)
                return true;
        }
    }
    return false;
}

bool isInRow( int p,   vector<vector<char>>& grid, char ch)
{
    for(int j = 0; j < 9; j++)
    {
        if( grid[p][j] == ch )
        {
            return true;
        }
    }
    return false;
}

bool isInColumn( int q,  vector<vector<char>>& grid, char ch)
{
    for( int i = 0; i< 9; i++)
    {
        if( grid[i][q] == ch)
        {
            return true;
        }
    }
    return false;
}

void getPossibleValues(int i, int j,vector<vector<char>>& grid, vector<char> &pv )
{
    pv.clear();
    for( char ch = '1' ; ch <= '9'; ch++)
    {
        if(!isInSquare(i,j,grid,ch) && !isInRow(i, grid, ch) && !isInColumn(j,grid,ch))
        {
            //std::cout << ch;
            pv.push_back(ch);
        }
    }
    //for( int i = 0; i < pv.size(); i++)
      //  std::cout << pv[i] << "\t";
}


bool sudoku2(vector<vector<char>>& grid)
{
    vector<char> pv;
    for( int i = 0; i < 9; i++)
    {
        for( int j = 0; j < 9; j++)
        {
            if( grid[i][j] == '.' )
            {
                getPossibleValues( i,j, grid, pv);
                std::cout <<"possible values at ("<<i <<", " << j <<"): ";
                std::copy(pv.begin(), pv.end(), ostream_iterator<char>(cout, ", ") );
                const int s = pv.size();
                for( int k = 0; k < s; k++)
                {
                    std::cout <<std::endl << "Trying out : " << pv[k] << " at " << i <<", "<<j << std::endl;
                    grid[i][j] = pv[k];
                    if( sudoku2(grid))
                        return true;
                    std::cout <<std::endl << "Failed: " << pv[k] << " at " << i <<", "<<j << std::endl;
                    
                }
                grid[i][j] = '.';
                return false;
            }
            
            
        }
    }
    return true;
    
}


int main(int argc, const char * argv[])
{
    char a[9][9] = {{'.','.','4','.','.','.','6','3','.'},
                    {'.','.','.','.','.','.','.','.','.'},
                    {'5','.','.','.','.','.','.','9','.'},
                    {'.','.','.','5','6','.','.','.','.'},
                    {'4','.','3','.','.','.','.','.','1'},
                    {'.','.','.','7','.','.','.','.','.'},
                    {'.','.','.','5','.','.','.','.','.'},
                    {'.','.','.','.','.','.','.','.','.'},
                    {'.','.','.','.','.','.','.','.','.'}};

    vector<vector<char>> grid;
    for(int i=0; i < 9; i++)
    {
        grid.push_back(vector<char>(9, '.'));
    }
    
    for(int i = 0; i< 9; i++)
    {
        for(int j=0; j <9; j++)
            grid[i][j] = a[i][j];
    }
    std::cout << "11111111111111111111111\n";

    std::cout << std::boolalpha << sudoku2(grid);
    std::cout << "11111111111111111111111\n";
std::cout << "Hello, World!\n";
    return 0;
}
