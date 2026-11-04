// Problem: Moocast
// Contest: USACO 2016 December Gold
// Link: https://usaco.org/index.php?cpid=669&page=viewproblem2

#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("moocast.in", "r", stdin);
    freopen("moocast.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;

    cin >> n;

    vector<pair<int, int>> cows(n);

    for (int i = 0; i < n; i++) {
        cin >> cows[i].first;
        cin >> cows[i].second;
    }

    vector<int> visited(n, INT_MAX);
    queue<int> q;
    visited[0] = 0;
    q.push(0);

    while (not q.empty()) {
        int x = q.front();
        q.pop();

        for (int i = 0; i < n; i++) {
            if (i != x) {
                int distance = max((visited[x] == INT_MAX ? 0 : visited[x]), (cows[x].first - cows[i].first) * (cows[x].first - cows[i].first) + (cows[x].second - cows[i].second) * (cows[x].second - cows[i].second));

                if (visited[i] > distance) {
                    visited[i] = distance;
                    q.push(i);
                }
            }
        }
    }

    cout << *std::max_element(visited.begin(), visited.end());

    return 0;
}
