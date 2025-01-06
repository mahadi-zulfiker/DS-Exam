#include <bits/stdc++.h>
using namespace std;

int main() {
    list<int> dl;
    int Q;
    cin >> Q;

    while (Q--) {
        int X, V;
        cin >> X >> V;

        if (X < 0 || X > dl.size()) {
            cout << "Invalid" << endl;
            continue;
        }

        int count = 0;
        bool inserted = false;
        list<int> tmpL;

        for (int val : dl) {
            if (count == X) {
                tmpL.push_back(V);
                inserted = true;
            }
            tmpL.push_back(val);
            count++;
        }

        if (!inserted && X == dl.size()) {
            tmpL.push_back(V);
        }

        dl = tmpL;

        cout << "L -> ";
        for (int val : dl) {
            cout << val << " ";
        }
        cout << endl;

        cout << "R -> ";
        list<int> reverse_dl(dl);
        reverse(reverse_dl.begin(), reverse_dl.end());
        for (int val : reverse_dl) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
