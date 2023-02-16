//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Solution{
public:
    bool solve(vector<int>&arr,int src,vector<int>&dp,vector<bool>&vis,int n){
        if((src+arr[src]>=n) || (src+arr[src]<0)){
            return 1;
        }
        if(vis[src])
        return dp[src];
        vis[src]=1;
        return dp[src]=solve(arr,src+arr[src],dp,vis,n);
    }
    int goodStones(int n,vector<int> &arr){
        vector<int>dp(n,0);
        vector<bool>vis(n,0);
        for(int i=0;i<n;i++){
            dp[i]=solve(arr,i,dp,vis,n);
        }
        int count=0;
        for(int i=0;i<n;i++){
            if(dp[i]==1)
            count++;
        }
        return count;
    } 
};

//{ Driver Code Starts.

int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.goodStones(n,arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends