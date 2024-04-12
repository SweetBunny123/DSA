#include <vector>
#include <set>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> fallingSquares(vector<vector<int>>& positions) {
        set<int> indexes;
        for (int i = 0; i < positions.size(); i++) {
            indexes.insert(positions[i][0]);
            indexes.insert(positions[i][1] + positions[i][0]);
        }

        // Convert set to vector for easier indexing
        vector<int> sortedIndexes(indexes.begin(), indexes.end());

        // Define a function to get index of a value in sortedIndexes
        auto getIndex = [&](int value) {
            return lower_bound(sortedIndexes.begin(), sortedIndexes.end(), value) - sortedIndexes.begin();
        };

        vector<int> segmentTree(4 * sortedIndexes.size(), 0);
        vector<int> result;

        for (auto& position : positions) {
            int left = getIndex(position[0]);
            int right = getIndex(position[0] + position[1]);

            // Query current segment
            int initial_max = query(segmentTree, 0, 0, sortedIndexes.size() - 1, left, right - 1);

            // Update segment tree with new square
            update(segmentTree, 0, 0, sortedIndexes.size() - 1, left, right - 1, initial_max + position[1]);

            // Get maximum height after current square is placed
            int maxHeight = query(segmentTree, 0, 0, sortedIndexes.size() - 1, 0, sortedIndexes.size() - 1);
            result.push_back(maxHeight);
        }

        return result;
    }

private:
    // Function to update the segment tree
    void update(vector<int>& tree, int node, int start, int end, int l, int r, int val) {
        if (start > r || end < l) return; // Out of range
        if (start== end) {
            // Current segment is fully within the update range
            tree[node] = max(tree[node], val);
            return;
        }
        int mid = (start + end) / 2;
        update(tree, 2 * node + 1, start, mid, l, r, val);
        update(tree, 2 * node + 2, mid + 1, end, l, r, val);
        tree[node] = max(tree[2 * node + 1], tree[2 * node + 2]);
    }

    // Function to query the segment tree
    int query(vector<int>& tree, int node, int start, int end, int l, int r) {
        if (start > r || end < l) return 0; // Out of range
        if (start >= l && end <= r) return tree[node]; // Current segment is fully within query range
        int mid = (start + end) / 2;
        int left = query(tree, 2 * node + 1, start, mid, l, r);
        int right = query(tree, 2 * node + 2, mid + 1, end, l, r);
        return max(left, right);
    }
};