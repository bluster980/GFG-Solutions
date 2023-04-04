//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int solve(int sum,int partitions,int gap,vector<vector<vector<int>>>&dp){
        if(partitions==1 and sum>=gap)return 1;
        else if(sum<gap)return 0;
        if(dp[sum][partitions][gap]!=-1)return dp[sum][partitions][gap];
        int ans=0;
        for(int i=gap;i<=sum;i++){
            ans+=solve(sum-i,partitions-1,i,dp);
        }
        return dp[sum][partitions][gap]=ans;
    }
    int countWaystoDivide(int N, int K) {
        // Code here
        vector<vector<vector<int>>>dp(N+1,vector<vector<int>>(K+1,vector<int>(N+1,-1)));
        return solve(N,K,1,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        Solution ob;
        cout << ob.countWaystoDivide(N, K) << endl;
    }
}
// } Driver Code Ends