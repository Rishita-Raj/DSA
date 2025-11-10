class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n <= 1) return 0;

        int hold = -prices[0];   // holding stock after day 0
        int sold = 0;           // sold a stock today
        int rest = 0;           // cooldown or doing nothing

        for (int i = 1; i < n; i++) {
            int prevHold = hold;
            int prevSold = sold;
            int prevRest = rest;

            hold = max(prevHold, prevRest - prices[i]);  // buy or keep holding
            sold = prevHold + prices[i];                 // sell today
            rest = max(prevRest, prevSold);              // cooldown or rest
        }

        return max(sold, rest);
    }
};
