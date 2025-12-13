class Solution {
public:
    vector<string> validateCoupons(vector<string>& code,
                                   vector<string>& businessLine,
                                   vector<bool>& isActive) {

        vector<string> order = {"electronics", "grocery", "pharmacy", "restaurant"};
        unordered_map<string, vector<string>> bucket;

        auto isValidCode = [&](const string& s) {
            if (s.empty()) return false;
            for (char c : s) {
                if (!isalnum(c) && c != '_')
                    return false;
            }
            return true;
        };

        unordered_set<string> validLines(order.begin(), order.end());

        for (int i = 0; i < code.size(); i++) {
            if (!isActive[i]) continue;
            if (!isValidCode(code[i])) continue;
            if (!validLines.count(businessLine[i])) continue;

            bucket[businessLine[i]].push_back(code[i]);
        }

        vector<string> result;
        for (auto& line : order) {
            auto& vec = bucket[line];
            sort(vec.begin(), vec.end());
            result.insert(result.end(), vec.begin(), vec.end());
        }

        return result;
    }
};
