// Problem: Crowded Cows
// Contest: USACO November 2013 Silver
// Link: https://usaco.org/index.php?page=viewproblem2&cpid=344

#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("crowded.in", "r", stdin);
    freopen("crowded.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, d;

    cin >> n >> d;

    vector<pair<int, int>> cows(n);
    vector<bool> passed(n, false);

    for (int i = 0; i < n; i++) {
        int x, h;

        cin >> x >> h;

        cows[i] = {x, h};
    }

    sort(cows.begin(), cows.end());
    priority_queue<pair<int, int>> pq;

    for (int i = 0; i < n; i++) {
        while (pq.size() > 0 and cows[i].first - pq.top().second > d) {
            pq.pop();
        }

        if (pq.size() > 0 and pq.top().first >= cows[i].second * 2) {
            passed[i] = true;
        }

        pq.push({cows[i].second, cows[i].first});
    }

    pq = priority_queue<pair<int, int>>();
    int crowded = 0;

    for (int i = n - 1; i >= 0; i--) {
        while (pq.size() > 0 and pq.top().second - cows[i].first > d) {
            pq.pop();
        }

        if (pq.size() > 0 and pq.top().first >= cows[i].second * 2 and passed[i]) {
            crowded += 1;
        }

        pq.push({cows[i].second, cows[i].first});
    }

    cout << crowded;

    return 0;
}
