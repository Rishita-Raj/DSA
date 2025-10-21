class Solution {
public:
    string convertToTitle(int columnNumber) {
        string result = "";

        while (columnNumber > 0) {
            columnNumber--; // shift to 0-based index
            int remainder = columnNumber % 26;
            char letter = 'A' + remainder;
            result += letter;
            columnNumber /= 26;
        }

        reverse(result.begin(), result.end());
        return result;
    }
};
