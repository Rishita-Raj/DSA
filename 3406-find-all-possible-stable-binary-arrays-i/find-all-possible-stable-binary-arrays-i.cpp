class Solution {
public:
    static const int MOD = 1e9 + 7;

    int numberOfStableArrays(int zero, int one, int limit) {
        vector<vector<vector<long long>>> dp(
            zero + 1,
            vector<vector<long long>>(one + 1, vector<long long>(2, 0))
        );
        // Starting blocks
        for(int i = 1; i <= min(limit, zero); i++)
            dp[i][0][0] = 1;

        for(int j = 1; j <= min(limit, one); j++)
            dp[0][j][1] = 1;

        for(int z = 0; z <= zero; z++) {
            for(int o = 0; o <= one; o++) {

                if(dp[z][o][0]) {
                    for(int k = 1; k <= limit && o + k <= one; k++) {
                        dp[z][o + k][1] =
                        (dp[z][o + k][1] + dp[z][o][0]) % MOD;
                    }
                }

                if(dp[z][o][1]) {
                    for(int k = 1; k <= limit && z + k <= zero; k++) {
                        dp[z + k][o][0] =
                        (dp[z + k][o][0] + dp[z][o][1]) % MOD;
                    }
                }
            }
        }

        return (dp[zero][one][0] + dp[zero][one][1]) % MOD;
    }
};