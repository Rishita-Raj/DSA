class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        
        int m = coins.size();
        int n = coins[0].size();
        
        vector<vector<vector<long long>>> dp(m, vector<vector<long long>>(n, vector<long long>(3, LLONG_MIN)));
        
        // Base case
        for (int k = 0; k < 3; k++) {
            if (coins[0][0] >= 0) {
                dp[0][0][k] = coins[0][0];
            } else {
                if (k > 0) dp[0][0][k] = 0; // neutralize
                else dp[0][0][k] = coins[0][0];
            }
        }
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                
                if (i == 0 && j == 0) continue;
                
                for (int k = 0; k < 3; k++) {
                    
                    long long best = LLONG_MIN;
                    
                    // from top
                    if (i > 0) {
                        best = max(best, dp[i-1][j][k]);
                    }
                    
                    // from left
                    if (j > 0) {
                        best = max(best, dp[i][j-1][k]);
                    }
                    
                    if (best == LLONG_MIN) continue;
                    
                    // Case 1: take value
                    dp[i][j][k] = max(dp[i][j][k], best + coins[i][j]);
                    
                    // Case 2: neutralize (if negative and k > 0)
                    if (coins[i][j] < 0 && k > 0) {
                        
                        long long bestPrev = LLONG_MIN;
                        
                        if (i > 0) bestPrev = max(bestPrev, dp[i-1][j][k-1]);
                        if (j > 0) bestPrev = max(bestPrev, dp[i][j-1][k-1]);
                        
                        if (bestPrev != LLONG_MIN) {
                            dp[i][j][k] = max(dp[i][j][k], bestPrev);
                        }
                    }
                }
            }
        }
        
        return max({dp[m-1][n-1][0], dp[m-1][n-1][1], dp[m-1][n-1][2]});
    }
};