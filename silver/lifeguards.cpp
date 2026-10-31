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

    long long total_shifts = shifts[0].second - shifts[0].first;
    long long prev_end = shifts[0].second;
    vector<pair<long long, long long>> alone;
    alone.push_back({shifts[0].second - shifts[0].first, shifts[0].second});
    long long min_alone = alone[0].first;

    for (int i = 1; i < n; i++) {
        if (shifts[i].first >= prev_end) {
            total_shifts += shifts[i].second - shifts[i].first;
            prev_end = shifts[i].second;
        } else if (shifts[i].second > prev_end) {
            total_shifts += shifts[i].second - prev_end;
            prev_end = shifts[i].second;
        }

        if (shifts[i].first >= alone[i - 1].second) {
            alone.push_back({shifts[i].second - shifts[i].first, shifts[i].second});
        } else if (shifts[i].second > alone[i - 1].second) {
            alone[i - 1].first = max(0LL, alone[i - 1].first - (alone[i - 1].second - shifts[i].first));
            min_alone = min(min_alone, alone[i - 1].first);
            alone.push_back({shifts[i].second - alone[i - 1].second, shifts[i].second});
        } else {
            alone.push_back({0, -1});
        }

        min_alone = min(min_alone, alone[i].first);
    }
    
    cout << total_shifts - min_alone;

    return 0;
}
