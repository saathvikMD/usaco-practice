// Problem: Fruit Feast
// Contest: USACO December 2015 Gold
// Link: https://usaco.org/index.php?page=viewproblem2&cpid=574

#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("feast.in", "r", stdin);
    freopen("feast.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t, a, b;

    cin >> t >> a >> b;

    vector<vector<bool>> dp(2, vector<bool>(t + 1, false));
    dp[0][0] = true;

    for (int i = 0; i <= t; i++) {
        if (dp[0][i]) {
            if (i + a <= t) {
                dp[0][i + a] = true;
            }

            if (i + b <= t) {
                dp[0][i + b] = true;
            }

            dp[1][i / 2] = true;
        }
    }

    for (int i = 0; i <= t; i++) {
        if (dp[1][i]) {
            if (i + a <= t) {
                dp[1][i + a] = true;
            }

            if (i + b <= t) {
                dp[1][i + b] = true;
            }
        }
    }

    for (int i = t; i >= 0; i--) {
        if (dp[0][i] or dp[1][i]) {
            cout << i;

            break;
        }
    }

    return 0;
}
