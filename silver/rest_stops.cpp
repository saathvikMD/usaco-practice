// Problem: Rest Stops
// Contest: USACO February 2018 Silver
// Link: https://usaco.org/index.php?page=viewproblem2&cpid=810

#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("reststops.in", "r", stdin);
    freopen("reststops.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int l, n, f, b;

    cin >> l >> n >> f >> b;

    vector<pair<int, int>> tasty(n);

    for (int i = 0; i < n; i++) {
        int x, c;

        cin >> x >> c;

        tasty[i] = {x, c};
    }

    vector<int> maximum(n);
    int curr_max = 0;

    for (int i = n - 1; i >= 0; i--) {
        curr_max = max(curr_max, tasty[i].second);
        maximum[i] = curr_max;
    }

    int current_pos = 0;
    int gain = f - b;
    int grass = 0;
    long long gap = 0;
    long long sum = 0;

    while (grass < tasty.size()) {
        gap += (long long) (tasty[grass].first - current_pos) * gain;

        if (tasty[grass].second == maximum[grass]) {
            sum += gap * tasty[grass].second;
            gap = 0;
        }

        current_pos = tasty[grass].first;
        grass += 1;
    }

    cout << sum;

    return 0;
}
