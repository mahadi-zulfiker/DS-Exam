#include<bits/stdc++.h>
using namespace std;

bool customComparator(const pair<string, int>& a, const pair<string, int>& b) {
    if (a.first == b.first) {
        return a.second > b.second;
    }
    return a.first < b.first;
}

int main(){
    int N;
    cin >> N;

    vector<pair<string, int>> pairs(N);
    for (int i = 0; i < N; i++) {
        cin >> pairs[i].first >> pairs[i].second;
    }

    sort(pairs.begin(), pairs.end(), customComparator);

    for (int i = 0; i < N; i++) {
        cout << pairs[i].first << " " << pairs[i].second << endl;
    }

    return 0;
}
