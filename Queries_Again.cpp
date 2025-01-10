#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
        int val;
        Node* next;
        Node* prev;
    Node(int val){
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};
void printLeftToRight(Node* head) {
    cout << "L -> ";
    Node* temp = head;
    while (temp) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

void printRightToLeft(Node* tail) {
    cout << "R -> ";
    Node* temp = tail;
    while (temp) {
        cout << temp->val << " ";
        temp = temp->prev;
    }
    cout << endl;
}

bool insertAtIndex(Node*& head, Node*& tail, int index, int value) {
    Node* newNode = new Node(value);

    if (index == 0) {
        if (!head) {
            head = newNode;
            tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        return true;
    }

    Node* temp = head;
    int currentIndex = 0;

    while (temp && currentIndex < index - 1) {
        temp = temp->next;
        currentIndex++;
    }

    if (!temp || (currentIndex < index - 1)) {
        delete newNode;
        return false;
    }

    if (!temp->next) {
        temp->next = newNode;
        newNode->prev = temp;
        tail = newNode;
    } else {
        newNode->next = temp->next;
        temp->next->prev = newNode;
        temp->next = newNode;
        newNode->prev = temp;
    }

    return true;
}

int main() {
    Node* head = NULL;
    Node* tail = NULL;

    int Q;
    cin >> Q;

    while (Q--) {
        int X, V;
        cin >> X >> V;

        if (insertAtIndex(head, tail, X, V)) {
            printLeftToRight(head);
            printRightToLeft(tail);
        } else {
            cout << "Invalid" << endl;
        }
    }

    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
