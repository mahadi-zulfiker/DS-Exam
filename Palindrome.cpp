#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* prev;

    Node(int val) {
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

bool isPalindrome(Node* head) {
    if (!head || !head->next) return true;

    Node* tail = head;
    while (tail->next) {
        tail = tail->next;
    }

    while (head && tail && head != tail && head->prev != tail) {
        if (head->val != tail->val) {
            return false;
        }
        head = head->next;
        tail = tail->prev;
    }

    return true;
}

int main() {
    Node* head = NULL;
    Node* tail = NULL;

    int value;
    while (cin >> value && value != -1) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    if (isPalindrome(head)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
