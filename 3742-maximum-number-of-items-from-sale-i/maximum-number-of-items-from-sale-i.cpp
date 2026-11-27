class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {

        int n = items.size();
        const int NEG = -1e9;

        vector<int> weight(n);
        for (int i = 0; i < n; i++) {
            weight[i] = 1;

            for (int j = 0; j < n; j++) {
                if (i != j && items[j][0] % items[i][0] == 0) {
                    weight[i]++;
                }
            }
        }
        vector<int> dp(budget + 1, NEG);
        dp[0] = 0;

        int ans = 0;
        for (int p = budget; p >= 1; p--) {
            vector<int> curr(budget + 1, NEG);
            for (int i = 0; i < n; i++) {
                if (items[i][1] != p) continue;

                for (int c = budget; c >= p; c--) {
                    if (curr[c - p] != NEG) {
                        curr[c] = max(curr[c],
                                      curr[c - p] + weight[i]);
                    }

                    if (dp[c - p] != NEG) {
                        curr[c] = max(curr[c],
                                      dp[c - p] + weight[i]);
                    }
                }
            }
            for (int c = 0; c <= budget; c++) {
                if (curr[c] != NEG) {
                    ans = max(ans, curr[c] + (budget - c) / p);
                }
            }
            for (int i = 0; i < n; i++) {
                if (items[i][1] != p) continue;

                for (int c = budget; c >= p; c--) {
                    if (dp[c - p] != NEG) {
                        dp[c] = max(dp[c],
                                    dp[c - p] + weight[i]);
                    }
                }
            }
        }

        return ans;
    }
};