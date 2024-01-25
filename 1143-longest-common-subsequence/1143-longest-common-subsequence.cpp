class Solution {
public:
    // int solve(int i, int j, string &text1, string &text2, vector<vector<int>> &dp){
    //     if(i<0 || j<0) return 0;
    //     if(dp[i][j] != -1) return dp[i][j];
    //     if(text1[i]==text2[j]) return dp[i][j] = 1 + solve(i-1,j-1,text1,text2,dp);
    //     return dp[i][j] = max(solve(i,j-1,text1,text2,dp), solve(i-1,j,text1,text2,dp));
    // }
    // int longestCommonSubsequence(string text1, string text2) {
    //     int n = text1.size(), m = text2.size();
    //     vector<vector<int>> dp(n,vector<int> (m,-1));
    //     return solve(n-1,m-1,text1,text2,dp);
    // }
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size()+1, vector<int> (text2.size()+1,0));
        for(int i=0; i<text1.size(); i++){
            for(int j=0; j<text2.size(); j++){
                if(text1[i] == text2[j]){
                    dp[i+1][j+1] = dp[i][j] + 1;
                }
                else{
                    dp[i+1][j+1] = max(dp[i][j+1],dp[i+1][j]);
                }
            }
            // cout<<endl;
        }
        return dp[text1.size()][text2.size()];
    }
};

