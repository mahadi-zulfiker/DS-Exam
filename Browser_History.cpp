#include<bits/stdc++.h>
using namespace std;

int main() {
    list<string> browserHistory;
    string address;

    while (cin >> address && address != "end") {
        browserHistory.push_back(address);
    }

    int Q;
    cin >> Q;
    cin.ignore();

    auto current = browserHistory.begin();

    while (Q--) {
        string command;
        getline(cin, command);

        if (command.substr(0, 6) == "visit ") {
            string visitAddress = command.substr(6);
            auto it = find(browserHistory.begin(), browserHistory.end(), visitAddress);
            if (it != browserHistory.end()) {
                current = it;
                cout << *current << endl;
            } else {
                cout << "Not Available" << endl;
            }
        } else if (command == "next") {
            if (next(current) != browserHistory.end()) {
                current = next(current);
                cout << *current << endl;
            } else {
                cout << "Not Available" << endl;
            }
        } else if (command == "prev") {
            if (current != browserHistory.begin()) {
                current = prev(current);
                cout << *current << endl;
            } else {
                cout << "Not Available" << endl;
            }
        }
    }

    return 0;
}