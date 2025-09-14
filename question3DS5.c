#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void push(Node*& head, int val) {
    Node* newNode = new Node{val, head};
    head = newNode;
}

int findMiddle(Node* head) {
    Node* slow = head;
    Node* fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow->data;
}

int main() {
    Node* head = nullptr;
    for (int i = 5; i >= 1; i--) push(head, i); // 1->2->3->4->5
    cout << "Middle: " << findMiddle(head) << endl;
    return 0;
}
