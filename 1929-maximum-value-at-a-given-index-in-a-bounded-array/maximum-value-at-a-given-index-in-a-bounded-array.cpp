class Solution {
public:
   bool isPossible(int n, int mid, int idx, int maxSum){
        int numAtRight = n - idx - 1;
        int numAtLeft = idx;
        long long val = mid-1;
        long long rightSum = 0, leftSum = 0;
        //Operation for right side
        if(numAtRight > val) rightSum = (val*(val+1))/2 + (numAtRight - val);
        else rightSum = (val*(val+1))/2 - ((val - numAtRight)*(val - numAtRight + 1))/2;
        //Operation for left side
        if(numAtLeft > val) leftSum = (val*(val+1))/2 + (numAtLeft - val);
        else leftSum = (val*(val+1))/2 - ((val - numAtLeft)*(val - numAtLeft + 1))/2;
        return (leftSum + rightSum + mid) <= maxSum;
    }
    int maxValue(int n, int index, int maxSum) {
        long long ans = 0;
        int low = 1, high = maxSum;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(isPossible(n,mid,index, maxSum) == true){
                ans = mid;
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return ans;
    }
};