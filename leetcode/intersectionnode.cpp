/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    int node1count = 0;
    int node2count = 0;
    ListNode *startA = headA;
    ListNode *startB = headB;
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
};