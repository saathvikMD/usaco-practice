// Problem: Cycle Correspondence
// Contest: USACO December 2023 Silver
// Link: https://usaco.org/index.php?page=viewproblem2&cpid=1351

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;

    cin >> n >> k;

    unordered_map<int, int> map_a;
    unordered_map<int, int> map_b;
    vector<int> a(n);
    vector<int> b(n);

    for (int i = 0; i < k; i++) {
        int val;

        cin >> val;

        a[i] = val;
        map_a[val] = i;
    }

    int differences = 0;

    for (int i = 0; i < k; i++) {
        int val;

        cin >> val;

        b[i] = val;
        map_b[val] = i;

        if (not map_a.count(val)) {
            differences += 1;
        }
    }

    vector<int> forward(n, 0);
    vector<int> reverse(n, 0);

    for (int i = 0; i < n; i++) {
        if (map_a.count(b[i])) {
            forward[(map_a[b[i]] - i + k) % k]++;
            reverse[(map_a[b[i]] + i) % k]++;
        }
    }

    int max_shift = 0;

    for (int i = 0; i < n; i++) {
        if (forward[i] > max_shift) {
            max_shift = forward[i];
        }

        if (reverse[i] > max_shift) {
            max_shift = reverse[i];
        }
    }

    cout << max_shift + n - k  - differences;

    return 0;
}
