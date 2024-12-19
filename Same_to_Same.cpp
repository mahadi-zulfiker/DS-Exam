#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int val;
        Node* next;
    Node(int val){
        this->val = val;
        this->next = NULL;
    }
        
};

void insertNode(Node* &head, Node* &tail, int val){
    Node* newNode = new Node(val);
    if(head == NULL){
        head = tail = newNode;
    }
    else{
        tail->next = newNode;
        tail = newNode;
    }
}

bool areListsIdentical(Node* &head1, Node* &head2){
    while(head1 != NULL && head2 != NULL){
        if(head1->val != head2->val){
            return false;
        }
        head1 = head1->next;
        head2 = head2->next;
    }
    return head1 == NULL && head2 == NULL;
}

int main(){
    Node* head1 = NULL;
    Node* tail1 = NULL;
    Node* head2 = NULL;
    Node* tail2 = NULL;
    int val;

    while(cin >> val && val != -1){
        insertNode(head1, tail1, val);
    }

    while(cin >> val && val != -1){
        insertNode(head2, tail2, val);
    }

    if(areListsIdentical(head1, head2)){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }

    while(head1 != NULL){
        Node* temp = head1;
        head1 = head1->next;
        delete temp;
    }

    while(head2 != NULL){
        Node* temp = head2;
        head2 = head2->next;
        delete temp;
    }
    
    return 0;
}