class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        //To prevent from integer overflow it is good to take long long int.
        long long int sum_from_front = 0, sum_from_back = 0;
        
        for(int i=0;i<nums.size();i++){
            sum_from_back += nums[i];
        }
        
        int count = 0;
        
        for(int i=0;i<nums.size()-1;i++){
            sum_from_front += nums[i];
            sum_from_back -= nums[i];
            if(sum_from_front >= sum_from_back) count++;
        }
        return count;
    }
};