class Solution {
public:
    pair<int, string> removeSubstrings(const string& s, char first, char second, int points) {
        stack<char> st;
        int total = 0;
        string remaining = "";

        for (char ch : s) {
            if (!st.empty() && st.top() == first && ch == second) {
                st.pop();
                total += points;
            } else {
                st.push(ch);
            }
        }
        while (!st.empty()) {
            remaining += st.top();
            st.pop();
        }
        reverse(remaining.begin(), remaining.end());
        return {total, remaining};
    }

    int maximumGain(string s, int x, int y) {
        int total = 0;

        if (x >= y) {
            auto [pointsAB, remaining] = removeSubstrings(s, 'a', 'b', x);
            auto [pointsBA, _] = removeSubstrings(remaining, 'b', 'a', y);
            total = pointsAB + pointsBA;
        } else {
            auto [pointsBA, remaining] = removeSubstrings(s, 'b', 'a', y);
            auto [pointsAB, _] = removeSubstrings(remaining, 'a', 'b', x);
            total = pointsBA + pointsAB;
        }

        return total;
    }
};
