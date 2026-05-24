class Solution {
public:

    vector<int> dp;

    int dfs(int idx, vector<int>& arr, int d) {

        // already computed
        if (dp[idx] != -1)
            return dp[idx];

        int best = 1; // count current index

        int n = arr.size();

        // Explore LEFT
        for (int i = idx - 1; i >= max(0, idx - d); i--) {

            // blocked
            if (arr[i] >= arr[idx])
                break;

            best = max(best, 1 + dfs(i, arr, d));
        }

        // Explore RIGHT
        for (int i = idx + 1; i <= min(n - 1, idx + d); i++) {

            // blocked
            if (arr[i] >= arr[idx])
                break;

            best = max(best, 1 + dfs(i, arr, d));
        }

        return dp[idx] = best;
    }

    int maxJumps(vector<int>& arr, int d) {

        int n = arr.size();

        dp.resize(n, -1);

        int ans = 1;

        for (int i = 0; i < n; i++) {
            ans = max(ans, dfs(i, arr, d));
        }

        return ans;
    }
};