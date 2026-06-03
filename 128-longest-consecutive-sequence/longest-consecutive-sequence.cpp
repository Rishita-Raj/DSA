class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
       unordered_set<int> st(nums.begin(), nums.end());
       int longest = 0;
       for(int num : st){
        if(st.find(num-1) != st.end())
        continue;

        int length = 1;
        int current = num;
        while(st.find(current+1) != st.end()){
            length++;
            current++;
        }
        longest = max(longest, length);
       } 
       return longest;
    }
};





















