class Solution {
public:
    string sortSentence(string s) {
        vector<string> words;
        string temp = "";

        for (char c : s) {
            if (c == ' ') {
                words.push_back(temp);
                temp.clear();
            } else {
                temp += c;
            }
        }
        words.push_back(temp); 
        vector<string> result(words.size());

        for (string w : words) {
            int pos = w.back() - '1';   
            w.pop_back();               // remove digit
            result[pos] = w;
        }

        string answer = "";
        for (int i = 0; i < result.size(); i++) {
            answer += result[i];
            if (i < result.size() - 1)
                answer += " ";
        }

        return answer;
    }
};
