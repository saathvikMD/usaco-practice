// Problem: Cow Tipping
// Contest: USACO January 2017 Bronze
// Link: https://usaco.org/index.php?page=viewproblem2&cpid=689

#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("cowtip.in", "r", stdin);
    freopen("cowtip.out", "w", stdout);

    int n;

    cin >> n;

    vector<vector<bool>> cows(n, vector<bool>(n));
    string row;

    for (int i = 0; i < n; i++) {
        cin >> row;

        for (int j = 0; j < n; j++) {
            if (row[j] == '1') {
                cows[i][j] = true;
            } else {
                cows[i][j] = false;
            }
        }
    }

    int flips = 0;

    for (int i = n - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 0; j--) {
            if (cows[i][j]) {
                flips += 1;

                for (int k = 0; k <= i; k++) {
                    for (int o = 0; o <= j; o++) {
                        cows[k][o] = not cows[k][o];
                    }
                }
            }
        }
    }

    cout << flips;

    return 0;
}
