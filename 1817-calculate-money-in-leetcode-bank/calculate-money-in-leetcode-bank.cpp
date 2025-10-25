class Solution {
public:
    int totalMoney(int n) {
        int weeks = n / 7;    // Number of complete weeks
        int days = n % 7;     // Remaining days

        // Money from complete weeks
        // Formula: 28 for week1, 35 for week2, 42 for week3, ...
        // It's an arithmetic series: total = weeks * (first + last) * 7 / 2 + extra pattern
        int total = 0;

        // Sum of full weeks
        // Week 0 starts with $1, week 1 starts with $2, ...
        // Each week total = 7 * start + 21 (since sum 0+1+...+6 = 21)
        total += (7 * weeks * (weeks - 1)) / 2 + weeks * 28;

        // Remaining days in the next (incomplete) week
        int start = weeks + 1;
        for (int i = 0; i < days; i++) {
            total += start + i;
        }

        return total;
    }
};
