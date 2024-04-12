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
    void Trim(TreeNode *root, int low, int high, vector<int>&arr)
    {
        if(root==NULL)return;
        if(root->val <= high && root->val>=low)
            arr.push_back(root->val);
        Trim(root->left, low, high, arr);
        Trim(root->right, low, high, arr);  
    }
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
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        vector<int>arr;
        Trim(root, low, high, arr);
        for(int i = 0; i< arr.size(); i++)cout<<arr[i]<<" ";
        TreeNode *node = recursivepreorder(0, arr.size()-1, arr);
        return node;
    }
};