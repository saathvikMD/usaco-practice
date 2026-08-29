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

        string patches(n, '.');

        int prev_patches = - k - 1;
        int patch_count = 0;

        for (int i = 0; i < n; i++) {
            if (cows[i] == 'G' and i - prev_patches > k) {
                patches[min(n - 1, i + k)] = 'G';
                prev_patches = i + k;
                patch_count += 1;
            }
        }

        prev_patches = - k - 1;

        for (int i = 0; i < n; i++) {
            if (cows[i] == 'H' and i - prev_patches > k) {
                bool done = false;

                for (int j = min(n - 1, i + k); j >= 0 and not done; j--) {
                    if (patches[j] == '.') {
                        patches[j] = 'H';
                        prev_patches = j;
                        patch_count += 1;
                        done = true;
                    }
                }
            }
        }

        cout << patch_count << "\n";

        for (int i = 0; i < n; i++) {
            cout << patches[i];
        }

        cout << "\n";
    }

    return 0;
}
