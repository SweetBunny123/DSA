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

LinkedList* create_linked_list(int n, int h, vector<pair<int,int>> &edges)
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

    return a[h];
}
LinkedList *reverse(LinkedList *head)
{
    if(head==NULL)return NULL;
    if(head->next==NULL)return head;
    LinkedList *temp = reverse(head->next);
    head->next->next = head;
    head->next = NULL;
    
    return temp;
}
int main()
{
    int n,  h;
    cin >> n >> h;

    vector<pair<int,int>> edges;
    for(int i=0; i<n-1; i++)
    {
        int u, v;
        cin >> u >> v;
        edges.push_back({u, v});
    }

    LinkedList* head = create_linked_list(n, h, edges);
    head = reverse(head);
    while(head!=NULL)
      {
        cout<<head->value<<" ";
        head = head->next;
      }
    return 0;
}
