class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.empty()) return 0;
        
        sort(points.begin(), points.end());  // sort by start
        
        int arrows = 1;  
        long long end = points[0][1];  // use long long because of big constraints
        
        for (int i = 1; i < points.size(); i++) {
            if (points[i][0] > end) {
                // no overlap → need new arrow
                arrows++;
                end = points[i][1];
            } else {
                // overlap → shrink to tighter end
                end = min(end, (long long)points[i][1]);
            }
        }
        
        return arrows;
    }
};
