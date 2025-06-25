class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
            int n = nums1.size(), m = nums2.size();
        int maxLen = 0;

        // Slide nums1 over nums2 from left to right
        for (int offset = 0; offset < n; ++offset) {
            int len = min(m, n - offset);
            maxLen = max(maxLen, maxMatch(nums1, nums2, offset, 0, len));
        }

        // Slide nums2 over nums1 from left to right
        for (int offset = 0; offset < m; ++offset) {
            int len = min(n, m - offset);
            maxLen = max(maxLen, maxMatch(nums1, nums2, 0, offset, len));
        }

        return maxLen;
    }

private:
    int maxMatch(const vector<int>& nums1, const vector<int>& nums2, int start1, int start2, int len) {
        int maxCount = 0, count = 0;
        for (int i = 0; i < len; ++i) {
            if (nums1[start1 + i] == nums2[start2 + i]) {
                ++count;
                maxCount = max(maxCount, count);
            } else {
                count = 0;
            }
        }
        return maxCount;
    }
};