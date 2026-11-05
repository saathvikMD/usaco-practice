// Problem: Wormhole Sort
// Contest: USACO January 2020 Silver
// Link: https://usaco.org/index.php?page=viewproblem2&cpid=992

#include <bits/stdc++.h>
using namespace std;

bool possible(const vector<vector<pair<int, int>>> &wormholes, const vector<int> &cows, int n, int limit) {
    vector<int> visited(n, -1);

    for (int i = 0; i < n; i++) {
        if (visited[i] == -1) {
            queue<int> q;
            q.push(i);
            visited[i] = i;

            while (not q.empty()) {
                int x = q.front();
                q.pop();

                for (int j = 0; j < wormholes[x].size(); j++) {
                    if (visited[wormholes[x][j].first] == -1 and wormholes[x][j].second >= limit) {
                        visited[wormholes[x][j].first] = i;
                        q.push(wormholes[x][j].first);
                    }
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (visited[cows[i]] != visited[i]) {
            return false;
        }
    }

    return true;
}

int main() {
    freopen("wormsort.in", "r", stdin);
    freopen("wormsort.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;

    cin >> n >> m;

    vector<int> cows(n);
    vector<int> reverse_cows(n);
    bool sorted = true;

    for (int i = 0; i < n; i++) {
        int cow;

        cin >> cow;

        cows[i] = cow - 1;
        reverse_cows[cows[i]] = i;

        if (cows[i] != i) {
            sorted = false;
        }
    }

    if (sorted) {
        cout << -1;
    } else {
        vector<vector<pair<int, int>>> wormholes(n, vector<pair<int, int>>());
        int max_weight = 0;

        for (int i = 0; i < m; i++) {
            int a, b, w;

            cin >> a >> b >> w;

            wormholes[a - 1].push_back({b - 1, w});
            wormholes[b - 1].push_back({a - 1, w});

            max_weight = max(max_weight, w);
        }

        int low = 0;
        int high = max_weight;
        int answer = 0;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (possible(wormholes, cows, n, mid)) {
                answer = max(answer, mid);
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        cout << answer;
    }

    return 0;
}
