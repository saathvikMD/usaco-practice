// Problem: Why Did the Cow Cross the Road III
// Contest: USACO February 2017 Bronze
// Link: https://usaco.org/index.php?page=viewproblem2&cpid=713

#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("cowqueue.in", "r", stdin);
    freopen("cowqueue.out", "w", stdout);

    int n;

    cin >> n;

    vector<pair<int, int>> cows(n);

    for (int i = 0; i < n; i++) {
        cin >> cows[i].first;
        cin >> cows[i].second;
    }

    sort(cows.begin(), cows.end());

    int time = 0;

    for (int i = 0; i < n; i++) {
        if (cows[i].first > time) {
            time = cows[i].first;
        }

        time += cows[i].second;
    }

    cout << time;

    return 0;
}
