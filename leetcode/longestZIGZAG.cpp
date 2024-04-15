class Solution {
public:
    int longestZigZag(TreeNode* root) {
        int maxZigZag = 0;
        longestZigZag(root, true, 0, maxZigZag); // Traverse starting from left child
        longestZigZag(root, false, 0, maxZigZag); // Traverse starting from right child
        return maxZigZag;
    }

    void longestZigZag(TreeNode* root, bool isLeft, int currLen, int& maxZigZag) {
        if (!root) return;

        // Update the maximum zigzag path length
        maxZigZag = max(maxZigZag, currLen);

        if (isLeft) {
            // Traverse to the right child to continue the zigzag path
            longestZigZag(root->right, false, currLen + 1, maxZigZag);
            // Start a new zigzag path from the left child
            longestZigZag(root->left, true, 1, maxZigZag);
        } else {
            // Traverse to the left child to continue the zigzag path
            longestZigZag(root->left, true, currLen + 1, maxZigZag);
            // Start a new zigzag path from the right child
            longestZigZag(root->right, false, 1, maxZigZag);
        }
    }
};
