class Solution {
public:
    static constexpr long long MOD = 1e9 + 7;

    long long modPow(long long base, long long exp) {
        long long result = 1;

        while (exp > 0) {
            if (exp & 1) {
                result = (result * base) % MOD;
            }

            base = (base * base) % MOD;
            exp >>= 1;
        }

        return result;
    }

    int assignEdgeWeights(vector<vector<int>>& edges) {

        int n = edges.size() + 1;

        vector<vector<int>> graph(n + 1);

        for (auto &e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        queue<pair<int,int>> q;
        q.push({1, 0});

        vector<bool> visited(n + 1, false);
        visited[1] = true;

        int maxDepth = 0;

        while (!q.empty()) {

            auto [node, depth] = q.front();
            q.pop();

            maxDepth = max(maxDepth, depth);

            for (int nei : graph[node]) {

                if (!visited[nei]) {
                    visited[nei] = true;
                    q.push({nei, depth + 1});
                }
            }
        }

        return (int)modPow(2, maxDepth - 1);
    }
};