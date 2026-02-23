class Solution {
public:
    string removeOccurrences(string s, string part) {
        string result;
        int partLen = part.length();
        
        for (char ch : s) {
            result.push_back(ch);
            
            // If result size is at least part length, check for match
            if (result.size() >= partLen) {
                if (result.substr(result.size() - partLen) == part) {
                    result.erase(result.size() - partLen);
                }
            }
        }
        
        return result;
    }
};