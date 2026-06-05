class Solution {
public:
    int solve(vector<int>& nums, int start, int end) {
        int prev = nums[start];
        int prev2 = 0;

        for (int i = start + 1; i <= end; i++) {
            int pick = nums[i];

            if (i > start + 1)
                pick += prev2;

            int nonPick = prev;

            int cur = max(pick, nonPick);

            prev2 = prev;
            prev = cur;
        }

        return prev;
    }

    int rob(vector<int>& nums) {
        int n = nums.size();

        if (n == 1)
            return nums[0];

        return max(
            solve(nums, 0, n - 2), 
            solve(nums, 1, n - 1)  
        );
    }
};