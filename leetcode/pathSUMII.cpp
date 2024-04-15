class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> result;
        vector<int> path; // Current path

        dfs(root, targetSum, path, result);

        return result;
    }

    void dfs(TreeNode* root, int targetSum, vector<int>& path, vector<vector<int>>& result) {
        if (!root) return; // Base case: null node

        // Add current node value to the path
        path.push_back(root->val);

        // If the current node is a leaf node and its value equals the target sum, add the path to the result
        if (!root->left && !root->right && root->val == targetSum) {
            result.push_back(path);
        }

        // Recursively search for paths in the left and right subtrees
        dfs(root->left, targetSum - root->val, path, result);
        dfs(root->right, targetSum - root->val, path, result);

        // Remove the current node value from the path (backtrack)
        path.pop_back();
    }
};
