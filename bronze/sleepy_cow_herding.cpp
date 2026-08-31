// Problem: Sleepy Cow Herding
// Contest: USACO February 2019 Bronze
// Link: https://usaco.org/index.php?page=viewproblem2&cpid=915

#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("herding.in", "r", stdin);
    freopen("herding.out", "w", stdout);

    vector<long long> cows(3);

    for (int i = 0; i < 3; i++) {
        cin >> cows[i];
    }

    sort(cows.begin(), cows.end());

    if (cows[2] - cows[1] == 1 and cows[1] - cows[0] == 1) {
        cout << 0 << "\n";
    } else if (cows[2] - cows[1] == 2 or cows[1] - cows[0] == 2) {
        cout << 1 << "\n";
    } else {
        cout << 2 << "\n";
    }

    cout << max(cows[2] - cows[1], cows[1] - cows[0]) - 1;

    return 0;
}
