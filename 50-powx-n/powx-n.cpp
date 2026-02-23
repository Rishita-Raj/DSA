class Solution {
    double pow_utils(double x, long n){
        if(n == 0) return 1.0;
        if(n == 1) return x;
        if(n < 0) return pow_utils(1/x, -n);
        double result = pow_utils(x*x, n/2);
        if(n%2) result *= x;
        return result;
    }
public:
    double myPow(double x, int n) {
        return pow_utils(x,  n);
    }
};