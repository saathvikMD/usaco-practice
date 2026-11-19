// Problem: Cow-libi
// Contest: USACO February 2023 Silver
// Link: https://usaco.org/index.php?page=viewproblem2&cpid=1303

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int g, n;

    cin >> g >> n;

    vector<tuple<int, int, int>> grazing;

    for (int i = 0; i < g; i++) {
        int x, y, t;

        cin >> x >> y >> t;

        grazing.push_back({t, x, y});
    }

    sort(grazing.begin(), grazing.end());

    int count = 0;

    for (int i = 0; i < n; i++) {
        long long x, y, t;

        cin >> x >> y >> t;

        int next = lower_bound( grazing.begin(), grazing.end(), make_tuple(t, INT_MIN, INT_MIN) ) - grazing.begin();
        int prev = next - 1;
        bool possible = true;

        if (prev >= 0) {
            long long a = get<1>(grazing[prev]);
            long long b = get<2>(grazing[prev]);

            if (abs(t - get<0>(grazing[prev])) * abs(t - get<0>(grazing[prev])) < (x - a) * (x - a) + (y - b) * (y - b)) {
                possible = false;
            }
        }

        if (possible and next < g) {
            long long a = get<1>(grazing[next]);
            long long b = get<2>(grazing[next]);

            if (abs(t - get<0>(grazing[next])) * abs(t - get<0>(grazing[next])) < (x - a) * (x - a) + (y - b) * (y - b)) {
                possible = false;
            }
        }

        if (not possible) {
            count += 1;
        }
    }

    cout << count;

    return 0;
}
