class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return nullptr; // Base case: root is null

        if (key < root->val) {
            root->left = deleteNode(root->left, key); // Search in the left subtree
        } else if (key > root->val) {
            root->right = deleteNode(root->right, key); // Search in the right subtree
        } else {
            // Case 1: Node to be deleted has no children or only one child
            if (!root->left) {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            } else if (!root->right) {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }

            // Case 2: Node to be deleted has two children
            // Find the inorder successor (smallest node in the right subtree)
            TreeNode* temp = findMin(root->right);
            root->val = temp->val; // Replace the value of the node to be deleted with the value of the successor
            root->right = deleteNode(root->right, temp->val); // Delete the inorder successor
        }

        return root;
    }

    TreeNode* findMin(TreeNode* node) {
        while (node->left) {
            node = node->left;
        }
        return node;
    }
};
