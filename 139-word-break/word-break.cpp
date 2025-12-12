class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<bool> dp(n + 1, false);
        dp[0] = true; // Empty string is valid

        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        int maxLen = 0;
        for (auto &w : wordDict) maxLen = max(maxLen, (int)w.size());

        for (int i = 1; i <= n; i++) {
            for (int len = 1; len <= maxLen && len <= i; len++) {
                string sub = s.substr(i - len, len);
                if (dp[i - len] && dict.count(sub)) {
                    dp[i] = true;
                    break;  // No need to check more
                }
            }
        }

        return dp[n];
    }
};
