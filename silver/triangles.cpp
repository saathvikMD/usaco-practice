// Problem: Triangles
// Contest: USACO February 2020 Silver
// Link: https://usaco.org/index.php?cpid=1015&page=viewproblem2

#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("triangles.in", "r", stdin);
    freopen("triangles.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;

    cin >> n;

    int min_x = INT_MAX, min_y = INT_MAX;
    int max_x = INT_MIN, max_y = INT_MIN;

    vector<pair<int, int>> points;

    for (int i = 0; i < n; i++) {
        int x, y;

        cin >> x >> y;

        min_x = min(min_x, x);
        min_y = min(min_y, y);
        max_x = max(max_x, x);
        max_y = max(max_y, y);

        points.push_back({x, y});
    }

    vector<vector<long long>> xs(max_x - min_x + 1, vector<long long>());
    vector<vector<long long>> ys(max_y - min_y + 1, vector<long long>());
    vector<vector<long long>> x_sum(max_x - min_x + 1, vector<long long>());
    vector<vector<long long>> y_sum(max_y - min_y + 1, vector<long long>());

    for (int i = 0; i < points.size(); i++) {
        int x = points[i].first, y = points[i].second;
        xs[x - min_x].push_back(y);
        ys[y - min_y].push_back(x);
    }

    for (int i = 0; i < xs.size(); i++) {
        sort(xs[i].begin(), xs[i].end());

        long long sum = 0;

        for (int j = 0; j < xs[i].size(); j++) {
            sum += xs[i][j];
            x_sum[i].push_back(sum);
        }
    }

    for (int i = 0; i < ys.size(); i++) {
        sort(ys[i].begin(), ys[i].end());

        long long sum = 0;

        for (int j = 0; j < ys[i].size(); j++) {
            sum += ys[i][j];
            y_sum[i].push_back(sum);
        }
    }

    long long area = 0;
    const long long MOD = 1000000007;

    for (int i = 0; i < points.size(); i++) {
        int x = points[i].first;
        int y = points[i].second;

        int xi = x - min_x;
        int yi = y - min_y;

        if (xs[xi].size() > 1 and ys[yi].size() > 1) {
            int x_index = lower_bound(xs[xi].begin(), xs[xi].end(), y) - xs[xi].begin();
            int y_index = lower_bound(ys[yi].begin(), ys[yi].end(), x) - ys[yi].begin();

            long long x_total = 1LL * x_index * y - (x_index > 0 ? x_sum[xi][x_index - 1] : 0) + (x_sum[xi][xs[xi].size() - 1] - x_sum[xi][x_index]) - 1LL * (xs[xi].size() - 1 - x_index) * y;
            long long y_total = 1LL * y_index * x - (y_index > 0 ? y_sum[yi][y_index - 1] : 0) + (y_sum[yi][ys[yi].size() - 1] - y_sum[yi][y_index]) - 1LL * (ys[yi].size() - 1 - y_index) * x;

            area = (area + (x_total % MOD) * (y_total % MOD)) % MOD;
        }
    }

    cout << area;

    return 0;
}
