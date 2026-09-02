// Problem: Hoof, Paper, Scissors
// Contest: USACO January 2017 Silver
// Link: https://usaco.org/index.php?page=viewproblem2&cpid=691

#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("hps.in", "r", stdin);
    freopen("hps.out", "w", stdout);

    int n;

    cin >> n;

    vector<vector<int>> symbol(n);
    vector<int> curr_count(3, 0);

    for (int i = 0; i < n; i++) {
        char move;

        cin >> move;

        if (move == 'H') {
            curr_count[0] += 1;
        } else if (move == 'P') {
            curr_count[1] += 1;
        } else {
            curr_count[2] += 1;
        }

        symbol[i] = curr_count;
    }

    int max_wins = 0;
    int end_H = symbol[n - 1][0], end_P = symbol[n - 1][1], end_S = symbol[n - 1][2];

    for (int i = 0; i < n; i++) {
        int curr_H = symbol[i][0], curr_P = symbol[i][1], curr_S = symbol[i][2];
        int curr_wins = max({curr_H, curr_P, curr_S}) + max({end_H - curr_H, end_P - curr_P, end_S - curr_S});

        if (curr_wins > max_wins) {
            max_wins = curr_wins;
        }
    }

    cout << max_wins;

    return 0;
}
