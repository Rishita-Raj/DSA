class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int,int>mp;
        for(int i=0;i<arr.size();i++){
            mp[arr[i]]++;
        }
        int ans=-1;
        for(auto ele:mp){
            if(ele.first==ele.second){
                ans=max(ans,ele.first);
            }
        }
        return ans;
    }
};
    