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
          curr->left->data = min(curr->left->data, curr->data);
          q.push(curr->left);
      }

        if (curr->right)
        { curr->right->data = min(curr->right->data, curr->data);
            q.push(curr->right);
        }
    }
}

int main() {
    int n;
    cin >> n;

    vector<int> parent(n);
    vector<int> value(n);
    vector<struct bintree*> nodes(n); // Vector to store node pointers

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
    levelOrderTraversal(head);

    return 0;
}
