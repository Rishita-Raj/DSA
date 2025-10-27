class Solution {
public:
    int titleToNumber(string columnTitle) {
        long long result = 0;  // use long long to prevent overflow for large titles
        
        for (char c : columnTitle) {
            int value = c - 'A' + 1;   // Convert letter to number (A=1, B=2, ..., Z=26)
            result = result * 26 + value;  // Move one position left (base-26)
        }
        
        return (int)result;
    }
};
