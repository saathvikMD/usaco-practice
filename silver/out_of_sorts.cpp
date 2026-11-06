// Problem: Out of Sorts
// Contest: USACO 2018 US Open Silver
// Link: https://usaco.org/index.php?page=viewproblem2&cpid=834

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

int main() {
    freopen("sort.in", "r", stdin);
    freopen("sort.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;

    cin >> n;

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> s;
    int moo = 0;

    for (int i = 0; i < n; i++) {
        s.insert({a[i], i});
        int index = s.order_of_key({a[i], i});

        moo = max(moo, i - index);
    }

    cout << moo + 1;

    return 0;
}
