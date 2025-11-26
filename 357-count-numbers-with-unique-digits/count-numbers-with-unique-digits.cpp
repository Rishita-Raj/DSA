class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0) return 1; // Only number 0 exists
        
        int total = 10; 
        int uniqueCount = 9; 
        int availableDigits = 9; // Remaining digits for next positions
        
        for (int i = 2; i <= n; i++) {
            uniqueCount *= availableDigits; 
            total += uniqueCount;
            availableDigits--;
        }
        
        return total;
    }
};
