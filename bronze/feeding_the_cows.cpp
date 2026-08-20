// Problem: Feeding the Cows
// Contest: USACO December 2022 Bronze
// Link: https://usaco.org/index.php?page=viewproblem2&cpid=1252

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;

    cin >> t;

    for (int iteration = 0; iteration < t; iteration++) {
        int n, k;

        cin >> n >> k;

        string cows;

        cin >> cows;

        string grass(n, '.');
        int range = -1;

        for (int i = 0; i < n; i++) {
            if (cows[i] == 'G') {
                bool placed = false;

                if (range < i) {
                    for (int j = min(i + k, n - 1); j >= max(0, i - k) and not placed; j--) {
                        if (grass[j] == '.') {
                            grass[j] = 'G';
                            placed = true;
                            range = j + k;
                        }
                    }
                }
            }
        }

        range = -1;

        for (int i = 0; i < n; i++) {
            if (cows[i] == 'H') {
                bool placed = false;

                if (range < i) {
                    for (int j = min(i + k, n - 1); j >= max(0, i - k) and not placed; j--) {
                        if (grass[j] == '.') {
                            grass[j] = 'H';
                            placed = true;
                            range = j + k;
                        }
                    }
                }
            }
        }

        cout << (n - count(grass.begin(), grass.end(), '.')) << "\n";
        cout << grass << "\n";
    }

    return 0;
}
