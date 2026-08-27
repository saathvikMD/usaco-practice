// Problem: Milk Factory
// Contest: USACO 2019 US Open Bronze
// Link: https://usaco.org/index.php?page=viewproblem2&cpid=940

#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("factory.in", "r", stdin);
    freopen("factory.out", "w", stdout);

    int n;

    cin >> n;

    vector<vector<bool>> graph(n, vector<bool> (n, false));

    for (int i = 0; i < n; i++) {
        graph[i][i] = true;
    }

    vector<pair<int, int>> pairs;

    for (int i = 0; i < n - 1; i++) {
        int a, b;

        cin >> a >> b;

        pairs.push_back({a, b});
    }

    for (int i = 0; i < n - 1; i++) {
        for (int i = 0; i < pairs.size(); i++) {
            int a = pairs[i].first, b = pairs[i].second;

            graph[b - 1][a - 1] = true;

            for (int j = 0; j < n; j++) {
                if (graph[a - 1][j]) {
                    graph[b - 1][j] = true;
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (accumulate(graph[i].begin(), graph[i].end(), 0) == n) {
            cout << i + 1;

            return 0;
        }
    }

    cout << -1;

    return 0;
}
