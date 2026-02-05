class Solution {
public:
    static const int MOD = 1337;

    int modPow(int a, int k) {
        int result = 1;
        a %= MOD;
        while (k > 0) {
            if (k & 1)
                result = (result * a) % MOD;
            a = (a * a) % MOD;
            k >>= 1;
        }
        return result;
    }

    int superPow(int a, vector<int>& b) {
        int result = 1;
        a %= MOD;

        for (int digit : b) {
            result = modPow(result, 10);
            result = (result * modPow(a, digit)) % MOD;
        }

        return result;
    }
};
