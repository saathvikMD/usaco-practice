// Problem: Acowdemia
// Contest: USACO 2021 US Open Bronze
// Link: https://usaco.org/index.php?page=viewproblem2&cpid=1136

#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, k , l;

    cin >> n >> k >> l;

    vector<long long> cows(n);

    for (long long i = 0; i < n; i++) {
        cin >> cows[i];
    }

    sort(cows.begin(), cows.end());
    long long low = 1, high = n, answer = 0;

    while (low <= high) {
        long long h = (low + high + 1) / 2;
        bool passed = true;

        if (cows[n - h] < h) {
            long long remaining = k * l;

            for (long long i = n - h; i < n; i++) {
                if (cows[i] < h) {
                    if (h - cows[i] > remaining or h - cows[i] > k) {
                        passed = false;

                        break;
                    } else {
                        remaining -= h - cows[i];
                    }
                } else {
                    break;
                }
            }
        }

        if (passed) {
            low = h + 1;

            if (h > answer) {
                answer = h;
            }
        } else {
            high = h - 1;
        }
    }

    cout << answer;

    return 0;
}
