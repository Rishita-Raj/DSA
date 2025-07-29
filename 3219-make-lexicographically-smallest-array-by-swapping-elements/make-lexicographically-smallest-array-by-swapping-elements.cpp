class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        vector<pair<int,int>> arr;
        for(int i=0;i<nums.size();i++) arr.push_back({nums[i], i});
        sort(arr.begin(), arr.end());
        int left = 0, right = 1;
        while(right < nums.size()){
            while(right < nums.size() && arr[right].first - arr[right - 1].first <= limit) right++;
            vector<int> idx;
            for(int i=left;i<right;i++){
                idx.push_back(arr[i].second);
            }
            sort(idx.begin(), idx.end());
            int curridx = left;
            for(auto x : idx){
                nums[x] = arr[curridx].first;
                curridx++;
            }
            left = right;
            right++;
        }
        return nums;
    }
};