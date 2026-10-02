class Solution {
public:
      void backtrack(vector<string>& result, string& current, int open, int close, int max){
        if(current.size() == max * 2){
            result.push_back(current);
            return;
        }

        if(open < max){
            current.push_back('(');
            backtrack(result, current, open+1, close, max);
            current.pop_back();
        }

        if(close < open){
             current.push_back(')');
            backtrack(result, current, open, close+1, max);
            current.pop_back();
        }
            }

              vector<string> generateParenthesis(int n) {
        vector<string> result;
        string current;

        backtrack(result, current, 0, 0, n);
        return result;
    }
        };