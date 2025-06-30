class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int,int>m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        int ans=0;
        for(auto ele:m){
            int x=ele.second;
            if(m.find(ele.first+1)!=m.end()){
                x+=m[ele.first+1];
                ans=max(x,ans);
            }
        }
        return ans;
    }
};