class Solution {
public:
    int calculate(string s) {
        long long currentNumber = 0;
        char lastSign = '+';      // Sign before the current number
        stack<long long> st;

        for (int i = 0; i < s.size(); i++) {
            char c = s[i];

            // If digit, keep building the number
            if (isdigit(c)) {
                currentNumber = currentNumber * 10 + (c - '0');
            }

            // When we hit an operator OR reach end of string
            if ((!isdigit(c) && c != ' ') || i == s.size() - 1) {

                if (lastSign == '+') {
                    st.push(currentNumber);
                } 
                else if (lastSign == '-') {
                    st.push(-currentNumber);
                } 
                else if (lastSign == '*') {
                    long long top = st.top(); st.pop();
                    st.push(top * currentNumber);
                } 
                else if (lastSign == '/') {
                    long long top = st.top(); st.pop();
                    st.push(top / currentNumber);    // Truncates toward zero
                }

                // Update for next number
                lastSign = c;
                currentNumber = 0;
            }
        }

        // Sum all values in the stack
        long long result = 0;
        while (!st.empty()) {
            result += st.top();
            st.pop();
        }

        return (int)result;
    }
};
