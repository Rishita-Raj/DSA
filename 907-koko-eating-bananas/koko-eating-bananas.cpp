#include <vector>
#include <cmath>      // For ceil()
#include <climits>    // For INT_MIN
using namespace std;

class Solution {
public:
    int findMax(vector<int> & piles){
        int maxi = INT_MIN;
        for(int i = 0; i < piles.size(); i++ ){
            maxi = max(maxi, piles[i]); 
        }
        return maxi;
    }

    long long calculateTotalHours(vector<int>& piles, int hourly){
        long long totalH = 0;
        for(int i = 0; i < piles.size(); i++){
            totalH += (piles[i] + hourly - 1) / hourly;  // Using integer math instead of ceil
        }
        return totalH;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = findMax(piles);
        while(low <= high){
            int mid = low + (high - low) / 2;
            long long totalH = calculateTotalHours(piles, mid);
            if(totalH <= h){
                high = mid - 1;
            } 
            else{
                low = mid + 1;
            }
        }
        return low;
    }
};
