class Solution {
public:
    int numberOfPermutations(int n, vector<vector<int>>& requirements) {
         const int MOD = 1e9 + 7;

        // map end index -> required inversions
        vector<int> req(n, -1);
        for (auto &r : requirements) {
            req[r[0]] = r[1];
        }

        int maxInv = 400;

        vector<vector<int>> dp(n + 1, vector<int>(maxInv + 1, 0));
        dp[0][0] = 1;

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= maxInv; j++) {
                long long sum = 0;

                for (int x = 0; x <= min(j, i - 1); x++) {
                    sum = (sum + dp[i - 1][j - x]) % MOD;
                }

                dp[i][j] = sum;
            }

            // apply requirement if exists
            if (req[i - 1] != -1) {
                for (int j = 0; j <= maxInv; j++) {
                    if (j != req[i - 1]) dp[i][j] = 0;
                }
            }
        }

        long long ans = 0;
        for (int j = 0; j <= maxInv; j++) {
            ans = (ans + dp[n][j]) % MOD;
        }

        return ans;
    }
};