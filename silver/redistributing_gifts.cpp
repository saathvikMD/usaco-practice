// Problem: Redistributing Gifts
// Contest: USACO February 2022 Silver
// Link: https://usaco.org/index.php?page=viewproblem2&cpid=1206

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;

    cin >> n;

    vector<unordered_map<int, int>> preferences(n, unordered_map<int, int>());
    vector<vector<int>> graph(n, vector<int>());

    for (int i = 0; i < n; i++) {
        bool found = false;

        for (int j = 0; j < n; j++) {
            int val;

            cin >> val;

            preferences[i][val - 1] = j;

            if (not found) {
                if (val == i + 1) {
                    found = true;
                } else {
                    graph[i].push_back(val - 1);
                }
            }
        }
    }

    vector<vector<bool>> visited(n, vector<bool>(n, false));

    for (int i = 0; i < n; i++) {
        queue<int> q;
        visited[i][i] = true;
        q.push(i);

        while (not q.empty()) {
            int val = q.front();
            q.pop();

            for (int j = 0; j < graph[val].size(); j++) {
                if (not visited[i][graph[val][j]]) {
                    visited[i][graph[val][j]] = true;
                    q.push(graph[val][j]);
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (i > 0) {
            cout << "\n";
        }

        int best = i;

        for (int j = 0; j < graph[i].size(); j++) {
            if (visited[graph[i][j]][i] and preferences[i][best] > preferences[i][graph[i][j]]) {
                best = graph[i][j];
            }
        }

        cout << best + 1;
    }

    return 0;
}
