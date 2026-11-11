// Problem: Sleepy Cow Herding
// Contest: USACO February 2019 Silver
// Link: https://usaco.org/index.php?page=viewproblem2&cpid=918

#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("herding.in", "r", stdin);
    freopen("herding.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;

    cin >> n;

    vector<int> cows(n);

    for (int i = 0; i < n; i++) {
        cin >> cows[i];
    }

    sort(cows.begin(), cows.end());

    int start = 0, end = 0;
    int min_moves = INT_MAX;

    if (cows[n - 1] - cows[0] == n - 1) {
        min_moves = 0;
    } else {
        while (end < cows.size()) {
            if (cows[end] - cows[start] < n) {
                if (n - (end - start + 1) == 1) {
                    if (cows[n - 1] - cows[1] == n - 1 or cows[n - 2] - cows[0] == n - 1) {
                        min_moves = 1;

                        break;
                    }

                    min_moves = min(min_moves, 2);
                } else {
                    min_moves = min(min_moves, n - (end - start + 1));
                }

                end += 1;
            } else {
                start += 1;
            }
        }
    }

    cout << min_moves << "\n";
    cout << max(cows[n - 1] - cows[1], cows[n - 2] - cows[0]) - n + 2;

    return 0;
}
