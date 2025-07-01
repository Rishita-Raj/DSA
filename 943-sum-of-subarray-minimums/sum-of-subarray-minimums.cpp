class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
         int n = arr.size();
        long res = 0;
        int MOD = 1e9 + 7;

        vector<int> prevSmaller(n), nextSmaller(n);
        stack<int> st;

        // Previous Smaller: Distance to previous less element
        for (int i = 0; i < n; ++i) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            prevSmaller[i] = st.empty() ? i + 1 : i - st.top();
            st.push(i);
        }

        // Clear stack before next use
        while (!st.empty()) st.pop();

        // Next Smaller: Distance to next less or equal element
        for (int i = n - 1; i >= 0; --i) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            nextSmaller[i] = st.empty() ? n - i : st.top() - i;
            st.push(i);
        }

        // Calculate total contribution
        for (int i = 0; i < n; ++i) {
            long prod = (long)arr[i] * prevSmaller[i] * nextSmaller[i];
            res = (res + prod) % MOD;
        }

        return (int)res;
    }
};