class Solution {
public:
    string getSmallestString(int n, int k) {
        string str =  "";
        for(int i=0;i<n;i++){
            str += 'a';
            k--;
        }
        int temp = n-1;
        while(k){
            if(k >= 25){
                str[temp] = str[temp] + 25;
                k = k - 25;
                temp--;
            }
            else{
                str[temp] = str[temp] + k;
                k = 0;
                temp--;
            }
            
        }
        return str;
    }
};