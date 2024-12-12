#include<bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin >> T;

    while(T--){
        int N;
        cin >> N;

        vector<int> A(N);
        for(int i = 0; i < N; i++){
            cin >> A[i];
        }

        bool isSorted = true;
        for(int i = 1; i < N; i++){
            if(A[i] < A[i - 1]){
                isSorted = false;
                break;
            }
        }

        if(isSorted){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
    return 0;
}