class Solution {
public:
    int trap(vector<int>& height) {
        map<int, int> maxLeft;
        map<int, int> maxRight;

        int n = height.size();
        int max_height = 0; // Renamed variable

        // Precompute max heights on the left
        for (int i = 0; i < n; ++i) {
            if (max_height > height[i]) {
                maxLeft[i] = max_height;
            } else {
                max_height = height[i];
            }
        }

        max_height = 0; // Reset max_height
        // Precompute max heights on the right
        for (int i = n - 1; i >= 0; --i) {
            if (max_height > height[i]) {
                maxRight[i] = max_height;
            } else {
                max_height = height[i];
            }
        }

        int result = 0;
        for (int i = 0; i < n; ++i) {
            result += std::max(0, std::min(maxLeft[i], maxRight[i]) - height[i]); // Using std::max
        }

        return result;
    }
};
