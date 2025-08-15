class Solution {
public:
    int minimumSeconds(vector<int>& nums) {
        map<int,vector<int>>mp;
        for(int i=0;i<nums.size();i++) mp[nums[i]].push_back(i);
        
        int size = nums.size(), ans = INT_MAX;
        for(auto x : mp){
            vector<int> idx = x.second;
            int curr = idx[0] + (size - idx[idx.size() - 1] - 1);
            for(int i=0;i<idx.size()-1;i++){
                curr = max(curr,idx[i+1]-idx[i]-1);
            }
            ans = min(curr, ans);
            // cout<<curr<<" ";
        }
        // cout<<endl;
        return (ans+1)/2;
    }
};