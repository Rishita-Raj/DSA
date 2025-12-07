class Solution {
public:
    int countOdds(int low, int high) {
        // If both numbers are even
        if(low % 2 == 0 && high % 2 == 0){
            return (high - low) / 2;
        }
        // Otherwise at least one of them is odd
        return (high - low) / 2 + 1;
    }
};
