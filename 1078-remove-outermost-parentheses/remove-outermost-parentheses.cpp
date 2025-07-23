class Solution {
public:
    string removeOuterParentheses(string s) {
        int bt = 0, left = 0, right = 0;
        string str = "";
        while(right < s.size()){
            if(s[right] == '(') bt++;
            else bt--;
            if(bt == 0){
                for(int i=left+1;i<right;i++){
                    str += s[i];
                }
                left = right + 1;
            }
            right++;
        }
        return str;
    }
};