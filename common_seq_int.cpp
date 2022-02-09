
#include <iostream>
#include<vector>
#include<string>

using namespace std;

string common_seq(vector<int> a, vector<int> b)
 {
	string longest_common_subseq = "";
	int i = 0;
	int j = 0;
	int k =0;
	string seq = "";
	int length = 0;
	int curr_length = 0;
	int m_p = 0;
	for( i = 0; i < a.size(); i++)
	{
		k = i;
		for( j = m_p; j < b.size(); )
		{
			if( a[k] == b[j])
			{
                cout << "position " << k << " = " << j << "\n";
                
                if( seq != "")
					seq.append(",");
				seq = seq.append(to_string(b[j]));
				curr_length++;
                cout << curr_length << " : "<< seq<< endl;
				k++;
				j++;
				m_p = j;
			}
			else
			{
				j++;
			}
		}
		if( curr_length > length)
		{
			length = curr_length;
			longest_common_subseq = "";
			longest_common_subseq.append(seq);
			m_p = 0;
           
		}
		
			seq = "";
			curr_length = 0;

	}

	return longest_common_subseq;
}
int main()
{
    vector<int> b = {5,6,10,17,181};
    vector<int> a = {6,5,32,181};
    std::cout << " Sequence : " << common_seq(a,b);
}