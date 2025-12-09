class Solution {
public:
    bool dfs(vector<vector<char>>& board, int i, int j, int index, string& word){
        if(index == word.size()) return true;

        // Out of bounds or mismatch
        if(i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] != word[index])
            return false;

        char temp = board[i][j];      // store original character
        board[i][j] = '#';            // mark as visited

        // Explore all 4 directions
        bool found = dfs(board, i+1, j, index+1, word) ||
                     dfs(board, i-1, j, index+1, word) ||
                     dfs(board, i, j+1, index+1, word) ||
                     dfs(board, i, j-1, index+1, word);

        board[i][j] = temp;           // backtrack (undo visit)

        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();

        // Start search from every position
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == word[0] && dfs(board, i, j, 0, word))
                    return true;
            }
        }
        return false;
    }
};
