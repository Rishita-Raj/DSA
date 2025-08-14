class Solution {
public:
    bool hasSameDigits(string s) {
        string str = s;
        for(int i=1;i<s.size()-1;i++){
            string curr = "";
            for(int j=0;j<str.size()-1;j++){
                curr += to_string((str[j]-'0' + str[j+1] - '0')%10);
            }
            str = curr;
            cout<<curr<<endl;
        }
        // cout<<str<<endl;
        return str[0] == str[1];
    }
};