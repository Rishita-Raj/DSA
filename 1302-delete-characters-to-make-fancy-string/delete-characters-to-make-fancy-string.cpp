class Solution {
public:
    string makeFancyString(string s) {
        std::string fancy_string = "";
        for (int i = 0; i < s.length(); ++i) {
            char current_char = s[i];
            if (fancy_string.length() < 2) {
                fancy_string.push_back(current_char);
            }
            else {
                char last_char = fancy_string.back();
                char second_last_char = fancy_string[fancy_string.length() - 2];
                if (current_char == last_char && current_char == second_last_char) {
                    continue; 
                } else {
                    fancy_string.push_back(current_char);
                }
            }
        }
        return fancy_string;
    }
};