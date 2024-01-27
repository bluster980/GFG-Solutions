class Solution {
public:
    int dp[1001][1001];
    int sum[1001];
    int kInversePairs(int n, int k) {
        dp[0][0] = 1;
        int s = 0;
        for (int i=1; i<=n; ++i) {
            sum[0] = 1;
            dp[i][0] = 1;
            for (int j=1; j<=k; ++j) {
                sum[j] = sum[j-1] + dp[i-1][j]; // cumulative sum of previous values
                sum[j] %= 1000000007;
                s = j - i; // available mininum previous inversion count to make current j inversions
                if(s < 0) { // if available inversion count is negative, means sum all
                    dp[i][j] = sum[j];
                }
                else { // if not, sum[s , j]
                    dp[i][j] = sum[j] - sum[s];
                    if(dp[i][j] < 0) dp[i][j] += 1000000007;
                    else dp[i][j] %= 1000000007;
                }
            }            
        }
        
        return dp[n][k];
    }
};