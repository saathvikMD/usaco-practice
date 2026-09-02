// Problem: Breed Counting
// Contest: USACO December 2015 Silver
// Link: https://usaco.org/index.php?page=viewproblem2&cpid=572

#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("bcount.in", "r", stdin);
    freopen("bcount.out", "w", stdout);

    int n, q;

    cin >> n >> q;

    vector<vector<int>> sums(n + 1);
    vector<int> current_count(3, 0);

    sums[0] = current_count;

    for (int i = 0; i < n; i++) {
        int group;

        cin >> group;

        current_count[group - 1] += 1;
        sums[i + 1] = current_count;
    }

    for (int i = 0; i < q; i++) {
        int a, b;

        cin >> a >> b;

        for (int j = 0; j < 3; j++) {
            cout << sums[b][j] - sums[a - 1][j];

            if (j < 2) {
                cout << " ";
            } else {
                cout << "\n";
            }
        }
    }

    return 0;
}
