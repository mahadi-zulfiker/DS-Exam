#include<bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;

    vector<long long int> A(N), prefixSum(N);

    for(int i = 0; i < N; i++){
        cin >> A[i];
        if(i == 0){
            prefixSum[i] = A[i];
        }
        else{
            prefixSum[i] = prefixSum[i - 1] + A[i];
        }
    }

    for(int i = N - 1; i >= 0; i--){
        cout << prefixSum[i] << " ";
    }

    cout << endl;
    return 0;
}