#include <vector>
using namespace std;

class NumArray {
public:
    vector<int> arr;
    vector<int> tree;
    long long size;

    void form_tree(vector<int>& nums) {
        long long n = 1; 
        while (n < nums.size()) {
            n *= 2; 
        }
        size = n;
        tree.resize(2 * n, 0);
        for (int i = 0; i < nums.size(); i++) {
            tree[n - 1 + i] = nums[i];
        }
        for (long long i = n - 2; i >= 0; i--) {
            tree[i] = tree[2 * i + 1] + tree[2 * i + 2];
        }
    }

    NumArray(vector<int>& nums) {
        arr = nums;
        form_tree(nums);
    }

    void update(int index, int val) {
        long long j = size - 1 + index;
        tree[j] = val;
        while (j > 0) {
            j = (j - 1) / 2;
            tree[j] = tree[2 * j + 1] + tree[2 * j + 2];
        }
    }

    int query(long long node, long long start, long long end, long long left, long long right) {
        if (start > right || end < left) {
            return 0;
        }
        if (start >= left && end <= right) return tree[node];
        long long mid = (start + end) / 2;
        int left_sum = query(2 * node + 1, start, mid, left, right);
        int right_sum = query(2 * node + 2, mid + 1, end, left, right);
        return left_sum + right_sum;
    }

    int sumRange(int left, int right) {
        return query(0, 0, size - 1, left, right);
    }
};
