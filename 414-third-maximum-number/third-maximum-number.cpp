class Solution {
public:
    int thirdMax(vector<int>& nums) {
        unordered_map<int,int>m;
        int ans;
        int maximum;
        int count=0;
        for(int i=0;i<3;i++){
            int maxi=INT_MIN;
            bool Found=false;
            for(int j=0;j<nums.size();j++){
                if(nums[j]>=maxi and m.find(nums[j])==m.end()){
                    maxi=nums[j];
                    Found=true;
                }
            }
            if(Found){
                m[maxi]=1;
                count++;
                if(i==0) maximum=maxi;
                ans=maxi;
            }
        }
        if(count<3){
            return maximum;
        }
        else{
            return ans;
        }
    }
};