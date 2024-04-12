class SegmentTree {
public:
    SegmentTree(int N) {
        this->N = N;
        int n = 2 * (1 << ((int)ceil(log(N) / log(2)) + 1));
        this->tree = vector<int>(n);
    }

    void update(int L, int R, int val) {
        updateUtil(1, 0, N - 1, L, R, val);
    }

    void updateUtil(int i, int s, int e, int L, int R, int val) {
        if (s > e || s > R || e < L) return;
        if (s >= L && e <= R) {
            tree[i] = max(tree[i], val);
            return;
        }
        int mid = s + (e - s) / 2;
        updateUtil(i * 2, s, mid, L, R, val);
        updateUtil(i * 2 + 1, mid + 1, e, L, R, val);
    }

    int query(int index) {
        return queryUtil(1, 0, N - 1, index);
    }

    int queryUtil(int i, int s, int e, int index) {
        if (s == e) return tree[i];
        int mid = s + (e - s) / 2;
        int ret = index <= mid ? queryUtil(i * 2, s, mid, index) : queryUtil(i * 2 + 1, mid + 1, e, index);
        return max(ret, tree[i]);
    }

private:
    vector<int> tree;
    int N;
};

class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        set<int> sets;
        for (const auto& b : buildings) {
            sets.insert(b[0]);
            sets.insert(b[1]);
        }

        unordered_map<int, int> umap, rUmap;
        int n = 0;
        for (const auto& s : sets) {
            umap[s] = n;
            rUmap[n++] = s;
        }

        SegmentTree* segTree = new SegmentTree(n);
        for (const auto& b : buildings) {
            segTree->update(umap[b[0]], umap[b[1]] - 1, b[2]);
        }

        vector<vector<int>> ret;
        int prevHeight = 0, curHeight = 0;
        for (int i = 0; i < n; ++i) {
            curHeight = segTree->query(i);
            if (curHeight == prevHeight) continue;
            ret.push_back({rUmap[i], curHeight});
            prevHeight = curHeight;
        }
        return ret;
    }
};