class Solution {
public:
    void dfs(int city, vector<vector<int>>& isConnected, vector<bool>& visited, int n) {
        visited[city] = true;
        for (int j = 0; j < n; j++) {
            if (isConnected[city][j] == 1 && !visited[j]) {
                dfs(j, isConnected, visited, n);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size(); 
        vector<bool> visited(n, false);
        int provinceCount = 0;

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs(i, isConnected, visited, n); 
                provinceCount++; 
            }
        }

        return provinceCount;
    }
};
