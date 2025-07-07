class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        // Step 1: Sort events by start day (greedy strategy to attend earliest-starting events first)
        sort(events.begin(), events.end());

        // Min-heap to store end days of ongoing events
        priority_queue<int, vector<int>, greater<int>> minHeap;

        int i = 0;  // Pointer to iterate over events
        int n = events.size();
        int day = 1;  // Starting from day 1
        int res = 0;  // Count of attended events

        // Process days until all events are either handled or the heap is empty
        while (i < n || !minHeap.empty()) {
            // Step 2: Add all events that start today to the heap
            while (i < n && events[i][0] == day) {
                minHeap.push(events[i][1]); // Push end day into heap
                ++i;
            }

            // Step 3: Remove events that already expired (end day < today)
            while (!minHeap.empty() && minHeap.top() < day) {
                minHeap.pop();
            }

            // Step 4: Attend the event with the earliest end day
            if (!minHeap.empty()) {
                minHeap.pop();  // Attend and remove it
                ++res;          // Increase attended event count
            }

            ++day; // Move to next day
        }

        return res;
    }
};
