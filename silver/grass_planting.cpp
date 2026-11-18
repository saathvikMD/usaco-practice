// Problem: Grass Planting
// Contest: USACO January 2019 Silver
// Link: https://usaco.org/index.php?page=viewproblem2&cpid=894

#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("planting.in", "r", stdin);
    freopen("planting.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;

    cin >> n;

    vector<vector<int>> graph(n, vector<int>());

    for (int i = 0; i < n - 1; i++) {
        int a, b;

        cin >> a >> b;

        graph[a - 1].push_back(b - 1);
        graph[b - 1].push_back(a - 1);
    }

    int max_out = 0;

    for (int i = 0; i < n; i++) {
        max_out = max(max_out, (int) graph[i].size());
    }

    cout << max_out + 1;

    return 0;
}
