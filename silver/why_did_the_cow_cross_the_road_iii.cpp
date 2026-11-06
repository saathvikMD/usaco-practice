// Problem: Why Did the Cow Cross the Road III
// Contest: USACO February 2017 Silver
// Link: https://usaco.org/index.php?page=viewproblem2&cpid=716

#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("countcross.in", "r", stdin);
    freopen("countcross.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k, r;

    cin >> n >> k >> r;

    vector<vector<vector<bool>>> road(n, vector<vector<bool>>(n, vector<bool>(4, false)));

    for (int i = 0; i < n; i++) {
        road[0][i][0] = true;
        road[n - 1][i][2] = true;
        road[i][0][3] = true;
        road[i][n - 1][1] = true;
    }

    for (int i = 0; i < r; i++) {
        int r1, c1, r2, c2;

        cin >> r1 >> c1 >> r2 >> c2;

        int d1, d2;

        if (r2 < r1) {
            d1 = 0;
            d2 = 2;
        } else if (c2 > c1) {
            d1 = 1;
            d2 = 3;
        } else if (r2 > r1) {
            d1 = 2;
            d2 = 0;
        } else {
            d1 = 3;
            d2 = 1;
        }

        road[r1 - 1][c1 - 1][d1] = true;
        road[r2 - 1][c2 - 1][d2] = true;
    }

    vector<vector<int>> visited(n, vector<int>(n, -1));
    int component = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (visited[i][j] == -1) {
                visited[i][j] = component;

                queue<pair<int, int>> q;
                q.push({i, j});

                while (not q.empty()) {
                    auto [x, y] = q.front();
                    q.pop();

                    if (not road[x][y][0] and visited[x - 1][y] == -1) {
                        visited[x - 1][y] = component;
                        q.push({x - 1, y});
                    }

                    if (not road[x][y][1] and visited[x][y + 1] == -1) {
                        visited[x][y + 1] = component;
                        q.push({x, y + 1});
                    }

                    if (not road[x][y][2] and visited[x + 1][y] == -1) {
                        visited[x + 1][y] = component;
                        q.push({x + 1, y});
                    }

                    if (not road[x][y][3] and visited[x][y - 1] == -1) {
                        visited[x][y - 1] = component;
                        q.push({x, y - 1});
                    }
                }

                component += 1;
            }
        }
    }

    vector<pair<int, int>> cows(k);

    for (int i = 0; i < k; i++) {
        int x, y;

        cin >> x >> y;

        cows[i] = {x - 1, y - 1};
    }

    int distant = 0;

    for (int i = 0; i < k; i++) {
        for (int j = i + 1; j < k; j++) {
            if (visited[cows[i].first][cows[i].second] != visited[cows[j].first][cows[j].second]) {
                distant += 1;
            }
        }
    }

    cout << distant;

    return 0;
}
