#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* getTail(ListNode* head);

ListNode* concatenate(ListNode* head1, ListNode* head2) {
    if (head1 == NULL) return head2;
    if (head2 == NULL) return head1;

    ListNode* temp = head1;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = head2;
    return head1;
}

ListNode* partition(ListNode* head, ListNode* end, ListNode** newHead, ListNode** newEnd) {
    ListNode* pivot = end;
    ListNode* prev = NULL;
    ListNode* cur = head;
    ListNode* tail = pivot;

    while (cur != pivot) {
        if (cur->val < pivot->val) {
            if (*newHead == NULL) {
                *newHead = cur;
            }
            prev = cur;
            cur = cur->next;
        } else {
            if (prev) prev->next = cur->next;
            ListNode* temp = cur->next;
            cur->next = NULL;
            tail->next = cur;
            tail = cur;
            cur = temp;
        }
    }

    if (*newHead == NULL) {
        *newHead = pivot;
    }
    *newEnd = tail;

    return pivot;
}

ListNode* quickSort(ListNode* head, ListNode* end) {
    if (!head || head == end) return head;

    ListNode* newHead = NULL;
    ListNode* newEnd = NULL;

    ListNode* pivot = partition(head, end, &newHead, &newEnd);

    if (newHead != pivot) {
        ListNode* temp = newHead;
        while (temp->next != pivot) {
            temp = temp->next;
        }
        temp->next = NULL;

        newHead = quickSort(newHead, temp);
        temp = getTail(newHead);
        temp->next = pivot;
    }

    pivot->next = quickSort(pivot->next, newEnd);

    return newHead;
}

ListNode* getTail(ListNode* head) {
    while (head != NULL && head->next != NULL) {
        head = head->next;
    }
    return head;
}

void printList(ListNode* head) {
    while (head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    ListNode* head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(4);
    head->next->next->next = new ListNode(1);

    cout << "Original List: ";
    printList(head);
    ListNode* tail = getTail(head);
    head = quickSort(head, tail);

    cout << "Sorted List: ";
    printList(head);

    return 0;
}
