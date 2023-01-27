//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	bool check(string s){

        int n = s.size();
    
        if(s[0] == 0)
            return false;
    
        for(int i=0; i<n-1; i++){
    
            if(s[i] == s[i+1] && s[i] == '0')
                return false;
    
            if(s[i+1] == '0'){
                int prev = stoi(s.substr(i,1));
                if(prev >= 3)
                    return false;
            }
        }
    
        return true;
    }
    int solveDP(string s, int n){

        long long int mod = 1e9+7;

        if(n == 1)
            return 1;
    
        int dp[n+1];
      
        for(int i=0; i<=n; i++)
            dp[i] = 0;
    
        dp[1] = 1;
        dp[0] = 1;
        
        int ans = 0;
    
        for(int i=2; i<=n; i++){
    
            if(s[i-2] == '0'){
                dp[i] += dp[i-1];
                continue;
            }
            else if(s[i-1] == '0'){
                dp[i] += dp[i-2];
                continue;
            }
    
            dp[i] += dp[i-1];
    
            if(i >= 2){
    
                string temp;
                temp.push_back(s[i-2]);
                temp.push_back(s[i-1]);
                if(stoi(temp) <= 26)
                    dp[i] += dp[i-2];
            }
            
            dp[i] = dp[i]%mod;
        }
    
        return dp[n];
    }
	public:
		int CountWays(string str){
		    
		    if(check(str) == false)
		        return 0;
		    return solveDP(str, str.size());
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.CountWays(str);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends