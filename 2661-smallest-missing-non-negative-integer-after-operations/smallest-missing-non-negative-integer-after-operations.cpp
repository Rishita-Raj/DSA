class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        vector<int> freq(value, 0);

        // Count frequency of each remainder mod value
        for (int num : nums) {
            int rem = ((num % value) + value) % value; // handle negatives
            freq[rem]++;
        }

        int mex = 0;
        while (true) {
            int rem = mex % value;
            if (freq[rem] == 0) break; // can't form this number
            freq[rem]--; // use one occurrence
            mex++;
        }
        return mex;
    }
};
