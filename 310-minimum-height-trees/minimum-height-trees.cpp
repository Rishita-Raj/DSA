class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) return {0};

        vector<vector<int>> graph(n);
        vector<int> degree(n, 0);
        for (auto &e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
            degree[e[0]]++;
            degree[e[1]]++;
        }

        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (degree[i] == 1)
                q.push(i);
        }

        int remainingNodes = n;
        while (remainingNodes > 2) {
            int size = q.size();
            remainingNodes -= size;

            for (int i = 0; i < size; i++) {
                int node = q.front();
                q.pop();

                for (int neighbor : graph[node]) {
                    degree[neighbor]--;
                    if (degree[neighbor] == 1)
                        q.push(neighbor);
                }
            }
        }
        vector<int> result;
        while (!q.empty()) {
            result.push_back(q.front());
            q.pop();
        }

        return result;
    }
};
