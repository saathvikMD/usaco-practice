// Problem: Swapity Swapity Swap
// Contest: USACO February 2020 Silver
// Link: https://usaco.org/index.php?cpid=1014&page=viewproblem2

#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("swap.in", "r", stdin);
    freopen("swap.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;

    cin >> n >> m >> k;

    vector<int> cows(n);
    vector<int> change(n);

    for (int i = 0; i < n; i++) {
        cows[i] = i;
    }

    for (int i = 0; i < m; i++) {
        int l, r;

        cin >> l >> r;

        reverse(cows.begin() + l - 1, cows.begin() + r);
    }

    for (int i = 0; i < n; i++) {
        change[cows[i]] = i;
    }

    vector<int> answer(n);
    vector<bool> visited(n, false);

    for (int i = 0; i < n; i++) {
        if (not visited[i]) {
            vector<int> order;
            int pos = i;
            order.push_back(pos);
            visited[i] = true;

            while (change[pos] != i) {
                pos = change[pos];
                order.push_back(pos);
                visited[pos] = true;
            }

            for (int j = 0; j < order.size(); j++) {
                answer[order[(j + k) % order.size()]] = order[j];
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << answer[i] + 1 << "\n";
    }

    return 0;
}
