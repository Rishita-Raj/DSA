class Solution {
public:
    bool uniformArray(vector<int>& nums1) {

        int minOdd = INT_MAX;
        bool hasOdd = false;
        bool hasEven = false;
        for(int x : nums1) {

            if(x % 2 == 0) {
                hasEven = true;
            }
            else {
                hasOdd = true;
                minOdd = min(minOdd, x);
            }
        }
        if(!hasOdd) {
            return true;
        }
        for(int x : nums1) {

            if(x % 2 == 0 && x <= minOdd) {
                return false;
            }
        }

        return true;
    }
};