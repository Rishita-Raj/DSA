class Solution {
public:
    int maxDepth(string s) {
          int st=0;
        int ans=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(') st++;
            ans=max(ans,st);
            if(s[i]==')') st--;
        }
        return ans;
    }
};