class Solution {
public:
    string decodeString(string s) {
        stack<int> numString;
        stack<string> strString;

        string curr = "";
        int num  = 0;

        for(char ch : s){
            if(isdigit(ch)){
                num = num * 10 + (ch - '0'); 
            }else if(ch == '['){
                numString.push(num);
                strString.push(curr);
                num = 0;
                curr = "";
            }else if(ch == ']'){
                int repeat = numString.top(); numString.pop();
                string prev = strString.top(); strString.pop();

                string temp = "";
                for(int i = 0; i<repeat; i++){
                    temp += curr;
                }
                curr = prev  + temp;
            }

            else{
                curr += ch;
            }
        }
        return curr;
    }
};