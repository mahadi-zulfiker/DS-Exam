#include<bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> v;
    for(int i = 0; i < N; i++){
        int value;
        cin >> value;
        if(find(v.begin(), v.end(), value) != v.end()){
            cout << "YES" << endl;
            return 0;
        }
        v.push_back(value);
    }

    cout << "NO" << endl;
    return 0;
}