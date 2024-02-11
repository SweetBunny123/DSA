#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;
};

int getIntersectionNode(Node *headA, Node *headB) {
    int node1count = 0;
    int node2count = 0;
    Node *startA = headA;
    Node *startB = headB;
    while (startA != NULL) {
        node1count++;
        startA = startA->next;
    }
    while (startB != NULL) {
        node2count++;
        startB = startB->next;
    }g++ in
    return node1count;
}

int main() {
    // Creating sample nodes for demonstration
    Node* headA = new Node();
    headA->data = 1;
    headA->next = new Node();
    headA->next->data = 2;
    headA->next->next = new Node();
    headA->next->next->data = 3;
    headA->next->next->next = nullptr;

    Node* headB = new Node();
    headB->data = 4;
    headB->next = headA->next; // making B intersect with A at node with data 2

    // Call your function to get the intersection node count
    int intersectionCount = getIntersectionNode(headA, headB);

    // Print the count of intersection nodes
    cout << "Count of intersection nodes: " << intersectionCount << endl;

    return 0;
}
