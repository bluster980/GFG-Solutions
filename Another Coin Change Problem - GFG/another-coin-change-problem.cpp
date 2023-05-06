//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {
  public:
  
    int dp[10000][101];
    int n,k,t;
  
    bool rec(int sum,int taken,vector<int> &coins){
        if(taken>k||sum>t){
            return false;
        }
        if(taken==k){
            if(sum==t)return true;
            else return false;
        }
        if(dp[sum][taken]!=-1)return dp[sum][taken];
        bool possible=false;
        for(int i=0;i<n;i++){
            possible|=rec(sum+coins[i],taken+1,coins);
        }
        return dp[sum][taken]=possible;
    }
  
    bool makeChanges(int N, int K, int target, vector<int> &coins) {
        // code here
        k=K;t=target;n=N;
        for(int i=0;i<=target;i++){
            for(int j=0;j<=k;j++){
                dp[i][j]=-1;
            }
        }
        return rec(0,0,coins);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int N;
        scanf("%d", &N);

        int K;
        scanf("%d", &K);

        int target;
        scanf("%d", &target);

        vector<int> coins(N);
        Array::input(coins, N);

        Solution obj;
        bool res = obj.makeChanges(N, K, target, coins);

        cout << res << endl;
    }
}

// } Driver Code Ends