class Solution {
public:
    bool isNumber(string s) {
        bool digitSeen = false;
        bool dotSeen = false;
        bool expSeen = false;
        bool digitAfterExp = true;  // only becomes false when exp appears

        for (int i = 0; i < s.size(); i++) {
            char c = s[i];

            if (isdigit(c)) {
                digitSeen = true;
                if (expSeen) digitAfterExp = true;
            }

            else if (c == '+' || c == '-') {
                // sign is valid only at start or just after exponent
                if (i > 0 && s[i-1] != 'e' && s[i-1] != 'E')
                    return false;
            }

            else if (c == '.') {
                // dot cannot appear after exponent or appear twice
                if (dotSeen || expSeen)
                    return false;
                dotSeen = true;
            }

            else if (c == 'e' || c == 'E') {
                // exp must appear after digit and only once
                if (expSeen || !digitSeen)
                    return false;

                expSeen = true;
                digitAfterExp = false;  // we must see digits after e
            }

            else {
                return false; // invalid character
            }
        }

        return digitSeen && digitAfterExp;
    }
};
