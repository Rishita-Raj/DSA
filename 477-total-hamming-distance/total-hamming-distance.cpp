class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        long long total = 0;
        int n = nums.size();

        // Check all 32 bit positions
        for (int bit = 0; bit < 32; bit++) {
            int ones = 0;

            // Count how many numbers have this bit = 1
            for (int x : nums) {
                if (x & (1 << bit)) ones++;
            }

            int zeros = n - ones;

            // Each 1 pairs with each 0 → contributes 1 to Hamming distance
            total += (long long)ones * zeros;
        }

        return (int)total;
    }
};
