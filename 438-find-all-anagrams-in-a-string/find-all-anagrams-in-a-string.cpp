class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;  
        if (s.length() < p.length()) return res;

        vector<int> pCount(26, 0), sCount(26, 0);

       
        for (char c : p) {
            pCount[c - 'a']++;
        }

        
        for (int i = 0; i < p.length(); ++i) {
            sCount[s[i] - 'a']++;
        }

        if (sCount == pCount) {
            res.push_back(0);
        }

        for (int i = p.length(); i < s.length(); ++i) {
           
            sCount[s[i] - 'a']++;
            sCount[s[i - p.length()] - 'a']--;

            if (sCount == pCount) {
                res.push_back(i - p.length() + 1);
            }
        }

        return res;
    }
};