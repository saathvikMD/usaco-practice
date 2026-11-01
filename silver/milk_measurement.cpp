// Problem: Milk Measurement
// Contest: USACO December 2017 Silver
// Link: https://usaco.org/index.php?page=viewproblem2&cpid=763

#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("measurement.in", "r", stdin);
    freopen("measurement.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, g;

    cin >> n >> g;

    vector<tuple<int, int, int>> measurements(n);
    unordered_map<int, int> cows;
    map<int, int> gallons;

    for (int i = 0; i < n; i++) {
        int t, c, d;

        cin >> t >> c >> d;

        measurements[i] = make_tuple(t, c, d);
        cows[c] = g;
        gallons[g] += 1;
    }

    gallons[g]++;

    sort(measurements.begin(), measurements.end());

    int curr_max = g;
    int changes = 0;

    for (int i = 0; i < n; i++) {
        auto [t, c, d] = measurements[i];

        gallons[cows[c]] -= 1;

        if (gallons[cows[c]] == 0) {
            gallons.erase(cows[c]);
        }

        cows[c] += d;
        gallons[cows[c]] += 1;

        if (cows[c] > curr_max) {
            if (gallons.count(curr_max) > 0) {
                changes += 1;
            }

            curr_max = cows[c];
        } else if (cows[c] == curr_max and d > 0) {
            changes += 1;
        } else if (cows[c] - d == curr_max) {
            if (gallons.rbegin() -> first == curr_max) {
                changes += 1;
            } else if (gallons[gallons.rbegin() -> first] == 1 and cows[c] == gallons.rbegin() -> first) {
                curr_max = gallons.rbegin() -> first;
            } else {
                curr_max = gallons.rbegin() -> first;
                changes += 1;
            }
        }
    }

    cout << changes;

    return 0;
}
