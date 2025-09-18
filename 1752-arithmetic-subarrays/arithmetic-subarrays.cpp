class Solution {
public:
    bool checkAirthmetic(vector<int>& vec){
        sort(vec.begin(),vec.end());
        if(vec.size() <= 2) return true;
        int d = vec[1] - vec[0];
        for(int i=1;i<vec.size();i++){
            if((vec[i] - vec[i-1]) != d) return false;
        }
        return true;
    }
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r)     {
        vector<bool> res;
        for(int i=0;i<l.size();i++){
            int a = l[i];
            int b = r[i];
            vector<int> temp;
            for(int i=a;i<=b;i++){
                temp.push_back(nums[i]);
            }
            res.push_back(checkAirthmetic(temp));
        }
        return res;
    }
};