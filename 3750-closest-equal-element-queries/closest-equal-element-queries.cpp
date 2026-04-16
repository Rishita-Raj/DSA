class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
         int n = nums.size();
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }

        // Step 2: store answer for every index
        vector<int> best(n, -1);

        // Step 3: process each group
        for (auto &it : mp) {
            vector<int> &idx = it.second;
            int k = idx.size();

            if (k == 1) continue; // no pair exists

            for (int i = 0; i < k; i++) {
                int curr = idx[i];

                int prev = idx[(i - 1 + k) % k];
                int next = idx[(i + 1) % k];

                int distPrev = abs(curr - prev);
                int distNext = abs(curr - next);

                // circular adjustment
                distPrev = min(distPrev, n - distPrev);
                distNext = min(distNext, n - distNext);

                best[curr] = min(distPrev, distNext);
            }
        }

        // Step 4: answer queries
        vector<int> ans;
        for (int q : queries) {
            ans.push_back(best[q]);
        }

        return ans;
    }
};