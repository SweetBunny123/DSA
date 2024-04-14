/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> generateTrees(int start, int end) {
        vector<TreeNode*> trees;
        if (start > end) {
            trees.push_back(nullptr); // Return a nullptr for empty subtree
            return trees;
        }

        for (int i = start; i <= end; i++) {
            vector<TreeNode*> leftSubtrees = generateTrees(start, i - 1); // Generate left subtrees
            vector<TreeNode*> rightSubtrees = generateTrees(i + 1, end); // Generate right subtrees

            for (TreeNode* left : leftSubtrees) {
                for (TreeNode* right : rightSubtrees) {
                    TreeNode* root = new TreeNode(i); // Create root with value i
                    root->left = left; // Assign left subtree
                    root->right = right; // Assign right subtree
                    trees.push_back(root); // Add current tree to the result
                }
            }
        }

        return trees;
    }

    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return {}; // Edge case: empty tree
        return generateTrees(1, n); // Call helper function to generate trees from 1 to n
    }
};
