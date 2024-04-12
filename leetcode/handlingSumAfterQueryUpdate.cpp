#include <vector>
using namespace std;

class Solution {
private:
    vector<long long> tree;
    vector<int> flipped;

    // Build segment tree
    void buildSegmentTree(vector<int>& arr, int node, int l, int r) {
        if (l == r) {
            tree[node] = arr[l];
            return;
        }
        int mid = (r + l) / 2;
        buildSegmentTree(arr, 2 * node + 1, l, mid);
        buildSegmentTree(arr, 2 * node + 2, mid + 1, r);
        tree[node] = tree[2 * node + 2] + tree[2 * node + 1];
    }

    // Update segment tree
    void update(int node, int ss, int se, int l, int r) {
        if (flipped[node] == 1) {
            tree[node] = se - ss + 1 - tree[node];
            flipped[node] = 0;
            if (ss != se) {
                flipped[2 * node + 1] = !flipped[2 * node + 1];
                flipped[2 * node + 2] = !flipped[2 * node + 2];
            }
        }
        if (l > se || r < ss) return; // Out of range
        if (ss >= l && r >= se) {
            tree[node] = se - ss + 1 - tree[node];
            if (ss != se) {
                flipped[2 * node + 1] = !flipped[2 * node + 1];
                flipped[2 * node + 2] = !flipped[2 * node + 2];
            }
            return;
        }
        int mid = (ss + se) / 2;
        update(2 * node + 1, ss, mid, l, r);
        update(2 * node + 2, mid + 1, se, l, r);
        tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
    }

public:
    vector<long long> handleQuery(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& queries) {
        int n = nums1.size();
        tree.resize(4 * n);
        flipped.resize(4 * n);

        // Build segment tree for nums1
        buildSegmentTree(nums1, 0, 0, n - 1);

        // Initialize sum
        long long sum = 0;
        for (int num : nums2)
            sum += num;

        vector<long long> ans;
        for (vector<int>& q : queries) {
            if (q[0] == 1) {
                update(0, 0, n - 1, q[1], q[2]);
            } else if (q[0] == 2) {
                sum += tree[0] * q[1];
            } else if (q[0] == 3) {
                ans.push_back(sum);
            }
        }
        return ans;
    }
};
