class Solution {
public:
    // Helper function to compute largest rectangle in histogram (from Leetcode 84)
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        int maxArea = 0;
        heights.push_back(0); // Add sentinel value to flush remaining stack

        for (int i = 0; i < heights.size(); ++i) {
            // Maintain increasing stack
            while (!st.empty() && heights[i] < heights[st.top()]) {
                int height = heights[st.top()];
                st.pop();
                int width = st.empty() ? i : i - st.top() - 1;
                maxArea = max(maxArea, height * width);
            }
            st.push(i);
        }

        return maxArea;
    }

    // Main function to find maximal rectangle of 1s
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<int> histogram(cols, 0); // Histogram for each row
        int maxRectangle = 0;

        // Build histogram for each row and compute max area
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                // If '1', increase the height in histogram
                if (matrix[i][j] == '1') {
                    histogram[j] += 1;
                } else {
                    histogram[j] = 0; // Reset if '0'
                }
            }
            // Use Largest Rectangle in Histogram for current row
            maxRectangle = max(maxRectangle, largestRectangleArea(histogram));
        }

        return maxRectangle;
    }
};
