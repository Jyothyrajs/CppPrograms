//
//  Graph.cpp
//  Utilities
//
//  Created by Jyothyraj S on 11/12/2020.
//


#include <iostream>
#include "Graph.hpp"
#include "Queue.hpp"

Graph::Graph(int n)
    : vertices(n)
{
    components = 0;
    g = new int*[vertices];
    for( int i = 0; i<vertices; i++)
    {
        g[i] = new int[vertices];
    }
}

Graph::~Graph()
{
    bool *visited = new bool[vertices];
    for ( int i = 0; i < vertices; i++)
    {
        visited[i] = false;
    }
    deleteNode(0,visited);
    
}

void Graph::deleteNode( int start, bool *visited )
{
    
    visited[start] = true;
    
    for ( int i = 0; i < vertices; i++ )
        {
            if ( g[start][i] && visited[i]!=true )
            {
                deleteNode(i, visited);
                
            }
            
        }
   // std::cout <<  "Deleting " << start <<"\n";
    delete(g[start]);
}

int Graph::getVertices()
{
    return vertices;
}
int Graph::getComponents()
{
    return components;
}

void Graph::addEdge(int u, int v)
{
    g[u][v] = 1;
    g[v][u] = 1;
}

void Graph::dfs(int start, bool *visited)
{
    
    visited[start] = true;
    std::cout << start <<"\t";
    for ( int i = 0; i < vertices; i++ )
        {
            
            if ( g[start][i] && visited[i]!=true )
            {
                dfs(i, visited);
            }
            
        }
}

void Graph::bfs (int source,bool *visited)
{
    Queue gQ(vertices);
    gQ.insertEnd(source);
    visited[source] = true;
    while( gQ.isEmpty() == false )
    {
        int start = gQ.frontElement();
        gQ.deletefront();
        
        std::cout << start << "\t";
       
        for( int i=0; i<vertices; i++ )
        {
            if ( g[start][i] == 1 && visited[i] != true )
            {
                gQ.insertEnd(i);
                visited[i] = true;
            }
        }
    }
}





