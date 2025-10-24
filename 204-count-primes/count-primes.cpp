class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0;  // No primes less than 2

        vector<bool> isPrime(n, true);
        isPrime[0] = isPrime[1] = false;

        // Only need to check up to sqrt(n)
        for (int i = 2; i * i < n; i++) {
            if (isPrime[i]) {
                // Mark all multiples of i as non-prime
                for (int j = i * i; j < n; j += i) {
                    isPrime[j] = false;
                }
            }
        }

        // Count all primes
        return count(isPrime.begin(), isPrime.end(), true);
    }
};
