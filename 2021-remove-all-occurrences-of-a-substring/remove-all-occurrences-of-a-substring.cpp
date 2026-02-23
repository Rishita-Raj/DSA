class Solution {
public:
    string removeOccurrences(string s, string part) {
       string result;
       int partLen = part.length();

       for(char ch : s){
        result.push_back(ch);
       

       if(result.size() >= partLen){
        if(result.substr(result.size() - partLen) == part){
            result.erase(result.size() - partLen);
        }
       }
       }
       return result;
    }
};