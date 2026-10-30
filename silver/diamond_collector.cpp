// Problem: Diamond Collector
// Contest: USACO 2016 US Open Silver
// Link: https://usaco.org/index.php?page=viewproblem2&cpid=643

#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("diamond.in", "r", stdin);
    freopen("diamond.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;

    cin >> n >> k;

    vector<int> diamonds(n);

    for (int i = 0; i < n; i++) {
        cin >> diamonds[i];
    }

    sort(diamonds.begin(), diamonds.end());

    vector<int> best(n);
    int start = n - 1, end = n - 1;
    int prev_max = 0;

    for (int i = 0; i < n; i++) {
        end = n - i - 1;

        while (diamonds[start] - diamonds[end] > k) {
            start -= 1;
        }

        prev_max = max(prev_max, start - end + 1);

        best[n - i - 1] = prev_max;
    }


    start = 0, end = 0;
    prev_max = 0;
    int max_diamonds = best[0];

    for (int i = 0; i < n - 1; i++) {
        end = i;

        while (diamonds[end] - diamonds[start] > k) {
            start += 1;
        }

        prev_max = max(prev_max, end - start + 1);

        max_diamonds = max(max_diamonds, prev_max + best[end + 1]);
    }

    cout << max_diamonds;

    return 0;
}
