class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        maxPathSumRecursive(root, maxSum);
        return maxSum;
    }

    int maxPathSumRecursive(TreeNode* root, int& maxSum) {
        if (root == nullptr) {
            return 0;
        }

        // Calculate the maximum path sum in the left and right subtrees
        int leftSum = max(0, maxPathSumRecursive(root->left, maxSum));
        int rightSum = max(0, maxPathSumRecursive(root->right, maxSum));

        // Update the global maximum path sum if the current path sum is greater
        maxSum = max(maxSum, leftSum + rightSum + root->val);

        // Return the maximum sum that can be extended from this node
        return max(leftSum, rightSum) + root->val;
    }
};
