//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {
  public:
    int getMinimumDays(int N,string S, vector<int> &P) {
        set<int>s;
        for(int i=0;i<N-1;i++)if(S[i]==S[i+1])
        s.insert(i);
        if(s.size()==0)return 0;
        int ans=0;
        for(int i=0;i<N;i++){
            char c=S[P[i]];
            int idx=P[i];
            if(idx>0 and S[idx]==S[idx-1])s.erase(idx-1);
            if(idx!=N-1 and S[idx]==S[idx+1])
            s.erase(idx);
            ans++;
            if(s.empty())return ans;
            S[idx]='?';
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        string S;cin>>S;
        
        vector<int> P(N);
        Array::input(P,N);
        
        Solution obj;
        int res = obj.getMinimumDays(N,S, P);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends