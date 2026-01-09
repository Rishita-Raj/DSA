class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<pair<int, int>> indexNums;
        for(int i = 0; i<n; ++i){
            indexNums.push_back({nums[i], i});
        }
        sort(indexNums.begin(), indexNums.end());
        int left = 0, right = n-1;
        while(left<right){
            int sum = indexNums[left].first + indexNums[right].first;
            if(sum == target){
                return {indexNums[left].second, indexNums[right].second};
            }
            else if(sum<target){
                left++;
            }else{
                right--;
            } 
        }
        return {-1,-1};
    }
};