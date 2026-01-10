class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int countBreak = 0;
        for(int i = 0; i<n; ++i){
            if(nums[i] > nums[(i+1)%n]){
                countBreak++;
            }            
            if(countBreak>1){
                return false;
                break;
            }
        }
        return true;
    }
};