// Problem: Spaced Out
// Contest: USACO January 2021 Silver
// Link: https://usaco.org/index.php?page=viewproblem2&cpid=1088

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;

    cin >> n;

    vector<vector<int>> beauty(n, vector<int>(n));
    vector<int> column_sum(n, 0);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> beauty[i][j];

            column_sum[j] += beauty[i][j];
        }
    }

    int total1 = 0, total2 = 0, total3 = 0, total4 = 0;

    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            total1 += column_sum[i];
        } else {
            total2 += column_sum[i];
        }

        int odd_row = 0, even_row = 0;

        for (int j = 0; j < n; j++) {
            if (j % 2 == 0) {
                even_row += beauty[i][j];
            } else {
                odd_row += beauty[i][j];
            }
        }

        total3 += max(odd_row, even_row);

        odd_row = 0, even_row = 0;

        for (int j = 0; j < n; j++) {
            if (j % 2 == 0) {
                even_row += beauty[j][i];
            } else {
                odd_row += beauty[j][i];
            }
        }

        total4 += max(odd_row, even_row);
    }

    cout << max(max(max(total1, total2), total3), total4);

    return 0;
}
