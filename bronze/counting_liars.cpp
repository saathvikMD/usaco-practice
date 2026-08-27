// Problem: Counting Liars
// Contest: USACO 2022 US Open Bronze
// Link: https://usaco.org/index.php?page=viewproblem2&cpid=1228

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;

    cin >> n;

    vector<pair<long long, bool>> cows;

    long long low_sum = 0;
    long long high_sum = 0;

    for (int i = 0; i < n; i++) {
        char g_or_l;

        cin >> g_or_l;

        long long p;

        cin >> p;

        if (g_or_l == 'L') {
            cows.push_back({p, true});
            high_sum += 1;
        } else {
            cows.push_back({p, false});
        }
    }

    sort(cows.begin(), cows.end());

    long long least = INT_MAX;

    for (int i = 0; i < n; i++) {
        long long lies = n - high_sum - low_sum;

        if (lies < least) {
            least = lies;
        }

        if (cows[i].second == false) {
            low_sum += 1;
        } else {
            high_sum -= 1;
        }
    }

    long long lies = n - high_sum - low_sum;

    if (lies < least) {
        least = lies;
    }

    cout << least;

    return 0;
}
