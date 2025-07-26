class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const long long INF = 1e18;
        const int MOD = 1e9 + 7;

        vector<pair<int, int>> adj[n];
        for (auto& road : roads) {
            int u = road[0], v = road[1], wt = road[2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }

        priority_queue<pair<long long, int>,
                       vector<pair<long long, int>>,
                       greater<pair<long long, int>>> pq;

        vector<long long> dist(n, INF);
        vector<int> ways(n, 0);
        dist[0] = 0;
        ways[0] = 1;
        pq.push({0, 0});

        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();

            if (d > dist[u]) continue;

            for (auto& [v, wt] : adj[u]) {
                long long newDist = d + wt;

                if (newDist < dist[v]) {
                    dist[v] = newDist;
                    ways[v] = ways[u];
                    pq.push({newDist, v});
                } else if (newDist == dist[v]) {
                    ways[v] = (ways[v] + ways[u]) % MOD;
                }
            }
        }

        return ways[n - 1];
    }
};
