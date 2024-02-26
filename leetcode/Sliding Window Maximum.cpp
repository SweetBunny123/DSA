class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        deque<int> window;

        for (int i = 0; i < nums.size(); ++i) {
            // Remove elements from the front of the window if they're out of the current window range
            if (!window.empty() && window.front() == i - k) {
                window.pop_front();
            }

            // Remove elements from the back of the window if they're smaller than the current element
            while (!window.empty() && nums[i] >= nums[window.back()]) {
                window.pop_back();
            }

            // Add the current index to the window
            window.push_back(i);

            // If the window is of size k or more, the front of the window gives the maximum for that window
            if (i >= k - 1) {
                result.push_back(nums[window.front()]);
            }
        }

        return result;
    }
};
