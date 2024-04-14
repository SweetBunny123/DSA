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
    int sumOfLeftLeaves(TreeNode* root) {
        if (root == NULL) return 0;

        int sum = 0;
        // Condition to check if the current root is left leaf
        if (root->left != NULL && root->left->left == NULL and root->left->right == NULL ){
            sum += root->left->val;
        }
        /**
        * if the root is right leaf it will call for its left and right which are both NULL
        * and hence both calls for right leaf will return 0
        */ 
        return sum + sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right); 
    }
};