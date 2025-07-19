class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<vector<int>> revGraph(V);
        vector<int> indegree(V, 0);

       
        for (int u = 0; u < V; u++) {
            for (int v : graph[u]) {
                revGraph[v].push_back(u); 
                indegree[u]++;           
            }
        }

        queue<int> q;
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) {
                q.push(i); 
            }
        }

        vector<int> safe;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            safe.push_back(node);

            for (int neighbor : revGraph[node]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        sort(safe.begin(), safe.end()); 
        return safe;
    }
};
