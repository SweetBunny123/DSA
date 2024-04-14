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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> result;
        vector<int> sorted1, sorted2;

        // In-order traversal for root1
        inorderTraversal(root1, sorted1);

        // In-order traversal for root2
        inorderTraversal(root2, sorted2);

        // Merge sorted arrays
        int i = 0, j = 0;
        while (i < sorted1.size() && j < sorted2.size()) {
            if (sorted1[i] < sorted2[j]) {
                result.push_back(sorted1[i]);
                i++;
            } else {
                result.push_back(sorted2[j]);
                j++;
            }
        }

        // Append remaining elements of sorted1
        while (i < sorted1.size()) {
            result.push_back(sorted1[i]);
            i++;
        }

        // Append remaining elements of sorted2
        while (j < sorted2.size()) {
            result.push_back(sorted2[j]);
            j++;
        }

        return result;
    }

    // In-order traversal function
    void inorderTraversal(TreeNode* root, vector<int>& sorted) {
        if (root == nullptr) return;
        inorderTraversal(root->left, sorted);
        sorted.push_back(root->val);
        inorderTraversal(root->right, sorted);
    }
};
