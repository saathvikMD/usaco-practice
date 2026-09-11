// Problem: Making Mexes
// Contest: USACO February 2025 Bronze
// Link: https://usaco.org/index.php?page=viewproblem2&cpid=1492

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;

    cin >> n;

    vector<int> operations(n + 1, 0);

    for (int i = 0; i < n; i++) {
        int temp;

        cin >> temp;

        operations[temp] += 1;
    }

    int missing = 0;

    for (int i = 0; i <= n; i++) {
        int extra = operations[i];

        cout << max(missing, extra) << "\n";

        if (operations[i] == 0) {
            missing += 1;
        }
    }

    return 0;
}
