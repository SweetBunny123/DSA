#include <bits/stdc++.h>
using namespace std;

struct bintree {
    int data;
    struct bintree* left;
    struct bintree* right;
    bintree(int val) {
        data = val;
        left = right = NULL;
    }
}; 

void levelOrderTraversal(struct bintree* node, vector<int>&arr) {
    if (node == NULL)
        return;
    
    queue<struct bintree*> q;
    q.push(node);

    while (!q.empty()) {
        struct bintree* curr = q.front();
        cout << curr->data << " ";
        q.pop();
        if (curr->left)
            q.push(curr->left);
        if (curr->right)
            q.push(curr->right);
    }
}

int main() {
    int n;
    cout << "Enter the number of nodes: ";
    cin >> n;

    vector<int> parent(n);
    vector<int> value(n);
    vector<struct bintree*> nodes(n); // Vector to store node pointers

    cout << "Enter the parent array: ";
    for (int i = 0; i < n; i++) {
        cin >> parent[i];
    }

    cout << "Enter the value array: ";
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

    cout << "Level Order Traversal: ";
    levelOrderTraversal(head);

    return 0;
}
