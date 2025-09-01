class Solution {
public:
    int LCS(string a, string b, int n, int m){
        vector<vector<int>> DP(n+1, vector<int>(m+1,0));
        if(m==0 || n==0) return 0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(a[i-1] == b[j-1]){
                    DP[i][j] = 1 + DP[i-1][j-1];
                }
                else{
                    DP[i][j] = max(DP[i-1][j],DP[i][j-1]);
                }
            }
        }
        return DP[n][m];
    }
    int minDistance(string word1, string word2) {
        int x = word1.size() + word2.size();
        return x - 2*LCS(word1,word2,word1.size(),word2.size());
    }
};