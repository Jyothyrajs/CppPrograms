// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(string &S)
{
   int n = S.size();
   int i = 0;
   int d = 0;
   std::string op = "";
   char oper;
   int sc ;
   stack<int> st;
   while( S[i] < n)
   {
      while( S[i] != " ") 
      {
          if( S[i] >= 0 && S[i] <=9)
          {
              d = d*10 + int(S[i]);
              sc = 1;
          }
          else if( S[i] != '+' && S[i] != '-')
          {
              op.append(S[i]);
              sc = 2;
          }
          else 
          {
              oper = S[i];
              sc = 3;
              break;
          }
          i++;
      }
      switch(sc)
      {
        case 1:st.push(d);
            break;
        case 2:int op1 = st.top();
                    int op2 = st.top();
                if( oper == '+')
                {
                    st.push( op1+op2);
                }
                else 
                {
                    st.push( op2-op1);
                }
            break;
        case 3: if( strcmp(op, 'DUP') == 0)
                {
                    int dupv = st.top();
                    st.push(dupv);
                }
                else {
                st.pop();
                }
            break;
      }
   }
}

