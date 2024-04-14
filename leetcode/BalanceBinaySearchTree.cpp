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
private:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> s;
        TreeNode* current = root;

        while (current != nullptr || !s.empty()) {
            while (current != nullptr) {
                s.push(current);
                current = current->left;
            }

            current = s.top();
            s.pop();
            result.push_back(current->val);
            current = current->right;
        }

        return result;
    }

    TreeNode* buildBST(vector<int>& sortedArray, int start, int end) {
        if (start > end) return nullptr;

        int mid = start + (end - start) / 2;
        TreeNode* root = new TreeNode(sortedArray[mid]);
        root->left = buildBST(sortedArray, start, mid - 1);
        root->right = buildBST(sortedArray, mid + 1, end);

        return root;
    }

public:
    TreeNode* balanceBST(TreeNode* root) {
        // Step 1: Perform in-order traversal to get sorted elements
        vector<int> sortedArray = inorderTraversal(root);

        // Step 2: Build balanced BST from sorted array
        return buildBST(sortedArray, 0, sortedArray.size() - 1);
    }
};
