class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        unordered_map<int, int> dp;
        int ans = 0;

        for (int x : nums) {
            int a = dp[x];
            int b = dp[x + 1];

            dp[x + 1] = max(dp[x + 1], a + 1);
            dp[x + 2] = max(dp[x + 2], b + 1);

            ans = max({ans, dp[x + 1], dp[x + 2]});
        }

        return ans;
    }
};