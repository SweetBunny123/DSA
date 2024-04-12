#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <unordered_map>
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
    struct bintree* left;
    struct bintree* right;
    bintree(long long val) {
        data = val;
        left = right = NULL;
    }
}; 

void preOrderTraversal(struct bintree* node, struct bintree* mednode, Treap& treap) {
    if (node) {
        treap.insert(node->data);
        int medianPos = (treap.size()-1)/ 2;  
        // cout<<treap.size()<<" "<<medianPos<<endl;
        
        long long median;
        median = treap.kth(medianPos+1);
        mednode->data = median;
        preOrderTraversal(node->left, mednode->left, treap);
        // cout<<"left side for "<<node->data<<" done"<<endl;
        preOrderTraversal(node->right, mednode->right, treap);
        // cout<<"yea "<<node->data<<" "<<endl;
        treap.erase(node->data);
        // cout<<"deleted "<<node->data<<endl;
        
    }
}
void preOrderTraversal2(struct bintree* node)
{
  if(node)
  {
    cout<<node->data<<" inserted ";
    preOrderTraversal2(node->left);
    preOrderTraversal2(node->right);
    cout<<node->data<<" deleted ";
  }
}

void levelOrderTraversal(struct bintree* node) {
    if (node == NULL)
        return;

    queue<struct bintree*> q;
    q.push(node);

    while (!q.empty()) {
        struct bintree* curr = q.front();
        cout << curr->data << " ";
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
    vector<struct bintree*> nodes1(n);
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

    struct bintree* head1 = NULL;
    for (int i = 0; i < n; i++) {
        nodes1[i] = new bintree(value[i]);

        if (parent[i] == -1) {
            head1 = nodes1[i];
        } else {
            if (nodes1[parent[i]]->left == NULL) {
                nodes1[parent[i]]->left = nodes1[i];
            } else {
                nodes1[parent[i]]->right = nodes1[i];
            }
        }
    }

    Treap treap;
    preOrderTraversal(head, head1, treap);
    levelOrderTraversal(head1);

    return 0;
}
