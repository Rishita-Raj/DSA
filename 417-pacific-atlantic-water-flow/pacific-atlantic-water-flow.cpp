class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        vector<vector<int>> result;
        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));
        
        vector<pair<int, int>> directions = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        
        function<void(int,int,vector<vector<bool>>&)> dfs = [&](int r, int c, vector<vector<bool>>& visited) {
            visited[r][c] = true;
            for (auto [dr, dc] : directions) {
                int nr = r + dr, nc = c + dc;
                if (nr >= 0 && nr < m && nc >= 0 && nc < n &&
                    !visited[nr][nc] && heights[nr][nc] >= heights[r][c]) {
                    dfs(nr, nc, visited);
                }
            }
        };
        
        for (int i = 0; i < m; ++i) dfs(i, 0, pacific);
        for (int j = 0; j < n; ++j) dfs(0, j, pacific);
        for (int i = 0; i < m; ++i) dfs(i, n - 1, atlantic);
        for (int j = 0; j < n; ++j) dfs(m - 1, j, atlantic);
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (pacific[i][j] && atlantic[i][j]) {
                    result.push_back({i, j});
                }
            }
        }
        return result;
    }
};
