// #include <bits/stdc++.h>
// using namespace std;

// // Definition for a binary tree node.
// struct TreeNode {
//    int val;
//    TreeNode *left;
//    TreeNode *right;
//    TreeNode() : val(0), left(nullptr), right(nullptr) {}
//    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };

// TreeNode* build_tree(vector<int>& sortedarr, int l, int r) {
//     if (l > r) return nullptr;
//     int mid = l + (r - l) / 2;
//     TreeNode* root = new TreeNode(sortedarr[mid]);
//     root->left = build_tree(sortedarr, l, mid - 1);
//     root->right = build_tree(sortedarr, mid + 1, r);
//     return root;
// }

// TreeNode* build_binary_search_tree(vector<int>& arr) {
//     // First, sort the array
//     sort(arr.begin(), arr.end());
//     // Then, build the binary search tree
//     return build_tree(arr, 0, arr.size() - 1);
// }

// int height(TreeNode* root) {
//     if (root == nullptr) return 0;
//     return 1 + max(height(root->left), height(root->right));
// }

// void inorder(TreeNode* root, vector<int>& result) {
//     if (root == nullptr) return;
//     inorder(root->left, result);
//     result.push_back(root->val);
//     inorder(root->right, result);
// }

// int main() {
//     vector<int> arr = {3, 1, 5, 2, 4};
//     TreeNode* root = build_binary_search_tree(arr);

//     // Test height function
//     cout << "Height of the tree: " << height(root) << endl;

//     // Perform inorder traversal to print the sorted array
//     vector<int> sorted_array;
//     inorder(root, sorted_array);
//     cout << "Sorted array: ";
//     for (int num : sorted_array) {
//         cout << num << " ";
//     }
//     cout << endl;

//     return 0;
// }
#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
   int val;
   TreeNode *left;
   TreeNode *right;
   TreeNode() : val(0), left(nullptr), right(nullptr) {}
   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
   TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


Treenode* build_tree(vector<int>& sortedarr, int l, int r)
{
    if(l>r) return nullptr;
    int mid = (l+r)/2;
    Treenode* root = new Treenode(sortedarr[mid]);
    root->left = build_tree(sortedarr, l, mid-1);
    root->right = build_tree(sortedarr, mid+1, r);
    return root;
}
Treenode *build_binary_search_tree(vector<int>& arr)
{
  sort(arr.begin(), arr.end());
  return build_tree(arr, 0, arr.size()-1);
}
int height(Treenode* root)
{
  if(root==nullptr) return 0;
  return 1+max(height(root->left), height(root->right));
}
void inorder(Treenode* root, vector<int>&results)
{
  if(root==nullptr)return;
  inorder(root->left, results);
  results.push_back(root->val);
  inorder(root->right, results);
}
int main()
{
  vector<int> arr = {3, 1, 5, 2, 4};
  Treenode* root = build_binary_search_tree(arr);
  cout<<"height of the tree: "<<height(root)<<endl;
  vector<int>sorted_array;
  inorder(root, sorted_array);
  cout<<"sorted array"<<endl;
  for(int num: sorted_array)
    {
      cout<<num<<" ";
    }
  cout<<endl;
  return 0;
}