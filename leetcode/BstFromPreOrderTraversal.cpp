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
    TreeNode* recursivepreorder(int l, int r, vector<int>& arr) {
        if (l > r) return nullptr;

        TreeNode* node = new TreeNode(arr[l]);
        if(l==r)return node;
        int i = l+1;
        while (i <= r && arr[i] < node->val)
            i++;

        node->left = recursivepreorder( l + 1, i - 1, arr);
        node->right = recursivepreorder(i, r, arr);

        return node;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return recursivepreorder(0, preorder.size() - 1, preorder);
    }
};
