#include<iostream>
#include<utility>
#include<vector>
#include<algorithm>
using namespace std;

class Graph
{
	int V;
	int *id;
	int edge_count;
	pair <int, pair<int,int> > edge[10];

public:
	Graph(int n )
	{
		V= n;
		id = new int[n];
		edge_count = 0;
		for(int i = 0; i < V; i++ )
		{
			id[i] = i;
		}
	}
	void addEdges(int w, int x, int y )
	{
		edge[edge_count] = make_pair(w,make_pair(x,y));
		edge_count++;
	}
	int root( int x)
	{
		while(id[x] != x )
		{
			id[x] = id[id[x]];
			x = id[x];
		}
		return x;
	}

	void union1( int x, int y )
	{
		int p = root(x);
		int q = root(y);
		id[p] = id[q];
	}

	int kruskal()
	{
		int x;
		int y;
		int w;
	       int min_cost = 0;
		sort(edge, edge + edge_count);
	       for( int i =0; i< edge_count; i++ )
		{
			w = edge[i].first;
			x = edge[i].second.first;
			y = edge[i].second.second;
			if ( root(x) != root(y) )
			{
				union1(x,y);
				min_cost += w;
			}
		}
		return min_cost;
	}
};

int main()
{
	Graph g(4);
	g.addEdges(3,0,1);
	g.addEdges(4,0,2);
	g.addEdges(2,0,3);
	g.addEdges(3,1,0);
	g.addEdges(1,1,2);
	g.addEdges(5,1,3);
	g.addEdges(2,2,3);
	cout << "Min cost : " <<g.kruskal();
	cout << endl;
}








































































































































































































































































































































































































































