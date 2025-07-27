class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n + 1);  
        for (auto& time : times) {
            int u = time[0], v = time[1], w = time[2];
            adj[u].push_back({v, w});
        }

        vector<int> dist(n + 1, INT_MAX);
        dist[k] = 0;

        priority_queue<pair<int, int>, 
                       vector<pair<int, int>>, 
                       greater<pair<int, int>>> pq;
        pq.push({0, k});  
        while (!pq.empty()) {
            auto [currTime, node] = pq.top();
            pq.pop();

            if (currTime > dist[node]) continue;

            for (auto& [nei, weight] : adj[node]) {
                if (dist[node] + weight < dist[nei]) {
                    dist[nei] = dist[node] + weight;
                    pq.push({dist[nei], nei});
                }
            }
        }
        int maxTime = 0;
        for (int i = 1; i <= n; ++i) {
            if (dist[i] == INT_MAX) return -1;
            maxTime = max(maxTime, dist[i]);
        }

        return maxTime;
    }
};
