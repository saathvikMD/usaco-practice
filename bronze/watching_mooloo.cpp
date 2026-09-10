// Problem: Watching Mooloo
// Contest: USACO February 2023 Bronze
// Link: https://usaco.org/index.php?page=viewproblem2&cpid=1301

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, k;

    cin >> n >> k;

    vector<long long> days(n);

    for (int i = 0; i < n; i++) {
        cin >> days[i];
    }

    long long payed = k + 1;
    long long started = days[0];

    for (int i = 1; i < n; i++) {
        if ((days[i] - started) > (k + 1)) {
            payed += k + 1;
        } else {
            payed += days[i] - started;
        }

        started = days[i];
    }

    cout << payed;

    return 0;
}
