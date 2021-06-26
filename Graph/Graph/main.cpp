//
//  main.cpp
//  Graph
//
//  Created by Jyothyraj S on 11/12/2020.
//

#include <iostream>
#include "Utilities/Graph.hpp"


int main()
{
    Graph g1(6);
    g1.addEdge(0,1);
    g1.addEdge(1,2);
    g1.addEdge(0,3);
    g1.addEdge(2,3);
    g1.addEdge(2,4);
    g1.addEdge(3,5);

    bool *visited = new bool[g1.getVertices()];
    for ( int i = 0; i < g1.getVertices (); i++)
    {
        visited[i] = false;
    }
    std::cout << "\n BFS :  \t";
    g1.bfs(0,visited);
   
    for ( int i = 0; i < g1.getVertices (); i++)
    {
        visited[i] = false;
    }
    std::cout << "\n DFS :  \t";
    g1.dfs(0,visited);
    std::cout <<"\n";
    
    Graph g2(6);
    g2.addEdge(0,1);
    g2.addEdge(2,3);
    g2.addEdge(3,4);
   

    for ( int i = 0; i < g1.getVertices (); i++)
    {
        visited[i] = false;
    }
    g2.dfs(0,visited);
   // std::cout <<"Components: "<< g2.getComponents() << "\n";
    std::cout <<"\n";
}
    /*
     std::cout << "No of vertices :";
    int vertices;
    std::cin >> vertices;
    
    int** g = new int*[vertices];
    for ( int i = 0; i < vertices ; i++ )
        g[i] = new int[vertices];
   
   
    create( g , vertices );
    bool *visited = new bool[vertices];
    for ( int i = 0; i < vertices ; i++)
    {
        visited[i] = false;
    }
 //   bfs( g ,0, vertices, visited );
    dfs( g , 0, vertices, visited);
    
    std::cout << "\nHello, World!\n";
    return 0;
}

void create ( int *g[], int vertices)
{
    for ( int i = 0; i < vertices ; i++ )
        for ( int j = 0; j < vertices ; j++ )
            std::cin >> g[i][j];
    
}

void bfs ( int *g[] ,int start, int vertices, bool *visited )
{
    visited[start] = true;
    std::cout << start << "\t";
    
    for ( int i = 0; i < vertices; i++)
    {
        for ( int j = 0; j < vertices; j++)
            if ( g[i][j] && visited[j]!=true )
            {
                visited[j] = true;
                int k = j+1;
                std::cout << k << "\t";
            }
        
        
    }
}


void dfs ( int *g[] , int start,  int vertices, bool *visited  )
{
    visited[start]=true;
    int k =start;
    std::cout << k+1 << "\t";
    
    for ( int i = 0; i < vertices; i++ )
        {
            if ( g[start][i] && visited[i]!=true )
            {
                dfs(g, i, vertices, visited);
            }
        }
}
*/
    

