class Solution {
public:
    int kInversePairs(int n, int k) {
        const int MOD = 1e9 + 7;

        vector<int> dp(k + 1, 0);
        dp[0] = 1;  // base case

        for (int i = 1; i <= n; i++) {
            vector<int> newDp(k + 1, 0);
            long long prefixSum = 0;

            for (int j = 0; j <= k; j++) {
                prefixSum = (prefixSum + dp[j]) % MOD;

                if (j >= i)
                    prefixSum = (prefixSum - dp[j - i] + MOD) % MOD;

                newDp[j] = prefixSum;
            }

            dp = newDp;
        }

        return dp[k];
    }
};
