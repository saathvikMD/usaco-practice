// Problem: Fence Planning
// Contest: USACO 2019 US Open Silver
// Link: https://usaco.org/index.php?page=viewproblem2&cpid=944

#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("fenceplan.in", "r", stdin);
    freopen("fenceplan.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;

    cin >> n >> m;

    vector<pair<int, int>> cow_position(n);
    vector<vector<int>> edges(n);

    for (int i = 0; i < n; i++) {
        int x, y;

        cin >> x >> y;

        cow_position[i].first = x;
        cow_position[i].second = y;
    }

    for (int i = 0; i < m; i++) {
        int a, b;

        cin >> a >> b;

        edges[a - 1].push_back(b - 1);
        edges[b - 1].push_back(a - 1);
    }

    vector<bool> visited(n, false);
    int min_perimeter = INT_MAX;

    for (int i = 0; i < n; i++) {
        if (not visited[i]) {
            vector<int> current;
            current.push_back(i);
            visited[i] = true;

            int min_x = INT_MAX;
            int max_x = INT_MIN;
            int min_y = INT_MAX;
            int max_y = INT_MIN;

            while (current.size() > 0) {
                vector<int> next;

                for (int j = 0; j < current.size(); j++) {
                    int node = current[j];

                    min_x = min(min_x, cow_position[node].first);
                    max_x = max(max_x, cow_position[node].first);
                    min_y = min(min_y, cow_position[node].second);
                    max_y = max(max_y, cow_position[node].second);

                    for (int k = 0; k < edges[node].size(); k++) {
                        if (not visited[edges[node][k]]) {
                            next.push_back(edges[node][k]);
                            visited[edges[node][k]] = true;
                        }
                    }
                }

                current = next;
            }

            int perimeter = 2 * ((max_x - min_x) + (max_y - min_y));

            if (perimeter < min_perimeter) {
                min_perimeter = perimeter;
            }
        }
    }

    cout << min_perimeter;

    return 0;
}
