//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
  public:
    vector<int> duplicates(int arr[], int n) {
        map<int,int> mp; vector<int> ans;
        for(int i=0; i<n; i++){
            mp[arr[i]]++;
        }
        for(auto xx:mp){
            if(xx.second > 1){
                ans.push_back(xx.first);
            }
        }
        vector<int> temp = {-1};
        return (ans.size()!=0)?ans:temp;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution obj;
        vector<int> ans = obj.duplicates(a, n);
        for (int i : ans) cout << i << ' ';
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends