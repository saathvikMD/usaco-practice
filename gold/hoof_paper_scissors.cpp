// Problem: Hoof, Paper, Scissors
// Contest: USACO January 2017 Gold
// Link: https://usaco.org/index.php?page=viewproblem2&cpid=694

#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("hps.in", "r", stdin);
    freopen("hps.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;

    cin >> n >> k;

    vector<int> moves(n);

    for (int i = 0; i < n; i++) {
        char move;

        cin >> move;

        if (move == 'H') {
            moves[i] = 0;
        } else if (move == 'P') {
            moves[i] = 1;
        } else {
            moves[i] = 2;
        }
    }

    vector<vector<vector<int>>> dp (n + 1, vector<vector<int>>(3, vector<int>(k + 1)));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            for (int o = 0; o < k + 1; o++) {
                dp[i + 1][j][o] = max(dp[i + 1][j][o], dp[i][j][o] + (moves[i] == j ? 1 : 0));

                if (o < k) {
                    for (int move = 0; move < 3; move++) {
                        if (move != j) {
                            dp[i + 1][move][o + 1] = max(dp[i + 1][move][o + 1], dp[i][j][o] + (moves[i] == move ? 1 : 0));
                        }
                    }
                }
            }
        }
    }

    int max_wins = 0;

    for (int i = 0; i <= k; i++) {
        for (int j = 0; j < 3; j++) {
            max_wins = max(max_wins, dp[n][j][i]);
        }
    }

    cout << max_wins;

    return 0;
}
