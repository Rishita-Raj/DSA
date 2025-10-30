class Solution {
public:
    int addDigits(int num) {
        if (num == 0) return 0;         // Base case
        return 1 + (num - 1) % 9;       // Digital root formula
    }
};
