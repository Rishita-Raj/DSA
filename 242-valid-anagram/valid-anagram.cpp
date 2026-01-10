class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;

        int freq[26] ={0};

        for( int c : s){
            freq[c-'a']++;
        }

        for(int c : t){
            freq[c-'a']--;
        }

        for(int i = 0; i<26; ++i){
            if(freq[i] != 0){
                return false;
                break;
            }
        }
        return true;
    }
};