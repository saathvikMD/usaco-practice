// Problem: Convention II
// Contest: USACO December 2018 Silver
// Link: https://usaco.org/index.php?page=viewproblem2&cpid=859

#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("convention2.in", "r", stdin);
    freopen("convention2.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;

    cin >> n;

    vector<tuple<int, int, int>> cows(n);

    for (int i = 0; i < n; i++) {
        int a, t;

        cin >> a >> t;

        cows[i] = {a, i, t};
    }

    sort(cows.begin(), cows.end());

    priority_queue<tuple<int, int, int>> waiting;
    int max_wait = 0;
    int finish_eating = 0;
    int curr_cow = 0;

    while (curr_cow < n) {
        if (waiting.size() == 0) {
            if (get<0>(cows[curr_cow]) >= finish_eating) {
                finish_eating = get<0>(cows[curr_cow]) + get<2>(cows[curr_cow]);
            } else {
                waiting.push({n - get<1>(cows[curr_cow]), get<2>(cows[curr_cow]), get<0>(cows[curr_cow])});
            }

            curr_cow += 1;
        } else {
            if (get<0>(cows[curr_cow]) > finish_eating) {
                auto [rank, time, arrival] = waiting.top();
                waiting.pop();

                max_wait = max(max_wait, finish_eating - arrival);
                finish_eating += time;
            } else {
                waiting.push({n - get<1>(cows[curr_cow]), get<2>(cows[curr_cow]), get<0>(cows[curr_cow])});
                curr_cow += 1;
            }
        }
    }

    while (waiting.size() > 0) {
        auto [rank, time, arrival] = waiting.top();
        waiting.pop();

        max_wait = max(max_wait, finish_eating - arrival);
        finish_eating += time;
    }

    cout << max_wait;

    return 0;
}
