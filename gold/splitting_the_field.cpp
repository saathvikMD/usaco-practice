// Problem: Splitting the Field
// Contest: USACO US Open 2016 Gold
// Link: https://usaco.org/index.php?page=viewproblem2&cpid=645

#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("split.in", "r", stdin);
    freopen("split.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;

    cin >> n;

    vector<pair<long long, long long>> cows(n);
    long long total_max_y = 0LL;
    long long total_min_y = LLONG_MAX;

    for (int i = 0; i < n; i++) {
        cin >> cows[i].first;
        cin >> cows[i].second;

        total_max_y = max(total_max_y, cows[i].second);
        total_min_y = min(total_min_y, cows[i].second);
    }

    sort(cows.begin(), cows.end());

    long long single_area = (cows[n - 1].first - cows[0].first) * (total_max_y - total_min_y);
    long long min_double_area = single_area;

    vector<long long> min_y(n);
    vector<long long> max_y(n);
    long long curr_min_y = LLONG_MAX;
    long long curr_max_y = 0;

    for (int i = n - 1; i >= 0; i--) {
        curr_min_y = min(curr_min_y, cows[i].second);
        curr_max_y = max(curr_max_y, cows[i].second);

        min_y[i] = curr_min_y;
        max_y[i] = curr_max_y;
    }

    curr_min_y = LLONG_MAX;
    curr_max_y = 0;

    for (int i = 0; i < n - 1; i++) {
        curr_min_y = min(curr_min_y, cows[i].second);
        curr_max_y = max(curr_max_y, cows[i].second);

        if (cows[i].first < cows[i + 1].first) {
            min_double_area = min(min_double_area, (cows[i].first - cows[0].first) * (curr_max_y - curr_min_y) + (cows[n - 1].first - cows[i + 1].first) * (max_y[i + 1] - min_y[i + 1]));
        }
    }

    sort(cows.begin(), cows.end(), [](const auto & a, const auto & b) {return a.second < b.second;});

    vector<long long> min_x(n);
    vector<long long> max_x(n);
    long long curr_min_x = LLONG_MAX;
    long long curr_max_x = 0;

    for (int i = n - 1; i >= 0; i--) {
        curr_min_x = min(curr_min_x, cows[i].first);
        curr_max_x = max(curr_max_x, cows[i].first);

        min_x[i] = curr_min_x;
        max_x[i] = curr_max_x;
    }

    curr_min_x = LLONG_MAX;
    curr_max_x = 0;

    for (int i = 0; i < n - 1; i++) {
        curr_min_x = min(curr_min_x, cows[i].first);
        curr_max_x = max(curr_max_x, cows[i].first);

        if (cows[i].second < cows[i + 1].second) {
            min_double_area = min(min_double_area, (cows[i].second - cows[0].second) * (curr_max_x - curr_min_x) + (cows[n - 1].second - cows[i + 1].second) * (max_x[i + 1] - min_x[i + 1]));
        }
    }

    cout << single_area - min_double_area;

    return 0;
}
