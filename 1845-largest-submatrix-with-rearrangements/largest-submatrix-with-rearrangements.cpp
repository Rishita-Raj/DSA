class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        
        int m = matrix.size();
        int n = matrix[0].size();
        
        vector<vector<int>> height = matrix;
        
        for (int i = 1; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (height[i][j] == 1) {
                    height[i][j] += height[i-1][j];
                }
            }
        }
        
        int maxArea = 0;
        
        for (int i = 0; i < m; i++) {
            
            vector<int> row = height[i];
            
            sort(row.begin(), row.end(), greater<int>());
            
            for (int j = 0; j < n; j++) {
                int h = row[j];
                int w = j + 1;
                
                maxArea = max(maxArea, h * w);
            }
        }
        
        return maxArea;
    }
};