class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        long long nextFree = LLONG_MIN;
        int distinctCount = 0;

        for (int x : nums) {
            long long left = (long long)x - k;
            long long right = (long long)x + k;

            long long use = max(nextFree, left);
            if (use <= right) {
                distinctCount++;
                nextFree = use + 1;
            }
        }
        return distinctCount;
    }
};
