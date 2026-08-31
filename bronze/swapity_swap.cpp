// Problem: Swapity Swap
// Contest: USACO February 2020 Bronze
// Link: https://usaco.org/index.php?page=viewproblem2&cpid=1013

#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("swap.in", "r", stdin);
    freopen("swap.out", "w", stdout);

    int n, k;

    cin >> n >> k;

    int a1, a2, b1, b2;

    cin >> a1 >> a2 >> b1 >> b2;

    vector<int> cows(n);

    for (int i = 0; i < n; i++) {
        cows[i] = i + 1;
    }

    vector<int> original = cows;

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < (a2 - a1 + 1) / 2; j++) {
            int temp = cows[a1 - 1 + j];
            cows[a1 - 1 + j] = cows[a2 - 1 - j];
            cows[a2 - 1 - j] = temp;
        }

        for (int j = 0; j < (b2 - b1 + 1) / 2; j++) {
            int temp = cows[b1 - 1 + j];
            cows[b1 - 1 + j] = cows[b2 - 1 - j];
            cows[b2 - 1 - j] = temp;
        }

        if (cows == original) {
            i = (k / (i + 1)) * (i + 1) - 1;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << cows[i] << "\n";
    }

    return 0;
}
