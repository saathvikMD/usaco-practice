// Problem: Acowdemia
// Contest: USACO 2021 US Open Bronze
// Link: https://usaco.org/index.php?page=viewproblem2&cpid=1136

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k, l;

    cin >> n >> k >> l;

    vector<int> cows(n);

    for (int i = 0; i < n; i++) {
        cin >> cows[i];
    }

    sort(cows.begin(), cows.end());

    int low = 1, high = n, answer = 0;

    while (low <= high) {
        int i = low + (high - low) / 2;

        bool passed = true;

        if (cows[n - i] < i) {
            bool done = false;
            long long remaining = (long long) k * l;

            for (int j = n - i; j < n and not done; j++) {
                if (cows[j] < i) {
                    if (i - cows[j] <= k and remaining >= i - cows[j]) {
                        remaining -= i - cows[j];
                    } else {
                        done = true;
                        passed = false;
                    }
                } else {
                    done = true;
                }
            }
        }

        if (passed) {
            if (i > answer) {
                answer = i;
            }

            low = i + 1;
        } else {
            high = i - 1;
        }
    }

    cout << answer;

    return 0;
}
