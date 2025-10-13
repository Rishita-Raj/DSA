#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isAnagram(string a, string b) {
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        return a == b;
    }
    
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> ans;
        
        for (string &word : words) {
            if (ans.empty() || !isAnagram(ans.back(), word)) {
                ans.push_back(word);
            }
        }
        return ans;
    }
};
