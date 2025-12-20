class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int rows = strs.size();
        int cols = strs[0].size();
        int deleteCount = 0;

             for (int col = 0; col < cols; col++) {
            for (int row = 0; row < rows - 1; row++) {
                if (strs[row][col] > strs[row + 1][col]) {
                    deleteCount++;
                    break; 
                }
            }
        }

        return deleteCount;
    }
};
