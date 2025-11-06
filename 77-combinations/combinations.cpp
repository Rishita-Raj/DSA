class Solution {
public:
    vector<vector<int>> result; // To store all valid combinations

    void backtrack(int start, int n, int k, vector<int>& current) {
        // Base case: if we have k numbers, store the combination
        if (current.size() == k) {
            result.push_back(current);
            return;
        }

        // Try picking each number from 'start' to 'n'
        for (int i = start; i <= n; ++i) {
            current.push_back(i);          // Choose this number
            backtrack(i + 1, n, k, current); // Move to next number
            current.pop_back();            // Undo choice (backtrack)
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<int> current;
        backtrack(1, n, k, current);
        return result;
    }
};
