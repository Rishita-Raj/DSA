class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int lmax = 0, rmax = 0, maxi = 0;
        for(int i = 0; i<k;i++){
            lmax += cardPoints[i];
        } 
          maxi = lmax;
          int rightIndex = cardPoints.size()-1;
          for(int i = k-1; i>=0;i--){
            lmax -= cardPoints[i];
            rmax += cardPoints[rightIndex];
            rightIndex--;
            maxi = max(maxi, lmax+rmax); 
          }  
          return maxi;
    }
};