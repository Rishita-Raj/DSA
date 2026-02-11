class Solution {
public:
    string toHex(int num) {
        if (num == 0) return "0";

        unsigned int n = num;  // handle negative using two’s complement
        string hexChars = "0123456789abcdef";
        string result = "";

        while (n > 0) {
            int digit = n & 15;  // extract last 4 bits
            result = hexChars[digit] + result;
            n >>= 4;  // shift right by 4 bits
        }

        return result;
    }
};
