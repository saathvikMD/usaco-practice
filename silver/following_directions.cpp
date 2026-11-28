// Problem: Following Directions
// Contest: USACO January 2023 Silver
// Link: https://usaco.org/index.php?page=viewproblem2&cpid=1279

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;

    cin >> n;

    vector<vector<int>> grid(n + 1, vector<int>(n + 1));

    for (int i = 0; i < n; i++) {
        string s;
        int cost;

        cin >> s >> cost;

        for (int j = 0; j < n; j++) {
            grid[i][j] = (s[j] == 'R' ? 1 : 0);
        }

        grid[i][n] = cost;
    }

    for (int i = 0; i < n; i++) {
        cin >> grid[n][i];
    }

    int q;

    cin >> q;

    vector<vector<int>> total(n + 1, vector<int>(n + 1, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 1) {
                total[i][j + 1] += total[i][j] + 1;
            } else {
                total[i + 1][j] += total[i][j] + 1;
            }
        }
    }

    long long cost = 0;

    for (int i = 0; i < n; i++) {
        cost += grid[i][n] * total[i][n];
        cost += grid[n][i] * total[n][i];
    }

    cout << cost;

    for (int i = 0; i < q; i++) {
        int x, y;

        cin >> x >> y;

        x -= 1, y -= 1;

        int cx = x, cy = y;
        int original = total[x][y] + 1;

        while (cx != n and cy != n) {
            total[cx][cy] -= original;

            if (grid[cx][cy] == 0) {
                cx += 1;
            } else {
                cy += 1;
            }
        }

        cost -= original * grid[cx][cy];

        grid[x][y] = (grid[x][y] == 1 ? 0 : 1);
        cx = x, cy = y;

        while (cx != n and cy != n) {
            total[cx][cy] += original;

            if (grid[cx][cy] == 0) {
                cx += 1;
            } else {
                cy += 1;
            }
        }

        cost += (total[x][y] + 1) * grid[cx][cy];

        cout << "\n";
        cout << cost;
    }

    return 0;
}
