#include<bits/stdc++.h>
using namespace std;

int main() {
    list<int> linkedList;
    int value;

    while (cin >> value && value != -1) {
        linkedList.push_back(value);
    }

    set<int> uniqueValues(linkedList.begin(), linkedList.end());

    linkedList.clear();
    for (int val : uniqueValues) {
        linkedList.push_back(val);
    }

    for (int val : linkedList) {
        cout << val << " ";
    }

    return 0;
}