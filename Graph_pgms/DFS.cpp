#include<iostream>
#include<list>
using namespace std;
class Graph
{

	int num_vertices;
	bool *visited;
	list *adj_list;
public:
	
	Graph(int vertices);
        void add_edge(int src,int dest);
	void dfs(int start); 
	void bfs(int start);
};
Graph::Graph(int n)
{
	num_vertices = n;
	adj_list<int> = new list[num_vertices];
}


void Graph::add_edge(int v1, int v2)
{
	adj_list[v1].push_back(v2);
	adj_list[v2].push_back(v1);

}

Graph::bfs(int start_vertex)
{
	int i;
	visited = new bool[num_vertices];
	for(i=0;i<num_vertices;i++)
		visited[i]=false;
	list q;
	visited[start_vertex]=true;
	q.push_back(start_vertex);
	list::iterator i;
	while(!q.empty())
	{
		int curr_vertex = q.front();
		cout<<curr_vertex<<" ";
		q.pop_front();
/*		for(i=adj_list[curr_vertex].begin();i!=adj_list[curr_vertex].end();i++)
		{
			int adj_vertex = *i;
			if(!visited[adj_vertex])
			{
				visited[adj_vertex]=true;
				q.push_back(adj_vertex);
			}
		}
*/		
	}

}
int main()
{
	Graph g(3);
	g.add_edge(1,3);
	g.add_edge(1,2);
	g.add_edge(2,3);

 	g.bfs(2);	
	return 0;
}

