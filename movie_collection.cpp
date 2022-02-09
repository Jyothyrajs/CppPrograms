
// Arrange a set of movies in a stack and watch movie after picking carefully from the stack and keep it back on the stack
// Program identifies the number of movie boxes above each watched move and return it as a string
#include<iostream>
#include<stack>
#include<string>
#include<vector>

using namespace std;

string movie_stack(int n, int m, vector<int> movies)
 {
    string movies_array = "";
	vector<int> no_mv_abov;
	std::stack<int> mov_st ;
	std::stack<int> temp_stack;
	for( int i = 0; i < n ; i++)
	{
		//no_mv_abov.push_back( i);
		mov_st.push(n-i);
	}
	for( int i = 0; i < m; i++)
	{
		while(mov_st.top() != movies[i] )
		{
			int t = mov_st.top();
			mov_st.pop();
			temp_stack.push(t);
		}
		
		mov_st.pop();
		if(movies_array !="")
			movies_array.append(",");
		int lc = temp_stack.size();
		movies_array.append(to_string(lc));
		
		while( !temp_stack.empty())
		{
			int t_e = temp_stack.top();
			temp_stack.pop();
			mov_st.push(t_e);
		}
		
		mov_st.push(movies[i]);
		
		
	}
	return movies_array;
}

int main()
{
    int n = 5;
    int m = 3;
    vector<int> mov = {4,5,4};
    cout << "No of movie stack above the list :: " << movie_stack(n,m,mov) <<endl;
}