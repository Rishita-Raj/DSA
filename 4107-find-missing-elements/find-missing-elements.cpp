class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        if(nums.size() <= 1) return {};
        sort(nums.begin(), nums.end());

        int start = nums.front();
    int end = nums.back();

        unordered_set<int>present(nums.begin(), nums.end());

        vector<int>missing;
        for(int i = start; i<=end; ++i){
            if(!present.count(i))
                missing.push_back(i);
        }
        return missing;
        }
};