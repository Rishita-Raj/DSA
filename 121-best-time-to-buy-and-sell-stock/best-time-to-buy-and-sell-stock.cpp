class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        
        int dp0 = 0;              // not holding stock
        int dp1 = -prices[0];     // holding stock
        
        for (int i = 1; i < n; i++) {
            dp0 = max(dp0, dp1 + prices[i]);
            dp1 = max(dp1, -prices[i]);
        }
        
        return dp0;
    }
};