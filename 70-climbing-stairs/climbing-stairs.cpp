class Solution {
public:
    int fun(int n) {
        int first=1;
        int second=1;
        int ans=1;
        for(int i=2;i<=n;i++){
            ans=first+second;
            second=first;
            first=ans;
        }
        return ans;
    }
    int climbStairs(int n) { 
        return fun(n);
    }
};