class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft,
                                vector<vector<int>>& topRight) {
        int n = bottomLeft.size();
        long long maxArea = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                long long xLeft = max(bottomLeft[i][0], bottomLeft[j][0]);
                long long yBottom = max(bottomLeft[i][1], bottomLeft[j][1]);
                long long xRight = min(topRight[i][0], topRight[j][0]);
                long long yTop = min(topRight[i][1], topRight[j][1]);

                // Check if intersection exists
                if (xLeft < xRight && yBottom < yTop) {
                    long long width = xRight - xLeft;
                    long long height = yTop - yBottom;
                    long long side = min(width, height);
                    maxArea = max(maxArea, side * side);
                }
            }
        }

        return maxArea;
    }
};
