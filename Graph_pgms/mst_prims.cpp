
#include<iostream>
#include<vector>

using namespace std;

class Graph
{
	int v;
	int **g;
	bool *mst;
public:
	Graph( int n, int g2[][5] )
	{
		v = n;
		g = new int*[v];
		for ( int i = 0; i<v; i++ )
		{
			g[i] = new int[v];
		}
		mst = new bool[v];
		for ( int i = 0; i<v; i++ )
		{
			mst[i] = false;;
		}
		
		for( int i = 0 ; i< v ; i++ )
		for( int j = 0 ; j< v ; j++ )
		{
			g[i][j] = g2[i][j];
		}
	}
	void display()
	{
		for( int i = 0 ; i<v ; i++ )
		{
		for( int j = 0 ; j<v ; j++ )
		{
			cout << g[i][j] << " ";
		}
		cout << endl;
		}
	}

	void prims()
	{
		int cost = 0;
		vector<int> mst_arr;
		mst_arr.insert(mst_arr.begin(),0);
		mst[0] = true;
		for( int i =0; i<v; i++ )
		{
			int min = INT_MAX;
			int found_min  = 0;
			int n;
			for( int j =0; j<v; j++ )
			{
				for( int k =0; k<v; k++ )
				{
					if ( g[j][k] && mst[j] && !mst[k] && min > g[j][k] )
					{
						found_min = 1;
						min = g[j][k];
						n = k;
					} 
					
				}
						
			}
			if(found_min)
			{
			cost += min;
			mst[n] = true;
			mst_arr.insert(mst_arr.end(),n);			
			}		
		}
		cout << "vertices added: ";
		for( int i =0; i<v; i++ )
		{
			cout << mst_arr[i] << " ";;
		}
	
		cout <<endl << "Minimum cost : " << cost<< endl;
	}
};

int main()
{
	
	int graph[5][5] = { { 0, 2, 0, 6, 0 },
                        { 2, 0, 3, 8, 5 },
                        { 0, 3, 0, 0, 7 },
                        { 6, 8, 0, 0, 9 },
                        { 0, 5, 7, 9, 0 } };
	Graph g(5,graph);
	g.display();
	g.prims();
}

	
