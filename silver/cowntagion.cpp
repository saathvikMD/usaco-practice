// Problem: Cowntagion
// Contest: USACO December 2020 Silver
// Link: https://usaco.org/index.php?page=viewproblem2&cpid=1062

#include <bits/stdc++.h>
using namespace std;

int main() {
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

    vector<int> visited(n, 0);
    queue<int> q;
    visited[0] = 1;
    q.push(0);
    int count = 0;

    while (not q.empty()) {
        int i = q.front();
        q.pop();

        vector<int> healthy;

        for (int j = 0; j < graph[i].size(); j++) {
            if (visited[graph[i][j]] == 0) {
                healthy.push_back(graph[i][j]);
                q.push(graph[i][j]);
                visited[graph[i][j]] += 1;
                count += 1;
            }
        }

        while (visited[i] < healthy.size() + 1) {
            visited[i] = visited[i] * 2;
            count += 1;
        }
    }

    cout << count;

    return 0;
}
