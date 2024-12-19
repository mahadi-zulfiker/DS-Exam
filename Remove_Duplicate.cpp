#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* next;

    Node(int val) {
        this->val = val;
        this->next = NULL;
    }
};

void insertNode(Node*& head, int val) {
    if (!head) {
        head = new Node(val);
        return;
    }
    Node* temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = new Node(val);
}

void removeDuplicates(Node* head) {
    if (!head) return;

    unordered_set<int> seen;
    Node* current = head;
    Node* prev = NULL;

    while (current) {
        if (seen.count(current->val)) {
            prev->next = current->next;
            delete current;
        } else {
            seen.insert(current->val);
            prev = current;
        }
        current = prev->next;
    }
}

void printList(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* head = NULL;
    int val;

    while (cin >> val && val != -1) {
        insertNode(head, val);
    }

    removeDuplicates(head);
    printList(head);

    return 0;
}