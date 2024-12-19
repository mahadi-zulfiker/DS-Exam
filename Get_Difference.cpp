#include <bits/stdc++.h>
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

void insertAndCalculate(Node*& head, Node*& tail, int val, int& maxVal, int& minVal){
    maxVal = max(maxVal, val);
    minVal = min(minVal, val);

    Node* newNode = new Node(val);
    if(head == NULL){
        head = tail = newNode;
    }
    else{
        tail->next = newNode;
        tail = newNode;
    }
}

int main(){
    Node* head = NULL;
    Node* tail = NULL;
    int val;

    int maxVal = INT_MIN;
    int minVal = INT_MAX;

    while(cin >> val && val != -1){
        insertAndCalculate(head, tail, val, maxVal, minVal);
    }

    cout << maxVal - minVal << endl;

    return 0;
}
