class Solution {
public:
    int maxOperations(string s) {
        vector<int> numberOfOnes(s.size(),0);
        int cnt = 0;
        for(int i=0;i<s.size();i++){
            if(s[i] == '1') cnt++;
            numberOfOnes[i] = cnt;
        }
        int ans = 0;
        for(int i=s.size()-1;i>=1;i--){
            if(s[i-1] == '1' and s[i] == '0'){
                ans += numberOfOnes[i-1];
            }
        }
        return ans;
    }
};