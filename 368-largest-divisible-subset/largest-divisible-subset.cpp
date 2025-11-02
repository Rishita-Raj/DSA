class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return {};

        sort(nums.begin(), nums.end());  // Step 1: Sort the array

        vector<int> dp(n, 1);      // Each number can form a subset of length 1
        vector<int> prev(n, -1);   // To trace the path
        int maxLen = 1, lastIndex = 0;

        // Step 2: Build dp table
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    prev[i] = j;
                }
            }
            if (dp[i] > maxLen) {
                maxLen = dp[i];
                lastIndex = i;
            }
        }

        // Step 3: Reconstruct the subset
        vector<int> result;
        while (lastIndex != -1) {
            result.push_back(nums[lastIndex]);
            lastIndex = prev[lastIndex];
        }

        reverse(result.begin(), result.end());
        return result;
    }
};
