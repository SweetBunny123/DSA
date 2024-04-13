#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

struct Treap {
    int len;
    const int ADD = 1000010;
    const int MAXVAL = 1000000010;
    unordered_map<long long, int> mp;
    tree<long long, null_type, less<long long>, rb_tree_tag, tree_order_statistics_node_update> T;

    Treap() {
        len = 0;
        T.clear(), mp.clear();
    }

    inline void clear() {
        len = 0;
        T.clear(), mp.clear();
    }

    inline void insert(long long x) {
        len++, x += MAXVAL;
        int c = mp[x]++;
        T.insert((x * ADD) + c);
    }

    inline void erase(long long x) {
        x += MAXVAL;
        int c = mp[x];
        if (c) {
            c--, mp[x]--, len--;
            T.erase((x * ADD) + c);
        }
    }

    /// 1-based index, returns the K'th element in the treap, -1 if none exists
    inline long long kth(int k) {
        if (k < 1 || k > len)
            return -1;
        auto it = T.find_by_order(--k);
        return ((*it) / ADD) - MAXVAL;
    }

    /// Count of value < x in treap
    inline int count(long long x) {
        x += MAXVAL;
        int c = mp[--x];
        return (T.order_of_key((x * ADD) + c));
    }

    /// Number of elements in treap
    inline int size() {
        return len;
    }
};

struct bintree {
    long long data;
    long long median; // Added to store median at each node
    struct bintree* left;
    struct bintree* right;
    bintree(long long val) {
        data = val;
        median = -1; // Initializing median as -1
        left = right = NULL;
    }
}; 

// Returns median of values in Treap
long long calculateMedian(Treap& treap) {
    if (treap.size() % 2 == 1) {
        return treap.kth(treap.size() / 2 + 1);
    } else {
        long long first = treap.kth(treap.size() / 2);
        long long second = treap.kth(treap.size() / 2 + 1);
        return (first + second) / 2;
    }
}

// Returns Treap of values in subtree rooted at 'node' and sets median for each node

// Returns vector of values in subtree rooted at 'node' and sets median for each node
vector<long long> postOrderTraversal(struct bintree* node, vector<long long>& values) {
    if (node == NULL)
        return;

    vector<long long> leftValues = postOrderTraversal(node->left, values);
    vector<long long> rightValues = postOrderTraversal(node->right, values);

    values.push_back(node->data);
    for (long long val : leftValues) {
        values.push_back(val);
    }
    for (long long val : rightValues) {
        values.push_back(val);
    }

    node->median = calculateMedian(values); // Set median for current node

    return values;
}

// Level order traversal for printing tree
void levelOrderTraversal(struct bintree* node) {
    if (node == NULL)
        return;

    queue<struct bintree*> q;
    q.push(node);

    while (!q.empty()) {
        struct bintree* curr = q.front();
        cout << "Node: " << curr->data << ", Median: " << curr->median << endl;
        q.pop();
        if (curr->left) {
            q.push(curr->left);
        }
        if (curr->right) {
            q.push(curr->right);
        }
    }
}

int main() {
    int n;
    cin >> n;

    vector<int> parent(n);
    vector<long long> value(n);
    vector<struct bintree*> nodes(n);

    for (int i = 0; i < n; i++) {
        cin >> parent[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> value[i];
    }

    struct bintree* head = NULL;

    for (int i = 0; i < n; i++) {
        nodes[i] = new bintree(value[i]);

        if (parent[i] == -1) {
            head = nodes[i];
        } else {
            if (nodes[parent[i]]->left == NULL) {
                nodes[parent[i]]->left = nodes[i];
            } else {
                nodes[parent[i]]->right = nodes[i];
            }
        }
    }

    Treap treap = postOrderTraversal(head);
    levelOrderTraversal(head);

    return 0;
}
