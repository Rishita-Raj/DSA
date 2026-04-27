class Solution {
public:
    vector<vector<int>> dirs = {{-1,0}, {0,1}, {1,0}, {0,-1}};

    vector<vector<int>> typeDirs = {
        {},          
        {1,3},          
        {0,2},         
        {3,2},         
        {1,2},          
        {3,0},          
        {1,0}          
    };

    bool hasValidPath(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        
        queue<pair<int,int>> q;
        vector<vector<bool>> vis(m, vector<bool>(n, false));

        q.push({0,0});
        vis[0][0] = true;

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            if (x == m-1 && y == n-1) return true;

            for (int d : typeDirs[grid[x][y]]) {
                int nx = x + dirs[d][0];
                int ny = y + dirs[d][1];

                if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
                if (vis[nx][ny]) continue;

                int opposite = (d + 2) % 4;
                for (int nd : typeDirs[grid[nx][ny]]) {
                    if (nd == opposite) {
                        vis[nx][ny] = true;
                        q.push({nx, ny});
                        break;
                    }
                }
            }
        }

        return false;
    }
};