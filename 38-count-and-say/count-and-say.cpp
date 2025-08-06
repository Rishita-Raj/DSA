class Solution {
public:
    string helper(string s){
        string res = "";
        int low = 0;
        int i;
        for(i=1;i<s.size();i++){
            if(s[low] == s[i]){
                continue;
            }
            else{
                int gap = i-low;
                res += to_string(gap) + s[low];
                low = i;
            }
        }
        int gap = i-low;
        res += to_string(gap) + s[low];
        
        return res;
    }
    string countAndSay(int n) {
        string str = "1";
        for(int i=1;i<n;i++){
            str = helper(str);
        }
        return str;
    }
};