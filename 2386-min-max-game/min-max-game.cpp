class Solution {
public:
        int minMaxGame(vector<int>& nums) {
             int temp;
             if(nums.size() == 1) return nums[0];
             int size = nums.size();
             while(size > 1){
                size = size/2;
                vector<int> newNum(size);
                for(int i=0;i<size;i++){
                    if(i&1){
                        newNum[i] = max(nums[2*i], nums[2*i + 1]);
                    }
                    else{
                        newNum[i] = min(nums[2*i], nums[2*i + 1]);
                    }
                }
                nums = newNum;
                if(newNum.size() == 1){
                    temp = newNum[0];
                }
             }
             return temp;

        }
};