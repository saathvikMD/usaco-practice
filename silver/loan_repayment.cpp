// Problem: Loan Repayment
// Contest: USACO January 2020 Silver
// Link: https://usaco.org/index.php?page=viewproblem2&cpid=991

#include <bits/stdc++.h>
using namespace std;

bool possible(long long n, long long k, long long m, long long x) {
    long long day = 0;
    long long g = 0;

    while (day < k) {
        long long y = (n - g) / x;

        if (y <= m) {
            if (g + m * (k - day) >= n) {
                return true;
            } else {
                return false;
            }
        } else if (g + y * (k - day) < n) {
            return false;
        } else {
            long long iterations = ((n - g) - x * y) / y;
            iterations = max(1LL, min(iterations, k - day));
            g += y * iterations;
            day += iterations;
        }
    }

    return g >= n;
}

int main() {
    freopen("loan.in", "r", stdin);
    freopen("loan.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, k, m;

    cin >> n >> k >> m;

    long long low = 1;
    long long high = n;
    long long ans = 0;

    while (low <= high) {
        long long mid = (low + high) / 2;

        if (possible(n, k, m, mid)) {
            low = mid + 1;
            ans = max(ans, mid);
        } else {
            high = mid - 1;
        }
    }

    cout << ans;

    return 0;
}
