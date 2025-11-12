class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> answer(n, 1);

        // Step 1: prefix products
        int prefix = 1;
        for (int i = 0; i < n; i++) {
            answer[i] = prefix;   // product of all left elements
            prefix *= nums[i];
        }

        // Step 2: suffix products
        int suffix = 1;
        for (int i = n - 1; i >= 0; i--) {
            answer[i] *= suffix;  // multiply with all right elements
            suffix *= nums[i];
        }

        return answer;
    }
};
