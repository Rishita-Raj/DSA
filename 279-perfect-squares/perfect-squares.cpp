class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0; // Base case

        // Precompute all perfect squares <= n
        vector<int> squares;
        for (int i = 1; i * i <= n; i++) {
            squares.push_back(i * i);
        }

        // Bottom-up DP
        for (int i = 1; i <= n; i++) {
            for (int sq : squares) {
                if (sq > i) break; // No need to check further
                dp[i] = min(dp[i], dp[i - sq] + 1);
            }
        }

        return dp[n];
    }
};
