class Solution {
public:
    vector<int> findClosestElements(vector<int>& nums, int k, int x) {
        int n = nums.size();
        int l = 0, r = n - k;
        vector<int> res;

        while (l < r) {
            int m = l + (r - l) / 2;
            if (x - nums[m] <= nums[m + k] - x) r = m;
            else l = m + 1;
        }

        for (int i = l; i < l + k; i++) {
            res.push_back(nums[i]);
        }

        return res;
    }
};