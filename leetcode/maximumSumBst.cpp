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
    int max_so_far = 0;
    vector<int>checkTree(TreeNode* root)
    {
        if(root==NULL)return {0,1, INT_MAX, INT_MIN};
        vector<int>left = checkTree(root->left);
        vector<int>right = checkTree(root->right);
        vector<int>result;
        cout<<"root value is "<<root->val<<endl;
        if(left[1]*right[1]==0)
        {
            result = {0, 0};
        }
        else
        {
            result = {left[0]+right[0]+root->val, 1};
        }
        int a = 0;

        if((root->left != NULL)  && (root->right !=NULL))
        {
            if((root->left->val < root->val) && ((root->right->val>root->val)))a = 1;
        } 
        else if((root->left== NULL)&& (root->right != NULL) && (root->val < root->right->val))a=1;
        else if((root->right == NULL) && (root->left!=NULL) && (root->val > root->left->val))a = 1;
        else if(root->left == NULL && root->right == NULL)a=1;


        if(root->val > right[2] || root->val < left[3])a = 0;
        max_so_far = max(max_so_far, result[0]*a);
        result = {result[0]*a, a*result[1], min(root->val,min(left[2], right[2])), max(root->val,(max(left[3], right[3])))};
        return result;
    }
    int maxSumBST(TreeNode* root) {
        vector<int>arr = checkTree(root);
        return max_so_far;
    }
};