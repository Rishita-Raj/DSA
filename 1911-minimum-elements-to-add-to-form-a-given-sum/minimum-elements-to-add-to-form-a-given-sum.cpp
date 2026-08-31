class Solution {
public:
    int minElements(vector<int>& nums, int limit, int goal) {
        long long sum = accumulate(nums.begin(), nums.end(), 0LL);
        long long request = llabs((long long)goal - sum);

        return (request + limit - 1) / limit;
    }
};