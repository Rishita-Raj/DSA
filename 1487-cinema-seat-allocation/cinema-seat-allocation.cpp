class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {

        unordered_map<int, int> rows;

        for(auto &seat : reservedSeats) {
            int row = seat[0];
            int col = seat[1];

            if(col >= 2 && col <= 9) {
                rows[row] |= (1 << col);
            }
        }

        long long ans = 2LL * (n - rows.size());

        for(auto &[row, mask] : rows) {

            bool left = true;
            bool middle = true;
            bool right = true;

            for(int seat = 2; seat <= 5; seat++) {
                if(mask & (1 << seat)) {
                    left = false;
                    break;
                }
            }
            for(int seat = 4; seat <= 7; seat++) {
                if(mask & (1 << seat)) {
                    middle = false;
                    break;
                }
            }
            for(int seat = 6; seat <= 9; seat++) {
                if(mask & (1 << seat)) {
                    right = false;
                    break;
                }
            }

            if(left && right) {
                ans += 2;
            }
            else if(left || middle || right) {
                ans += 1;
            }
        }

        return ans;
    }
};