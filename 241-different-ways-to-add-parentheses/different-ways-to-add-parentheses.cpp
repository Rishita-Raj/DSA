class Solution {
public:
    unordered_map<string, vector<int>> memo;

    vector<int> diffWaysToCompute(string expression) {
        if (memo.count(expression))
            return memo[expression];
        
        vector<int> results;
        

        for (int i = 0; i < expression.size(); i++) {
            char c = expression[i];
            
            // If current character is an operator, split here
            if (c == '+' || c == '-' || c == '*') {
                vector<int> left = diffWaysToCompute(expression.substr(0, i));
                vector<int> right = diffWaysToCompute(expression.substr(i + 1));
                
                // Combine all left and right results
                for (int a : left) {
                    for (int b : right) {
                        if (c == '+') results.push_back(a + b);
                        else if (c == '-') results.push_back(a - b);
                        else results.push_back(a * b);
                    }
                }
            }
        }
        
        // If no operator was found → it's just a number
        if (results.empty()) {
            results.push_back(stoi(expression));
        }
        
        // Save in memo
        memo[expression] = results;
        return results;
    }
};
