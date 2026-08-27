#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.size();
        int freq[26] = {0};
        for (char c : s) freq[c - 'a']++;

        int fallbackPos = -1;
        int fallbackChar = -1;
        int fallbackFreq[26];
        for (int i = 0; i < n; i++) {
            int current = target[i] - 'a';
            for (int c = current + 1; c < 26; c++) {
                if (freq[c] > 0) {
                    fallbackPos = i;
                    fallbackChar = c;
                    memcpy(fallbackFreq, freq, sizeof(freq));
                    break;
                }
            }
            if (freq[current] > 0) {
                freq[current]--;
            } else {
                break;
            }
        }

        if (fallbackPos == -1) return "";
        string ans = target.substr(0, fallbackPos);
        ans += char('a' + fallbackChar);
        fallbackFreq[fallbackChar]--;

        for (int x = 0; x < 26; x++) {
            while (fallbackFreq[x] > 0) {
                ans += char('a' + x);
                fallbackFreq[x]--;
            }
        }

        return ans;
    }
};