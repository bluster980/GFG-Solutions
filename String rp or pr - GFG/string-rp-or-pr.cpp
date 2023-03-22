//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{   
public:
    long long remove2(string &s,string b,stack<char> &temp1)
        {   
            //b="rp"
            long long int count2=0;
            stack <char>temp2;
            temp2.push(temp1.top());
            temp1.pop();
            while(!temp1.empty())
            {
                if(!temp2.empty()&&(temp1.top()==b[0]&&temp2.top()==b[1]))
                {
                    temp1.pop();
                    temp2.pop();
                    count2++;
                }
                else
                {
                    temp2.push(temp1.top());
                    temp1.pop();
                }
            }
            
            return count2;
        }
        long long remove1(string &s,string a, string b,int X,int Y)
        {
            //a="pr"
            //b="rp"
            int n =s.size();
            long long int count1=0,count2=0;
            stack<char>temp1;
            temp1.push(s[0]);
            
          for(int i=1;i<n;i++)
          {
              if(!temp1.empty()&&(temp1.top()==a[0]&&s[i]==a[1]))
              {
                  temp1.pop();
                  count1++;
              }
              else temp1.push(s[i]);
          }
          count2=remove2(s,b,temp1);
          return count1*X+count2*Y;
        }


    long long solve(int X,int Y,string S){
      //code here
        string string1="pr";
        string string2="rp";
      
      
      if(X>Y) return remove1(S,string1,string2,X,Y);
        else
        {
            swap(X,Y);
            return remove1(S,string2,string1,X,Y);
        }
    }
};

//{ Driver Code Starts.
signed main()
{
  int t;
  cin>>t;
  while(t--)
  {
      int X,Y;
      cin>>X>>Y;
      string S;
      cin>>S;
      Solution obj;
      long long answer=obj.solve(X,Y,S);
      cout<<answer<<endl;
  }
}
// } Driver Code Ends