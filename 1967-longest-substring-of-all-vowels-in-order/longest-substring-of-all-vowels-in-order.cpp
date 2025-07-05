class Solution {
public:
    int longestBeautifulSubstring(string word) {
        int maxLen = 0;     
        int currLen = 0;    
        int count = 0;   

        for (int i = 0; i < word.size(); ++i) {
           
            if (i > 0 && word[i] >= word[i - 1]) {
                currLen++;  
                if (word[i] != word[i - 1]) {
                    count++;
                }
            } else {
                               currLen = 1;
                count = 1;
            }

            if (count == 5) {
                maxLen = max(maxLen, currLen);
            }
        }

        return maxLen;
    }
};