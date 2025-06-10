class Solution {
public:
    int trap(vector<int>& height) {
        int totalWater = 0;
        int lmax = 0, rmax = 0;
        int i = 0, j = height.size()-1;
        while(i<j){
            lmax = max(lmax, height[i]);
            rmax=max(rmax,height[j]);
            if(height[i]<=height[j]){
                totalWater+=lmax-height[i];
                i++;
            }
            else{
                totalWater+=rmax-height[j];
                j--;
            }
        }
        return totalWater;
    }
};