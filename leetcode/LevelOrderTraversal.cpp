class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (!root) return result; // Handle empty tree case

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int levelSize = q.size(); // Number of nodes at current level
            vector<int> levelNodes;

            // Process all nodes at current level
            for (int i = 0; i < levelSize; ++i) {
                TreeNode* node = q.front();
                q.pop();

                // Add node value to current level vector
                levelNodes.push_back(node->val);

                // Enqueue left and right children of the current node
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            // Add current level vector to result
            result.push_back(levelNodes);
        }

        return result;
    }
};

