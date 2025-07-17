class Solution {
public:
    int beautySum(string s) {
        int ans=0;
        for(int i=0;i<s.size();i++){
            vector<int>frequency(26,0);
            for(int j=i;j<s.size();j++){
                frequency[s[j]-'a']++;
                int mini = INT_MAX, maxi = INT_MIN;
                for (int k = 0; k < 26; k++) {
                    if (frequency[k] > 0) {
                        mini = min(mini, frequency[k]);
                        maxi = max(maxi, frequency[k]);
                    }
                }
                ans+=(maxi-mini);
            }
        }
        return ans;
    }
};