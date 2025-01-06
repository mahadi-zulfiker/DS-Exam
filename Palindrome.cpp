#include <bits/stdc++.h>
using namespace std;

int main()
{
    list<int> dl;
    int value;

    while (cin >> value && value != -1)
    {
        dl.push_back(value);
    }

    vector<int> values(dl.begin(), dl.end());

    bool isPalindrome = true;
    int n = values.size();
    for (int i = 0; i < n / 2; ++i)
    {
        if (values[i] != values[n - i - 1])
        {
            isPalindrome = false;
            break;
        }
    }

    if (isPalindrome)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}
