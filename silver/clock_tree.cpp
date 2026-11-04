// Problem: Clock Tree
// Contest: USACO February 2020 Silver
// Link: https://usaco.org/index.php?cpid=1016&page=viewproblem2

#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("clocktree.in", "r", stdin);
    freopen("clocktree.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;

    cin >> n;

    vector<int> clocks(n);

    for (int i = 0; i < n; i++) {
        cin >> clocks[i];
    }

    vector<vector<int>> corridors(n);

    for (int i = 0; i < n - 1; i++) {
        int a, b;

        cin >> a >> b;

        corridors[a - 1].push_back(b - 1);
        corridors[b - 1].push_back(a - 1);
    }

    int evens = 0, even_total = 0;
    int odds = 0, odd_total = 0;
    vector<int> depth(n, -1);
    queue<int> q;
    depth[0] = 0;
    q.push(0);

    while (not q.empty()) {
        int x = q.front();
        q.pop();

        if (depth[x] % 2 == 0) {
            even_total += clocks[x];
            evens += 1;
        } else {
            odd_total += clocks[x];
            odds += 1;
        }

        for (int i = 0; i < corridors[x].size(); i++) {
            if (depth[corridors[x][i]] == -1) {
                depth[corridors[x][i]] = depth[x] + 1;
                q.push(corridors[x][i]);
            }
        }
    }

    if (even_total % 12 == odd_total % 12) {
        cout << n;
    } else if ((even_total + 1) % 12 == odd_total % 12) {
        cout << odds;
    } else if ((odd_total + 1) % 12 == even_total % 12) {
        cout << evens;
    } else {
        cout << 0;
    }

    return 0;
}
