#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Helper function to check if subarray of length k starting from 'start' is strictly increasing
    bool isIncreasing(vector<int>& nums, int start, int k) {
        for (int i = start; i < start + k - 1; i++) {
            if (nums[i] >= nums[i + 1]) return false;
        }
        return true;
    }

    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        // Check each possible starting index
        for (int i = 0; i + 2 * k <= n; i++) {
            if (isIncreasing(nums, i, k) && isIncreasing(nums, i + k, k)) {
                return true;
            }
        }
        return false;
    }
};
