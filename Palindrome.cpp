#include<bits/stdc++.h>
using namespace std;

int main() {
    list<int> doublyLinkedList;
    int value;

    while (cin >> value && value != -1) {
        doublyLinkedList.push_back(value);
    }

    auto front = doublyLinkedList.begin();
    auto back = doublyLinkedList.rbegin();
    bool isPalindrome = true;

    while (front != doublyLinkedList.end() && back != doublyLinkedList.rend()) {
        if (*front != *back) {
            isPalindrome = false;
            break;
        }
        ++front;
        ++back;
    }

    if (isPalindrome) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
