// Problem: Painting the Barn
// Contest: USACO February 2019 Silver
// Link: https://usaco.org/index.php?page=viewproblem2&cpid=919

#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("paintbarn.in", "r", stdin);
    freopen("paintbarn.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;

    cin >> n >> k;

    vector<vector<int>> grid(1002, vector<int>(1002));

    for (int i = 0; i < n; i++) {
        int x1, y1, x2, y2;

        cin >> x1 >> y1 >> x2 >> y2;

        x1 += 1, y1 += 1, x2 += 1, y2 += 1;

        grid[x1][y1] += 1;
        grid[x2][y1] -= 1;
        grid[x1][y2] -= 1;
        grid[x2][y2] += 1;
    }

    for (int i = 1; i < 1001; i++) {
        for (int j = 1; j < 1001; j++) {
            grid[i][j] += grid[i - 1][j];
        }
    }

    int count = 0;

    for (int i = 1; i < 1001; i++) {
        for (int j = 1; j < 1001; j++) {
            grid[i][j] += grid[i][j - 1];

            if (grid[i][j] == k) {
                count += 1;
            }
        }
    }

    cout << count;

    return 0;
}
