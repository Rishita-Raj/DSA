class Solution {
public:
    int change(int amount, vector<int>& coins) {
        if (amount == 0) return 1;
        if (coins.empty()) return 0;
        int g = 0;
        for (int c : coins) g = std::gcd(g, c);
        if (g != 0 && amount % g != 0) return 0;
        if (g > 1) {
            amount /= g;
            for (int &c : coins) c /= g;
        }

        coins.erase(remove_if(coins.begin(), coins.end(),
                              [&](int c){ return c <= 0 || c > amount; }),
                    coins.end());
        if (coins.empty()) return 0;
        sort(coins.begin(), coins.end());
        coins.erase(unique(coins.begin(), coins.end()), coins.end());
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;
        for (int coin : coins) {
            for (int t = coin; t <= amount; ++t) {
                long long add = (long long)dp[t] + dp[t - coin];
                dp[t] = (int)add;
            }
        }
        return dp[amount];
    }
};
