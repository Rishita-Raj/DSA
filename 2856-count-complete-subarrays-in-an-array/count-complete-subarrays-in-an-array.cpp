class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
         int n = nums.size();

        // Step 1: Find the total number of unique elements in the array
        unordered_set<int> uniqueSet(nums.begin(), nums.end());
        int totalDistinct = uniqueSet.size();

        int count = 0;

        // Step 2: Fix the starting index of the subarray
        for (int i = 0; i < n; ++i) {
            unordered_map<int, int> freq;
            int distinctCount = 0;

            // Step 3: Extend the subarray from index i to j
            for (int j = i; j < n; ++j) {
                // If the element is new in this window, increment distinctCount
                if (++freq[nums[j]] == 1) {
                    distinctCount++;
                }

                // Step 4: If distinctCount matches the total distinct, it's a complete subarray
                if (distinctCount == totalDistinct) {
                    count++;
                }
            }
        }

        return count;
    }
};