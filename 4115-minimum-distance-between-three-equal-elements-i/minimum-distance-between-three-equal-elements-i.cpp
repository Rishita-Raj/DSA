class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        
        unordered_map<int, vector<int>> mp;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }
        
        int ans = INT_MAX;

        for (auto &p : mp) {
            
            auto &idx = p.second;
            
            if (idx.size() < 3) continue;
            
            for (int i = 0; i + 2 < idx.size(); i++) {
                
                int dist = 2 * (idx[i+2] - idx[i]);
                ans = min(ans, dist);
            }
        }
        
        return ans == INT_MAX ? -1 : ans;
    }
};