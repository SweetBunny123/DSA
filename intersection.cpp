#include <bits/stdc++.h>
using namespace std;
class LinkedList
{
public:
    int value;
    LinkedList *next;

    LinkedList()
    {
        next = nullptr;
    }
};
pair<LinkedList*, LinkedList*> create_linked_list(int n, int h1, int h2, vector<pair<int,int>> &edges)
{
    vector<LinkedList*> a(n, nullptr);
    for(int i=0; i<n; i++)
    {
        a[i] = new LinkedList();
        a[i] -> value = i;
    }

    for(auto &p: edges)
    {
        a[p.first]->next = a[p.second];
    }

    return {a[h1], a[h2]};
}
LinkedList *getIntersectionNode(LinkedList *headA, LinkedList *headB) {
  int node1count = 0;
  int node2count = 0;
  LinkedList *startA = headA;
  LinkedList *startB = headB;
  while(startA!=NULL)
  {
      node1count++;
      startA = startA->next;

  }   
  while(startB!=NULL)
  {
      node2count++;
      startB = startB->next;
  }
  startA = headA;
  startB = headB;
  if(node1count>node2count)
  {
      while(node1count!=node2count)
      {
          node1count--;
          startA = startA->next;

      }
  }
  else
  {
      while(node1count!=node2count)
      {
          node2count--;
          startB = startB->next;
      }
  }
  if(startA->next == NULL)
  {
      if(startA == startB)
          return startA;
      else
          return NULL;
  }
  else
  {
  while(startA->next!=NULL)
  {
      if(startA==startB)
      {
          return startA;
      }
      startA = startA->next;
      startB = startB->next;
  }
  if(startA == startB)
      return startA;
  else
      return NULL;
  }
}


int main()
{
    int n, m, h1, h2;
    cin >> n >> m >> h1 >> h2;

    vector<pair<int,int>> edges;
    for(int i=0; i<m; i++)
    {
        int u, v;
        cin >> u >> v;
        edges.push_back({u, v});
    }

    pair<LinkedList*, LinkedList*> heads = create_linked_list(n, h1,h2, edges);

    LinkedList* head_1 = heads.first;
    LinkedList* head_2 = heads.second;
    LinkedList* temp1 = head_1;
    LinkedList* temp2 = head_2;
    int flag = 0;
    while(temp1->next!= nullptr)temp1 = temp1->next;
    while(temp2->next!= nullptr)temp2 = temp2->next;
    if(temp1 == temp2)flag=1;
    if(flag==1)
    {
      LinkedList *head = getIntersectionNode(head_1, head_2);
      cout<<head->value<<endl;
    }
    else cout<<-1<<endl;
    return 0;
}
