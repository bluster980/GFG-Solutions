//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    int maxSweetness(vector<int>& sweetness, int N, int K) {
    int sum = 0;
        for(int i: sweetness)
            sum += i;
        int ans, low = 1, high = sum;
        while(low <= high){
            int mid = (low+high)/2;
            if(check(sweetness, mid, K)){
                ans = mid;
                low = mid+1;
            }
            else
                high = mid-1;
        }
        return ans;
    }
    
    bool check(vector<int> &v, int t, int k){
        int cur = 0;
        for(int i: v){
            cur += i;
            if(cur >= t){
                k--;
                cur = 0;
            }
        }
        return k < 0;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> sweetness(n);
        for (int i = 0; i < n; i++) {
            cin >> sweetness[i];
        }
          Solution ob;
          int res=ob.maxSweetness(sweetness, n, k);
        cout << res << endl;
    }
}
// } Driver Code Ends