/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

// The API guess is already defined for you.
// int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int low = 1, high = n;
        
        while (low <= high) {
            int mid = low + (high - low) / 2; // avoid overflow
            
            int res = guess(mid); // use the given API
            
            if (res == 0)
                return mid; // found the number
            else if (res < 0)
                high = mid - 1; // guess is too high
            else
                low = mid + 1; // guess is too low
        }
        
        return -1; // just in case (shouldn’t happen)
    }
};
