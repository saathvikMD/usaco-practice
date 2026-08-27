// Problem: Photoshoot
// Contest: USACO January 2020 Bronze
// Link: https://usaco.org/index.php?page=viewproblem2&cpid=988

#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("photo.in", "r", stdin);
    freopen("photo.out", "w", stdout);

    int n;

    cin >> n;

    vector<int> sums(n - 1);

    for (int i = 0; i < n - 1; i++) {
        cin >> sums[i];
    }

    vector<bool> used(n);

    for (int i = 0; i < n; i++) {
        used[i] = false;
    }

    for (int i = 1; i <= n; i++) {
        bool done = false;
        int prev_value = i;
        vector<bool> used_temp = used;
        used_temp[i - 1] = true;

        for (int j = 1; j < n; j++) {
            int curr = sums[j - 1] - prev_value;

            if (curr > 0 and curr <= n) {
                if (used_temp[curr - 1]) {
                    done = true;
                } else {
                    used_temp[curr - 1] = true;
                }
            } else {
                done = true;
            }

            prev_value = curr;
        }

        if (not done) {
            prev_value = i;

            for (int j = 1; j < n; j++) {
                cout << prev_value << " ";
                
                prev_value = sums[j - 1] - prev_value;
            }

            cout << prev_value;

            return 0;
        }
    }

    return 0;
}
