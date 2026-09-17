// Problem: Counting Haybales
// Contest: USACO December 2016 Silver
// Link: https://usaco.org/index.php?page=viewproblem2&cpid=666

#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("haybales.in", "r", stdin);
    freopen("haybales.out", "w", stdout);

    int n, q;

    cin >> n >> q;

    vector<long long> bales(n);

    for (int i = 0; i < n; i++) {
        cin >> bales[i];
    }

    sort(bales.begin(), bales.end());

    for (int i = 0; i < q; i++) {
        long long a, b;

        cin >> a >> b;

        long long low = 0;
        long long high = n - 1;
        long long a_max = -1;

        while (low <= high) {
            long long mid = low + (high - low) / 2;

            if (bales[mid] < a) {
                a_max = max(a_max, mid);

                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        low = 0;
        high = n - 1;
        long long b_min = n;

        while (low <= high) {
            long long mid = low + (high - low) / 2;

            if (bales[mid] > b) {
                b_min = min(b_min, mid);

                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        cout << b_min - a_max - 1 << endl;
    }

    return 0;
}
