#include<bits/stdc++.h>
using namespace std;

int main() {
    list<int> doublyLinkedList;
    int Q;
    cin >> Q;

    while (Q--) {
        int X, V;
        cin >> X >> V;

        auto it = doublyLinkedList.begin();
        bool isValid = true;

        if (X >= 0 && X <= doublyLinkedList.size()) {
            advance(it, X);
            doublyLinkedList.insert(it, V);
        } else {
            isValid = false;
        }

        if (isValid) {
            cout << "L -> ";
            for (int val : doublyLinkedList) {
                cout << val << " ";
            }
            cout << endl;

            cout << "R -> ";
            for (auto rit = doublyLinkedList.rbegin(); rit != doublyLinkedList.rend(); ++rit) {
                cout << *rit << " ";
            }
            cout << endl;
        } else {
            cout << "Invalid" << endl;
        }
    }

    return 0;
}
