/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return buildTreeHelper(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);
    }

    TreeNode* buildTreeHelper(vector<int>& inorder, vector<int>& postorder, int inStart, int inEnd, int postStart, int postEnd) {
        if (inStart > inEnd || postStart > postEnd) {
            return nullptr; // Base case: empty subtree
        }

        int rootValue = postorder[postEnd]; // Root value is at the end of postorder sequence
        TreeNode* root = new TreeNode(rootValue); // Create root node

        // Find index of root value in inorder sequence
        int rootIndex = inStart;
        while (inorder[rootIndex] != rootValue) {
            rootIndex++;
        }

        // Recursively build left and right subtrees
        int leftSubtreeSize = rootIndex - inStart;
        root->left = buildTreeHelper(inorder, postorder, inStart, rootIndex - 1, postStart, postStart + leftSubtreeSize - 1);
        root->right = buildTreeHelper(inorder, postorder, rootIndex + 1, inEnd, postStart + leftSubtreeSize, postEnd - 1);

        return root;
    }
};
