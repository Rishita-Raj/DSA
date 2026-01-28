class Solution {
public:
    int longestSubstring(string s, int k) {
      if (s.length() < k)
            return 0;

        // Count frequency
        vector<int> freq(26, 0);
        for (char c : s)
            freq[c - 'a']++;

        // Find a bad character
        for (int i = 0; i < s.length(); i++) {
            if (freq[s[i] - 'a'] < k) {
                // Split around this character
                int left = longestSubstring(s.substr(0, i), k);
                int right = longestSubstring(s.substr(i + 1), k);
                return max(left, right);
            }
        }

        // All characters appear at least k times
        return s.length();
    }
};
