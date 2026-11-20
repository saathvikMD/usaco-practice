// Problem: Bovine Acrobatics
// Contest: USACO December 2023 Silver
// Link: https://usaco.org/index.php?page=viewproblem2&cpid=1350

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;

    cin >> n >> m >> k;

    vector<pair<int, int>> cows(n);

    for (int i = 0; i < n; i++) {
        int w, a;

        cin >> w >> a;

        cows[i].first = w;
        cows[i].second = a;
    }

    sort(cows.begin(), cows.end());

    long long total = 0;
    int remaining = m;
    int index = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    while (index < n) {
        int extended = 0;

        while (cows[index].second > 0 and not pq.empty() and cows[index].first >= pq.top().first) {
            if (cows[index].second > pq.top().second) {
                total += pq.top().second;
                cows[index].second -= pq.top().second;

                extended += pq.top().second;
                pq.pop();
            } else {
                total += cows[index].second;
                int minimum = pq.top().first, count = pq.top().second;
                pq.pop();

                if (count > cows[index].second) {
                    pq.push({minimum, count - cows[index].second});
                }

                extended += cows[index].second;
                cows[index].second = 0;
            }
        }

        if (extended > 0) {
            pq.push({cows[index].first + k, extended});
        }

        if (cows[index].second >= remaining) {
            total += remaining;

            if (remaining > 0) {
                pq.push({cows[index].first + k, remaining});
            }

            remaining = 0;
        } else {
            remaining -= cows[index].second;
            total += cows[index].second;
            pq.push({cows[index].first + k, cows[index].second});
        }

        index += 1;
    }

    cout << total;

    return 0;
}
