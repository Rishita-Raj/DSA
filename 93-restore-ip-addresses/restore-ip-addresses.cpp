class Solution {
public:
    vector<string> result;

    void backtrack(string& s, int index, int parts, string curr) {
        // If 4 parts are formed and all digits are used
        if (parts == 4 && index == s.size()) {
            curr.pop_back(); // remove last '.'
            result.push_back(curr);
            return;
        }

        // If 4 parts already used or string exhausted incorrectly
        if (parts == 4 || index == s.size())
            return;

        // Try taking 1 to 3 digits
        for (int len = 1; len <= 3 && index + len <= s.size(); len++) {
            string part = s.substr(index, len);

            // Leading zero check
            if (part.size() > 1 && part[0] == '0')
                break;

            int value = stoi(part);
            if (value > 255)
                break;

            backtrack(s, index + len, parts + 1, curr + part + ".");
        }
    }

    vector<string> restoreIpAddresses(string s) {
        backtrack(s, 0, 0, "");
        return result;
    }
};
