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
bool hascycle(LinkedList *head)
{
    if(head == nullptr)return false;
    LinkedList *slow = head;
    LinkedList *fast = head;
    while(fast!=nullptr && fast->next!=nullptr)
      {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast)
          {
            return true;
          }
      }
    return false;
}
int main()
{
    int n,h;
    cin >> n >> h;

    vector<pair<int,int>> edges;
    for(int i=0; i<n; i++)
    {
        int u, v;
        cin >> u >> v;
        if(u<n && v<n)
        edges.push_back({u, v});
    }

    LinkedList* head = create_linked_list(n, h, edges);
    //Do not change code above this line
    if(hascycle(head))cout<<"TRUE"<<endl;
    else cout<<"FALSE"<<endl;
    return 0;
}
