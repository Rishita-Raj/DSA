class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        
        int n = nums.size();
        
        long long totalSum = 0;
        long long F = 0;
        
        // Step 1: compute totalSum and F(0)
        for (int i = 0; i < n; i++) {
            totalSum += nums[i];
            F += (long long)i * nums[i];
        }
        
        long long maxVal = F;
        
        // Step 2: compute F(k) using relation
        for (int k = 1; k < n; k++) {
            F = F + totalSum - (long long)n * nums[n - k];
            maxVal = max(maxVal, F);
        }
        
        return maxVal;
    }
};