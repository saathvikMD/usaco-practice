// Problem: Palindrome Game
// Contest: USACO February 2024 Bronze
// Link: https://usaco.org/index.php?page=viewproblem2&cpid=1395

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;

    cin >> t;

    for (int iteration = 0; iteration < t; iteration++) {
        string s;

        cin >> s;

        if (s[s.length() - 1] == '0') {
            cout << 'E';
        } else {
            cout << 'B';
        }

        cout << '\n';
    }

    return 0;
}
