class Solution {
public:
    
    string answer = "";
    int count = 0;

    void dfs(int n, int k, string &curr) {
        
        if (!answer.empty()) return;

        if (curr.size() == n) {
            count++;
            if (count == k) {
                answer = curr;
            }
            return;
        }

        for (char ch : {'a','b','c'}) {

            if (!curr.empty() && curr.back() == ch)
                continue;

            curr.push_back(ch);

            dfs(n, k, curr);

            curr.pop_back();
        }
    }

    string getHappyString(int n, int k) {
        
        string curr = "";

        dfs(n, k, curr);

        return answer;
    }
};