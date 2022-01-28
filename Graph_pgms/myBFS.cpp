

#include<iostream>
#include<list>
using namespace std;

class Graph
{
	int V;
	list<int> *adj;
public:
	Graph(int n)
	{
		V = n;
		adj = new list<int>[V];
	}
	void addEdge(int a, int b)
	{
		adj[a].push_back(b);
	}
	void bfs( int s )
	{
		bool *visited = new bool[V];
		for ( int i = 0; i< V; i++ )
		{
			visited[i] = false;
		}
		list<int> bfsq;
		visited[s] = true;
		bfsq.push_back(s);

		list<int>::iterator i;
		while( !bfsq.empty() )
		{
			s = bfsq.front();
			cout << s << " ";
			bfsq.pop_front();

			for( i = adj[s].begin(); i != adj[s].end(); ++i )
			{
				if( !visited[*i] )
				{
					visited[*i] = true;
					bfsq.push_back(*i);
				}
			}
		}
	}


};

int main()
{
	Graph g(6);
	g.addEdge(0,1);
	g.addEdge(0,2);
	g.addEdge(1,3);
	g.addEdge(2,4);
	g.addEdge(4,5);
	g.bfs(0);
}
