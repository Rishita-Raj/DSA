class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {

        vector<vector<int>> adj(n);

        for (auto &e : invocations) {
            adj[e[0]].push_back(e[1]);
        }

        vector<bool> suspicious(n, false);

        function<void(int)> dfs = [&](int node) {
            suspicious[node] = true;

            for (int next : adj[node]) {
                if (!suspicious[next])
                    dfs(next);
            }
        };

        dfs(k);

        for (auto &e : invocations) {

            int u = e[0];
            int v = e[1];

            if (!suspicious[u] && suspicious[v]) {

                vector<int> ans;

                for (int i = 0; i < n; i++)
                    ans.push_back(i);

                return ans;
            }
        }

        vector<int> ans;

        for (int i = 0; i < n; i++) {

            if (!suspicious[i])
                ans.push_back(i);
        }

        return ans;
    }
};