// return the length of longest common sub sequence

#include <iostream>
#include<vector>

using namespace std;


int long_common_subseq( string str1, string str2)
{
    int length = 0;
    int curr_length = 0;
    string s1 = str2;
    string s2 = str1;
    int i = 0;
    int j = 0;
     int k = 0;
    while( s1[k] != '\0' )
    {
        i = k;
        j = 0;
        while( s2[j] != '\0' )
       {
            if( s1[i] == s2[j] )
            {
                curr_length++;
                i++;
                j++;
            }
             else
            {
                j++;
            }
       }
       if( curr_length > length)
        {
            length = curr_length;
            curr_length = 0;
        }
        k++;
    }
    return length;
}

int main()
{
    string str1 = "abcde", str2 = "ace";
    cout << " Length : " << long_common_subseq(str1, str2);
}
