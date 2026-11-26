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
    vector<int> rows(n, 0);
    vector<int> cols(n, 0);
    int remaining = 0;

    for (int i = 0; i < n; i++) {
        string row;

        cin >> row;

        for (int j = 0; j < n; j++) {
            if (row[j] == 'L') {
                grid[i][j] = true;
                rows[i] -= 1;
                cols[j] -= 1;
                remaining += 1;
            } else {
                grid[i][j] = false;
                rows[i] += 1;
                cols[j] += 1;
            }
        }
    }

    if (remaining == 0 or remaining == n * n) {
        cout << -1;
    } else {
        int iter = 0;
        while (remaining > 1 and iter < 1000) {
            for (int i = 0; i < n; i++) {
                if (rows[i] < 0) {
                    for (int j = 0; j < n; j++) {
                        if (not grid[i][j]) {
                            cols[j] -= 2;
                            remaining += 1;
                        } else {
                            cols[j] += 2;
                            remaining -= 1;
                        }

                        grid[i][j] = not grid[i][j];
                    }

                    rows[i] = -rows[i];
                }
            }

            for (int i = 0; i < n; i++) {
                if (cols[i] < 0) {
                    for (int j = 0; j < n; j++) {
                        if (not grid[j][i]) {
                            rows[j] -= 2;
                            remaining += 1;
                        } else {
                            rows[j] += 2;
                            remaining -= 1;
                        }

                        grid[j][i] = not grid[j][i];
                    }

                    cols[i] = -cols[i];
                }
            }

            iter += 1;
        }

        if (iter == 1000) {
            cout << -1;
        } else {
            bool done = false;

            for (int i = 0; i < n and not done; i++) {
                for (int j = 0; j < n; j++) {
                    if (grid[i][j]) {
                        cout << i + 1 << " " << j + 1;

                        done = true;
                        break;
                    }
                }
            }

            if (not done) {
                cout << -1;
            }
        }
    }

    return 0;
}
