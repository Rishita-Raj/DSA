class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        
        long long totalSum = 0;
        for (auto &row : grid) {
            for (int val : row) {
                totalSum += val;
            }
        }
        
        if (totalSum % 2 != 0) return false;
        
        long long target = totalSum / 2;
        
        long long curr = 0;
        
        for (int i = 0; i < m - 1; i++) { // ensure non-empty below
            for (int j = 0; j < n; j++) {
                curr += grid[i][j];
            }
            
            if (curr == target) return true;
        }
        curr = 0;
        
        for (int j = 0; j < n - 1; j++) { // ensure non-empty right
            for (int i = 0; i < m; i++) {
                curr += grid[i][j];
            }
            
            if (curr == target) return true;
        }
        
        return false;
    }
};