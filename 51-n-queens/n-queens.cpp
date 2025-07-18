class Solution {
public:
    bool Valid(int n,int row,int col,vector<string>&board){
        for(int i=col;i>=0;i--){
            if(board[row][i]=='Q') return false;
        }

        int r = row - 1, c = col - 1;
        while (r >= 0 && c >= 0) {
            if (board[r][c] == 'Q') return false;
            r--;
            c--;
        }
      
        r=row+1,c=col-1;
        while(r<n and c>=0){
            if (board[r][c] == 'Q') return false;
            r++;
            c--;
        }

        return true;
    }
    void solve(int n,int col,vector<vector<string>> &ans,vector<string>&board){
        if(n==col){
            ans.push_back(board);
            return;
        }
        for(int row=0;row<n;row++){
            if(Valid(n,row,col,board)){
                board[row][col]='Q';
                solve(n,col+1,ans,board);
                board[row][col]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string>board;
        string s="";
        for(int i=0;i<n;i++){
            s+='.';
        }
        for(int i=0;i<n;i++){
            board.push_back(s);
        }
        solve(n,0,ans,board);
        return ans;
    }
};