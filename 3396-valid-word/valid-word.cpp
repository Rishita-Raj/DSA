class Solution {
public:
    bool isValid(string word) {
        if (word.length() < 3) return false;

        bool isVowel = false;
        bool isConsonant = false;

        for (char c : word) {
            if (!isalnum(c)) return false; 
            if (isalpha(c)) {
                char lower = tolower(c);
                if (lower == 'a' || lower == 'e' || lower == 'i' || lower == 'o' || lower == 'u') {
                    isVowel = true;
                } else {
                    isConsonant = true;
                }
            }
        }

        return isVowel && isConsonant;
    }
};
