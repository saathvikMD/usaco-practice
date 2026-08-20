// Problem: Diamond Collector
// Contest: USACO 2016 US Open Bronze
// Link: https://usaco.org/index.php?page=viewproblem2&cpid=639

#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("diamond.in", "r", stdin);
    freopen("diamond.out", "w", stdout);

    int n, k;

    cin >> n >> k;

    vector<int> diamonds(n);

    for (int i = 0; i < n; i++) {
        cin >> diamonds[i];
    }

    sort(diamonds.begin(), diamonds.end());

    if (diamonds[n - 1] - diamonds[0] <= k) {
        cout << diamonds.size();
    } else {
        int max_diamonds = 1;

        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (diamonds[j] - diamonds[i] <= k) {
                    if (j - i + 1 > max_diamonds) {
                        max_diamonds = j - i + 1;
                    }
                }
            }
        }

        cout << max_diamonds;
    }

    return 0;
}
