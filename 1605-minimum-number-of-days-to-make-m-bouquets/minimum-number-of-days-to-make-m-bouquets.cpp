class Solution {
public:
    bool possible(vector<int>& bloomDay, int day, int m, int k) {
        int cnt = 0, bouquets = 0;
        for (int i = 0; i < bloomDay.size(); i++) {
            if (bloomDay[i] <= day) {
                cnt++;
                if (cnt == k) {
                    bouquets++;
                    cnt = 0;
                }
            } else {
                cnt = 0;
            }
        }
        return bouquets >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        long long totalFlowers = 1LL * m * k;
        int n = bloomDay.size();
        if (totalFlowers > n) return -1;  // Impossible case

        int low = INT_MAX, high = INT_MIN;
        for (int i = 0; i < n; i++) {
            low = min(low, bloomDay[i]);
            high = max(high, bloomDay[i]);
        }

        int result = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (possible(bloomDay, mid, m, k)) {
                result = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return result;
    }
};
