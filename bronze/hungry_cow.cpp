// Problem: Hungry Cow
// Contest: USACO February 2023 Bronze
// Link: https://usaco.org/index.php?page=viewproblem2&cpid=1299

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, t;

    cin >> n >> t;

    long long eaten = 0;
    long long remaining = 0;
    long long prev_day = 1;

    for (int i = 0; i < n; i++) {
        long long d, b;

        cin >> d >> b;

        long long to_eat = min(remaining, d - prev_day);
        eaten += to_eat;
        remaining += b - to_eat;
        prev_day = d;
    }

    eaten += min(remaining, t - prev_day + 1);

    cout << eaten;

    return 0;
}
