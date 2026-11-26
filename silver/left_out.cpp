// Problem: Left Out
// Contest: USACO 2019 US Open Silver
// Link: https://usaco.org/index.php?page=viewproblem2&cpid=942

#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("leftout.in", "r", stdin);
    freopen("leftout.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;

    cin >> n;

    vector<vector<bool>> grid(n, vector<bool>(n));

    for (int i = 0; i < n; i++) {
        string row;

        cin >> row;

        for (int j = 0; j < n; j++) {
            if (row[j] == 'L') {
                grid[i][j] = true;
            } else {
                grid[i][j] = false;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (grid[0][i]) {
            for (int j = 0; j < n; j++) {
                grid[j][i] = not grid[j][i];
            }
        }
    }

    for (int i = 1; i < n; i++) {
        if (grid[i][0]) {
            for (int j = 0; j < n; j++) {
                grid[i][j] = not grid[i][j];
            }
        }
    }

    int remaining = 0;

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            if (grid[i][j]) {
                remaining += 1;
            }
        }
    }

    if (remaining == 0) {
        cout << -1;
    } else if (remaining == (n - 1) * (n - 1)) {
        cout << "1 1";
    } else if (remaining == 1) {
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < n; j++) {
                if (grid[i][j]) {
                    cout << i + 1 << " " << j + 1;
                }
            }
        }
    } else if (remaining != (n - 1)) {
        cout << -1;
    } else {
        bool passed = false;

        for (int i = 1; i < n and not passed; i++) {
            bool pass = true;

            for (int j = 1; j < n; j++) {
                if (not grid[i][j]) {
                    pass = false;
                }
            }

            if (pass) {
                cout << i + 1 << " " << 1;
                passed = true;
            }
        }

        for (int i = 1; i < n and not passed; i++) {
            bool pass = true;

            for (int j = 1; j < n; j++) {
                if (not grid[j][i]) {
                    pass = false;
                }
            }

            if (pass) {
                cout << 1 << " " << i + 1;
                passed = true;
            }
        }

        if (not passed) {
            cout << -1;
        }
    }

    return 0;
}
