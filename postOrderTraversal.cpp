// C++ program for iterative postorder traversal using one
// stack
#include <bits/stdc++.h>
using namespace std;

// A tree node
struct Node {
    int data;
    struct Node *left, *right;
};

// A utility function to create a new tree node
struct Node* newNode(int data)
{
    struct Node* node = new Node;
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// An iterative function to do postorder traversal of a
// given binary tree
vector<int> postOrderIterative(struct Node* root)
{
    vector<int> postOrderList;
    // Check for empty tree
    if (root == NULL)
        return postOrderList;
    stack<Node*> S;
    S.push(root);
    Node* prev = NULL;
    while (!S.empty()) {
        auto current = S.top();
        /* go down the tree in search of a leaf an if so
           process it and pop stack otherwise move down */
        if (prev == NULL || prev->left == current
            || prev->right == current) {
            if (current->left)
                S.push(current->left);
            else if (current->right)
                S.push(current->right);
            else {
                S.pop();
                postOrderList.push_back(current->data);
            }
            /* go up the tree from left node, if the child
               is right push it onto stack otherwise process
               parent and pop stack */
        }

        else if (current->left == prev) {
            if (current->right)
                S.push(current->right);
            else {
                S.pop();
                postOrderList.push_back(current->data);
            }

            /* go up the tree from right node and after
            coming back from right node process parent and
            pop stack */
        }
        else if (current->right == prev) {
            S.pop();
            postOrderList.push_back(current->data);
        }
        prev = current;
    }
    return postOrderList;
}

// Driver program to test above functions
int main()
{
    // Let us construct the tree shown in above figure
    struct Node* root = NULL;
    root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    printf("Post order traversal of binary tree is :\n");
    printf("[");
    vector<int> postOrderList = postOrderIterative(root);
    for (auto it : postOrderList)
        cout << it << " ";
    printf("]");
    return 0;
}