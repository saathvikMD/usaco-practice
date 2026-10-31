// Problem: Lifeguards
// Contest: USACO January 2018 Silver
// Link: https://usaco.org/index.php?page=viewproblem2&cpid=786

#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("lifeguards.in", "r", stdin);
    freopen("lifeguards.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;

    cin >> n;

    vector<pair<long long, long long>> shifts(n);

    for (int i = 0; i < n; i++) {
        long long start, end;

        cin >> start >> end;

        shifts[i] = {start, end};
    }

    sort(shifts.begin(), shifts.end());

    long long min_covered = shifts[0].second - shifts[0].first;
    long long total_covered = shifts[0].second - shifts[0].first;
    long long prev_start = shifts[0].first, prev_end = shifts[0].second;

    for (int i = 1; i < n; i++) {
        if (shifts[i].first == shifts[i - 1].first) {
            min_covered = 0;
            total_covered += max(0LL, shifts[i].second - prev_end);
            prev_end = max(prev_end, shifts[i].second);
        } else if (shifts[i].second <= prev_end) {
            min_covered = 0;
        } else if (prev_end > shifts[i].first) {
            min_covered = min(min_covered, shifts[i].first - prev_start);
            total_covered += shifts[i].second - prev_end;
            prev_start = prev_end;
            prev_end = shifts[i].second;
        } else if (shifts[i].first >= prev_end) {
            min_covered = min(min_covered, shifts[i].second - shifts[i].first);
            total_covered += shifts[i].second - shifts[i].first;
            prev_start = shifts[i].first;
            prev_end = shifts[i].second;
        }
    }

    cout << total_covered - min_covered;

    return 0;
}
