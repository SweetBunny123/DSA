class Solution {
public:
    long long pathSum(TreeNode* root, long long targetSum) {
        if (!root) return 0; // Base case: empty tree

        long long count = 0;
        count += pathSumFrom(root, targetSum); // Count paths starting from the root
        count += pathSum(root->left, targetSum); // Recursively search in the left subtree
        count += pathSum(root->right, targetSum); // Recursively search in the right subtree

        return count;
    }

    long long pathSumFrom(TreeNode* node, long long targetSum) {
        if (!node) return 0; // Base case: empty node

        long long count = 0;
        if (node->val == targetSum) {
            count++; // Found a path starting from this node with the targetSum
        }

        // Recursively search for paths starting from the children nodes
        count += pathSumFrom(node->left, targetSum - node->val);
        count += pathSumFrom(node->right, targetSum - node->val);

        return count;
    }
};
