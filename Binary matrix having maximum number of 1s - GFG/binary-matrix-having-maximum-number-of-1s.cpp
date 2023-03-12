//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    vector<int> findMaxRow(vector<vector<int>> mat, int N) {
        map<int,int> mp;
        for(int i=0; i<mat.size(); i++){
            int temp = 0;
            for(int j=0; j<mat[i].size(); j++){
                temp += mat[i][j];
            }
            mp[i] = temp;
        }
        int rowi=0,maxx=INT_MIN;
        for(auto xx:mp){
            if(xx.second > maxx){
                maxx = xx.second;
                rowi = xx.first;
            }
        }
        return {rowi,maxx};
    }
};

//{ Driver Code Starts.

int main() {
	int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<vector<int>> arr(n, vector<int> (n));
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                cin >> arr[i][j];
        Solution obj;
        vector<int> ans = obj.findMaxRow(arr, n);
        for(int val : ans) {
            cout << val << " ";
        }
        cout << endl;
    }
}
// } Driver Code Ends