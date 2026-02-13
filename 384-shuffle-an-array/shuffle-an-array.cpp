class Solution {
private:
    vector<int> original;
    vector<int> nums;

public:
    Solution(vector<int>& nums) {
        this->original = nums;
        this->nums = nums;
        srand(time(0));  // initialize random seed
    }

    vector<int> reset() {
        nums = original;
        return nums;
    }

    vector<int> shuffle() {
        int n = nums.size();
        
        for (int i = 0; i < n; i++) {
            int j = i + rand() % (n - i);  // random index from [i, n-1]
            swap(nums[i], nums[j]);
        }
        
        return nums;
    }
};


/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */