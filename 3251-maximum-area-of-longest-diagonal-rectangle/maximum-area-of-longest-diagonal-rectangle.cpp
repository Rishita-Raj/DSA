class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int dia = 0;
        int area = 0;
        for(auto x : dimensions){
            int currDiag = x[0]*x[0] + x[1]*x[1];
            if(currDiag > dia){
                area = x[0]*x[1];
                dia = currDiag;
            }
            else if(currDiag == dia){
                area = max(area, x[0]*x[1]);
            }
        }
        return area;
    }
};