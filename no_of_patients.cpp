int solution(vector<string> &A) 
{
    
    int n = A.size();
    int f[n];
    bool checked[n];
    for( int i = 0; i< n; i++)
    {
        f[i] = 0;
        checked[i] = false;
    }
    
    for( int i =0; i< n; i++)
    {
        for(int j = i ; j<n; j++)
        {
            if(checked[i] != true)
            {
                checked[i] = true;
                f[i]++;
            }
            
            if( A[i] == A[j] && checked[j] != true)
            {
                checked[j] = true;
                f[i]++;
            }
        }
    }
    int max = f[0];
    for( int i =1; i< n; i++)
    {
        if( f[i] > max )
            max = f[i];

    }
    return max;
}

