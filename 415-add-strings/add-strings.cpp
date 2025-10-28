class Solution {
public:
    string addStrings(string num1, string num2) {
        int i = num1.size() - 1;  // Pointer for num1
        int j = num2.size() - 1;  // Pointer for num2
        int carry = 0;            // Carry for addition
        string result = "";       // To store final answer

        // Process digits from the end
        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;

            // Add current digits if available
            if (i >= 0) sum += num1[i--] - '0';
            if (j >= 0) sum += num2[j--] - '0';

            // Add last digit of sum to result
            result += (sum % 10) + '0';

            // Update carry
            carry = sum / 10;
        }

        // Reverse the result since we added from the end
        reverse(result.begin(), result.end());
        return result;
    }
};
