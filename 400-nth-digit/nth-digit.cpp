class Solution {
public:
    int findNthDigit(int n) {
        long long digitLength = 1;
        long long count = 9;
        long long start = 1;

        // Step 1: Find the digit-length group
        while (n > digitLength * count) {
            n -= digitLength * count;
            digitLength++;
            count *= 10;
            start *= 10;
        }

        // Step 2: Find the exact number
        long long number = start + (n - 1) / digitLength;

        // Step 3: Find the digit index
        int digitIndex = (n - 1) % digitLength;

        // Step 4: Return the digit
        return to_string(number)[digitIndex] - '0';
    }
};
