class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (!root) {
            // If the tree is empty, create a new node with the given value
            return new TreeNode(val);
        }

        if (val < root->val) {
            // If the value is less than the root's value, insert into the left subtree
            root->left = insertIntoBST(root->left, val);
        } else {
            // If the value is greater than or equal to the root's value, insert into the right subtree
            root->right = insertIntoBST(root->right, val);
        }

        return root;
    }
};
