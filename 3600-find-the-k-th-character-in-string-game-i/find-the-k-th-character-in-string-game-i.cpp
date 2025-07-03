class Solution {
public:
    char kthCharacter(int k) {
        string word = "a";  
        
        while (word.size() < k) {  
            string nextStr = "";   
            
            for (char ch : word) {
                    if (ch == 'z') {
                    nextStr += 'a';
                } else {
                    nextStr += ch + 1;
                }
            }

            word += nextStr;  
        }

        return word[k - 1];  
    }
};