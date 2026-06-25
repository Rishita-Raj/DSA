class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        int answer = 0;

        for (int start = 0; start < n; start++) {

            int targetCount = 0;

            for (int end = start; end < n; end++) {

                if (nums[end] == target)
                    targetCount++;

                int length = end - start + 1;

                if (targetCount * 2 > length)
                    answer++;
            }
        }

        return answer;
    }
};