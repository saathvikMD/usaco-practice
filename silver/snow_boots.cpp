// Problem: Snow Boots
// Contest: USACO February 2018 Silver
// Link: https://usaco.org/index.php?page=viewproblem2&cpid=811

#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("snowboots.in", "r", stdin);
    freopen("snowboots.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, b;

    cin >> n >> b;

    vector<int> depth(n);

    for (int i = 0; i < n; i++) {
        cin >> depth[i];
    }

    vector<pair<int, int>> boots(b);

    for (int i = 0; i < b; i++) {
        int d, s;

        cin >> d >> s;

        boots[i].first = d;
        boots[i].second = s;
    }

    queue<pair<int, int>> q;
    vector<vector<bool>> visited(n, vector<bool>(b, false));
    q.push({0, 0});
    visited[0][0] = true;
    int min_boots = INT_MAX;

    while (q.size() > 0) {
        auto [pos, boot] = q.front();
        q.pop();

        for (int i = 1; i <= boots[boot].second and i + pos < n; i++) {
            if (boots[boot].first >= depth[pos + i]) {
                if (pos + i == n - 1) {
                    min_boots = min(min_boots, boot);
                } else {
                    if (not visited[pos + i][boot]) {
                        q.push({pos + i, boot});
                        visited[pos + i][boot] = true;
                    }
                }
            }
        }
        
        for (int i = boot + 1; i < b; i++) {
            if (boots[i].first >= depth[pos] and not visited[pos][i]) {
                q.push({pos, i});
                visited[pos][i] = true;
            }
        }
    }

    cout << min_boots;

    return 0;
}
