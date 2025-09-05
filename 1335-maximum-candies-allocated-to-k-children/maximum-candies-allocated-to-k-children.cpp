class Solution {
public:
   bool helper(vector<int> candies, long long mid, long long k){
        int idx = 0;
        while(k>0 and idx < candies.size()){
            if(candies[idx] >= (int)mid){
                long long toSubtract = candies[idx] / mid;
                candies[idx] %= mid;
                k -= toSubtract;
            }
            else{
                idx++;
            } 
        }
        return idx!=candies.size();
    }
    
    int maximumCandies(vector<int>& candies, long long k) {
        long long sum = 0;
        for(int i=0;i<candies.size();i++){
            sum += candies[i];
        }
        if(sum < k) return 0;
        
        long long maxx = sum/k;
        long long low = 0;
        long long high = maxx;
        while((high - low) > 1){
            long long mid = low + (high - low)/2;
            if(helper(candies,mid,k)){
                low = mid;
            }else{
                high = mid - 1;
            }
        }
        
        if(helper(candies, high, k)){
            return high;
        }
        
        return low;
         
    }
};