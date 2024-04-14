class Solution {
public:
    void PostOrder(TreeNode* root, int depth, vector<int>& result) {
        if (root == nullptr) return; // Base case: null node

        // If the current depth is equal to the size of result vector, this is the rightmost node at this depth
        if (depth == result.size()) {
            result.push_back(root->val);
        }

        // Recur for right child first, as we are interested in right side view
        PostOrder(root->right, depth + 1, result);
        PostOrder(root->left, depth + 1, result);
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        PostOrder(root, 0, result);
        return result;
    }
};
