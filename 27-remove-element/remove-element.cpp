class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0; // position for next non-val element
        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != val) {
                nums[k] = nums[i];
                k++; // move position for next valid element
            }
        }
        
        return k; // number of elements not equal to val
    }
};
