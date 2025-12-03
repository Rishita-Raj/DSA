class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }

    bool solve(vector<vector<char>>& board) {
        for (int row = 0; row < 9; row++) {
            for (int col = 0; col < 9; col++) {

                if (board[row][col] == '.') {  // Empty cell found

                    for (char c = '1'; c <= '9'; c++) {
                        if (isValid(board, row, col, c)) {
                            board[row][col] = c;

                            // Move to the next cell
                            if (solve(board)) return true;

                            // Backtrack
                            board[row][col] = '.';
                        }
                    }

                    // If no number works here, return false
                    return false;
                }
            }
        }
        return true;  // Fully solved
    }

    bool isValid(vector<vector<char>>& board, int row, int col, char c) {
        
        // Check row and column
        for (int i = 0; i < 9; i++) {
            if (board[row][i] == c) return false;
            if (board[i][col] == c) return false;
        }

        // Check 3x3 sub-box
        int startRow = (row / 3) * 3;
        int startCol = (col / 3) * 3;

        for (int i = startRow; i < startRow + 3; i++) {
            for (int j = startCol; j < startCol + 3; j++) {
                if (board[i][j] == c) return false;
            }
        }

        return true;
    }
};
