#include<bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    struct Node* next;
    Node(int x) : val(x), next(nullptr) {}
};

Node *merge(Node *a, Node *b)
{
 if(a==NULL)return b;
 if(b==NULL)return a;
 if(a->val<b->val)
 {
   a->next = merge(a->next, b);
   return a;
 }
 else
 {
   b->next = merge(a, b->next);
   return b;
 }   
}
Node *findMiddle(Node *head)
{
  Node *slow = head, *fast = head;
  Node *prev =NULL;
  while(fast!=NULL && fast->next !=NULL)
    {
      prev = slow;
      slow = slow->next;
      fast = fast->next->next;
    }
  if(prev!=NULL)
  {
    prev->next = NULL;
  }
  return slow;
}
Node *mergeSort(Node *head)
{
  if(head==NULL || head->next==NULL)return head;
  Node *mid = findMiddle(head);
  Node *left = mergeSort(head);
  Node *right = mergeSort(mid);
  return merge(left, right);
}
void printList(Node *head)
{
  while(head!=NULL)
    {
      cout<<head->val<<" ";
      head = head->next;
    }
  cout<<endl;
}

int main() {
    Node* head = new  Node(3);
    head->next = new  Node(2);
    head->next->next = new  Node(4);
    head->next->next->next = new  Node(1);

    cout << "Original List: ";
    printList(head);
    head = mergeSort(head);

    cout << "Sorted List: ";
    printList(head);

    return 0;
}