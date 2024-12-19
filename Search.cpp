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

int searchValue(Node* &head, int x){
    int index = 0;
    Node* temp = head;
    while(temp != NULL){
        if(temp->val == x){
            return index;
        }
        temp = temp->next;
        index++;
    }
    return -1;
}

int main(){
    int T;
    cin >> T;

    while(T--){
        Node* head = NULL;
        Node* tail = NULL;
        int val;

        while(cin >> val && val != -1){
            insertNode(head, tail, val);
        }

        int x;
        cin >> x;

        cout << searchValue(head, x) << endl;

        while(head != NULL){
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
    return 0;
}