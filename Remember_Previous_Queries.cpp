#include <bits/stdc++.h>
using namespace std;

int main()
{
    int Q;
    cin >> Q;

    list<int> dl;

    while (Q--)
    {
        int X, V;
        cin >> X >> V;

        if (X == 0)
        {
            dl.push_front(V);
        }
        else if (X == 1)
        {
            dl.push_back(V);
        }
        else if (X == 2)
        {
            if (V >= 0 && V < dl.size())
            {
                int count = 0;
                list<int> temp;
                while (!dl.empty())
                {
                    if (count == V)
                    {
                        dl.pop_front();
                        break;
                    }
                    else
                    {
                        temp.push_back(dl.front());
                        dl.pop_front();
                    }
                    count++;
                }
                while (!temp.empty())
                {
                    dl.push_front(temp.back());
                    temp.pop_back();
                }
            }
        }

        cout << "L -> ";
        list<int> temp1 = dl;
        while (!temp1.empty())
        {
            cout << temp1.front() << " ";
            temp1.pop_front();
        }
        cout << endl;

        cout << "R -> ";
        list<int> temp2 = dl;
        while (!temp2.empty())
        {
            cout << temp2.back() << " ";
            temp2.pop_back();
        }
        cout << endl;
    }

    return 0;
}
