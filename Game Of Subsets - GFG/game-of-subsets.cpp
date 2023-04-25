//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    const int MOD = 1e9 + 7;
    
    vector<int> temp;

    long long helper(int i, vector<int>& options, long long prod, vector<int>& freq) {
        int n = options.size();
        if(i == n) {
            return 1;
        }
    
        long long option = options[i];
        long long g = __gcd(prod, option);

        long long pick = 0;
        if(g == 1 && freq[option]) {
            temp.push_back(option);
            pick = freq[option] * helper(i+1, options, prod * options[i], freq);
            pick %= MOD;
            temp.pop_back();
        }
        
        long long notPick = helper(i+1, options, prod, freq);
        
        return (pick + notPick) % MOD;
    }

    int goodSubsets(vector<int> &arr, int n){
        // Code here
        vector<int> freq(31);
        for(auto it: arr) freq[it]++;
        
        vector<int> options;
        for(int i = 1; i <= 30; i++) {
            int num = i;
            bool ok = true;
            for(int j = 2; j*j <= i; j++) {
                if(num % (j*j) == 0) {
                    ok = false;
                    break;
                }
            }
            if(ok)
                options.push_back(num);
        }
        
        return helper(0, options, 1, freq) - 1 - freq[1];
    }

};

//{ Driver Code Starts.

int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        Solution ob;
        cout<<ob.goodSubsets(a, n)<<endl;
    }
    return 0;
}
// } Driver Code Ends