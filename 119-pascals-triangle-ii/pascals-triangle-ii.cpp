class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> row;
        long long val = 1;
        row.push_back(1); // First element is always 1

        // Generate row using the combination formula
        for (int i = 1; i <= rowIndex; ++i) {
            val = val * (rowIndex - i + 1) / i;
            row.push_back(val);
        }
        return row;
    }
};
