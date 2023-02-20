//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
private:
    static const int mod = 1e9 + 7;

public:
    int countPaths(int N){
        vector<int> dp(4, 0);
        dp[0] = 1;
        for(int i = 1; i <= N; i++){
            vector<int> tDp(4, 0);
            for(int j = 0; j < 4; j++){
                for(int k = 0; k < 4; k++){
                    if( j == k ) continue;
                    tDp[j] += dp[k];
                    tDp[j] %= mod;
                }
            }
            swap(dp, tDp);
        }
        return dp[0];
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        
        Solution ob;
        cout << ob.countPaths(N) << endl;
    }
    return 0; 
}

// } Driver Code Ends