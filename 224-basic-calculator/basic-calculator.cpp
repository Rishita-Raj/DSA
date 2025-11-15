class Solution {
public:
    int calculate(string s) {
        long long result = 0;
        int sign = 1;
        long long num = 0;
        stack<long long> st;

        for (char c : s) {
            if (isdigit(c)) {
                num = num * 10 + (c - '0');  // build the number
            }
            else if (c == '+' || c == '-') {
                result += sign * num;
                num = 0;
                sign = (c == '+') ? 1 : -1;
            }
            else if (c == '(') {
                st.push(result);
                st.push(sign);

                result = 0;
                sign = 1;
            }
            else if (c == ')') {
                result += sign * num;
                num = 0;

                int prevSign = st.top(); st.pop();
                long long prevResult = st.top(); st.pop();

                result = prevResult + prevSign * result;
            }
        }

        result += sign * num;

        return (int)result;
    }
};
