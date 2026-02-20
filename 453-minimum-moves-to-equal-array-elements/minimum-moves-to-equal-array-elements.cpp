class Solution {
public:
    int minMoves(vector<int>& nums) {
        long long sum = 0;
        int minVal = INT_MAX;

        for (int num : nums) {
            sum += num;
            minVal = min(minVal, num);
        }

        return sum - (long long)nums.size() * minVal;
    }
};
