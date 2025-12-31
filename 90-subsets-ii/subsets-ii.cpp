class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;

    void backtrack(vector<int>& nums, int start) {
        // Add current subset
        result.push_back(path);

        for (int i = start; i < nums.size(); i++) {
            // Skip duplicates
            if (i > start && nums[i] == nums[i - 1])
                continue;

            path.push_back(nums[i]);
            backtrack(nums, i + 1);
            path.pop_back(); // backtrack
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end()); // Important
        backtrack(nums, 0);
        return result;
    }
};
