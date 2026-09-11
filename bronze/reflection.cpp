// Problem: Reflection
// Contest: USACO February 2025 Bronze
// Link: https://usaco.org/index.php?page=viewproblem2&cpid=1491

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, u;

    cin >> n >> u;

    vector<string> painting(n);

    for (int i = 0; i < n; i++) {
        cin >> painting[i];
    }

    int mid = n / 2;
    vector<vector<int>> differences(mid, vector<int>(mid));
    int changes = 0;

    for (int i = 0; i < mid; i++) {
        for (int j = 0; j < mid; j++) {
            differences[i][j] = (painting[i][j] == '.' ? 0 : 1) + (painting[n - 1 - i][j] == '.' ? 0 : 1) + (painting[i][n - 1 - j] == '.' ? 0 : 1) + (painting[n - 1 - i][n - 1 - j] == '.' ? 0 : 1);
            changes += min(differences[i][j], 4 - differences[i][j]);
        }
    }

    cout << changes << "\n";

    for (int i = 0; i < u; i++) {
        int r, c;

        cin >> r >> c;

        r -= 1;
        c -= 1;

        if (painting[r][c] == '.') {
            painting[r][c] = '#';

            if (r >= mid) {
                r = n - 1 - r;
            }

            if (c >= mid) {
                c = n - 1 - c;
            }

            changes -= min(differences[r][c], 4 - differences[r][c]);
            differences[r][c] += 1;
            changes += min(differences[r][c], 4 - differences[r][c]);
        } else {
            painting[r][c] = '.';

            if (r >= mid) {
                r = n - 1 - r;
            }

            if (c >= mid) {
                c = n - 1 - c;
            }

            changes -= min(differences[r][c], 4 - differences[r][c]);
            differences[r][c] -= 1;
            changes += min(differences[r][c], 4 - differences[r][c]);
        }

        cout << changes << "\n";
    }

    return 0;
}
