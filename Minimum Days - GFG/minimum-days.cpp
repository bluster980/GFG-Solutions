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
    int getMinimumDays(int n,string s, vector<int> &v) {
        int temp = 0;
        for(int i=1; i<s.size(); i++){
            if(s[i-1]==s[i]) temp++;
        }
        if(!temp) return 0;
        for(int i=0; i<v.size(); i++){
            if(v[i]>0 && s[v[i]]==s[v[i]-1]) temp--;
            if(v[i]<n-1 && s[v[i]+1]==s[v[i]]) temp--;
            if(temp <= 0) return i+1;
            s[v[i]]='$';
        }
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