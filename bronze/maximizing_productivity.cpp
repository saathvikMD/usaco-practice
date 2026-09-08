// Problem: Maximizing Productivity
// Contest: USACO February 2024 Bronze
// Link: https://usaco.org/index.php?page=viewproblem2&cpid=1397

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;

    cin >> n >> q;

    vector<int> remaining(n);

    for (int i = 0; i < n; i++) {
        cin >> remaining[i];
    }

    for (int i = 0; i < n; i++) {
        int temp;

        cin >> temp;

        remaining[i] = remaining[i] - temp - 1;
    }

    sort(remaining.begin(), remaining.end());

    for (int i = 0; i < q; i++) {
        int v, s;

        cin >> v >> s;

        if (remaining[n - v] >= s) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }

    return 0;
}
