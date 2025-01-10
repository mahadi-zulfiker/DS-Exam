#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; 
    cin >> t; // Number of test cases
    while (t--) {
        string binaryString;
        cin >> binaryString;

        stack<char> stk;

        for (char ch : binaryString) {
            // Check for eliminations
            if (!stk.empty() && ((stk.top() == '0' && ch == '1') || (stk.top() == '1' && ch == '0'))) {
                stk.pop(); // Eliminate the pair
            } else {
                stk.push(ch);
            }
        }

        // If stack is empty, the string is completely eliminated
        cout << (stk.empty() ? "YES" : "NO") << endl;
    }

    return 0;
}
