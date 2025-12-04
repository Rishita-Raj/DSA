// class Solution {
// public:

//     void reverseArr(vector<int>nums, int start, int end){
//         while(start < end){
//             swap(nums[start], nums[end]);
//             start++;
//             end--;
//         }
//     }

//     void rotate(vector<int>& nums, int k) {
//         string direction;
//         int n = nums.size();

//         if(n == 0 || k == 0 ) return ;
//         k = k%n;         
//         if(direction == "right"){
//             reverseArr(nums, 0, n-1);
//             reverseArr(nums, 0 , k-1);
//             reverseArr(nums, k, n-1);
//         }
//         else if(direction == "left"){
//              reverseArr(nums, 0, k-1);
//             reverseArr(nums, k, n-1);
//             reverseArr(nums, 0 , n-1);
//         }
//     }
// };


class Solution {
public:

    void reverseArr(vector<int>& nums, int start, int end){
        while(start < end){
            swap(nums[start], nums[end]);
            start++;
            end--;
        }
    }

    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if(n == 0) return;

        k = k % n; 

        reverseArr(nums, 0, n-1);
        reverseArr(nums, 0, k-1);
        reverseArr(nums, k, n-1);
    }
};
