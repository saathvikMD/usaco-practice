// Problem: Word Processor
// Contest: USACO January 2020 Bronze
// Link: https://usaco.org/index.php?page=viewproblem2&cpid=987

#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("word.in", "r", stdin);
    freopen("word.out", "w", stdout);

    int n, k;

    cin >> n >> k;

    vector<string> words(n);

    for (int i = 0; i < n; i++) {
        cin >> words[i];
    }

    int row_chars = words[0].length();
    cout << words[0];

    for (int i = 1; i < n; i++) {
        if (words[i].length() + row_chars <= k) {
            row_chars += words[i].length();
            cout << " " << words[i];
        } else {
            cout << "\n" << words[i];
            row_chars = words[i].length();
        }
    }

    return 0;
}
