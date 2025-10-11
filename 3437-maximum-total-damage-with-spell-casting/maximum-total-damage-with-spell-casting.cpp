#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        // Step 1: Count frequency of each unique power value
        unordered_map<long long, long long> freq;
        for (int p : power) freq[p]++;

        // Step 2: Sort unique damage values
        vector<long long> vals;
        for (auto& [v, f] : freq) vals.push_back(v);
        sort(vals.begin(), vals.end());

        int n = vals.size();
        vector<long long> dp(n, 0);

        for (int i = 0; i < n; ++i) {
            long long gain = vals[i] * freq[vals[i]]; // total damage from this power

            // Find the last value that is not conflicting (difference > 2)
            int j = i - 1;
            while (j >= 0 && vals[i] - vals[j] <= 2) j--;

            long long include = gain + (j >= 0 ? dp[j] : 0);
            long long exclude = (i > 0 ? dp[i - 1] : 0);

            dp[i] = max(include, exclude);
        }

        return dp[n - 1];
    }
};
