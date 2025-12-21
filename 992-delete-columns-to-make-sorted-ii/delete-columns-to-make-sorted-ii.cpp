class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        int m = strs[0].size();
        
        vector<bool> fixed(n - 1, false); 
        int deletions = 0;

        for (int col = 0; col < m; col++) {
            bool needDelete = false;

            for (int i = 0; i < n - 1; i++) {
                if (!fixed[i] && strs[i][col] > strs[i + 1][col]) {
                    needDelete = true;
                    break;
                }
            }

            if (needDelete) {
                deletions++;
                continue;
            }

            for (int i = 0; i < n - 1; i++) {
                if (!fixed[i] && strs[i][col] < strs[i + 1][col]) {
                    fixed[i] = true;
                }
            }
        }

        return deletions;
    }
};
