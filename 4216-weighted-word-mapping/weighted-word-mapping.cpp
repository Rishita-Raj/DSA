class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string answer;

        for (string &word : words) {

            long long totalWeight = 0;

            for (char ch : word) {
                totalWeight += weights[ch - 'a'];
            }

            int remainder = totalWeight % 26;

            char mappedChar = 'z' - remainder;

            answer.push_back(mappedChar);
        }

        return answer;
    }
};