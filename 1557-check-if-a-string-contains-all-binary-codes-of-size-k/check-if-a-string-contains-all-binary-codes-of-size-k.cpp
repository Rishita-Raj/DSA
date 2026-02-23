class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = s.size();
        
        // Total possible binary codes of length k
        int total = 1 << k;
        
        // Early exit: Not enough substrings
        if (n - k + 1 < total) return false;
        
        unordered_set<int> seen;
        
        int num = 0;
        int mask = total - 1;  // Keeps last k bits
        
        for (int i = 0; i < n; i++) {
            // Shift left and add current bit
            num = ((num << 1) & mask) | (s[i] - '0');
            
            // Start checking only when window size reaches k
            if (i >= k - 1) {
                seen.insert(num);
                
                // If we found all patterns
                if (seen.size() == total) {
                    return true;
                }
            }
        }
        
        return false;
    }
};