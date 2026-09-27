// Problem: Race
// Contest: USACO January 2020 Bronze
// Link: https://usaco.org/index.php?page=viewproblem2&cpid=989

#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("race.in", "r", stdin);
    freopen("race.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long k, n;

    cin >> k >> n;

    vector<long long> sum;
    sum.push_back(0);

    for (int i = 1; i < pow(10, 9); i++) {
        sum.push_back(sum[i - 1] + i);

        if (sum[i] > k) {
            sum.push_back(sum[i] + i + 1);

            break;
        }
    }

    for (int i = 0; i < n; i++) {
        long long x;

        cin >> x;

        long long best_time = INT_MAX;

        for (int j = 1; j < min(k, (long long) sum.size()); j++) {
            long long climb = sum[j];

            if (j > x) {
                climb += sum[j] - sum[x] - (j - x);
            }

            if (climb > k) {
                if (j > x) {
                    break;
                } else {
                    best_time = min(best_time, (long long) j);
                }
            } else {
                best_time = min(best_time, (j > x ? j + j - x : j) + (k - climb) / j + ((k - climb) % j == 0 ? 0 : 1));
            }
        }

        cout << best_time << "\n";
    }

    return 0;
}
