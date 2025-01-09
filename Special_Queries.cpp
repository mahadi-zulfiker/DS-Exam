#include <bits/stdc++.h>
using namespace std;

int main() {
    int q;
    cin >> q;

    queue<string> ticketLine;

    while (q--) {
        int command;
        cin >> command;

        if (command == 0) {
            string name;
            cin >> name;
            ticketLine.push(name);
        } else if (command == 1) {
            if (!ticketLine.empty()) {
                cout << ticketLine.front() << endl;
                ticketLine.pop();
            } else {
                cout << "Invalid" << endl;
            }
        }
    }

    return 0;
}
