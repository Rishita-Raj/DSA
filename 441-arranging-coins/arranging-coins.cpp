class Solution {
public:
    int arrangeCoins(long long n) {
        long long left = 1, right = n, ans = 0;

        while (left <= right) {
            long long mid = left + (right - left) / 2;
            long long coins = mid * (mid + 1) / 2; // total coins needed for mid rows

            if (coins == n) {
                return mid;       // perfect fit
            } else if (coins < n) {
                ans = mid;         // mid rows possible, try for more
                left = mid + 1;
            } else {
                right = mid - 1;   // too many coins, reduce rows
            }
        }
        return ans;
    }
};
