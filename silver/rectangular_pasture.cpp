// Problem: Rectangular Pasture
// Contest: USACO December 2020 Silver
// Link: https://usaco.org/index.php?page=viewproblem2&cpid=1063

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;

    cin >> n;

    vector<pair<int, int>> cows(n);

    for (int i = 0; i < n; i++) {
        cin >> cows[i].first;
        cin >> cows[i].second;
    }

    sort(cows.begin(), cows.end());

    long long count = n + 1;

    for (int i = 0; i < n; i++) {
        tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> s;
        s.insert(cows[i].second);

        for (int j = i + 1; j < n; j++) {
            s.insert(cows[j].second);

            count += 1LL * (s.order_of_key(min(cows[i].second, cows[j].second)) + 1) * (s.size() - s.order_of_key(max(cows[i].second, cows[j].second)));
        }
    }

    cout << count;

    return 0;
}
