class Solution {
public:
    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();

        vector<int> sa(n), rank(n), temp(n);

        iota(sa.begin(), sa.end(), 0);

        // Coordinate compression
        vector<int> vals = nums;
        sort(vals.begin(), vals.end());
        vals.erase(unique(vals.begin(), vals.end()), vals.end());

        for (int i = 0; i < n; i++) {
            rank[i] = lower_bound(vals.begin(), vals.end(), nums[i]) - vals.begin();
        }

        // Build suffix array using doubling
        for (int len = 1; len < n; len *= 2) {
            sort(sa.begin(), sa.end(), [&](int a, int b) {
                if (rank[a] != rank[b])
                    return rank[a] < rank[b];

                int ra = (a + len < n) ? rank[a + len] : -1;
                int rb = (b + len < n) ? rank[b + len] : -1;

                return ra < rb;
            });

            temp[sa[0]] = 0;

            for (int i = 1; i < n; i++) {
                int a = sa[i - 1], b = sa[i];

                int a2 = (a + len < n) ? rank[a + len] : -1;
                int b2 = (b + len < n) ? rank[b + len] : -1;

                temp[b] = temp[a] +
                    (rank[a] != rank[b] || a2 != b2);
            }

            rank = temp;

            if (rank[sa[n - 1]] == n - 1)
                break;
        }

        // Build LCP array using Kasai's algorithm
        vector<int> pos(n), lcp(n, 0);

        for (int i = 0; i < n; i++)
            pos[sa[i]] = i;

        int h = 0;

        for (int i = 0; i < n; i++) {
            int r = pos[i];

            if (r == 0) continue;

            int j = sa[r - 1];

            while (i + h < n && j + h < n &&
                   nums[i + h] == nums[j + h]) {
                h++;
            }

            lcp[r] = h;

            if (h > 0) h--;
        }

        // Find the shortest unique subarray
        int ans = n;

        for (int i = 0; i < n; i++) {
            int r = pos[i];

            int mx = max(lcp[r],
                         (r + 1 < n ? lcp[r + 1] : 0));

            if (mx < n - i) {
                ans = min(ans, mx + 1);
            }
        }

        return ans;
    }
};