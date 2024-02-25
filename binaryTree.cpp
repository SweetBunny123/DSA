#include<bits/stdc++.h>
using namespace std;
struct bintree {
    int data;
    struct bintree* left;
    struct bintree* right;
    bintree(int val) {
        data = val;
        left = right = NULL;
    }
};
void preOrderTraversal(struct bintree* node)
{
  if(node)
  {
    cout<<node->data<<" ";
    preOrderTraversal(node->left);
    preOrderTraversal(node->right);
  }
}



void inOrderTraversal(struct bintree*node)
{
  if(node)
  {
    inOrderTraversal(node->left);
    cout<<node->data<<" ";
    inOrderTraversal(node->right);
  }
}
void postOrderTraversal(struct bintree *node)
{
  if(node)
  {
    postOrderTraversal(node->left);
    postOrderTraversal(node->right);
    cout<<node->data<<" ";
  }
}


void levelOrderTraversal(struct bintree* node)
{
  queue<struct bintree*>q;
  q.push(node);
  while(!q.empty())
    {
      struct bintree* curr = q.front();
      cout<<curr->data<<" ";
      q.pop();
      if(curr->left)q.push(curr->left);
      if(curr->right)q.push(curr->right);
    }
}


void preorderTraversalStack(struct bintree* node)
{
  stack<struct bintree*>s;
  s.push(node);
  while(!s.empty())
    {
      struct bintree* curr = s.top();
      cout<<curr->data<<" ";
      s.pop();
      if(curr->right)s.push(curr->right);
      if(curr->left)s.push(curr->left);
    }
}

void inOrderTraversalStack(struct bintree* node)
{
  stack<struct bintree*>s;
  struct bintree* curr = node;
  while(curr || !s.empty())
    {
      while(curr!=NULL)
        {
          s.push(curr);
          curr = curr->left;
        }
      curr = s.top();
      s.pop();
      cout<<curr->data<<" ";
      curr = curr->right;
    }
}
// why is queue working
//ooooo oookkkkkkkk
void postOrderTraversals(struct bintree* node)
{
  stack<struct bintree*>s;
  struct bintree* curr = node;
  while(curr || !s.empty())
    {
      while(curr!=NULL)
        {
          s.push(curr);
          curr = curr->left;
        }
      curr = s.top();
      s.pop();
      if(curr->right && curr->right!=node)
      {
        s.push(curr);
      }
      
    }
}

int main()
{
   bintree* root = new bintree(1);
   root->left = new bintree(2);
   root->right = new bintree(3);
   root->left->left = new bintree(4);
   root->left->right = new bintree(5);
   root->right->left = new bintree(6);
   root->right->right = new bintree(7);
   root->left->left->left = new bintree(8);
   root->right->left->left = new bintree(9);
   root->right->right->left = new bintree(10);
   preOrderTraversal(root);
   cout<<endl;
   inOrderTraversal(root);
   cout<<endl;
   postOrderTraversal(root);
   cout<<endl;
   levelOrderTraversal(root);
   cout<<endl;
   preorderTraversalStack(root);
  cout<<endl;
  inOrderTraversalStack(root);
  
}
