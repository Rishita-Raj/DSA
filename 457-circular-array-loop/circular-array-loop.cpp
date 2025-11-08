class Solution {
public:
    int nextIndex(vector<int>& nums, int i) {
        int n = nums.size();
        int next = (i + nums[i]) % n; // move forward or backward
        if (next < 0) next += n;      // handle negative wrap-around
        return next;
    }

    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();

        for (int i = 0; i < n; ++i) {
            if (nums[i] == 0) continue; // already visited

            // direction: true = forward, false = backward
            bool forward = nums[i] > 0;
            int slow = i, fast = i;

            while (true) {
                // Move slow pointer
                int nextSlow = nextIndex(nums, slow);
                // Check direction validity
                if (nums[nextSlow] == 0 || (nums[nextSlow] > 0) != forward) break;

                // Move fast pointer twice
                int nextFast = nextIndex(nums, fast);
                if (nums[nextFast] == 0 || (nums[nextFast] > 0) != forward) break;

                nextFast = nextIndex(nums, nextFast);
                if (nums[nextFast] == 0 || (nums[nextFast] > 0) != forward) break;

                slow = nextSlow;
                fast = nextFast;

                // If they meet, valid cycle (size > 1)
                if (slow == fast) {
                    if (slow == nextIndex(nums, slow)) break; // single-element loop, invalid
                    return true;
                }
            }

            // Mark path as visited (optimization)
            int j = i;
            while (nums[j] != 0 && (nums[j] > 0) == forward) {
                int next = nextIndex(nums, j);
                nums[j] = 0;
                j = next;
            }
        }

        return false;
    }
};
