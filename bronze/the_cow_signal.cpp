// Problem: The Cow-Signal
// Contest: USACO December 2016 Bronze
// Link: https://usaco.org/index.php?page=viewproblem2&cpid=665

#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("cowsignal.in", "r", stdin);
    freopen("cowsignal.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m, n, k;

    cin >> m >> n >> k;

    for (int i = 0; i < m; i++) {
        if (i > 0) {
            cout << "\n";
        }

        string row;

        cin >> row;

        for (int iter = 0; iter < k; iter++) {
            if (iter > 0) {
                cout << "\n";
            }

            for (int j = 0; j < row.length(); j++) {
                for (int o = 0; o < k; o++) {
                    cout << row[j];
                }
            }
        }
    }

    return 0;
}
