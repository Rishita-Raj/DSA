class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        int low = 0, high = n - k;

        // Binary search for the best starting index
        while (low < high) {
            int mid = low + (high - low) / 2;

            // Compare the distances of the edges of window [mid...mid+k-1]
            if (x - arr[mid] > arr[mid + k] - x) {
                // Move window to the right
                low = mid + 1;
            } else {
                // Keep window or move it to the left
                high = mid;
            }
        }

        // Return the k closest elements starting from low
        return vector<int>(arr.begin() + low, arr.begin() + low + k);
    }
};
