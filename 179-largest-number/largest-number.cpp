class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> arr;
        for (int num : nums) arr.push_back(to_string(num));
        
        // Custom sort: compare concatenated results
        sort(arr.begin(), arr.end(), [](string &a, string &b) {
            return a + b > b + a; // sort in descending order
        });
        
        // If the largest number is "0", answer is just "0"
        if (arr[0] == "0") return "0";
        
        // Build final result string
        string result = "";
        for (string &s : arr) result += s;
        
        return result;
    }
};
