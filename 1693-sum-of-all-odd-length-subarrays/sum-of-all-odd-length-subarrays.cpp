class Solution {
public:
    int findsum(int i,int j,vector<int> &arr)
    {
        return arr[j]-(i>0?arr[i-1]:0);
    }
    int sumOddLengthSubarrays(vector<int>& arr) {
        for(int i=1;i<arr.size();i++)
        {
            arr[i] += arr[i-1];
        }
        int result = 0;
        for(int i=0;i<arr.size();i++)
        {
            for(int j=i;j<arr.size();j=j+2)
                result += findsum(i,j,arr);
        }
        return result;
    }
};