class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if (n <= 2) return n;

        int ans = 1;

        for (int i = 0; i < n; i++) {
            unordered_map<long long, int> mp;
            int same = 0, maxCount = 0;

            for (int j = i + 1; j < n; j++) {
                int dx = points[j][0] - points[i][0];
                int dy = points[j][1] - points[i][1];

                if (dx == 0 && dy == 0) {
                    same++;  
                    continue;
                }

                int g = gcd(dx, dy);
                dx /= g;
                dy /= g;

                if (dx < 0) { dx = -dx; dy = -dy; }
                else if (dx == 0 && dy < 0) { dy = -dy; }

                long long key = ((long long)dx << 32) ^ (long long)(dy & 0xffffffff);
                maxCount = max(maxCount, ++mp[key]);
            }

            ans = max(ans, maxCount + same + 1);
        }

        return ans;
    }

    int gcd(int a, int b) {
        if (b == 0) return abs(a);
        return gcd(b, a % b);
    }
};
