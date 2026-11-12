// Problem: Paired Up
// Contest: USACO 2017 US Open Silver
// Link: https://usaco.org/index.php?page=viewproblem2&cpid=738

#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("pairup.in", "r", stdin);
    freopen("pairup.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;

    cin >> n;

    vector<pair<int, int>> cows(n);

    for (int i = 0; i < n; i++) {
        int count, milk;

        cin >> count >> milk;

        cows[i].first = milk;
        cows[i].second = count;
    }

    sort(cows.begin(), cows.end());

    int start = 0;
    int end = n - 1;
    int start_remaining = cows[start].second;
    int end_remaining = cows[end].second;
    int min_time = 0;

    while (start < end) {
        min_time = max(cows[start].first + cows[end].first, min_time);

        if (start_remaining < end_remaining) {
            end_remaining -= start_remaining;
            start += 1;
            start_remaining = cows[start].second;
        } else if (end_remaining < start_remaining) {
            start_remaining -= end_remaining;
            end -= 1;
            end_remaining = cows[end].second;
        } else {
            start += 1;
            end -= 1;
            start_remaining = cows[start].second;
            end_remaining = cows[end].second;
        }
    }

    if (start == end) {
        min_time = max(cows[start].first + cows[end].first, min_time);
    }

    cout << min_time;

    return 0;
}
