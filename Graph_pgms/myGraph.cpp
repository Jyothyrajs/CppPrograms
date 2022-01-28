#include<iostream>
#include<queue>
#include<list>

using namespace std;

class Graph
{
	int V;
	list<int> *adj;
	bool *visited;
public:
	Graph(int n )
	{
		V = n;
		visited = new bool[V]; 
		adj = new list<int>[V];
	}
	void addEdge( int a, int b )
	{
		adj[a].push_back(b);
	}
	void reset (  )
	{
		for( int i =0; i < V; i++ )
		{
			visited[i] = false;
		}
	}

	void dfsVisit( int s )
	{
		list<int>::iterator i;
		cout << s << " ";
		visited[s]= true;
		
		for( i = adj[s].begin(); i != adj[s].end(); i++ )
		{
			if(!visited[*i])
				dfsVisit(*i);
		}
	}
	void dfs(  )
	{
		for ( int i =0; i< V; i++ )
		{
			if(!visited[i])
				dfsVisit(i);
		}
	}

	void bfs( int s, queue<int> q )
	{
		list<int>::iterator i;
		if( !visited[s] )
		{
			cout << s << " ";
			visited[s]= true;
		}
		for( i = adj[s].begin(); i != adj[s].end(); i++ )
		{
			q.push(*i);
		}
		while( !q.empty()) 
		{
			int f = q.front();
			q.pop();
			if ( !visited[f] )
			{
				bfs( f, q );
			}
		}
	}

};

int main()
{
	Graph g(8);
	g.addEdge(0,1);
	g.addEdge(0,2);
	g.addEdge(2,3);
	g.addEdge(2,4);
	g.addEdge(4,5);
	g.addEdge(1,7);
	g.addEdge(3,6);
	g.reset();

	queue<int> q;
	cout << "BFS : " ;
	g.bfs(0,q);
	cout << endl;
	g.reset();
	cout << "DFS : " ;
	g.dfs();
    cout << endl;
    
}
