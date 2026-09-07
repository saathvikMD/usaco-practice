// Problem: Farmer John Actually Farms
// Contest: USACO December 2023 Bronze
// Link: https://usaco.org/index.php?page=viewproblem2&cpid=1349

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;

    cin >> t;

    for (int iteration = 0; iteration < t; iteration++) {
        int n;

        cin >> n;

        vector<tuple<long long, long long, long long>> plants(n);
        long long temp;

        for (int i = 0; i < n; i++) {
            cin >> temp;

            get<1>(plants[i]) = temp;
        }

        for (int i = 0; i < n; i++) {
            cin >> temp;

            get<2>(plants[i]) = temp;
        }

        for (int i = 0; i < n; i++) {
            cin >> temp;

            get<0>(plants[i]) = temp;
        }

        sort(plants.begin(), plants.end());

        long long days = 0;
        bool possible = true;

        for (int i = 0; i < n - 1; i++) {
            long long height_diff = get<1>(plants[i]) - get<1>(plants[i + 1]);

            if (height_diff <= 0) {
                long long growth_rate = (get<2>(plants[i]) - get<2>(plants[i + 1]));

                if (growth_rate > 0) {
                    days = max((long long) ceil((double) (-height_diff + 1) / growth_rate), days);
                } else {
                    possible = false;
                    break;
                }
            }
        }

        if (possible) {
            for (int i = 0; i < n - 1; i++) {
                if (get<1>(plants[i]) + get<2>(plants[i]) * days <= get<1>(plants[i + 1]) + get<2>(plants[i + 1]) * days) {
                    possible = false;
                    break;
                }
            }
        }

        if (possible) {
            cout << days << "\n";
        } else {
            cout << -1 << "\n";
        }
    }

    return 0;
}
