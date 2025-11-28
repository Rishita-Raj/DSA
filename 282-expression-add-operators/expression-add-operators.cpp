class Solution {
public:
    vector<string> result;

    void backtrack(string &num, int target, int index,
                   long long currValue, long long prevValue,
                   string path) {

        // If we reached the end of the string
        if (index == num.size()) {
            if (currValue == target) {
                result.push_back(path);
            }
            return;
        }

        long long currentNum = 0;
        string currentStr = "";

        for (int i = index; i < num.size(); i++) {

            currentNum = currentNum * 10 + (num[i] - '0');
            currentStr += num[i];

            // Prevent numbers with leading zero
            if (currentStr.size() > 1 && currentStr[0] == '0') break;

            if (index == 0) {
                // First number — no operator needed before it
                backtrack(num, target, i + 1,
                          currentNum, currentNum, currentStr);
            } else {
                // Option 1: '+'
                backtrack(num, target, i + 1,
                          currValue + currentNum,
                          currentNum,
                          path + "+" + currentStr);

                // Option 2: '-'
                backtrack(num, target, i + 1,
                          currValue - currentNum,
                          -currentNum,
                          path + "-" + currentStr);

                // Option 3: '*'
                backtrack(num, target, i + 1,
                          currValue - prevValue + prevValue * currentNum,
                          prevValue * currentNum,
                          path + "*" + currentStr);
            }
        }
    }

    vector<string> addOperators(string num, int target) {
        backtrack(num, target, 0, 0, 0, "");
        return result;
    }
};
