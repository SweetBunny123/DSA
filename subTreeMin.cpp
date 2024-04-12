#include<bits/stdc++.h>
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

int preOrderTraversal(struct bintree* node, struct bintree *mednode)
{
  if(node)
  {
    int left  = preOrderTraversal(node->left, mednode->left);
    int right = preOrderTraversal(node->right, mednode->right);
    mednode->data = min(node->data,min(left,right));
    return mednode->data;
  }
  return INT_MAX;
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

        if (curr->right)
        {
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
    vector<struct bintree*>nodes1(n);
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
            head1 = nodes[i];
        } else {
            if (nodes1[parent[i]]->left == NULL) {
                nodes1[parent[i]]->left = nodes1[i];
            } else {
                nodes1[parent[i]]->right = nodes1[i];
            }
        }
    }
    preOrderTraversal(head, head1);
    levelOrderTraversal(head1);

    return 0;
}
