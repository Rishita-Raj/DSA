class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        int minPrice = INT_MAX;

        vector<int> freq(n + 1, 0);

        for (auto& item : items) {
            freq[item[0]]++;
            minPrice = min(minPrice, item[1]);
        }
        vector<int> multiples(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            for (int j = i; j <= n; j += i) {
                multiples[i] += freq[j];
            }
        }
        vector<pair<int, int>> bonus;

        for (auto& item : items) {
            int factor = item[0];
            int price = item[1];

            int freeCount = multiples[factor] - 1;
            if (freeCount > 0 && price < 2LL * minPrice) {
                bonus.push_back({price, freeCount});
            }
        }

        sort(bonus.begin(), bonus.end());

        long long remaining = budget;
        long long ans = 0;
        for (auto [price, count] : bonus) {
            long long take = min((long long)count, remaining / price);

            ans += 2 * take;
            remaining -= take * price;
        }
        ans += remaining / minPrice;

        return (int)ans;
    }
};