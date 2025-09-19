class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
    vector<int> mapp(1000002,-1);
    for(int i=0;i<nums.size();i++){
        mapp[nums[i]] = i;
    }
    for(int i=0;i<operations.size();i++){
        int a = operations[i][0];
        int b = operations[i][1];
        int idx = mapp[a];
        mapp[a] = -1;
        mapp[b] = idx;
        nums[idx] = b;
    }
    return nums;
}
};