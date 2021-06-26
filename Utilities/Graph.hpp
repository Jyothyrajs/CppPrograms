//
//  Graph.hpp
//  Utilities
//
//  Created by Jyothyraj S on 11/12/2020.
//

//To do: Add to find no of components

#ifndef Graph_hpp
#define Graph_hpp

#include <stdio.h>

class Graph
{
    int vertices;
    int** g;
    int components;
public:
    Graph(int n);
    ~Graph();
    void deleteNode(int source, bool *visited);
    int getVertices();
    int getComponents();
    void addEdge(int u, int v);
    void dfs(int source,bool *visited);
    void bfs(int source, bool *visited);
  
};

#endif /* Graph_hpp */
