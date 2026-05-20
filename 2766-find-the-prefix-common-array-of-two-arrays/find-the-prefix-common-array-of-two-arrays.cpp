class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {

        int n = A.size();

        vector<int> ans(n);
        vector<bool> seenA(n + 1, false);
        vector<bool> seenB(n + 1, false);

        int common = 0;

        for (int i = 0; i < n; i++) {

            seenA[A[i]] = true;
            seenB[B[i]] = true;
            if (seenB[A[i]])
                common++;
            if (A[i] != B[i] && seenA[B[i]])
                common++;

            ans[i] = common;
        }

        return ans;
    }
};