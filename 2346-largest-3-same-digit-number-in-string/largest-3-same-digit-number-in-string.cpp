class Solution {
public:
    string largestGoodInteger(string num) {
        string best = "";

        for (int i = 0; i + 2 < num.size(); i++) {
            string sub = num.substr(i, 3);

            if (sub[0] == sub[1] && sub[1] == sub[2]) {
                if (best == "" || sub > best) {
                    best = sub;
                }
            }
        }

        return best;
    }
};
