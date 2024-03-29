//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int minimizeSum(int N, vector<int> arr) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i=0; i<arr.size(); i++){
            pq.push(arr[i]);
        }
        int ans = 0; int x,y;
        while(!pq.empty() && pq.size()>1){
            ans += pq.top(); x=pq.top(); pq.pop();
            ans += pq.top(); y=pq.top(); pq.pop();
            pq.push(x+y);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
	int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i = 0; i < n; i++)
            cin>>arr[i];
        Solution obj;
        cout << obj.minimizeSum(n, arr) << "\n";
    }
}
// } Driver Code Ends