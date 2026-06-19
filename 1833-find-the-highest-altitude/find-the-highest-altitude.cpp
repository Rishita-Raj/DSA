class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int currentAltitude = 0;
        int highestAltitude = 0;

        for (int change : gain) {
            currentAltitude += change;
            highestAltitude = max(highestAltitude, currentAltitude);
        }

        return highestAltitude;
    }
};