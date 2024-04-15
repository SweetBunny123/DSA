class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1) {
            TreeNode* newRoot = new TreeNode(val);
            newRoot->left = root;
            return newRoot;
        }

        queue<TreeNode*> q;
        q.push(root);
        int currDepth = 1;

        while (!q.empty() && currDepth < depth - 1) {
            int levelSize = q.size();
            for (int i = 0; i < levelSize; ++i) {
                TreeNode* node = q.front();
                q.pop();
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            ++currDepth;
        }

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            TreeNode* tempLeft = new TreeNode(val);
            TreeNode* tempRight = new TreeNode(val);
            tempLeft->left = node->left;
            tempRight->right = node->right;
            node->left = tempLeft;
            node->right = tempRight;
        }

        return root;
    }
};