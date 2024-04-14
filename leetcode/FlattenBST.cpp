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
    vector<int> v; 
public:
    void flatten(TreeNode* root) {
        if (root == nullptr) return;

        preorder(root);
        int size=v.size();
        TreeNode* head = root;
        //TreeNode* head = new TreeNode(v[0]); 
        //We must make the changes using root. If we make it with new, it will be independent of root.
        TreeNode* tmp = head;

       for (int i = 1; i < size; ++i) {
            tmp->right = new TreeNode(v[i]);
            tmp->left = nullptr; 
            tmp = tmp->right; 
        }
    }
    void preorder(TreeNode *subNode){
      if(subNode != nullptr){
        v.push_back(subNode->val); 
        preorder(subNode->left);
        preorder(subNode->right);
      }
    }
};