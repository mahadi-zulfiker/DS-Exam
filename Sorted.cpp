#include<bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin >> T;

    while(T--) {
        int N;
        cin >> N;

        set<int> unique_numbers;
        for(int i = 0; i < N; i++) {
            int num;
            cin >> num;
            unique_numbers.insert(num);
        }

        vector<int> sorted_numbers(unique_numbers.begin(), unique_numbers.end());
        sort(sorted_numbers.begin(), sorted_numbers.end());

        for(int num : sorted_numbers) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
