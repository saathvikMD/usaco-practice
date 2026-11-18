// Problem: Comfortable Cows
// Contest: USACO February 2021 Silver
// Link: https://usaco.org/index.php?page=viewproblem2&cpid=1110

#include <bits/stdc++.h>
using namespace std;

int comfort(vector<vector<bool>> & grid, vector<vector<int>> & count, int x, int y) {
    queue<pair<int, int>> q;

    if (grid[x][y] and count[x][y] == 3) {
        q.push({x, y});
    }

    if (grid[x - 1][y] and count[x - 1][y] == 3) {
        q.push({x - 1, y});
    }

    if (grid[x + 1][y] and count[x + 1][y] == 3) {
        q.push({x + 1, y});
    }

    if (grid[x][y - 1] and count[x][y - 1] == 3) {
        q.push({x, y - 1});
    }

    if (grid[x][y + 1] and count[x][y + 1] == 3) {
        q.push({x, y + 1});
    }

    int total = 0;

    while (not q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if (count[x][y] != 3) {
            continue;
        }

        total += 1;

        int a, b;

        if (not grid[x - 1][y]) {
            grid[x - 1][y] = true;
            a = x - 1, b = y;
        } else if (not grid[x + 1][y]) {
            grid[x + 1][y] = true;
            a = x + 1, b = y;
        } else if (not grid[x][y - 1]) {
            grid[x][y - 1] = true;
            a = x, b = y - 1;
        } else if (not grid[x][y + 1]) {
            grid[x][y + 1] = true;
            a = x, b = y + 1;
        }

        count[a - 1][b] += 1;
        count[a + 1][b] += 1;
        count[a][b - 1] += 1;
        count[a][b + 1] += 1;

        if (grid[a][b] and count[a][b] == 3) {
            q.push({a, b});
        }

        if (grid[a - 1][b] and count[a - 1][b] == 3) {
            q.push({a - 1, b});
        }

        if (grid[a + 1][b] and count[a + 1][b] == 3) {
            q.push({a + 1, b});
        }

        if (grid[a][b - 1] and count[a][b - 1] == 3) {
            q.push({a, b - 1});
        }

        if (grid[a][b + 1] and count[a][b + 1] == 3) {
            q.push({a, b + 1});
        }
    }

    return total;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;

    cin >> n;

    vector<pair<int, int>> points(n);
    int min_x = INT_MAX, min_y = INT_MAX, max_x = INT_MIN, max_y = INT_MIN;

    for (int i = 0; i < n; i++) {
        int x, y;

        cin >> x >> y;

        points[i] = {x, y};
        min_x = min(min_x, x);
        min_y = min(min_y, y);
        max_x = max(max_x, x);
        max_y = max(max_y, y);
    }

    vector<vector<bool>> grid(3005, vector<bool>(3005, false));
    vector<vector<int>> count(3005, vector<int>(3005, 0));
    int extra = 0;

    for (int i = 0; i < n; i++) {
        int x = points[i].first, y = points[i].second;
        x += 1001, y += 1001;

        if (grid[x][y]) {
            extra -= 1;
        } else {
            grid[x][y] = true;

            count[x - 1][y] += 1;
            count[x + 1][y] += 1;
            count[x][y - 1] += 1;
            count[x][y + 1] += 1;

            extra += comfort(grid, count, x, y);
        }

        if (i > 0) {
            cout << "\n";
        }

        cout << extra;
    }

    return 0;
}
