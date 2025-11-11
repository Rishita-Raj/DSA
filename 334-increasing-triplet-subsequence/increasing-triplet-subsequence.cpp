class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int first = INT_MAX;   // smallest number seen so far
        int second = INT_MAX;  // second smallest number seen so far

        for (int x : nums) {
            if (x <= first) {
                // update the smallest number
                first = x;
            } else if (x <= second) {
                // update second smallest number (but greater than first)
                second = x;
            } else {
                // found a number greater than both -> triplet exists
                return true;
            }
        }

        return false;
    }
};
