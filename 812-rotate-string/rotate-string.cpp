class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size()!=goal.size()) return 0;
        if(s==goal) return 1;
        for(int i=0;i<s.size();i++){
            string temp=s.substr(1,s.size()-1);
            s=temp+s[0];
            if(s==goal) return 1;
        }
        return 0;
    }
};