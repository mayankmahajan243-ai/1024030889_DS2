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

int deleteOccurrences(Node*& head, int key) {
    int count = 0;
    while (head && head->data == key) {
        Node* temp = head;
        head = head->next;
        delete temp;
        count++;
    }
    Node* curr = head;
    while (curr && curr->next) {
        if (curr->next->data == key) {
            Node* del = curr->next;
            curr->next = del->next;
            delete del;
            count++;
        } else {
            curr = curr->next;
        }
    }
    return count;
}

void display(Node* head) {
    while (head) {
        cout << head->data;
        if (head->next) cout << "->";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;
    // Linked List: 1->2->1->2->1->3->1
    int arr[] = {1,2,1,2,1,3,1};
    for (int i = 6; i >= 0; i--) push(head, arr[i]);

    int key = 1;
    cout << "Original List: "; display(head);

    int cnt = deleteOccurrences(head, key);
    cout << "Count: " << cnt << endl;
    cout << "Updated List: "; display(head);

    return 0;
}
