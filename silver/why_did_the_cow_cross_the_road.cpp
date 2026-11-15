// Problem: Why Did the Cow Cross the Road
// Contest: USACO February 2017 Silver
// Link: https://usaco.org/index.php?page=viewproblem2&cpid=714

#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("helpcross.in", "r", stdin);
    freopen("helpcross.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int c, n;

    cin >> c >> n;

    vector<int> time(c);

    for (int i = 0; i < c; i++) {
        cin >> time[i];
    }

    vector<pair<int, int>> availability(n);

    for (int i = 0; i < n; i++) {
        cin >> availability[i].first >> availability[i].second;
    }

    sort(time.begin(), time.end());
    sort(availability.begin(), availability.end());

    priority_queue<int, vector<int>, greater<int>> pq;
    int index = 0;
    int crossed = 0;

    for (int i = 0; i < c; i++) {
        while (index < n and availability[index].first <= time[i]) {
            pq.push(availability[index].second);
            index += 1;
        }

        while (not pq.empty() and pq.top() < time[i]) {
            pq.pop();
        }

        if (not pq.empty()) {
            pq.pop();
            crossed += 1;
        }
    }

    cout << crossed;

    return 0;
}
