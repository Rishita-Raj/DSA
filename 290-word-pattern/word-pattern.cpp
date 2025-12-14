class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> words;
        string temp;

        for (char c : s) {
            if (c == ' ') {
                words.push_back(temp);
                temp.clear();
            } else {
                temp += c;
            }
        }
        words.push_back(temp); 

        if (pattern.length() != words.size())
            return false;

        unordered_map<char, string> charToWord;
        unordered_map<string, char> wordToChar;

        for (int i = 0; i < pattern.length(); i++) {
            char p = pattern[i];
            string w = words[i];

            if (charToWord.count(p) && charToWord[p] != w)
                return false;

            if (wordToChar.count(w) && wordToChar[w] != p)
                return false;

            charToWord[p] = w;
            wordToChar[w] = p;
        }

        return true;
    }
};
