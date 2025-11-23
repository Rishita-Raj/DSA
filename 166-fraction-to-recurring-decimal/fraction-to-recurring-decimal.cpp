class Solution {
public:
    string fractionToDecimal(long long numerator, long long denominator) {
        if (numerator == 0) return "0";

        string result = "";

        // Check sign
        if ((numerator < 0) ^ (denominator < 0)) {
            result += "-";
        }

        // Convert to positive long long to avoid overflow
        long long n = llabs(numerator);
        long long d = llabs(denominator);

        // Integer part
        result += to_string(n / d);

        long long remainder = n % d;
        if (remainder == 0) return result;  // No decimal part

        result += ".";

        // Map to store remainder -> position in result where it appeared
        unordered_map<long long, int> seen;

        // Build decimal part
        while (remainder != 0) {
            if (seen.count(remainder)) {
                // Insert '(' where this remainder first appeared
                result.insert(seen[remainder], "(");
                result += ")";
                return result;
            }

            seen[remainder] = result.size(); // Mark position
            remainder *= 10;
            result += to_string(remainder / d);
            remainder %= d;
        }

        return result; // Finite decimal
    }
};
