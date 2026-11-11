// Problem: Switching on the Lights
// Contest: USACO December 2015 Silver
// Link: https://usaco.org/index.php?page=viewproblem2&cpid=570

#include <bits/stdc++.h>
using namespace std;

bool reachable(const vector<vector<bool>> &visited, int x, int y) {
    if (x > 0 and visited[x - 1][y]) {
        return true;
    }

    if (x < visited.size() - 1 and visited[x + 1][y]) {
        return true;
    }

    if (y > 0 and visited[x][y - 1]) {
        return true;
    }

    if (y < visited.size() - 1 and visited[x][y + 1]) {
        return true;
    }

    return false;
}

int main() {
    freopen("lightson.in", "r", stdin);
    freopen("lightson.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;

    cin >> n >> m;

    vector<vector<vector<pair<int, int>>>> rooms(n, vector<vector<pair<int, int>>>(n));

    for (int i = 0; i < m; i++) {
        int x, y, a, b;

        cin >> x >> y >> a >> b;

        rooms[x-1][y-1].push_back({a - 1, b - 1});
    }

    vector<vector<bool>> visited(n, vector<bool>(n, false));
    vector<vector<bool>> lit(n, vector<bool>(n, false));

    queue<pair<int, int>> q;
    visited[0][0] = true;
    lit[0][0] = true;
    q.push({0, 0});

    while (not q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for (int i = 0; i < rooms[x][y].size(); i++) {
            auto [a, b] = rooms[x][y][i];
            lit[a][b] = true;

            if (not visited[a][b] and reachable(visited, a, b)) {
                visited[a][b] = true;
                q.push({a, b});
            }
        }

        if (x > 0 and lit[x - 1][y] and not visited[x - 1][y]) {
            visited[x - 1][y] = true;
            q.push({x - 1, y});
        }

        if (x < n - 1 and lit[x + 1][y] and not visited[x + 1][y]) {
            visited[x + 1][y] = true;
            q.push({x + 1, y});
        }

        if (y > 0 and lit[x][y - 1] and not visited[x][y - 1]) {
            visited[x][y - 1] = true;
            q.push({x, y - 1});
        }

        if (y < n - 1 and lit[x][y + 1] and not visited[x][y + 1]) {
            visited[x][y + 1] = true;
            q.push({x, y + 1});
        }
    }

    int lit_rooms = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (lit[i][j]) {
                lit_rooms += 1;
            }
        }
    }

    cout << lit_rooms;

    return 0;
}
