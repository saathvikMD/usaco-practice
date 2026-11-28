// Problem: Haybale Feast
// Contest: USACO December 2017 Gold
// Link: https://usaco.org/index.php?page=viewproblem2&cpid=767

#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("hayfeast.in", "r", stdin);
    freopen("hayfeast.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, m;

    cin >> n >> m;

    vector<pair<int, int>> hay(n);

    for (int i = 0; i < n; i++) {
        cin >> hay[i].first >> hay[i].second;
    }

    int start = 0;
    int end = -1;
    long long total = 0;
    priority_queue<pair<int, int>> pq;
    int minimum = INT_MAX;

    while (end < n - 1 or total >= m) {
        if (total < m) {
            end += 1;
            total += hay[end].first;
            pq.push({hay[end].second, end});
        } else if (total >= m) {
            while (pq.top().second < start) {
                pq.pop();
            }

            minimum = min(minimum, pq.top().first);
            total -= hay[start].first;
            start += 1;
        }
    }

    cout << minimum;

    return 0;
}
