class Solution {
public:
    int minimizedMaximum(int n, vector<int>& q) {
        int low = 1;
        int high = *max_element(q.begin(), q.end());

        while (low < high) {
            int mid = (low + high) / 2;

            int stores = 0;
            for (int x : q) {
                stores += (x + mid - 1) / mid; // ceil division
            }

            if (stores > n) {
                low = mid + 1;   // not possible → increase limit
            } else {
                high = mid;      // possible → try smaller
            }
        }

        return low;
    }
};