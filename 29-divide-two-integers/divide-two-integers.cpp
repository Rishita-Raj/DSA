class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;
        bool negative = (dividend < 0) ^ (divisor < 0);
        long long dvd = labs(dividend);
        long long dvs = labs(divisor);
        long long ans = 0;

        while (dvd >= dvs) {
            long long temp = dvs, multiple = 1;

            while ((temp << 1) <= dvd) {
                temp <<= 1;
                multiple <<= 1;
            }

            dvd -= temp;
            ans += multiple;
        }
        if (negative) ans = -ans;
        if (ans > INT_MAX) return INT_MAX;
        if (ans < INT_MIN) return INT_MIN;

        return (int)ans;
    }
};
