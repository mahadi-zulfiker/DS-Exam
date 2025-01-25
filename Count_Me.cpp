#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    cin.ignore();

    while (T--) {
        string S;
        getline(cin, S);

        vector<string> words;
        vector<int> counts;
        stringstream ss(S);
        string word;
        string mostFrequentWord;
        int maxCount = 0;

        while (ss >> word) {

            auto it = find(words.begin(), words.end(), word);
            if (it != words.end()) {

                int index = distance(words.begin(), it);
                counts[index]++;

                if (counts[index] > maxCount) {
                    maxCount = counts[index];
                    mostFrequentWord = word;
                }
            } else {

                words.push_back(word);
                counts.push_back(1); 
                if (maxCount == 0) {
                    maxCount = 1;
                    mostFrequentWord = word;
                }
            }
        }

        cout << mostFrequentWord << " " << maxCount << endl;
    }

    return 0;
}