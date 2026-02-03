class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        int i = 1;

        while (i < n && nums[i] > nums[i - 1]) {
            i++;
        }
        if (i == 1) return false;  

        int p = i;
        while (i < n && nums[i] < nums[i - 1]) {
            i++;
        }
        if (i == p) return false;  

        int q = i;
        while (i < n && nums[i] > nums[i - 1]) {
            i++;
        }
        if (i == q) return false;
        return i == n;
    }
};
