class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(), happiness.end(), greater<int>());

        long long totalHappiness = 0;

        for (int i = 0; i < k; i++) {
            int current = happiness[i] - i;
            if (current > 0) {
                totalHappiness += current;
            } else {
                break; // further values will be 0 or negative
            }
        }

        return totalHappiness;
    }
};
