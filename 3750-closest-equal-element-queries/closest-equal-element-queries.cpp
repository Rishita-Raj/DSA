class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
         int n = nums.size();
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }

        vector<int> best(n, -1);

        for (auto &it : mp) {
            vector<int> &idx = it.second;
            int k = idx.size();

            if (k == 1) continue; 

            for (int i = 0; i < k; i++) {
                int curr = idx[i];

                int prev = idx[(i - 1 + k) % k];
                int next = idx[(i + 1) % k];

                int distPrev = abs(curr - prev);
                int distNext = abs(curr - next);

                distPrev = min(distPrev, n - distPrev);
                distNext = min(distNext, n - distNext);

                best[curr] = min(distPrev, distNext);
            }
        }

        vector<int> ans;
        for (int q : queries) {
            ans.push_back(best[q]);
        }

        return ans;
    }
};