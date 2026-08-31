// Problem: Farmer John Actually Farms
// Contest: USACO December 2023 Bronze
// Link: https://usaco.org/index.php?page=viewproblem2&cpid=1349

#include <bits/stdc++.h>
using namespace std;

int main() {
    int test_cases;

    cin >> test_cases;

    for (int iteration = 0; iteration < test_cases; iteration++) {
        int n;

        cin >> n;

        vector<tuple<long long, long long, long long>> plants(n);

        for (int i = 0; i < n; i++) {
            cin >> get<1>(plants[i]);
        }

        for (int i = 0; i < n; i++) {
            cin >> get<2>(plants[i]);
        }

        for (int i = 0; i < n; i++) {
            cin >> get<0>(plants[i]);
        }

        sort(plants.begin(), plants.end());

        long long max_days = LONG_LONG_MAX;
        long long min_days = 0LL;
        bool done =  false;

        for (int i = 0; i < n - 1; i++) {
            if (get<2>(plants[i]) < get<2>(plants[i + 1])) {
                if (get<1>(plants[i]) + get<2>(plants[i]) * min_days > get<1>(plants[i + 1]) + get<2>(plants[i + 1]) * min_days) {
                    max_days = min(max_days, (get<1>(plants[i]) - get<1>(plants[i + 1]) - 1) / (get<2>(plants[i + 1]) - get<2>(plants[i])));
                } else {
                    cout << -1 << "\n";
                    done = true;
                    break;
                }
            } else if (get<2>(plants[i]) == get<2>(plants[i + 1])) {
                if (get<1>(plants[i]) <= get<1>(plants[i + 1])) {
                    cout << -1 << "\n";
                    done = true;
                    break;
                }
            } else {
                if (get<1>(plants[i]) <= get<1>(plants[i + 1])) {
                    long long curr_min = (get<1>(plants[i + 1]) - get<1>(plants[i])) / (get<2>(plants[i]) - get<2>(plants[i + 1])) + 1;

                    min_days = max(min_days, curr_min);
                }
            }

            if (min_days > max_days) {
                cout << -1 << "\n";
                done = true;
                break;
            }
        }

        if (not done) {
            cout << min_days << "\n";
        }
    }

    return 0;
}
