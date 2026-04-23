class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        vector<long long> ans(n, 0);

        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }
        for (auto &it : mp) {
            vector<int> &idx = it.second;
            int k = idx.size();

            long long totalSum = 0;
            for (int x : idx) totalSum += x;

            long long prefixSum = 0;

            for (int p = 0; p < k; p++) {
                long long i = idx[p];

                long long left = i * p - prefixSum;

                long long right = (totalSum - prefixSum - i) - i * (k - p - 1);

                ans[i] = left + right;

                prefixSum += i;
            }
        }

        return ans;
    }
};