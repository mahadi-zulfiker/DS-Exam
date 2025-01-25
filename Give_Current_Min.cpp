#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, Q;
    cin >> N;

    vector<int> elements(N);
    for (int i = 0; i < N; ++i) {
        cin >> elements[i];
    }

    cin >> Q;
    while (Q--) {
        int command;
        cin >> command;
        if (command == 0) {
            int X;
            cin >> X;
            elements.push_back(X);
            if (!elements.empty()) {
                int minValue = *min_element(elements.begin(), elements.end());
                cout << minValue << endl;
            } else {
                cout << "Empty" << endl;
            }
        } else if (command == 1) {
            if (!elements.empty()) {
                int minValue = *min_element(elements.begin(), elements.end());
                cout << minValue << endl;
            } else {
                cout << "Empty" << endl;
            }
        } else if (command == 2) {
            if (!elements.empty()) {
                int minValue = *min_element(elements.begin(), elements.end());
                for (int i = 0; i < elements.size(); ++i) {
                    if (elements[i] == minValue) {
                        elements.erase(elements.begin() + i);
                        break;
                    }
                }
                if (!elements.empty()) {
                    minValue = *min_element(elements.begin(), elements.end());
                    cout << minValue << endl;
                } else {
                    cout << "Empty" << endl;
                }
            } else {
                cout << "Empty" << endl;
            }
        }
    }

    return 0;
}
