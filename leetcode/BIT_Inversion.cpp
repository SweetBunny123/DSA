class Solution {
public:
    int binary_search(vector<long long>& nums, long long target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return -1; // Target not found
    }

    int lower_bound_index(vector<long long>& sorted, long long value) {
        int left = 0, right = sorted.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (sorted[mid] < value) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }

    int upper_bound_index(const vector<long long>& sorted, long long value) {
        int left = 0, right = sorted.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (sorted[mid] <= value) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }

    void update_binary_index_tree(int i, vector<int>& bit, int x) {
        while (i <= bit.size()) {
            bit[i-1] += x;
            i += i & (-i);
        }
    }   

    int prefix_sum_usingbit(int i, const vector<int>& bit) {
        int sum = 0;
        while (i > 0) {
            sum += bit[i-1];
            i -= (i & (-i));
        }
        return sum;
    }

    int reversePairs(vector<int>& nums) {
        vector<long long> nums_long(nums.begin(), nums.end()); // Create a duplicate vector of nums using long long
        vector<long long> sorted;
        for(int i = 0; i < nums_long.size(); i++) {
            sorted.push_back(2 * nums_long[i]);
        }
        vector<int> bit(nums.size() + 1, 0); // Increase size by 1 for 1-based indexing
        sort(sorted.begin(), sorted.end());
        int count = 0;
        for(int i = nums.size() - 1; i >= 0; i--) { // Decrement i
            int j = lower_bound_index(sorted,nums_long[i]); // Use nums_long[i] instead of nums[i]
            count += prefix_sum_usingbit(j, bit);
            int k = binary_search(sorted, 2 * nums_long[i]); // Cast to long long
            update_binary_index_tree(k + 1, bit, 1); // k + 1 for 1-based indexing
        }
        return count;
    }
};