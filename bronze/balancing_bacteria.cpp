// Problem: Balancing Bacteria
// Contest: USACO January 2024 Bronze
// Link: https://usaco.org/index.php?page=viewproblem2&cpid=1373

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;

    cin >> n;

    vector<long long> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    long long total_sprays = 0;
    long long current = 0;
    long long difference = 0;

    for (int i = 0; i < n; i++) {
        a[i] += current;
        total_sprays += abs(a[i]);

        current += difference - 2 * a[i];
        difference -= a[i];
    }

    cout << total_sprays;

    return 0;
}
