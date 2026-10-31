// Problem: Closing the Farm
// Contest: USACO 2016 US Open Silver
// Link: https://usaco.org/index.php?page=viewproblem2&cpid=644

#include <bits/stdc++.h>
using namespace std;

bool check(vector<bool> visited, vector<vector<int>> &paths) {
    int start = 0;

    for (int i = 0; i < visited.size(); i++) {
        if (not visited[i]) {
            start = i;
            break;
        }
    }

    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (q.size() > 0) {
        int curr = q.front();
        q.pop();

        for (int i = 0; i < paths[curr].size(); i++) {
            if (not visited[paths[curr][i]]) {
                visited[paths[curr][i]] = true;
                q.push(paths[curr][i]);
            }
        }
    }

    return count(visited.begin(), visited.end(), true) == visited.size();
}

int main() {
    freopen("closing.in", "r", stdin);
    freopen("closing.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;

    cin >> n >> m;

    vector<vector<int>> paths(n, vector<int>());

    for (int i = 0; i < m; i++) {
        int a, b;

        cin >> a >> b;

        paths[a - 1].push_back(b - 1);
        paths[b - 1].push_back(a - 1);
    }

    vector<bool> visited(n, false);

    for (int i = 0; i < n; i++) {
        if (check(visited, paths)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }

        int remove;

        cin >> remove;

        visited[remove - 1] = true;
    }

    return 0;
}
