class Solution {
public:
    int sumNumbers(TreeNode* root) {
        return inOrder(root, 0);
    }

    int inOrder(TreeNode* node, int sum) {
        if (node == nullptr) return 0; // Base case: null node

        // Calculate the sum formed by the path from the root to the current node
        sum = sum * 10 + node->val;

        // If the current node is a leaf node, return the sum
        if (node->left == nullptr && node->right == nullptr) {
            return sum;
        }

        // Recursively calculate the sum for left and right subtrees
        int leftSum = inOrder(node->left, sum);
        int rightSum = inOrder(node->right, sum);

        // Return the sum of sums from left and right subtrees
        return leftSum + rightSum;
    }
};
